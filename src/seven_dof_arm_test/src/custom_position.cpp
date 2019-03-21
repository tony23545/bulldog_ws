#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/RobotTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include "stdio.h"
#include "ros/ros.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"
#include "tf/transform_listener.h"
#include "geometry_msgs/Point.h"
#include <vector>
#include <string>
#include "math.h"
#include "std_msgs/String.h"
#include <sstream>
using namespace std;

int main(int argc, char **argv){
	ros::init(argc, argv, "pick_node");
  	ros::NodeHandle nh;  
  	ros::AsyncSpinner spinner(1);
  	spinner.start();

  	/* This sleep is ONLY to allow Rviz to come up */
  	sleep(2.0);

  	moveit::planning_interface::MoveGroup left_group("left_arm");
  	moveit::planning_interface::MoveGroup right_group("right_arm");

  	

  	ros::shutdown();
	return 0;
}
