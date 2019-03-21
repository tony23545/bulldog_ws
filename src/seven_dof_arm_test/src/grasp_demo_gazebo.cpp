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

#include "grasp_demo.h"

geometry_msgs::Pose Listener::add_pose(geometry_msgs::Pose pose1,geometry_msgs::Pose pose2){

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
geometry_msgs::Pose Listener::average_pose(vector<geometry_msgs::Pose> pose1, int count){

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

void Listener::CallBack(const object_recognition_msgs::RecognizedObjectArray::ConstPtr& msg){
   if(&(msg->objects[0])!=NULL) {
      current_count++;

      if(current_count<=listen_times){
      //ROS_INFO("I hear the pose!");

      geometry_msgs::Pose pose_init=msg->objects[0].pose.pose.pose;
      //printf("%f\n",msg->objects[0].pose.pose.pose.position.x);
      tf::StampedTransform transform;
      tf::TransformListener listener;
      try {
            listener.waitForTransform("/camera_frame_optical", "/base_link", ros::Time(0), ros::Duration(10.0));
            listener.lookupTransform("/camera_frame_optical", "/base_link", ros::Time(0), transform);
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
void pluginListener::plugin_callback(const std_msgs::String::ConstPtr& msg){
     std::string rec = msg->data;
     ROS_INFO("I heard %s!", rec.c_str());
     if(rec=="AUTO") mode = AUTO; 
     if(rec=="DETECT") mode = DETECT; 
     if(rec=="NAVIGATION1")  mode = NAVIGATION1;
     if(rec=="ARRIVEPLAN") mode = ARRIVEPLAN; 
     if(rec=="ARRIVEEXECUTE") mode = ARRIVEEXECUTE;
     if(rec=="PICKPLAN") mode = PICKPLAN; 
     if(rec=="PICKEXECUTE") mode = PICKEXECUTE;
     if(rec=="PLACEPLAN") mode = PLACEPLAN; 
     if(rec=="PLACEEXECUTE") mode = PLACEEXECUTE;
     if(rec=="NAVIGATION2")  mode = NAVIGATION2;
     if(rec=="RESET") mode = RESET;
     if(rec=="POWER") mode = POWER;    
}

void laserListener::CallBack_laserscan(const sensor_msgs::LaserScan &msg){
   if(hit)
      return ;
   ROS_INFO("LASERSCAN_RUN");
   float minrange = 1e10, maxrange = -1e10;
   int i = 0;
   for(float t = msg.angle_min ; t < msg.angle_max ; t += msg.angle_increment)
   {
     if(msg.range_min < msg.ranges[i] && msg.ranges[i] < msg.range_max)
     {
        if(msg.ranges[i] < minrange)
            minrange = msg.ranges[i];
        if(msg.ranges[i] > maxrange)
            maxrange = msg.ranges[i];
     }
     i++;
   }
   ROS_INFO("%d %f", hit?1:0, minrange);
   if(minrange < MIN_TOLERANT_RANGE)
     hit = true;
   else if(!hit)
   {
     move_step = (minrange - MIN_TOLERANT_RANGE) * MOVE_STEP_PROP;
     if(move_step < MIN_MOVE_STEP)
        move_step = MIN_MOVE_STEP;
     geometry_msgs::Twist m;
     m.linear.x = move_step;
     navigation_pub.publish(m);
   }

}
void GraspNode::power()  
{  
            
}
void GraspNode::pose_init_zero(geometry_msgs::Pose *pose){

  pose->position.x = 0;
  pose->position.y = 0;
  pose->position.z = 0;

  pose->orientation.x = 0;
  pose->orientation.y = 0;
  pose->orientation.z = 0;
  pose->orientation.w = 0;

}

geometry_msgs::Pose GraspNode::add_pose(geometry_msgs::Pose pose1,geometry_msgs::Pose pose2){

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

geometry_msgs::Pose GraspNode::average_pose(vector<geometry_msgs::Pose> pose1, int count){

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

void GraspNode::middleStateDecision(geometry_msgs::Pose pose_terminal, geometry_msgs::Pose *pose_middle){
  // decide_target_pose(pose_middle,0.9*pose_terminal.position.x,pose_terminal.position.y-0.3,1.2*pose_terminal.position.z,pose_terminal.orientation.x,pose_terminal.
  //  orientation.y,pose_terminal.orientation.z,pose_terminal.orientation.w);
  decide_target_pose(pose_middle,pose_terminal.position.x-0.2,pose_terminal.position.y,2*pose_terminal.position.z,0,0,-sqrt(2)/2,sqrt(2)/2);
}

void GraspNode::SubCallBack(const object_recognition_msgs::RecognizedObjectArray::ConstPtr& msg)
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
            listener.waitForTransform("/camera_frame_optical", "/base_link", ros::Time(0), ros::Duration(10.0));
            listener.lookupTransform("/camera_frame_optical", "/base_link", ros::Time(0), transform);
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
        printf("average:\npose:\nx:%f\ty:%f\tz:%f\n", pose_average.position.x,pose_average.position.y,pose_average.position.z);
        printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",pose_average.orientation.x,pose_average.orientation.y,pose_average.orientation.z,pose_average.orientation.w);
        ROS_INFO("STOP!!!");
        }
      }
 }     
bool GraspNode::ourplan(moveit::planning_interface::MoveGroup *group,geometry_msgs::Pose target_pose2,moveit::planning_interface::MoveGroup::Plan *my_plan){
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

void GraspNode::decide_target_pose(geometry_msgs::Pose *target_pose,double pose_x,double pose_y,double pose_z,double orientation_x,double orientation_y,double orientation_z,double orientation_w){


  target_pose->position.x = pose_x;
  target_pose->position.y = pose_y;
  target_pose->position.z = pose_z;
  target_pose->orientation.x = orientation_x;
  target_pose->orientation.y = orientation_y;
  target_pose->orientation.z = orientation_z;
  target_pose->orientation.w = orientation_w;

}
void GraspNode::pub_gripper(ros::Publisher *pub, std::string str){

  std_msgs::String msg;
  std::stringstream ss;
    ss << str;
    msg.data = ss.str();
    pub->publish(msg);
  ROS_INFO("gripper signal has been published!");
}
void GraspNode::decide_orientation(geometry_msgs::Pose *target_pose2,geometry_msgs::Pose pose_average){
 
}
void GraspNode::init(){
  isBegin='a';
  isGrasp='b';
  porg='c';
  lorr='d'; 
  haveGrasp = 'e';
  std::string arm_name="";
  std::string gripper_command="a";
  spinner.start();
  
  stop_ork_signal_pub = nh.advertise<std_msgs::String>("stop_ork_signal",1000);
  start_ork_pub = nh.advertise<std_msgs::String>("start_ork_signal",1000);
  left_gripper_signal_pub = nh.advertise<std_msgs::String>("left_gripper_signal", 1000);
  right_gripper_signal_pub = nh.advertise<std_msgs::String>("right_gripper_signal", 1000);
  display_publisher = nh.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 100, true);
  navigation_goal_publisher = nh.advertise <geometry_msgs::PoseStamped>("/move_base_simple/goal", 1, true);
  laserlis.navigation_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 100);

  laser_sub = nh.subscribe("scan", 1000, &laserListener::CallBack_laserscan,&laserlis);

  waypoints.clear();
  pose_init_zero(&pose_average);
  //power();
  /*This sleep is ONLY to allow Rviz to come up */
  sleep(2.0);
  // BEGIN_TUTORIAL
  
  ROS_INFO("Reference frame: %s", group.getPlanningFrame().c_str());
  
  // We can also print the name of the end-effector link for this group.
  ROS_INFO("Reference frame: %s", group.getEndEffectorLink().c_str());
  pub_gripper(&left_gripper_signal_pub,gripper_command);
    
  sleep(3.0);

  pub_gripper(&right_gripper_signal_pub,gripper_command);
    
  sleep(3.0);
  
  ros::spinOnce();
    
}
bool GraspNode::detect(double &x,double &y,double &z){
    Listener lis;
    sub=nh.subscribe("recognized_object_array", 1000, &Listener::CallBack,&lis);
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"Start object recognition";
    msg.data=ss.str();
    start_ork_pub.publish(msg);
    while(!lis.isReceived);
    if(lis.isReceived){
    pose_average = lis.pose_ans;
    x=pose_average.position.x;
    y=pose_average.position.y;
    z=pose_average.position.z;
    target_pose2 = lis.pose_ans;
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
      pose.position.z = pose_average.position.z;

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
      primitive3.dimensions[2] = 0.38;

      /* A pose for the box (specified relative to frame_id) */
      geometry_msgs::Pose box2_pose;
      box2_pose.orientation.w = 1.0;
      box2_pose.position.x =  0.88;
      box2_pose.position.y =  0.2;
      box2_pose.position.z =  0;

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
      group.setPlanningTime(1.0);


      // Now when we plan a trajectory it will avoid the obstacle
      group.setStartState(*group.getCurrentState());
      lis.isReceived = false;
      return true;
    }else
      return false; 
}

bool GraspNode::navigation(){

  /*std::string fixed_frame = "/base_link";
  std::string robot_link = "/base_link", map_link = "/map";
  tf::TransformListener tf_listener;
  sleep(1.5);
  geometry_msgs::Pose pose_init = pose_average;
  pose_init.position.x = pose_average.position.x - 0.8 ; 

  tf::StampedTransform transform;
      tf::TransformListener listener;
      try {
            listener.waitForTransform("/base_link", "/map", ros::Time(0), ros::Duration(10.0));
            listener.lookupTransform("/base_link", "/map", ros::Time(0), transform);
        } catch (tf::TransformException ex) {
            ROS_ERROR("%s",ex.what());
        }
      
      tf::Transform transform1 = transform.inverse(), transform2(tf::Quaternion(pose_init.orientation.x, pose_init.orientation.y, pose_init.orientation.z, pose_init.orientation.w), tf::Vector3(pose_init.position.x, pose_init.position.y, pose_init.position.z));
      transform2 = transform1 * transform2;
      /*target_pose1.position=pose_init.position;
      target_pose1.orientation=pose_init.orientation;*/
     /* geometry_msgs::Pose target_pose1;
      target_pose1.position.x = transform2.getOrigin().getX();
      target_pose1.position.y = transform2.getOrigin().getY();
      target_pose1.position.z = transform2.getOrigin().getZ();
      target_pose1.orientation.x = transform2.getRotation().getX();
      target_pose1.orientation.y = transform2.getRotation().getY();
      target_pose1.orientation.z = transform2.getRotation().getZ();
      target_pose1.orientation.w = transform2.getRotation().getW();

  double target_x = target_pose1.position.x;
  double target_y = target_pose1.position.y;
  tf::Quaternion quat;
  quat.setRPY(0.0, 0.0, 90.0);
  tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(quat, tf::Point(target_x, target_y, 0.0)), ros::Time::now(), map_link);
 
      geometry_msgs::PoseStamped goal;
      tf::poseStampedTFToMsg(p, goal);
      /*ROS_INFO("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
          goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
          goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, 90);
      *///navigation_goal_publisher.publish(goal);
      /*sleep(2.0);
      ros::spinOnce();
      sleep(10.0);*/
  laserlis.hit = false;
  ROS_INFO("Navigation Started!");
  while(ros::ok())
  {
    if(laserlis.hit)
      break;
    ros::spinOnce();
    sleep(SLEEP_INTERVAL);
    
  }
  ROS_INFO("Navigation Finished!");
  laserlis.hit = false;
 
  return true;

}

bool GraspNode::arrive_plan(double x,double y,double z,bool &arm,moveit::planning_interface::MoveGroup::Plan &plan ){
      group.setStartState(*group.getCurrentState());
      pose_average.position.x=x;
      pose_average.position.y=y;
      pose_average.position.z=z;
      //target_pose2 = pose_average;
      target_pose2.position.x=pose_average.position.x;
      target_pose2.position.z=pose_average.position.z+0.15;
      target_pose2.position.y=pose_average.position.y;
      target_pose2.orientation.x=0;
      target_pose2.orientation.y=-sqrt(2)/2;
      target_pose2.orientation.z=sqrt(2)/2;
      target_pose2.orientation.w=0;
      //leftwards:(x:0.991776 y:-0.011776 z:0.054329  w:0.115287)  downwards:(0,-sqrt(2)/2,sqrt(2)/2,0) rightwards:(0,0,0,0)
      //decide_target_pose(&target_pose2,1.002963-0.03,-0.0816710-0.03,0.391100,0,0,1,0);

      // target_pose2 = target_pose1;
      printf("pose:\nx:%f\ty:%f\tz:%f\n",target_pose2.position.x,target_pose2.position.y,target_pose2.position.z);
      printf("orientation:\nx:%f\ty:%f\tz:%f\tw:%f\n",target_pose2.orientation.x,target_pose2.orientation.y,target_pose2.orientation.z,target_pose2.orientation.w);
      /*waypoints.clear();
      waypoints.push_back(target_pose2);
      moveit_msgs::RobotTrajectory trajectory;
      double fraction = group.computeCartesianPath(waypoints,
                                               0.01,  // eef_step
                                               0.0,   // jump_threshold
                                               trajectory);

  ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
        fraction * 100.0); */
      group.setPoseTarget(target_pose2);
      ROS_INFO("Begin Planning!");
  
      // Now, we call the planner to compute the plan
       // and visualize it.
     // Note that we are just planning, not asking move_group 
     // to actually move the robot.
      //my_plan.trajectory_ = trajectory;
      bool success = group.plan(my_plan);
      //bool success = true;
      ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
      if(success){
          enable_arm = RIGHT_ARM;
          arm = RIGHT_ARM;
          plan = my_plan;
	  group.execute(plan);
	  return true;
      }else{
        moveit::planning_interface::MoveGroup group("left_arm");
        group.setStartState(*group.getCurrentState());
        target_pose2.position.x=pose_average.position.x;
      	target_pose2.position.z=pose_average.position.z+0.15;
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
          enable_arm = LEFT_ARM;
          arm = LEFT_ARM;
          plan = my_plan;
	  group.execute(plan);
	  return true;        
         }else{
          moveit::planning_interface::MoveGroup group("left_arm");
          group.setStartState(*group.getCurrentState());
          target_pose2 = pose_average;
          target_pose2.position.x=pose_average.position.x;
          target_pose2.position.z=pose_average.position.z+0.15;
          target_pose2.position.y=pose_average.position.y;
          target_pose2.orientation.x=0;
          target_pose2.orientation.y=-sqrt(2)/2;
          target_pose2.orientation.z=sqrt(2)/2;
          target_pose2.orientation.w=0;
          group.setPoseTarget(target_pose2);
          bool success = group.plan(my_plan);
          ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
          if(success){
            enable_arm = LEFT_ARM;
            arm = LEFT_ARM;
            plan = my_plan;
	    group.execute(plan);
            }else{
              moveit::planning_interface::MoveGroup group("right_arm");
              group.setStartState(*group.getCurrentState());
              target_pose2 = pose_average;
            target_pose2.position.x=pose_average.position.x;
            target_pose2.position.z=pose_average.position.z+0.15;
            target_pose2.position.y=pose_average.position.y;
            target_pose2.orientation.x=0;
            target_pose2.orientation.y=-sqrt(2)/2;
            target_pose2.orientation.z=sqrt(2)/2;
            target_pose2.orientation.w=0;
            group.setPoseTarget(target_pose2);
            bool success = group.plan(my_plan);
            ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
            if(success){
              enable_arm = RIGHT_ARM;
              arm = RIGHT_ARM;
              plan = my_plan;
	      group.execute(plan);
              }else{
		  return false;
	        }
            }
         }
      }
}
bool GraspNode::arrive_execute(bool arm,moveit::planning_interface::MoveGroup::Plan plan){

  if(arm == LEFT_ARM){
    moveit::planning_interface::MoveGroup group("left_arm");
    group.setStartState(*group.getCurrentState());
    bool success = group.execute(plan);
    if(success){
      sleep(1.0);
      gripper_command=75;
      pub_gripper(&left_gripper_signal_pub,gripper_command);
      sleep(1.0);
      ros::spinOnce();
      return true;
    }else{
      return false;
    }
  }else{
    moveit::planning_interface::MoveGroup group("right_arm");
    group.setStartState(*group.getCurrentState());
    bool success = group.execute(plan);
    if(success){
      sleep(1.0);
      gripper_command=75;
      pub_gripper(&right_gripper_signal_pub,gripper_command);
      sleep(1.0);
      ros::spinOnce();
      return true;
    }else{
      return false;
    }
  }
}
bool GraspNode::execute(double x,double y,double z){
      pose_average.position.x=x;
      pose_average.position.y=y;
      pose_average.position.z=z;
      //target_pose2 = pose_average;
      target_pose2.position.x=pose_average.position.x;
      target_pose2.position.z=pose_average.position.z+0.15;
      target_pose2.position.y=pose_average.position.y;
      target_pose2.orientation.x=0;
      target_pose2.orientation.y=-sqrt(2)/2;
      target_pose2.orientation.z=sqrt(2)/2;
      target_pose2.orientation.w=0;
      //leftwards:(x:0.991776 y:-0.011776 z:0.054329  w:0.115287)  downwards:(0,-sqrt(2)/2,sqrt(2)/2,0) rightwards:(0,0,0,0)
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
          enable_arm = RIGHT_ARM;
          bool ex = group.execute(my_plan);
          while(!ex) {
            power();
	    group.setStartState(*group.getCurrentState());
	    group.plan(my_plan);
	    ex = group.execute(my_plan);
            //continue;
          }
      }else{
        moveit::planning_interface::MoveGroup group("left_arm");
        target_pose2.position.x=pose_average.position.x;
      	target_pose2.position.z=pose_average.position.z+0.15;
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
          enable_arm = LEFT_ARM;
          bool ex=group.execute(my_plan);
          while(!ex) {
              power();
              //continue;
              group.setStartState(*group.getCurrentState());
	    	group.plan(my_plan);
	    	ex = group.execute(my_plan);
            }          
         }else{
          moveit::planning_interface::MoveGroup group("left_arm");
          target_pose2 = pose_average;
          target_pose2.position.x=pose_average.position.x;
          target_pose2.position.z=pose_average.position.z+0.15;
          target_pose2.position.y=pose_average.position.y;
          target_pose2.orientation.x=0;
          target_pose2.orientation.y=-sqrt(2)/2;
          target_pose2.orientation.z=sqrt(2)/2;
          target_pose2.orientation.w=0;
          group.setPoseTarget(target_pose2);
          bool success = group.plan(my_plan);
          ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
          if(success){
            enable_arm = LEFT_ARM;
              bool ex=group.execute(my_plan);
            while(!ex) {
                power();
                //continue;
		group.setStartState(*group.getCurrentState());
	        group.plan(my_plan);
	        ex = group.execute(my_plan);
              }
            }else{
              moveit::planning_interface::MoveGroup group("right_arm");
              target_pose2 = pose_average;
            target_pose2.position.x=pose_average.position.x;
            target_pose2.position.z=pose_average.position.z+0.15;
            target_pose2.position.y=pose_average.position.y;
            target_pose2.orientation.x=0;
            target_pose2.orientation.y=-sqrt(2)/2;
            target_pose2.orientation.z=sqrt(2)/2;
            target_pose2.orientation.w=0;
            group.setPoseTarget(target_pose2);
            bool success = group.plan(my_plan);
            ROS_INFO("Visualizing plan 1 (pose goal) %s",success?"SUCCEED":"FAILED"); 
            if(success){
              enable_arm = RIGHT_ARM;
                bool ex=group.execute(my_plan);
            if(!ex) return false;
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
      group.setPlanningTime(1.0);
      // printf("Have we grasped the object?(y/n)");
      // scanf("%s",&haveGrasp);
      std::vector<std::string> object_ids;
    object_ids.push_back("cylinder");
    planning_scene_interface.removeCollisionObjects(object_ids);
    group.setStartState(*group.getCurrentState());
    power();
    sleep(1.0);
        vector<double> group_variable_values;
	group.setStartState(*group.getCurrentState());
	

    sleep(1.0);
    group_variable_values.clear();
    if(enable_arm==LEFT_ARM){
		/*target_pose_temp.position.x=0.864536;
		target_pose_temp.position.y=0.367802;
		target_pose_temp.position.z=0.945851;
		target_pose_temp.orientation.x=0.251804;
		target_pose_temp.orientation.y=0.697385;
		target_pose_temp.orientation.z=0.593748;
		target_pose_temp.orientation.w=-0.312589;*/
		group.setStartState(*group.getCurrentState());
		group_variable_values.push_back(2.999290);
		group_variable_values.push_back(-2.236700);
		group_variable_values.push_back(-0.559131);
		group_variable_values.push_back(-2.830370);
		group_variable_values.push_back(-1.319326);
		group_variable_values.push_back(-1.608036);
	      ROS_INFO("Start planning picking!");
	     // group.setPoseTarget(target_pose_temp);
		group.setJointValueTarget(group_variable_values);
        }else{
        	/*target_pose_temp.position.x=0.566997;
		target_pose_temp.position.y=-0.435485;
		target_pose_temp.position.z=1.055114;
		target_pose_temp.orientation.x=0.342295;
		target_pose_temp.orientation.y=0.593277;
		target_pose_temp.orientation.z=0.654907;
		target_pose_temp.orientation.w=-0.319300;*/
		group.setStartState(*group.getCurrentState());
		  group_variable_values.push_back(-2.815427);
		  group_variable_values.push_back(-1.499180);
		  group_variable_values.push_back(0.997918);
		  group_variable_values.push_back(0.024248);
		  group_variable_values.push_back(1.522912);
		  group_variable_values.push_back(-1.612360);
		  ROS_INFO("Start planning picking!");
		  group.setJointValueTarget(group_variable_values);
        }
		//group.setRandomTarget();
		ROS_INFO("Start picking!");
      	//group.setPoseTarget(target_pose_temp);
      	bool pick_success = group.plan(my_plan);
	 
      	if(pick_success){ 
      		bool pick_exc=group.execute(my_plan);
      		if(!pick_exc)
      		{
      			power();
      			group.setStartState(*group.getCurrentState());
      			group.setJointValueTarget(group_variable_values);
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
	ROS_INFO("Start reseting!");
	//reset pose 
	power();
	sleep(1.0);
        group_variable_values.clear();
	group.setStartState(*group.getCurrentState());
	
	if(enable_arm==LEFT_ARM){
		
		group_variable_values.push_back(0.1412);
		group_variable_values.push_back(-3.1415);
		group_variable_values.push_back(2.8238);
		group_variable_values.push_back(-2.8238);
		group_variable_values.push_back(-1.612);
		group_variable_values.push_back(-1.5708);
		group.setJointValueTarget(group_variable_values);
		bool hui_success = group.plan(my_plan);
		//ROS_INFO("Visualizing plan 1 (pose goal) %s",hui_success?"SUCCEED":"FAILED");
	      	if(hui_success){ 
	      		bool hui_exc=group.execute(my_plan);
	      		if(!hui_exc)
	      		{
	      			power();
				sleep(0.5);
				group.setStartState(*group.getCurrentState());
	      			group.setJointValueTarget(group_variable_values);
	      			group.plan(my_plan);
	      			group.execute(my_plan);
	      		}
	      	}
	}else{
    		group_variable_values.push_back(-0.187947);
		group_variable_values.push_back(0.070866);
		group_variable_values.push_back(-2.824250);
		group_variable_values.push_back(-0.176628);
		group_variable_values.push_back(1.912136);
		group_variable_values.push_back(1.465337);
		group.setJointValueTarget(group_variable_values);
			bool hui_success = group.plan(my_plan);
		//ROS_INFO("Reset plan %s",hui_success?"SUCCEED":"FAILED");
	      	if(hui_success){ 
	      		bool hui_exc=group.execute(my_plan);
	      		if(!hui_exc)
	      		{
	      			power();
				sleep(0.5);
				group.setStartState(*group.getCurrentState());
	      			group.setJointValueTarget(group_variable_values);
	      			group.plan(my_plan);
	      			group.execute(my_plan);
	      		}
	      	}
        }
	
      
      // printf("Have we place the object?(y/n)");
     //  scanf("%s",&haveGrasp);
    group_variable_values.clear();  
    object_ids.push_back("box1");
    object_ids.push_back("box2");
    planning_scene_interface.removeCollisionObjects(object_ids);
     // isReceived = false;
     // ros::shutdown();
      return true;
}
bool GraspNode::pick_plan(bool arm,moveit::planning_interface::MoveGroup::Plan &plan){
    sleep(2.0);
    
    group.setPlanningTime(1.0);
    // printf("Have we grasped the object?(y/n)");
    // scanf("%s",&haveGrasp);
    std::vector<std::string> object_ids;
    object_ids.push_back("cylinder");
    planning_scene_interface.removeCollisionObjects(object_ids);
    group.setStartState(*group.getCurrentState());
    
    if(arm==LEFT_ARM){
      moveit::planning_interface::MoveGroup group("left_arm");
	 group.setStartState(*group.getCurrentState());
      //target_pose_temp.position.x=0.864536;
      //target_pose_temp.position.y=0.367802;
      //target_pose_temp.position.z=0.945851;
      //target_pose_temp.orientation.x=0.251804;
      //target_pose_temp.orientation.y=0.697385;
      //target_pose_temp.orientation.z=0.593748;
      //target_pose_temp.orientation.w=-0.312589;
	vector<double> group_variable_values;
	group_variable_values.push_back(2.999290);
	group_variable_values.push_back(-2.236700);
	group_variable_values.push_back(-0.559131);
	group_variable_values.push_back(-2.830370);
	group_variable_values.push_back(-1.319326);
	group_variable_values.push_back(-1.608036);
      ROS_INFO("Start planning picking!");
     // group.setPoseTarget(target_pose_temp);
	group.setJointValueTarget(group_variable_values);
      bool pick_success = group.plan(my_plan);
      if(pick_success){
        plan =my_plan;
        return true;
        }else{
        return false;
        }
     }else{
          moveit::planning_interface::MoveGroup group("right_arm");
          //target_pose_temp.position.x=0.566997;
          //target_pose_temp.position.y=-0.435485;
          //target_pose_temp.position.z=1.055114;
          //target_pose_temp.orientation.x=0.342295;
          //target_pose_temp.orientation.y=0.593277;
          //target_pose_temp.orientation.z=0.654907;
          //target_pose_temp.orientation.w=-0.319300;
	  vector<double> group_variable_values;
	  group.setStartState(*group.getCurrentState());
	  group_variable_values.push_back(-2.815427);
	  group_variable_values.push_back(-1.499180);
	  group_variable_values.push_back(0.997918);
	  group_variable_values.push_back(0.024248);
	  group_variable_values.push_back(1.522912);
	  group_variable_values.push_back(-1.612360);
          ROS_INFO("Start planning picking!");
	  group.setJointValueTarget(group_variable_values);
          //group.setPoseTarget(target_pose_temp);
          bool pick_success = group.plan(my_plan);
          if(pick_success){
            plan =my_plan;
            return true;
          }else{
            return false;
          }
        }
    //group.setRandomTarget();
    
   
}
bool GraspNode::pick_execute(bool arm,moveit::planning_interface::MoveGroup::Plan plan){
    //power();
    sleep(1.0);
    if(arm==LEFT_ARM){
      moveit::planning_interface::MoveGroup group("left_arm");
      bool success = group.execute(plan);
      if(success){
        sleep(3.0);
        gripper_command="o";
        pub_gripper(&left_gripper_signal_pub,gripper_command);
        ros::spinOnce();
        sleep(3.0);
        return true;
      }else{
        return false;
      }
    }else{
      moveit::planning_interface::MoveGroup group("right_arm");
      bool success = group.execute(plan);
      if(success){
        sleep(3.0);
        gripper_command="o";
        pub_gripper(&right_gripper_signal_pub,gripper_command);
        ros::spinOnce();
        sleep(3.0);
        return true;
      }else{
        return false;
      }
    }

}
bool GraspNode::reset(){
    ROS_INFO("Start reseting!");
	//reset pose 
	//power();
	sleep(1.0);
	
	vector<double> group_variable_values;
	if(enable_arm==LEFT_ARM){
		moveit::planning_interface::MoveGroup group("left_arm");
    group.setStartState(*group.getCurrentState());
		group_variable_values.push_back(0.1412);
		group_variable_values.push_back(-3.1415);
		group_variable_values.push_back(2.8238);
		group_variable_values.push_back(-2.8238);
		group_variable_values.push_back(-1.612);
		group_variable_values.push_back(-1.5708);
		group.setJointValueTarget(group_variable_values);
		bool hui_success = group.plan(my_plan);
      	      if(hui_success){ 
      		bool hui_exc=group.execute(my_plan);
      		if(!hui_exc)
      		{
      			power();
			      sleep(0.5);
			      group.setStartState(*group.getCurrentState());
      			group.setJointValueTarget(group_variable_values);
      			group.plan(my_plan);
      			group.execute(my_plan);
      		}
      	     }
	}else{
		    moveit::planning_interface::MoveGroup group("right_arm");
		    group.setStartState(*group.getCurrentState());
		    group_variable_values.push_back(-0.187947);
		group_variable_values.push_back(0.070866);
		group_variable_values.push_back(-2.824250);
		group_variable_values.push_back(-0.176628);
		group_variable_values.push_back(1.912136);
		group_variable_values.push_back(1.465337);
		group.setJointValueTarget(group_variable_values);
		bool hui_success = group.plan(my_plan);
      	if(hui_success){ 
      		bool hui_exc=group.execute(my_plan);
      		if(!hui_exc)
      		{
      			power();
			      sleep(0.5);
			      group.setStartState(*group.getCurrentState());
      			group.setJointValueTarget(group_variable_values);
      			group.plan(my_plan);
      			group.execute(my_plan);
      		}
      	}
        }
std::vector<std::string> object_ids;
	object_ids.push_back("box1");
    object_ids.push_back("box2");
    planning_scene_interface.removeCollisionObjects(object_ids);
      //lis.isReceived = false;
     // lis.pose_sample.clear();
	return true;
}
int main(int argc, char **argv){

  double x,y,z;
  int state=1;
  bool arm = LEFT_ARM;
  char ch;
  bool detect_success,navigation_success,execute_success,plan_success,reset_success;
  moveit::planning_interface::MoveGroup::Plan plan;
  ros::init(argc, argv, "grasp_demo_gazebo");
  ros::NodeHandle nh;
  pluginListener plis;
  std_msgs::String msg;
  stringstream ss;
  ros::Publisher plugin_return_pub = nh.advertise<std_msgs::String>("plugin_return",1000);
  ros::Publisher start_ork_pub = nh.advertise<std_msgs::String>("start_ork_signal",1000);
  ros::Subscriber plugin_command_sub = nh.subscribe("plugin_command",1000,&pluginListener::plugin_callback,&plis);
  if(!ros::ok())
  {
    ROS_INFO("ros::ok failed!");
    return -1;
  }
  GraspNode graspnode;
  graspnode.init();
  graspnode.enable_arm=RIGHT_ARM;
  graspnode.reset();
  graspnode.enable_arm=LEFT_ARM;
  graspnode.reset();
  ROS_INFO("Init succeed!");
  /*ss<<"Init succeed!";
  msg.data = ss.str();
  plugin_return_pub.publish(msg);
  ros::spinOnce();*/
  while(ros::ok()){
    //graspnode.lis.isReceived = false;
    ss.clear();
    ss.str("");
    sleep(1.0);   
    
    //printf("Current state: %d\n",state);
    //std::cout<< plis.mode << std::endl;//ROS_INFO(plis.mode);
    switch(plis.mode){
      case AUTO:
        state = 0;
       // if(graspnode.detect(x,y,z)){
       //     ROS_INFO("First step of detection succeed!");
          if(graspnode.navigation()){
    	      ROS_INFO("Navigation succeed!");	
    	      if(graspnode.detect(x,y,z)){
    	      ROS_INFO("Second step of detection succeed!");
    	      bool success = graspnode.execute(x,y,z);
    	      if(success){
    		      ROS_INFO("Excecution succeed!");
    		    }
    	      else
    		      continue;
    	   }
    	   else
    	     ROS_INFO("Second step of detection failed!");
           }
           else
    	     ROS_INFO("Navigation failed!");
        //}
        //else 
        //{
         // ROS_INFO("First step of detection failed!"); 
        //  sleep(5.0);
        //}
        break;
      case DETECT:
      	if(true){
      		detect_success = graspnode.detect(x,y,z);
      		if(detect_success){
      		  ss<<"Detect succeed!";
                  state = 2;
      		}else{
      		  ss<<"Detect failed!";
      		}
      		msg.data = ss.str();
      		plugin_return_pub.publish(msg);
      		ROS_INFO("Detect plugin return has been published!");
      		plis.mode = 0;
      		ros::spinOnce();
      		
      	}
        break;
      case NAVIGATION1:
        if(true){
          //ROS_INFO("navigation 1");
          navigation_success = graspnode.navigation();
          if(navigation_success) ss << "Navigation succeed!";
          else ss << "Navigation failed!";
          msg.data = ss.str();
          plugin_return_pub.publish(msg);
          ROS_INFO("Navigation plugin return has been published!");
          ros::spinOnce();
          state = 1;
 	        plis.mode = 0;
        }else{
          ROS_INFO("Haven't deteccted objects yet!");
        }
        break;
      case ARRIVEPLAN:
          if(true){
              plan_success = graspnode.arrive_plan(x,y,z,arm,plan);
              if(plan_success) {
                ss << "Plan succeed!";
                //state = 3;
              }
              else ss << "Plan failed!";
              msg.data = ss.str();
              plugin_return_pub.publish(msg);
              ROS_INFO("Plan plugin return has been published!");
              ros::spinOnce();
              plis.mode = 0;
          }else{
             ROS_INFO("Haven't detected objects yet!");
          }
          break;
      case ARRIVEEXECUTE:
        if(true){
          execute_success = graspnode.arrive_execute(arm,plan);
          if(execute_success) {
            ss << "Execute succeed!";
            state = 3;
          }
          else ss << "Execute failed!";
          msg.data = ss.str();
          plugin_return_pub.publish(msg);
          ROS_INFO("Execute plugin return has been published!");
          ros::spinOnce();
	         plis.mode = 0;
        }else{
          ROS_INFO("Haven't planed arriving yet!");
        }
        break;
   case PICKPLAN:
        if(true){
          plan_success = graspnode.pick_plan(arm,plan);
          if(execute_success) {
            ss << "Plan succeed!";
            //state = 5;
          }
          else ss << "Plan failed!";
          msg.data = ss.str();
          plugin_return_pub.publish(msg);
          ROS_INFO("Plan plugin return has been published!");
          ros::spinOnce();
           plis.mode = 0;
        }else{
          ROS_INFO("Haven't arrived yet!");
        }
        break;
   case PICKEXECUTE:
        if(true){
          execute_success = graspnode.pick_execute(arm,plan);
          if(execute_success) {
            ss << "Execute succeed!";
            state = 1;
          }
          else ss << "Execute failed!";
          msg.data = ss.str();
          plugin_return_pub.publish(msg);
          ROS_INFO("Execute plugin return has been published!");
          ros::spinOnce();
           plis.mode = 0;
        }else{
          ROS_INFO("Haven't planed picking yet!");
        }
        break;
	 case RESET:
          reset_success = graspnode.reset();
          if(reset_success) ss << "Reset succeed!";
          else ss << "Reset failed!";
          msg.data = ss.str();
          plugin_return_pub.publish(msg);
          ROS_INFO("Reset plugin return has been published!");
          ros::spinOnce();
	  plis.mode = 0;
	  //printf("Exit?(y/n)\n");
	  //  ch =getchar();
	  //  if(ch=='y'||ch=='Y') {return 0;}
	  //  else{;}
        break;
   case POWER:
	sleep(1.0);
	graspnode.power();
	ss<<"Power succeed!";
	msg.data = ss.str();
        plugin_return_pub.publish(msg);
        ROS_INFO("Power plugin return has been published!");
        ros::spinOnce();
        plis.mode = 0;
      default:
        ;
    }
    
  }
  return 0;
}

