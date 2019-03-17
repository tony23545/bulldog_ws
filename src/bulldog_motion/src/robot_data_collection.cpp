#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <boost/math/constants/constants.hpp>
#include <math.h>

//constraint database
#include <moveit/ompl_interface/ompl_interface.h>
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/profiler/profiler.h>

//ompl related
#include <moveit/ompl_interface/parameterization/model_based_state_space.h>

//date read and wirte
#include <iostream>
#include <fstream>
using namespace std;

double rand_in_range(double min, double max){
	return ((double) rand() / (RAND_MAX)) * (max - min) + min;
}

geometry_msgs::Pose random_position_generator(){
	geometry_msgs::Pose pose;
	pose.position.x = rand_in_range(0.3, 0.8);
	pose.position.y = rand_in_range(-0.8, 0.8);
	pose.position.z = rand_in_range(0.4, 1.2);
	pose.orientation.z = rand_in_range(-0.9, 0.9);
	pose.orientation.w = sqrt(1 - pose.orientation.z * pose.orientation.z);
	pose.orientation.y = 0.0;
	pose.orientation.x = 0.0;
	//printf("\npx: %f, py: %f, pz: %f, oz: %f, ow: %f\n", pose.position.x, pose.position.y, pose.position.z, pose.orientation.z, pose.orientation.w);

	return pose;
}

/*void copyToRobotState(robot_state::RobotState& rstate, ompl::base::State* state){
	rstate.setJointGroupPositions(rstate.getJointModelGroup("arm"), state->as<ompl_interface::ModelBasedStateSpace::StateType>()->values);
  	rstate.update();
}*/

int main(int argc, char **argv){
	ros::init(argc, argv, "robot_data_collection");
	ros::NodeHandle node_handle;
	ros::AsyncSpinner spinner(1);
	spinner.start();

	sleep(5.0);

	moveit::planning_interface::MoveGroup group("manipulator");
	moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

	moveit::planning_interface::MoveGroup::Plan my_plan;
	group.setPlanningTime(10);
	group.setPlannerId("RRTstarkConfigDefault");
	bool success;
	//bool success = group.plan(my_plan);

	//define the constraint message
	moveit_msgs::OrientationConstraint ocm;
	ocm.link_name = "wrist_roll_link";
	ocm.header.frame_id = "base_link";
	ocm.orientation.w = 1.0;
	ocm.absolute_x_axis_tolerance = 0.1;
	ocm.absolute_y_axis_tolerance = 0.1;
	ocm.absolute_z_axis_tolerance = boost::math::constants::pi<double>();
	ocm.weight = 1.0;
	moveit_msgs::Constraints cmsg;
	cmsg.orientation_constraints.resize(1, ocm);
	cmsg.name = ocm.link_name + ":upright";
	//group.setPathConstraints(cmsg);

	geometry_msgs::Pose start_pose;
	robot_state::RobotState start_state(*group.getCurrentState());

	geometry_msgs::PoseStamped target_pose;
	robot_state::RobotState target_state(*group.getCurrentState());

	moveit_msgs::RobotTrajectory t_msgs;

	//create file handle
	ofstream start_file("/home/shengjian/start2.txt");
	ofstream target_file("/home/shengjian/target2.txt");
	ofstream trajectory_file("/home/shengjian/trajectory2.txt");
	std::vector<double> group_variable_values;
	int error_try = 0;
	for(int i = 0; i < 1000; ){
		ROS_INFO("generating start state\n");
		/*do{
			start_pose = random_position_generator();
		}while(!start_state.setFromIK(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), start_pose));
		group.setStartState(start_state);*/

		//save the start joint angle
		group_variable_values = group.getRandomJointValues();
		start_state.setJointGroupPositions(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), group_variable_values);
		group.setStartState(start_state);
		/*printf("\nstart joint: ");
		printf("%f %f %f %f %f %f %f", group_variable_values[0],
									   group_variable_values[1], 
									   group_variable_values[2],
									   group_variable_values[3],
									   group_variable_values[4],
									   group_variable_values[5],
									   group_variable_values[6]);*/

		ROS_INFO("generating goal state\n");
		/*do{
			target_pose = random_position_generator();
		}while(!target_state.setFromIK(group.getCurrentState()->getRobotModel()->getJointModelGroup(group.getName()), target_pose));*/
		target_pose = group.getRandomPose();
		group.setPoseTarget(target_pose);

		success = group.plan(my_plan);

		if(success){
			//save start joint angle
			ROS_INFO("planning secceed, saving data\n\n");
			start_file << group_variable_values[0] << " "
				   << group_variable_values[1] << " "
				   << group_variable_values[2] << " "
				   << group_variable_values[3] << " "
				   << group_variable_values[4] << " "
				   << group_variable_values[5] << std::endl;

			//save target pose
			target_file << target_pose.pose.position.x << " "
					<< target_pose.pose.position.y << " "
					<< target_pose.pose.position.z << " "
					<< target_pose.pose.orientation.x << " "
					<< target_pose.pose.orientation.y << " "
					<< target_pose.pose.orientation.z << " "
					<< target_pose.pose.orientation.w << endl;

			t_msgs = my_plan.trajectory_;

			//save trajectory
			for(size_t j = 0;j < t_msgs.joint_trajectory.points.size(); j++){
				/*ROS_INFO("\n%d: ", j);
				ROS_INFO("%f %f %f %f %f %f %f",
					t_msgs.joint_trajectory.points[j].positions[0], 
					t_msgs.joint_trajectory.points[j].positions[1],
					t_msgs.joint_trajectory.points[j].positions[2],
					t_msgs.joint_trajectory.points[j].positions[3],
					t_msgs.joint_trajectory.points[j].positions[4],
					t_msgs.joint_trajectory.points[j].positions[5],
					t_msgs.joint_trajectory.points[j].positions[6]);*/

					trajectory_file << t_msgs.joint_trajectory.points[j].positions[0] << " "
									<< t_msgs.joint_trajectory.points[j].positions[1] << " "
									<< t_msgs.joint_trajectory.points[j].positions[2] << " "
									<< t_msgs.joint_trajectory.points[j].positions[3] << " "
									<< t_msgs.joint_trajectory.points[j].positions[4] << " "
									<< t_msgs.joint_trajectory.points[j].positions[5] << " " << std::endl;
			}
			trajectory_file << endl;

			i++;

			if(i % 50 == 0){
				ROS_INFO("finished %d times of success planning \n", i);
			}
		}else{
			ROS_INFO("failed, not going to save the data\n\n");
			error_try ++;
		}
	}
	
	ROS_INFO("finised\n");
	start_file.close();
	target_file.close();
	trajectory_file.close();
	ROS_INFO("total planning: %d, success: %d, fail: %d, success_rate: %f", error_try + 1000, 1000, error_try, 1000.0 / (1000 + error_try));

	//load constraint database
	/*robot_model_loader::RobotModelLoader rml(ROBOT_DESCRIPTION);
	planning_scene::PlanningScenePtr ps(new planning_scene::PlanningScene(rml.getModel()));
	ompl_interface::OMPLInterface ompl_interface(rml.getModel());
	ompl_interface.getConstraintsLibrary().loadConstraintApproximations(cpath);


	//define start state
	printf("\ngetting start state\n");
	ompl::base::State* temp_state;
	printf("\nhhh\n");
	robot_state::RobotState start_state(*group.getCurrentState());
	printf("\nhhh\n");

	copyToRobotState(start_state, ompl_interface.getConstraintsLibrary().getConstraintApproximation(cmsg)->getStateStorage()->getState(start_state.getRandomNumberGenerator().uniformInteger(0, max_index_)));
	printf("\nhhh\n");
	group.setStartState(start_state);

	//defien target pose
	printf("\ngetting target state\n");
	robot_state::RobotState target_state(*group.getCurrentState());
	copyToRobotState(target_state, ompl_interface.getConstraintsLibrary().getConstraintApproximation(cmsg)->getStateStorage()->getState(target_state.getRandomNumberGenerator().uniformInteger(0, max_index_)));
	const Eigen::Affine3d &end_effector = target_state.getGlobalLinkTransform("wrist_roll_link");

	geometry_msgs::Pose target_pose;
	Eigen::Quaterniond rot_qua(end_effector.rotation());
	target_pose.orientation.w = rot_qua.w();
	target_pose.orientation.x = rot_qua.x();
	target_pose.orientation.y = rot_qua.y();
	target_pose.orientation.z = rot_qua.z();
	Eigen::Vector3d end_pos = end_effector.translation();
	target_pose.position.x = end_pos.x();
	target_pose.position.y = end_pos.y();
	target_pose.position.z = end_pos.z();

	group.setPoseTarget(target_pose);*/

	ros::shutdown();
	return 0;
}