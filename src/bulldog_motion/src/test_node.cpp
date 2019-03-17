
#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <boost/math/constants/constants.hpp>
#include <moveit_msgs/Constraints.h>
#include <moveit_msgs/OrientationConstraint.h>

#include "stdio.h"
#include "ros/ros.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"
#include "tf/transform_listener.h"
#include "geometry_msgs/Point.h"
#include <vector>
using namespace std;


int main(int argc, char** argv){
	ros::init(argc, argv, "move_group_interface_tutorial");
	ros::NodeHandle node_handle;
	ros::AsyncSpinner spinner(1);
	spinner.start();

	bool success, ex;

	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
	moveit::planning_interface::MoveGroup move_group("left_arm");
	ROS_INFO("End Effector: %s", move_group.getEndEffectorLink().c_str());
	ROS_INFO("Planning Frame: %s", move_group.getPlanningFrame().c_str());
	move_group.setPlannerId("RRTstarkConfigDefault");
	move_group.setNumPlanningAttempts(5);
	move_group.setPlanningTime(5);

	//define constraints
	moveit_msgs::OrientationConstraint ocm;
	ocm.link_name = "left_arm_wrist_3_link";
	ocm.header.frame_id = "base_link";
	ocm.orientation.x = 0;
  	ocm.orientation.y = 0;
  	ocm.orientation.z = 0;
	ocm.orientation.w = 1.0;
	ocm.absolute_x_axis_tolerance = 0.1;
	ocm.absolute_y_axis_tolerance = 0.1;
	ocm.absolute_z_axis_tolerance = boost::math::constants::pi<double>();
	ocm.weight = 1.0;
	moveit_msgs::Constraints cmsg;
	cmsg.orientation_constraints.resize(1, ocm);
	cmsg.name = ocm.link_name + ":upright";

	geometry_msgs::Pose target_pose1;
	target_pose1.orientation.w = 1.0;
	//target_pose1.orientation.z = -0.8;
	target_pose1.position.x = 0.180870908203 + 0.13;
	target_pose1.position.y = -0.176920480332;
	target_pose1.position.z = 0.52867310215 + 0.13;
	move_group.setStartState(*move_group.getCurrentState());
	move_group.setPoseTarget(target_pose1);
	ROS_INFO("start planning");
	moveit::planning_interface::MoveGroup::Plan my_plan;
	success = move_group.plan(my_plan);
	getchar();
	if(success){
		ex = move_group.execute(my_plan);
		if(!ex){
			ROS_INFO("exe failed!");
		}
	}
	getchar();

	/*
	move_group.setPathConstraints(cmsg);
	target_pose1.orientation.w = 0.6;
	target_pose1.orientation.z = 0.8;

	target_pose1.position.x = 0.6;
	target_pose1.position.y = 0.5;
	target_pose1.position.z = 0.6;
	move_group.setStartState(*move_group.getCurrentState());
	move_group.setPoseTarget(target_pose1);
	ROS_INFO("start planning");
	success = move_group.plan(my_plan);
	if(success){
		ex = move_group.execute(my_plan);
		if(!ex){
			ROS_INFO("exe failed!");
		}
	}*/



	ros::shutdown();

	return 0;
}