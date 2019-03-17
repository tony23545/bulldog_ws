#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>


int main(int argc, char** argv){
	ros::init(argc, argv, "move_group_interface_tutorial");
	ros::NodeHandle node_handle;
	ros::AsyncSpinner spinner(1);
	spinner.start();

	sleep(2.0);

	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
	moveit::planning_interface::MoveGroup group("left_arm");
	group.setPlannerId("RRTstarkConfigDefault");
	group.setNumPlanningAttempts(5);

	geometry_msgs::Pose target_pose1;
	geometry_msgs::Vector3 approach;
	approach.x = -0.285098020093;
	approach.y = -0.114193337419;
	approach.z = 0.951671687415;
	target_pose1.orientation.w = 1.0;
	target_pose1.position.x = 0.180870908203 + 0.13;
	target_pose1.position.y = -0.176920480332;
	target_pose1.position.z = 0.52867310215 + 0.13;
	move_group.setPoseTarget(target_pose1);

	moveit::planning_interface::MoveGroupInterface::Plan my_plan;
	bool success = group.plan(my_plan);
	if(success){
		ex = group.execute(my_plan);
		if(!ex){
			ROS_INFO("exe failed!");
		}
	}

	ros::shutdown();

	return 0;
}