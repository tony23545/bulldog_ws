//server node to transform pointcloud from focal frame to base link frame
#include "ros/ros.h"
#include <tf/transform_listener.h>
#include "gpd/pc_transform.h"
#include "pcl_ros/transforms.h"

class pc_transformer{
public:
	pc_transformer() {}
	tf::TransformListener listener;
	bool pc_transform_func(gpd::pc_transform::Request &req,
	              gpd::pc_transform::Response &res){
		ROS_INFO("Receive point cloud msg!");
	
		//listener.waitForTransform("base_link", req.in_cloud.header.frame_id, ros::Time(0), ros::Duration(2.0));
		//printf("get!");
		bool error_flag = true;
		while(error_flag){
			error_flag = false;
			try{
				listener.waitForTransform("base_link", req.in_cloud.header.frame_id, req.in_cloud.header.stamp, ros::Duration(10.0));
				pcl_ros::transformPointCloud("base_link", req.in_cloud, res.out_cloud, listener);
			}
			catch(tf::TransformException &ex){
				error_flag = true;
				ROS_ERROR("%s", ex.what());
				ros::Duration(0.5).sleep();
				continue;
			}
		}
	return true;
	}
};


int main(int argc, char **argv){
	ros::init(argc, argv, "point_cloud_transform");
	ros::NodeHandle n;
	pc_transformer tf;
	ros::ServiceServer service = n.advertiseService("pc_transform_srv", &pc_transformer::pc_transform_func, &tf);
	ROS_INFO("READY TO TRANSFORM POINTCLOUD!");
	ros::spin();
	return 0;
}