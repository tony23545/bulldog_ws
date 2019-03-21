/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2013, SRI International
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of SRI International nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Sachin Chitta */

#include <moveit/move_group_interface/move_group.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

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
#include <vector>

#define middle_state_count 1
#define LEFT_ARM  true
#define RIGHT_ARM false 

using namespace std;

const double pi=3.141592653;
const double pose_x=0;
const double pose_y=0;
const double pose_z=0;
const double orientation_x=0;
const double orientation_y=0;
const double orientation_z=0;
const double orientation_w=0;
int current_count =0;
int listen_times=2;
geometry_msgs::Pose target_pose1;
bool isReceived = false;
geometry_msgs::Pose pose_average;
vector<geometry_msgs::Pose> pose_sample;
bool enable_arm = true;//true---left   false----right
void decide_target_pose(geometry_msgs::Pose *target_pose,double pose_x,double pose_y,double pose_z,double orientation_x,double orientation_y,double orientation_z,double orientation_w);
geometry_msgs::Pose  add_pose(geometry_msgs::Pose pose1,geometry_msgs::Pose pose2);
void power()  
{  
        FILE * fp;  
        char buf[40] = {"python netcatbotharm.py"};  
        fp = popen("bash", "w");  
        if(NULL == fp)  
        {  
                perror("popen error.\n");   
        }   
 
        fputs(buf, fp);  
        pclose(fp);    
}
void pose_init_zero(geometry_msgs::Pose *pose){

	pose->position.x = 0;
	pose->position.y = 0;
	pose->position.z = 0;

	pose->orientation.x = 0;
	pose->orientation.y = 0;
	pose->orientation.z = 0;
	pose->orientation.w = 0;

}

geometry_msgs::Pose add_pose(geometry_msgs::Pose pose1,geometry_msgs::Pose pose2){

	geometry_msgs::Pose pose_add;
	pose_add.position.x = pose1.position.x + pose2.position.x;
	pose_add.position.y = pose1.position.y + pose2.position.y;
	pose_add.position.z = pose1.position.z + pose2.position.z;
	pose_add.orientation.x = pose1.orientation.x + pose2.orientation.x;
	pose_add.orientation.y = pose1.orientation.y + pose2.orientation.y;
	pose_add.orientation.z = pose1.orientation.z + pose2.orientation.z;
	pose_add.orientation.w = pose1.orientation.w + pose2.orientation.w;

	return pose_add;
}

geometry_msgs::Pose average_pose(vector<geometry_msgs::Pose> pose1, int count){

	geometry_msgs::Pose pose_add,pose_ans;
	for(int i=0;i<count;i++){
		pose_add=add_pose(pose_add,pose1[i]);
	}
	pose_ans.position.x = pose_add.position.x / count;
	pose_ans.position.y = pose_add.position.y / count;
	pose_ans.position.z = pose_add.position.z / count;
	pose_ans.orientation.x = pose_ans.orientation.x / count;
	pose_ans.orientation.y = pose_ans.orientation.y / count;
	pose_ans.orientation.z = pose_ans.orientation.z / count;
	pose_ans.orientation.w = pose_ans.orientation.w / count;

	return pose_ans;
}

void middleStateDecision(geometry_msgs::Pose pose_terminal, geometry_msgs::Pose *pose_middle){
	// decide_target_pose(pose_middle,0.9*pose_terminal.position.x,pose_terminal.position.y-0.3,1.2*pose_terminal.position.z,pose_terminal.orientation.x,pose_terminal.
	// 	orientation.y,pose_terminal.orientation.z,pose_terminal.orientation.w);
	decide_target_pose(pose_middle,pose_terminal.position.x-0.2,pose_terminal.position.y,2*pose_terminal.position.z,0,0,-sqrt(2)/2,sqrt(2)/2);
}

void CallBack(const object_recognition_msgs::RecognizedObjectArray::ConstPtr& msg)
{
	  if(&(msg->objects[0])!=NULL) {
      current_count++;

      if(current_count<=listen_times){
      //ROS_INFO("I hear the pose!");

      geometry_msgs::Pose pose_init=msg->objects[0].pose.pose.pose;
      //printf("%f\n",msg->objects[0].pose.pose.pose.position.x);
      tf::StampedTransform transform;
      tf::TransformListener listener;
      try {
            listener.waitForTransform("/kinect2_rgb_optical_frame", "/base_link", ros::Time(0), ros::Duration(10.0));
            listener.lookupTransform("/kinect2_rgb_optical_frame", "/base_link", ros::Time(0), transform);
        } catch (tf::TransformException ex) {
            ROS_ERROR("%s",ex.what());
        }
      
      tf::Transform transform1 = transform.inverse(), transform2(tf::Quaternion(pose_init.orientation.x, pose_init.orientation.y, pose_init.orientation.z, pose_init.orientation.w), tf::Vector3(pose_init.position.x, pose_init.position.y, pose_init.position.z));
      transform2 = transform1 * transform2;
      /*target_pose1.position=pose_init.position;
      target_pose1.orientation=pose_init.orientation;*/
      
      target_pose1.position.x = transform2.getOrigin().getX();
      target_pose1.position.y = transform2.getOrigin().getY();
      target_pose1.position.z = transform2.getOrigin().getZ();
      target_pose1.orientation.x = transform2.getRotation().getX();
      target_pose1.orientation.y = transform2.getRotation().getY();
      target_pose1.orientation.z = transform2.getRotation().getZ();
      target_pose1.orientation.w = transform2.getRotation().getW();


      //printf("sample %d:\npose:\nx:%f\ty:%f\tz:%f\n",current_count, target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
      //printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose1.orientation.x,target_pose1.orientation.y,target_pose1.orientation.z,target_pose1.orientation.w);

      pose_sample.push_back(target_pose1);

      }
      else{
        //printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
        //printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose1.orientation.x,target_pose1.orientation.y,target_pose1.orientation.z,target_pose1.orientation.w);
        isReceived = true; 
        pose_average = average_pose(pose_sample , listen_times);
        //printf("average:\npose:\nx:%f\ty:%f\tz:%f\n", pose_average.position.x,pose_average.position.y,pose_average.position.z);
     	//printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",pose_average.orientation.x,pose_average.orientation.y,pose_average.orientation.z,pose_average.orientation.w);
        //ROS_INFO("STOP!!!");
        }
      }
 }     
bool ourplan(moveit::planning_interface::MoveGroup *group,geometry_msgs::Pose target_pose2,moveit::planning_interface::MoveGroup::Plan *my_plan){
      //target_pose2=target_pose1;
      printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose2.position.x,target_pose2.position.y,target_pose2.position.z);
      printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose2.orientation.x,target_pose2.orientation.y,target_pose2.orientation.z,target_pose2.orientation.w);
      group->setPoseTarget(target_pose2);
      ROS_INFO("Begin Planning!");
	
      // Now, we call the planner to compute the plan
       // and visualize it.
     // Note that we are just planning, not asking move_group 
     // to actually move the robot.
      bool success = group->plan(*my_plan);

      ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED");
      sleep(5.0);
      return success;

   	
}

void decide_target_pose(geometry_msgs::Pose *target_pose,double pose_x,double pose_y,double pose_z,double orientation_x,double orientation_y,double orientation_z,double orientation_w){


	target_pose->position.x = pose_x;
	target_pose->position.y = pose_y;
	target_pose->position.z = pose_z;
	target_pose->orientation.x = orientation_x;
	target_pose->orientation.y = orientation_y;
	target_pose->orientation.z = orientation_z;
	target_pose->orientation.w = orientation_w;

}
void pub_gripper(ros::Publisher *pub, std::string str){

	std_msgs::String msg;
	std::stringstream ss;
    ss << str;
    msg.data = ss.str();
    pub->publish(msg);
	ROS_INFO("gripper signal has been published!");
}
void decide_orientation(geometry_msgs::Pose *target_pose2,geometry_msgs::Pose pose_average){
  moveit::planning_interface::MoveGroup group("left_arm");
  moveit::planning_interface::MoveGroup::Plan my_plan;
  *target_pose2 = pose_average;
  target_pose2->position.x=pose_average.position.x;
  target_pose2->position.z=pose_average.position.z+0.02;
  target_pose2->position.y=pose_average.position.y+0.2;
  target_pose2->orientation.x=0.991776;
  target_pose2->orientation.y=-0.011776;
  target_pose2->orientation.z=0.054329;
  target_pose2->orientation.w=0.115287;
  //leftwards:(x:0.991776	y:-0.011776	z:0.054329	w:0.115287)  downwards:(0,-sqrt(2)/2,sqrt(2)/2,0) rightwards:(0,0,0,0)
  //decide_target_pose(&target_pose2,1.002963-0.03,-0.0816710-0.03,0.391100,0,0,1,0);

  // target_pose2 = target_pose1;
  printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose2->position.x,target_pose2->position.y,target_pose2->position.z);
  printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose2->orientation.x,target_pose2->orientation.y,target_pose2->orientation.z,target_pose2->orientation.w);
  group.setPoseTarget(*target_pose2);
  ROS_INFO("Begin Planning!");

  // Now, we call the planner to compute the plan
   // and visualize it.
 // Note that we are just planning, not asking move_group 
 // to actually move the robot.
  
  bool success = group.plan(my_plan);

  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
  if(success){
     // while(ros::ok()){
     //    printf("Plan again or just grasp?(p/g)");
     //    scanf("%s",&porg);
     //    if(porg=='g')
     //      break; 
     //    else ourplan(&group,target_pose2,&my_plan);             
     // }
     //printf("Can we start grasping?(y/n)");
     //scanf("%s",&isGrasp);
     //if(isGrasp=='y') 
  	  enable_arm = LEFT_ARM;
      bool ex = group.execute(my_plan);
      if(!ex) {
      	power();
      }
  }else{
  	moveit::planning_interface::MoveGroup group("right_arm");
  	target_pose2->position.x=pose_average.position.x;
  	target_pose2->position.z=pose_average.position.z+0.02;
  	target_pose2->position.y=pose_average.position.y+0.2;
  	target_pose2->orientation.x=0;
  	target_pose2->orientation.y=0;
  	target_pose2->orientation.z=0;
  	target_pose2->orientation.w=0;
  	group.setPoseTarget(*target_pose2);
 	ROS_INFO("Begin Planning!");
 	bool success = group.plan(my_plan);

 	ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
  	if(success){
     // while(ros::ok()){
     //    printf("Plan again or just grasp?(p/g)");
     //    scanf("%s",&porg);
     //    if(porg=='g')
     //      break; 
     //    else ourplan(&group,target_pose2,&my_plan); 
    	// } 
    	enable_arm = RIGHT_ARM;
    	bool ex=group.execute(my_plan);
    	if(!ex) {
      		power();
      	}           
     }else{
     	moveit::planning_interface::MoveGroup group("left_arm");
     	*target_pose2 = pose_average;
  		target_pose2->position.x=pose_average.position.x;
  		target_pose2->position.z=pose_average.position.z+0.25;
  		target_pose2->position.y=pose_average.position.y;
  		target_pose2->orientation.x=0;
  		target_pose2->orientation.y=-sqrt(2)/2;
  		target_pose2->orientation.z=sqrt(2)/2;
  		target_pose2->orientation.w=0;
  		group.setPoseTarget(*target_pose2);
  		bool success = group.plan(my_plan);
  		ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
  		if(success){
     		// while(ros::ok()){
       //  		printf("Plan again or just grasp?(p/g)");
       //  		scanf("%s",&porg);
       //  		if(porg=='g')
       //   		 break; 
       //  		else ourplan(&group,target_pose2,&my_plan);
       //  	}
  			enable_arm = LEFT_ARM;
        	bool ex=group.execute(my_plan);
    		if(!ex) {
      			power();
      		}
        }else{
        	moveit::planning_interface::MoveGroup group("right_arm");
        	*target_pose2 = pose_average;
  			target_pose2->position.x=pose_average.position.x;
  			target_pose2->position.z=pose_average.position.z+0.25;
  			target_pose2->position.y=pose_average.position.y;
  			target_pose2->orientation.x=0;
  			target_pose2->orientation.y=-sqrt(2)/2;
  			target_pose2->orientation.z=sqrt(2)/2;
  			target_pose2->orientation.w=0;
  			group.setPoseTarget(*target_pose2);
  			bool success = group.plan(my_plan);
  			ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
  			if(success){
     			// while(ros::ok()){
        // 			printf("Plan again or just grasp?(p/g)");
        // 			scanf("%s",&porg);
        // 			if(porg=='g')
        //  			 break; 
        // 			else ourplan(&group,target_pose2,&my_plan);
        // 		}
  				enable_arm = RIGHT_ARM;
        		bool ex=group.execute(my_plan);
    		if(!ex) {
      			power();
      			}
        	}
        }
     }
    } 
}
int main(int argc, char **argv)
{
  double pose[7]={0};
  char isBegin='a';
  char isGrasp='b';
  char porg='c';
  char lorr='d';
  char haveGrasp = 'e';
  std::string arm_name="";
  std::string gripper_command="a";
  ros::init(argc, argv, "test_custom_node");
  ros::NodeHandle node_handle,nh;  
  ros::AsyncSpinner spinner(1);
  spinner.start();
  ros::Subscriber sub=nh.subscribe("recognized_object_array", 1000, CallBack);
  ros::NodeHandle nh1;
  ros::Publisher stop_ork_signal_pub = nh1.advertise<std_msgs::String>("stop_ork_signal", 1000);
  ros::Publisher left_gripper_signal_pub = node_handle.advertise<std_msgs::String>("left_gripper_signal", 1000);
  ros::Publisher right_gripper_signal_pub = node_handle.advertise<std_msgs::String>("right_gripper_signal", 1000);
  pose_init_zero(&pose_average);
  power();
  /* This sleep is ONLY to allow Rviz to come up */
  sleep(2.0);
  // BEGIN_TUTORIAL
  // Setup
  // ^^^^^
  // 
  // The :move_group_interface:`MoveGroup` class can be easily 
  // setup using just the name
  // of the group you would like to control and plan for.
  // printf("Do you want to operate left or right arm?(l/r)");
  // scanf("%c",&lorr);
  // if(lorr=='l') arm_name="left_arm";
  // if(lorr=='r') arm_name="right_arm";
  moveit::planning_interface::MoveGroup group("left_arm");
  

  // We will use the :planning_scene_interface:`PlanningSceneInterface
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

  // (Optional) Create a publisher for visualizing plans in Rviz.
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);

  moveit_msgs::DisplayTrajectory display_trajectory;
  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // We can print the name of the reference frame for this robot.
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());

  moveit::planning_interface::MoveGroup::Plan my_plan;
  
  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.

  // We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  //left_arm 0 0 1 0 right_arm 0 0 0 1
  geometry_msgs::Pose target_pose2,target_pose_temp;
  std::vector<moveit_msgs::CollisionObject> collision_objects;
  while(!isReceived);
  while(ros::ok()){
  	  if (!isReceived) break;
  	  if(isReceived){
  	  	std_msgs::String msg;
        std::stringstream ss;
        ss << "Pause object recognition";
        msg.data = ss.str();
        stop_ork_signal_pub.publish(msg);
        ROS_INFO("Pause object recognition");
        pub_gripper(&left_gripper_signal_pub,gripper_command);
        sleep(3.0);
        pub_gripper(&right_gripper_signal_pub,gripper_command);
        sleep(3.0);
        // gripper_command="p";
        // pub_gripper(&left_gripper_signal_pub,gripper_command);
        // sleep(3.0);
        // pub_gripper(&right_gripper_signal_pub,gripper_command);
  //       std_msgs::String msg2;
  //   	msg2.data = "a";
  //   	//printf("%s\n", ss.str());
  //   	gripper_signal_pub.publish(msg2);
		// ROS_INFO("gripper signal has been published!");
        ros::spinOnce();
 		sleep(1.0);

	    moveit_msgs::CollisionObject cylinder,box1,box2;

	    cylinder.id = "cylinder";

	    shape_msgs::SolidPrimitive primitive;
	    primitive.type = primitive.CYLINDER;
	    primitive.dimensions.resize(3);
	    primitive.dimensions[0] = 0.135;
	    primitive.dimensions[1] = 0.025;
	//    primitive.dimensions[2] = 0.2;

	    geometry_msgs::Pose pose;
	    pose.orientation.w = 1.0;
	    pose.position.x =  pose_average.position.x;
	    pose.position.y = pose_average.position.y;
	    pose.position.z =  pose_average.position.z+0.08;

	    cylinder.primitives.push_back(primitive);
	    cylinder.primitive_poses.push_back(pose);
	    cylinder.operation = cylinder.ADD;

	 
  		

		  /* The id of the object is used to identify it. */
		  box1.id = "box1";

		  /* Define a box to add to the world. */
		  shape_msgs::SolidPrimitive primitive2;
		  primitive2.type = primitive.BOX;
		  primitive2.dimensions.resize(3);
		  primitive2.dimensions[0] = 10.2;
		  primitive2.dimensions[1] = 10.2;
		  primitive2.dimensions[2] = 0.01;

		  /* A pose for the box (specified relative to frame_id) */
		  geometry_msgs::Pose box1_pose;
		  box1_pose.orientation.w = 1.0;
		  box1_pose.position.x =  0;
		  box1_pose.position.y =  0;
		  box1_pose.position.z =  -0.16;

		  box1.primitives.push_back(primitive2);
		  box1.primitive_poses.push_back(box1_pose);
		  box1.operation = box1.ADD;


		  box2.id = "box2";

		  /* Define a box to add to the world. */
		  shape_msgs::SolidPrimitive primitive3;
		  primitive3.type = primitive.BOX;
		  primitive3.dimensions.resize(3);
		  primitive3.dimensions[0] = 0.225;
		  primitive3.dimensions[1] = 0.55;
		  primitive3.dimensions[2] = 0.33;

		  /* A pose for the box (specified relative to frame_id) */
		  geometry_msgs::Pose box2_pose;
		  box2_pose.orientation.w = 1.0;
		  box2_pose.position.x =  0.88;
		  box2_pose.position.y =  0.1;
		  box2_pose.position.z =  0.13;

		  box2.primitives.push_back(primitive3);
		  box2.primitive_poses.push_back(box2_pose);
		  box2.operation = box2.ADD;

	    
	    collision_objects.push_back(cylinder);
	    collision_objects.push_back(box1);
	    collision_objects.push_back(box2);
	    // Once all of the objects (in this case just one) have been added to the
	    // vector, we tell the planning scene to add our new box
	    planning_scene_interface.addCollisionObjects(collision_objects);
	    ROS_INFO("Add collision objects into the world");
	    sleep(5.0);
	    group.setPlanningTime(2.0);


  		// Now when we plan a trajectory it will avoid the obstacle
  		group.setStartState(*group.getCurrentState());
  	  } 
      // printf("Can we start planning?(y/n)");
      // scanf("%s",&isBegin);
      if(true){
      // printf("First step:");
      // middleStateDecision(pose_average,&target_pose_temp);
      // //decide_target_pose(&target_pose_temp,0.7,-0.1,0.5,0,0,1,0);
      // // target_pose_temp.orientation.x = -0.044989;
      // // target_pose_temp.orientation.y = 0.078979;
      // // target_pose_temp.orientation.z = -0.288613;
      // // target_pose_temp.orientation.w = 0.953122;
      // bool temp_success=ourplan(&group,target_pose_temp,&my_plan);
      // if(temp_success){
      //    /*while(ros::ok()){
      //       printf("Plan again or just grasp?(p/g)");
      //       scanf("%s",&porg);
      //       if(porg=='g')
      //         break; 
      //       else temp_success= ourplan(&group,target_pose_temp,&my_plan);             
      //    }
      //    printf("Can we start grasping?(y/n)");
      //    scanf("%s",&isGrasp);
      //    if(isGrasp=='y')*/
      //    group.execute(my_plan);
      // }
      // else{
         
      // }
      target_pose2 = pose_average;
      
      
      target_pose2.position.x=pose_average.position.x;
target_pose2.position.z=pose_average.position.z+0.25;
	target_pose2.position.y=pose_average.position.y;
	target_pose2.orientation.x=0;
	target_pose2.orientation.y=-sqrt(2)/2;
	target_pose2.orientation.z=sqrt(2)/2;
	target_pose2.orientation.w=0;
      //leftwards:(x:0.991776	y:-0.011776	z:0.054329	w:0.115287)  downwards:(0,-sqrt(2)/2,sqrt(2)/2,0) rightwards:(0,0,0,0)
      //decide_target_pose(&target_pose2,1.002963-0.03,-0.0816710-0.03,0.391100,0,0,1,0);

      // target_pose2 = target_pose1;
      printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose2.position.x,target_pose2.position.y,target_pose2.position.z);
      printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose2.orientation.x,target_pose2.orientation.y,target_pose2.orientation.z,target_pose2.orientation.w);
      group.setPoseTarget(target_pose2);
      ROS_INFO("Begin Planning!");
	
      // Now, we call the planner to compute the plan
       // and visualize it.
     // Note that we are just planning, not asking move_group 
     // to actually move the robot.
      
      bool success = group.plan(my_plan);

      ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
      if(success){
         // while(ros::ok()){
         //    printf("Plan again or just grasp?(p/g)");
         //    scanf("%s",&porg);
         //    if(porg=='g')
         //      break; 
         //    else ourplan(&group,target_pose2,&my_plan);             
         // }
         //printf("Can we start grasping?(y/n)");
         //scanf("%s",&isGrasp);
         //if(isGrasp=='y') 
      	  enable_arm = LEFT_ARM;
          bool ex = group.execute(my_plan);
          if(!ex) {
          	power();
          	continue;
          }
      }else{
      	moveit::planning_interface::MoveGroup group("right_arm");
      	target_pose2.position.x=pose_average.position.x;
		target_pose2.position.z=pose_average.position.z+0.25;
		target_pose2.position.y=pose_average.position.y;
		target_pose2.orientation.x=0;
		target_pose2.orientation.y=-sqrt(2)/2;
		target_pose2.orientation.z=sqrt(2)/2;
		target_pose2.orientation.w=0;
      	group.setPoseTarget(target_pose2);
     	ROS_INFO("Begin Planning!");
     	bool success = group.plan(my_plan);

     	ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
      	if(success){
         // while(ros::ok()){
         //    printf("Plan again or just grasp?(p/g)");
         //    scanf("%s",&porg);
         //    if(porg=='g')
         //      break; 
         //    else ourplan(&group,target_pose2,&my_plan); 
        	// } 
        	enable_arm = RIGHT_ARM;
        	bool ex=group.execute(my_plan);
        	if(!ex) {
          		power();
          		continue;
          	}           
         }else{
         	moveit::planning_interface::MoveGroup group("left_arm");
         	target_pose2 = pose_average;
      		target_pose2.position.x=pose_average.position.x;
	      target_pose2.position.z=pose_average.position.z+0.02;
	      target_pose2.position.y=pose_average.position.y+0.2;
	      target_pose2.orientation.x=0.991776;
	      target_pose2.orientation.y=-0.011776;
	      target_pose2.orientation.z=0.054329;
	      target_pose2.orientation.w=0.115287;
      		group.setPoseTarget(target_pose2);
      		bool success = group.plan(my_plan);
      		ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
      		if(success){
         		// while(ros::ok()){
           //  		printf("Plan again or just grasp?(p/g)");
           //  		scanf("%s",&porg);
           //  		if(porg=='g')
           //   		 break; 
           //  		else ourplan(&group,target_pose2,&my_plan);
           //  	}
      			enable_arm = LEFT_ARM;
            	bool ex=group.execute(my_plan);
        		if(!ex) {
          			power();
          			continue;
          		}
            }else{
            	moveit::planning_interface::MoveGroup group("right_arm");
            	target_pose2 = pose_average;
      			
			target_pose2.position.x=pose_average.position.x;
		      	target_pose2.position.z=pose_average.position.z+0.02;
		      	target_pose2.position.y=pose_average.position.y+0.2;
		      	target_pose2.orientation.x=0;
		      	target_pose2.orientation.y=0;
		      	target_pose2.orientation.z=0;
		      	target_pose2.orientation.w=0;
      			group.setPoseTarget(target_pose2);
      			bool success = group.plan(my_plan);
      			ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
      			if(success){
         			// while(ros::ok()){
            // 			printf("Plan again or just grasp?(p/g)");
            // 			scanf("%s",&porg);
            // 			if(porg=='g')
            //  			 break; 
            // 			else ourplan(&group,target_pose2,&my_plan);
            // 		}
      				enable_arm = RIGHT_ARM;
            		bool ex=group.execute(my_plan);
        		if(!ex) {
          			power();
          			continue;
          			}
            	}
            }
         }
      }
      
      /* Sleep to give Rviz time to visualize the plan. */
      sleep(2.0);
      target_pose_temp = target_pose2;
      gripper_command=75;
      if(enable_arm==LEFT_ARM)  {
      	pub_gripper(&left_gripper_signal_pub,gripper_command);
      	arm_name = "left_arm";
      }
  	  else  {
  	  	pub_gripper(&right_gripper_signal_pub,gripper_command);
  	  	arm_name = "right_arm";
  	  }
      ros::spinOnce();
      sleep(2.0);
      moveit::planning_interface::MoveGroup group(arm_name);
      group.setPlanningTime(5.0);
      // printf("Have we grasped the object?(y/n)");
      // scanf("%s",&haveGrasp);
      if(true){
      	std::vector<std::string> object_ids;
    	object_ids.push_back("cylinder");
    	planning_scene_interface.removeCollisionObjects(object_ids);
    	group.setStartState(*group.getCurrentState());
    	power();
        sleep(1.0);
  //       target_pose_temp.position.x=0.90;
  //       target_pose_temp.position.y=0.5;
  //       target_pose_temp.position.z=0.7;
  //       target_pose_temp.orientation.x=0;
		// target_pose_temp.orientation.y=0;
		// target_pose_temp.orientation.z=0;
		// target_pose_temp.orientation.w=0;
		// //group.setRandomTarget();
		// ROS_INFO("Start picking!");
  //     	group.setPoseTarget(target_pose_temp);
  //     	bool pick_success1 = group.plan(my_plan);
  //     	if(pick_success1){ 
  //     		bool pick_exc1=group.execute(my_plan);
  //     		if(!pick_exc1)
  //     		{
  //     			power();
  //     			group.setStartState(*group.getCurrentState());
  //     			group.setPoseTarget(target_pose_temp);
  //     			group.plan(my_plan);
  //     			group.execute(my_plan);
  //     		}
  //     	}
        if(enable_arm==LEFT_ARM){
		target_pose_temp.position.x=0.864536;
		target_pose_temp.position.y=0.367802;
		target_pose_temp.position.z=0.945851;
		target_pose_temp.orientation.x=0.251804;
		target_pose_temp.orientation.y=0.697385;
		target_pose_temp.orientation.z=0.593748;
		target_pose_temp.orientation.w=-0.312589;
        }else{
        	target_pose_temp.position.x=0.567017;
		target_pose_temp.position.y=-0.435451;
		target_pose_temp.position.z=1.055147;
		target_pose_temp.orientation.x=0.098212;
		target_pose_temp.orientation.y=-0.127870;
		target_pose_temp.orientation.z=-0.730341;
		target_pose_temp.orientation.w=0.663781;
        }
		//group.setRandomTarget();
		ROS_INFO("Start picking!");
      	group.setPoseTarget(target_pose_temp);
      	bool pick_success = group.plan(my_plan);
      	if(pick_success){ 
      		bool pick_exc=group.execute(my_plan);
      		if(!pick_exc)
      		{
      			power();
      			group.setStartState(*group.getCurrentState());
      			group.setPoseTarget(target_pose_temp);
      			group.plan(my_plan);
      			group.execute(my_plan);
      		}
      	}
      	sleep(5.0);
      	gripper_command="o";
      	if(enable_arm==LEFT_ARM)  pub_gripper(&left_gripper_signal_pub,gripper_command);
  	  	else  pub_gripper(&right_gripper_signal_pub,gripper_command);
      	ros::spinOnce();
      	sleep(5.0);
	ROS_INFO("Start receting!");
	power();
	if(enable_arm==LEFT_ARM){
		target_pose_temp.position.x=0.152698;
		target_pose_temp.position.y=0.452910;
		target_pose_temp.position.z=0.544295;
		target_pose_temp.orientation.x=0.452260;
		target_pose_temp.orientation.y=0.522986;
		target_pose_temp.orientation.z=-0.510330;
		target_pose_temp.orientation.w=0.511381;
	}else{
                target_pose_temp.position.x=0.117831;
	        target_pose_temp.position.y=-0.439276;
		target_pose_temp.position.z=0.572630;
		target_pose_temp.orientation.x=0.480942;
		target_pose_temp.orientation.y=0.581612;
		target_pose_temp.orientation.z=0.532653;
		target_pose_temp.orientation.w=-0.383104;  
        }
	group.setPoseTarget(target_pose_temp);
      	bool hui_success = group.plan(my_plan);
      	if(hui_success){ 
      		bool hui_exc=group.execute(my_plan);
      		if(!hui_exc)
      		{
      			power();
      			group.setStartState(*group.getCurrentState());
      			group.setPoseTarget(target_pose_temp);
      			group.plan(my_plan);
      			group.execute(my_plan);
      		}
      	}
      	// printf("Have we place the object?(y/n)");
       //  scanf("%s",&haveGrasp);
        }
        std::vector<std::string> object_ids;
    	object_ids.push_back("box1");
    	object_ids.push_back("box2");
    	planning_scene_interface.removeCollisionObjects(object_ids);
        isReceived = false;
        ros::shutdown();
      }
      ros::spinOnce();  
  }
  return 0;
}
