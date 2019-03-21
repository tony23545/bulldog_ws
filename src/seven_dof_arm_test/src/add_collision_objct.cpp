#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include "stdio.h"
#include "ros/ros.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"
#include "tf/transform_listener.h"
#include "geometry_msgs/Point.h"
#include <string>
#include "math.h"
#include "std_msgs/String.h"
#include <sstream>

const double pi=3.141592653;
bool isGetPose = false;
geometry_msgs::Pose pose_average;
void CallBack(const geometry_msgs::Pose::ConstPtr& msg)
{
	isGetPose = true ;
	pose_average = *msg;
    ROS_INFO("I have received the pose!");
    printf("average:\npose:\nx:%f\ty:%f\tz:%f\n", pose_average.position.x,pose_average.position.y,pose_average.position.z);
    printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",pose_average.orientation.x,pose_average.orientation.y,pose_average.orientation.z,pose_average.orientation.w);

       
 } 

int main(int argc, char **argv)
{
    // Initialize ROS, create the node handle and an async spinner
    ros::init(argc, argv, "add_collision_objct");
    ros::NodeHandle nh;

    ros::AsyncSpinner spin(1);
    spin.start();
    ros::Subscriber position_sub = nh.subscribe("object_position_signal", 1000, CallBack);
    // We obtain the current planning scene and wait until everything is up
    // and running, otherwise the request won't succeed
    moveit::planning_interface::PlanningSceneInterface current_scene;

    sleep(5.0);

    // We create a box with certain dimensions and orientation, we also
    // give it a name which can later be used to remove it from the scene
    // The dimensions of the box (and also the object type which in this case
    // is box) is defined by a SolidPrimitive message, the pose of the box by a
    // pose message
    while(!isGetPose);
    moveit_msgs::CollisionObject cylinder;

    cylinder.id = "seven_dof_arm_cylinder";

    shape_msgs::SolidPrimitive primitive;
    primitive.type = primitive.CYLINDER;
    primitive.dimensions.resize(3);
    primitive.dimensions[0] = 0.113;
    primitive.dimensions[1] = 0.033;
//    primitive.dimensions[2] = 0.2;

    geometry_msgs::Pose pose;
    pose.orientation.w = 1.0;
    pose.position.x =  pose_average.position.x;
    pose.position.y = pose_average.position.y;
    pose.position.z =  pose_average.position.z;

    cylinder.primitives.push_back(primitive);
    cylinder.primitive_poses.push_back(pose);
    cylinder.operation = cylinder.ADD;

    std::vector<moveit_msgs::CollisionObject> collision_objects;
    collision_objects.push_back(cylinder);

    // Once all of the objects (in this case just one) have been added to the
    // vector, we tell the planning scene to add our new box
    current_scene.addCollisionObjects(collision_objects);

    ros::shutdown();

    return 0;
}
