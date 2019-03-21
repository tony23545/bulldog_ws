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

geometry_msgs::Pose target_pose1;
int current_count=0;
int listen_times=2;
vector<geometry_msgs::Pose> pose_sample;
bool isReceived = false;
geometry_msgs::Pose pose_ans;
double target_x,target_y,target_z;
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
  for(int i=1;i<count;i++){
    pose_add=add_pose(pose_add,pose1[i]);
  }
  pose_ans.position.x = pose_add.position.x / (count-1);
  pose_ans.position.y = pose_add.position.y / (count-1);
  pose_ans.position.z = pose_add.position.z / (count-1);
  pose_ans.orientation.x = pose_ans.orientation.x / (count-1);
  pose_ans.orientation.y = pose_ans.orientation.y / (count-1);
  pose_ans.orientation.z = pose_ans.orientation.z / (count-1);
  pose_ans.orientation.w = pose_ans.orientation.w / (count-1);

  return pose_ans;
}

void CallBack(const object_recognition_msgs::RecognizedObjectArray::ConstPtr& msg){
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
      geometry_msgs::Pose target_pose1;
      target_pose1.position.x = transform2.getOrigin().getX();
      target_pose1.position.y = transform2.getOrigin().getY();
      target_pose1.position.z = transform2.getOrigin().getZ();
      target_pose1.orientation.x = transform2.getRotation().getX();
      target_pose1.orientation.y = transform2.getRotation().getY();
      target_pose1.orientation.z = transform2.getRotation().getZ();
      target_pose1.orientation.w = transform2.getRotation().getW();


     printf("sample %d:\npose:\nx:%f\ty:%f\tz:%f\n",current_count, target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
     printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose1.orientation.x,target_pose1.orientation.y,target_pose1.orientation.z,target_pose1.orientation.w);

      pose_sample.push_back(target_pose1);

      }
      else{
	
        //printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
        //printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose1.orientation.x,target_pose1.orientation.y,target_pose1.orientation.z,target_pose1.orientation.w); 
        pose_ans = average_pose(pose_sample , listen_times);
        //pose_sample.clear();
        printf("average:\npose:\nx:%f\ty:%f\tz:%f\n", pose_ans.position.x,pose_ans.position.y,pose_ans.position.z);
        printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",pose_ans.orientation.x,pose_ans.orientation.y,pose_ans.orientation.z,pose_ans.orientation.w);
        //ROS_INFO("STOP!!!");
	isReceived = true;
        }
      }
}
bool detect(double &x,double &y,double &z,ros::NodeHandle nh,ros::Publisher start_ork_pub,ros::Publisher stop_ork_signal_pub){
    ros::Subscriber sub=nh.subscribe("recognized_object_array", 1000, CallBack);
    std_msgs::String msg;
    std::stringstream ss;
    geometry_msgs::Pose pose_average;
    std::vector<moveit_msgs::CollisionObject> collision_objects;
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

    ss<<"Start object recognition";
    msg.data=ss.str();
    start_ork_pub.publish(msg);
    while(!isReceived);
    if(isReceived){
    pose_average = pose_ans;
    x=pose_average.position.x;
    y=pose_average.position.y;
    z=pose_average.position.z;
    //target_pose2 = pose_ans;
    ss.str("");
    ss.clear();
    ss << "Pause object recognition";
    msg.data = ss.str();
    stop_ork_signal_pub.publish(msg);
    ROS_INFO("Pause object recognition");
    
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
      pose.position.x = pose_average.position.x;
      pose.position.y = pose_average.position.y;
      pose.position.z = pose_average.position.z+0.08;

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
      sleep(2.0);
      //group.setPlanningTime(1.0);


      // Now when we plan a trajectory it will avoid the obstacle
      //group.setStartState(*group.getCurrentState());
      isReceived = false;
      return true;
    }else
      return false; 
}

void pub_gripper(ros::Publisher *pub, std::string str){

  std_msgs::String msg;
  std::stringstream ss;
    ss << str;
    msg.data = ss.str();
    pub->publish(msg);
  ROS_INFO("gripper signal has been published!");
}
int main(int argc, char **argv)
{
  ros::init(argc, argv, "pick_node");
  ros::NodeHandle node_handle,nh;  
  ros::AsyncSpinner spinner(1);
  spinner.start();


  /* This sleep is ONLY to allow Rviz to come up */
  sleep(2.0);
  
  // BEGIN_TUTORIAL
  // 
  // Setup
  // ^^^^^
  // 
  // The :move_group_interface:`MoveGroup` class can be easily 
  // setup using just the name
  // of the group you would like to control and plan for.
  
  ros::Publisher stop_ork_signal_pub = nh.advertise<std_msgs::String>("stop_ork_signal",1000);
  ros::Publisher start_ork_pub = nh.advertise<std_msgs::String>("start_ork_signal",1000);
  ros::Publisher left_gripper_signal_pub = nh.advertise<std_msgs::String>("left_gripper_signal", 10);
  ros::Publisher right_gripper_signal_pub = nh.advertise<std_msgs::String>("right_gripper_signal", 10);
  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // Planning to a Pose goal
  // ^^^^^^^^^^^^^^^^^^^^^^^
  // We can plan a motion for this group to a desired pose for the 
  // end-effector.
  std::string gripper_command="a";

  pub_gripper(&left_gripper_signal_pub,gripper_command);
    
  sleep(3.0);

  //pub_gripper(&right_gripper_signal_pub,gripper_command);
    
  sleep(3.0);
  
  
  /*printf("please input target position:\n");
  printf("x:\n");
  scanf("%lf",&target_x);
  printf("y:\n");
  scanf("%lf",&target_y);
  printf("z:\n");
  scanf("%lf",&target_z);*/  
  detect(target_x,target_y,target_z,nh,start_ork_pub,stop_ork_signal_pub);
  printf("target pose:\nx:%f\ty:%f\tz:%f\n",target_x,target_y,target_z);



  


  moveit::planning_interface::MoveGroup group("left_arm");
  sleep(1.0);

  // We will use the :planning_scene_interface:`PlanningSceneInterface`
  // class to deal directly with the world.
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
  geometry_msgs::Pose target_pose2;
  
  moveit::planning_interface::MoveGroup::Plan my_plan;  

  // (Optional) Create a publisher for visualizing plans in Rviz.
  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;

  group.setPlannerId("RRTstarkConfigDefault");

  target_pose2.position.x=target_x;
  target_pose2.position.y=target_y+0.2;
  target_pose2.position.z=target_z+0.05;
  target_pose2.orientation.x=0.991776;
  target_pose2.orientation.y=-0.011776;
  target_pose2.orientation.z=0.054329;
  target_pose2.orientation.w=0.115287;
  ROS_INFO("Begin Planning!");

  // Now, we call the planner to compute the plan
   // and visualize it.
 // Note that we are just planning, not asking move_group 
 // to actually move the robot.
  group.setStartState(*group.getCurrentState());
  group.setPoseTarget(target_pose2); 
  bool success = group.plan(my_plan);

  ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
  if(success){
     bool ex = group.execute(my_plan);
      if(!ex) {
      	printf("execute failed!");
      }
  
  }
  sleep(1.0);
  ROS_INFO("Press ENTER to pick.");
  getchar();

  ROS_INFO("Planning finished. Going to pick!");
 // std::vector<geometry_msgs::Pose> waypoints;
 // geometry_msgs::Pose car_start = target_pose2;
 // waypoints.push_back(car_start);

 // car_start.position.y -= 0.1;
 // waypoints.push_back(car_start);

 // moveit_msgs::RobotTrajectory trajectory;
 // double fraction = group.computeCartesianPath(waypoints, 0.01, 0.0, trajectory);

 // my_plan.trajectory_ = trajectory;
 // group.execute(my_plan);
 // sleep(1.0);
  target_pose2.position.y -= 0.1;
  group.setStartState(*group.getCurrentState());
  group.setPoseTarget(target_pose2);
  success = group.plan(my_plan);
  if(success){
     bool ex = group.execute(my_plan);
      if(!ex) {
        printf("execute failed!");
      }
  }
  ROS_INFO("Press ENTER to grasp.");
  getchar();

  gripper_command=75;
  pub_gripper(&left_gripper_signal_pub,gripper_command); 
  sleep(2.0);

  ROS_INFO("Press ENTER to continue.");
  getchar();


 /* target_pose2.position.z += 0.1;
  group.setStartState(*group.getCurrentState());
  group.setPoseTarget(target_pose2);
  success = group.plan(my_plan);
  if(success){
     bool ex = group.execute(my_plan);
      if(!ex) {
        printf("execute failed!");
      }
  }*/

//  sleep(3.0);


  //moveit::planning_interface::MoveGroup group("left_arm");
  geometry_msgs::Pose target_pose_temp;
  target_pose_temp.position.x=0.864536;
  target_pose_temp.position.y=0.367802;
  target_pose_temp.position.z=0.945851;
  target_pose_temp.orientation.x=0.251804;
  target_pose_temp.orientation.y=0.697385;
  target_pose_temp.orientation.z=0.593748;
  target_pose_temp.orientation.w=-0.312589;
  group.setStartState(*group.getCurrentState());
  group.setPoseTarget(target_pose_temp);
		
  


	//group.setRandomTarget();
	ROS_INFO("Start picking!");
  //group.setPoseTarget(target_pose_temp);
  bool pick_success = group.plan(my_plan);
 
  if(pick_success){ 
	bool pick_exc=group.execute(my_plan);
	if(!pick_exc)
	{
		ROS_INFO("Pick failed!");
	}
  }
  sleep(1.0);
  
   gripper_command="o";
   pub_gripper(&left_gripper_signal_pub,gripper_command);

  ROS_INFO("Press ENTER to continue.");
  getchar();


   //moveit::planning_interface::MoveGroup group("left_arm");
   std::vector<double> group_variable_values;
   group_variable_values.clear();
   group.setStartState(*group.getCurrentState());
   group_variable_values.push_back(0.1412);
   group_variable_values.push_back(-3.1415);
   group_variable_values.push_back(2.8238);
   group_variable_values.push_back(-2.8238);
   group_variable_values.push_back(-1.612);
   group_variable_values.push_back(-1.5708);
   group.setJointValueTarget(group_variable_values);
		
   bool reset_success = group.plan(my_plan);
   //ROS_INFO("Visualizing plan 1 (pose goal) %s",hui_success?"SUCCEED":"FAILED");
   if(reset_success){ 
	bool hui_exc=group.execute(my_plan);
	if(!hui_exc)
	{
		ROS_INFO("Reset failed!");
	}
   }

  
  ros::shutdown();  
  return 0;
}


