#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/OrientationConstraint.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include "stdio.h"
#include "ros/ros.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"
#include "tf/transform_listener.h"
#include "geometry_msgs/Point.h"
#include <vector>
using namespace std;


int main(int argc, char **argv){
	ros::init(argc, argv, "grasp_node");
	ros::NodeHandle nh;
	ros::AsyncSpinner spinner(1);
	spinner.start();

	std::vector<double> left_group_variable_values;
	std::vector<double> right_group_variable_values;

	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
	moveit::planning_interface::MoveGroup left_group("left_arm");
	moveit::planning_interface::MoveGroup right_group("right_arm");
	left_group.setPlannerId("RRTstarkConfigDefault");
	right_group.setPlannerId("RRTstarkConfigDefault");
	bool success;
	bool ex;
	moveit::planning_interface::MoveGroup::Plan my_plan;

	ROS_INFO("\n\nReference frame: %s", left_group.getEndEffectorLink().c_str());
	//ROS_INFO("range: %f", left_group.getRange().c_str());
	left_group_variable_values.clear();
	left_group_variable_values.push_back(-0.8);
	left_group_variable_values.push_back(-1.5);
	left_group_variable_values.push_back(1.7);
	left_group_variable_values.push_back(-3.2);
	left_group_variable_values.push_back(-0.5);
	left_group_variable_values.push_back(1.4);

	right_group_variable_values.clear();
	right_group_variable_values.push_back(0.8);
	right_group_variable_values.push_back(-1.5);
	right_group_variable_values.push_back(-1.7);
	right_group_variable_values.push_back(0.2);
	right_group_variable_values.push_back(0.5);
	right_group_variable_values.push_back(1.4);

	left_group.setStartState(*left_group.getCurrentState());
	left_group.setJointValueTarget(left_group_variable_values);

	ROS_INFO("start planning\n");
	
	success = left_group.plan(my_plan);
	if(success){
		bool ex = left_group.execute(my_plan);
	}

	right_group.setStartState(*right_group.getCurrentState());
	right_group.setJointValueTarget(right_group_variable_values);

	success = right_group.plan(my_plan);
	if(success){
		bool ex = right_group.execute(my_plan);
	}

	sleep(1.0);

	geometry_msgs::Pose target_pose1;
	target_pose1.position.x = 0.748422;
	target_pose1.position.y = 0.009253;
	target_pose1.position.z = 0.542553;
	target_pose1.orientation.x = 1.0;
	target_pose1.orientation.y = 0.0;
	target_pose1.orientation.z = 0.0;
	target_pose1.orientation.w = 0.0;

	left_group.setStartState(*left_group.getCurrentState());
	left_group.setPoseTarget(target_pose1); 
	success = left_group.plan(my_plan);
	if(success){
		ex = left_group.execute(my_plan);
		if(!ex){
			ROS_INFO("exe failed!");
		}
	}

	sleep(1.0);

	std::vector<geometry_msgs::Pose> waypoints;
	geometry_msgs::Pose target_pose3 = target_pose1;
	target_pose3.position.x += 0.2;
	target_pose3.position.z += 0.2;
	waypoints.push_back(target_pose3);

	target_pose3.position.y -= 0.2;
	waypoints.push_back(target_pose3);
	moveit_msgs::RobotTrajectory trajectory;
	left_group.setStartState(*left_group.getCurrentState());
	double fraction = left_group.computeCartesianPath(waypoints,
                                             0.01,  // eef_step
                                             0.0,   // jump_threshold
                                             trajectory);
	my_plan.trajectory_ = trajectory;
	left_group.execute(my_plan);





/*
	target_pose1.position.x = 0.5;
	target_pose1.position.y = 0.2;
	target_pose1.position.z = 0.4;
	target_pose1.orientation.x = 1.0;
	target_pose1.orientation.y = 0.0;
	target_pose1.orientation.z = 0.0;
	target_pose1.orientation.w = 0.0;

	moveit_msgs::OrientationConstraint ocm;
	ocm.link_name = "left_arm_wrist_3_link";
	ocm.header.frame_id = "base_link";
	ocm.orientation.z = 0.0;
	ocm.absolute_x_axis_tolerance = 0.1;
	ocm.absolute_y_axis_tolerance = 0.1;
	ocm.absolute_z_axis_tolerance = 0.1;
	ocm.weight = 1.0;

	moveit_msgs::Constraints test_constraints;
	test_constraints.orientation_constraints.push_back(ocm);
	left_group.setPathConstraints(test_constraints);



	left_group.setStartState(*left_group.getCurrentState());
	left_group.setPoseTarget(target_pose1); 
	success = left_group.plan(my_plan);
	if(success){
		ex = left_group.execute(my_plan);
		if(!ex){
			ROS_INFO("exe failed!");
		}
	}*/


	ros::shutdown();
	return 0;
}