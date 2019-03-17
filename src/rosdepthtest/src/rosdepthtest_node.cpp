#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/PointCloud2.h>
#include <sensor_msgs/Image.h>

// PCL Lib
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
//#include <pcl/visualization/pcl_visualizer.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/point_cloud.h>
#include <pcl/filters/voxel_grid.h>
//#include <pcl/visualization/cloud_viewer.h>
#include <pcl_ros/transforms.h>
#include <tf/transform_listener.h>

#include <mask_rcnn_ros/Result.h>

typedef pcl::PointCloud<pcl::PointXYZRGB> PointCloud;

using namespace std;

// Camera Parameters (inner)
const double camera_factor = 1;
const double camera_cx = 320.5;
const double camera_cy = 240.5;
const double camera_fx = 554.254691191187;
const double camera_fy = 554.254691191187;

cv_bridge::CvImagePtr color_ptr, depth_ptr;
cv::Mat color_pic, depth_pic;

mask_rcnn_ros::Result mask_result;
sensor_msgs::Image mask_image;

void color_Callback(const sensor_msgs::ImageConstPtr& color_msg)
{
    try
    {
        cv::imshow("color_view", cv_bridge::toCvShare(color_msg, sensor_msgs::image_encodings::BGR8)->image);
        color_ptr = cv_bridge::toCvCopy(color_msg, sensor_msgs::image_encodings::BGR8);

        cv::waitKey(10);
    }
    catch (cv_bridge::Exception& e )
    {
        ROS_ERROR("Could not convert from '%s' to 'bgr8'.", color_msg->encoding.c_str());
    }
    color_pic = color_ptr->image;

    // output some info about the rgb image in cv format
    cout << "RGB PIC INFO: " << endl;
    cout<<"output some info about the rgb image in cv format"<<endl;
    cout<<"rows of the rgb image = "<<color_pic.rows<<endl;
    cout<<"cols of the rgb image = "<<color_pic.cols<<endl;
    cout<<"type of rgb_pic's element = "<<color_pic.type()<<endl;
}


void depth_Callback(const sensor_msgs::ImageConstPtr& depth_msg)
{

    try
    {
        cv::imshow("depth_view", cv_bridge::toCvShare(depth_msg, sensor_msgs::image_encodings::TYPE_32FC1)->image);
        depth_ptr = cv_bridge::toCvCopy(depth_msg, sensor_msgs::image_encodings::TYPE_32FC1);

        cv::waitKey(10);
    }
    catch (cv_bridge::Exception& e)
    {
        ROS_ERROR("Could not convert from '%s' to 'mono16'.", depth_msg->encoding.c_str());
    }

    depth_pic = depth_ptr->image;

    // output some info about the depth image in cv format
    cout << "DEPTH PIC INFO: " << endl;
    cout<<"output some info about the depth image in cv format"<<endl;
    cout<<"rows of the depth image = "<<depth_pic.rows<<endl;
    cout<<"cols of the depth image = "<<depth_pic.cols<<endl;
    cout<<"type of depth_pic's element = "<<depth_pic.type()<<endl;
}

void mask_Callback(const mask_rcnn_ros::Result::ConstPtr& mask_msg){
   if(mask_msg->masks.size() <= 0){
    cout << "no objects in the result!" << endl;
   }else{
    mask_image = mask_msg->masks[0];
   }

}

sensor_msgs::PointCloud2 cloud_cb (const sensor_msgs::PointCloud2& cloud_msg)
{
    // transform pointcloud to base_link
    tf::TransformListener tf_listener;
    tf_listener.waitForTransform("base_link", cloud_msg.header.frame_id, ros::Time(0), ros::Duration(2.0));
    tf::StampedTransform transform;

    try{
      tf_listener.lookupTransform("base_link",  cloud_msg.header.frame_id, ros::Time(0), transform);
    }catch(tf::LookupException& e){
      std::cerr << e.what() << std::endl;
    }catch(tf::ExtrapolationException& e){
      std::cerr << e.what() << std::endl;
    }

    // Convert to ROS data type
    sensor_msgs::PointCloud2 output;
    pcl_ros::transformPointCloud("base_link",  transform, cloud_msg, output);

    // Publish converted data
    return output;
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "Depth2PointCloud");
    ros::NodeHandle nh;

    cv::namedWindow("color_view");
    cv::namedWindow("depth_view");
    cv::namedWindow("mask_view");
    cv::startWindowThread();

    image_transport::ImageTransport it(nh);
    image_transport::Subscriber sub = it.subscribe("/camera/rgb/image_raw", 1, color_Callback);
    image_transport::Subscriber sub1 = it.subscribe("/camera/depth/image_raw", 1, depth_Callback);
    ros::Subscriber mask_sub = nh.subscribe("/mask_rcnn/result", 1, mask_Callback);
    //image_transport::Subscriber mask_sub = it.subscribe("/mask_rcnn/result", 1, mask_Callback);
    ros::Publisher pointcloud_publisher = nh.advertise<sensor_msgs::PointCloud2>("/Depth2PointCloud/initPC", 1);


    PointCloud::Ptr cloud ( new PointCloud );
    sensor_msgs::PointCloud2 pub_pointcloud;

    double sample_rate = 5; // 1HZ，1秒发1次
    ros::Rate naptime(sample_rate); // use to regulate loop rate

    cout<<"Depth2PointCloud:    Depth Sampling"<<endl;
    while (ros::ok())
    {
        // 遍历深度图
        if((depth_pic.rows > 0 && depth_pic.cols > 0))
        {
        	for (int m = 0; m < depth_pic.rows; m++)
            {
                for (int n = 0; n < depth_pic.cols; n++)
                {

                    if(mask_image.data[m*mask_image.step+n] == 0)
                        continue;
                    float d = depth_pic.ptr<float>(m)[n];
                    if (d == 0)
                        continue;

                    pcl::PointXYZRGB p;
                    p.z = double(d) / camera_factor;
                    p.x = (n - camera_cx) * p.z / camera_fx;
                    p.y = (m - camera_cy) * p.z / camera_fy;

                    p.b = color_pic.ptr<uchar>(m)[n*3];
                    p.g = color_pic.ptr<uchar>(m)[n*3+1];
                    p.r = color_pic.ptr<uchar>(m)[n*3+2];

                    cloud->points.push_back( p );
                }
        	}

        	cloud->height = 1;
        	cloud->width = cloud->points.size() / cloud->height;
            cloud->is_dense = false;

        	pcl::toROSMsg(*cloud,pub_pointcloud);
        	pub_pointcloud.header.frame_id = "camera_frame_optical";
        	pub_pointcloud.header.stamp = ros::Time::now();
        	// pcl::io::savePCDFile("~/pointcloud.pcd", pub_pointcloud);

            pointcloud_publisher.publish(cloud_cb(pub_pointcloud));

            ROS_INFO("Point Cloud size = %d",cloud->width);
        	cout<<"Depth2PointCloud: publish point_cloud height = "<<pub_pointcloud.height<<endl;
        	cout<<"Depth2PointCloud: publish point_cloud width = "<<pub_pointcloud.width<<endl;

        	cloud->points.clear();
        }
        ros::spinOnce();
        naptime.sleep();
    }

    cv::destroyWindow("color_view");
    cv::destroyWindow("depth_view");
    cv::destroyWindow("mask_view");
}
