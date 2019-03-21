/*
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

/*
#include <tf/transform_listener.h>

#include <geometry_msgs/PoseStamped.h>


int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_goal_node");
  ros::NodeHandle nh;
  ros::Publisher navigation_goal_publisher = nh.advertise <geometry_msgs::PoseStamped>("/move_base_simple/goal", 1, true);

  std::string fixed_frame = "/base_link";


  while(ros::ok()){
      tf::Quaternion quat;
      quat.setRPY(0.0, 0.0, 90.0);
      tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(quat, tf::Point(1.5, 1.0, 0.0)), ros::Time::now(), fixed_frame);
      geometry_msgs::PoseStamped goal;
      tf::poseStampedTFToMsg(p, goal);
      ROS_INFO("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
          goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
          goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, 90);
      navigation_goal_publisher.publish(goal);
      sleep(2.0);
      ros::spinOnce();
  }
  return 0;
}
*/
#include "stdio.h"
#include "ros/ros.h"
#include "object_recognition_msgs/RecognizedObjectArray.h"
#include "geometry_msgs/Point.h"
#include "nav_msgs/GetPlan.h"
#include <tf/transform_listener.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
#include <string>
const double pi=3.141592653;


bool isGetPose = false;
geometry_msgs::Pose pose_average;
std::string fixed_frame = "/base_link";
std::string robot_link = "/base_link", map_link = "/map";
ros::Publisher navigation_goal_publisher;
ros::Subscriber position_sub;
double target_x, target_y;
double goalTolerance = 0.5;
std::string service_name = "move_base/make_plan";

void CallBack(const geometry_msgs::Pose::ConstPtr& msg)
{
    pose_average = *msg;
    target_x = pose_average.position.x-0.8;
    target_y = pose_average.position.y;
    isGetPose = true;
    ROS_INFO("I have received the pose! %lf %lf %d", target_x, target_y, isGetPose?1:0);
}

void fillPathRequest(nav_msgs::GetPlan::Request &request)
{
    request.start.header.frame_id = "map";
    request.start.pose.position.x = 0;
    request.start.pose.position.y = 0;
    request.start.pose.orientation.w = 1.0;

    request.goal.header.frame_id = "map";
    request.goal.pose.position.x = target_x;
    request.goal.pose.position.y = target_y;
    request.goal.pose.orientation.w = 1.0;

    request.tolerance = goalTolerance;
}

void callPlanningService(ros::ServiceClient &serviceClient, nav_msgs::GetPlan &srv)
{
    // Perform the actual path planner call
    if (serviceClient.call(srv)) {
        if (!srv.response.plan.poses.empty()) {
            /*forEach(const geometry_msgs::PoseStamped &p, srv.response.plan.poses) {
                ROS_INFO("x = %f, y = %f", p.pose.position.x, p.pose.position.y);
            }*/
        }
        else {
            ROS_WARN("Got empty plan");
        }
    }
    else {
        ROS_ERROR("Failed to call service %s - is the robot moving?", serviceClient.getService().c_str());
    }
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_goal_node");
  ros::NodeHandle nh;

  while (!ros::service::waitForService(service_name, ros::Duration(3.0))) {
    ROS_INFO("Waiting for service move_base/make_plan to become available");
  }

  ros::ServiceClient serviceClient = nh.serviceClient<nav_msgs::GetPlan>(service_name, true);
  if (!serviceClient) {
     ROS_FATAL("Could not initialize get plan service from %s", serviceClient.getService().c_str());
     return -1;
  }

  navigation_goal_publisher = nh.advertise <geometry_msgs::PoseStamped>("/move_base_simple/goal", 1, true);
  position_sub = nh.subscribe("object_position_signal", 1000, CallBack);

  while(ros::ok())
  {
  	ROS_INFO("Enter_loop %d", isGetPose?1:0);
  	if(isGetPose)
  	{
  	    nav_msgs::GetPlan srv;
        fillPathRequest(srv.request);
        ROS_INFO("Start Process! %lf %lf", target_x, target_y);

        if(!serviceClient)
        {
            ROS_FATAL("Persistent service connection to %s failed", serviceClient.getService().c_str());
            return -1;
        }
   		callPlanningService(serviceClient, srv);
	    /*Quaternion quat;
	    quat.setRPY(0.0, 0.0, 90.0);
	    tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(quat, tf::Point(target_x, target_y, 0.0)), ros::Time::now(), robot_link);
	    tf::Stamped<tf::Pose> p_map;
	    while(1)
	    {
	      try{
	       tf_listener.transformPose(map_link, p, p_map);
	     }catch(tf2::ExtrapolationException &e)
	     {
	       std::cout<<"ERROR_1"<<std::endl;
	       sleep(0.2); 
	       continue;
	     }
	     break;
	    }*/
	     /*geometry_msgs::PoseStamped goal;
	     tf::poseStampedTFToMsg(p_map, goal);
	     //ROS_INFO("Transform pose! %lf %lf", p_map.position.x, p_map.position.y);
	     ROS_INFO("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
	              goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
	              goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, 90.0);
	    navigation_goal_publisher.publish(goal);*/

  		isGetPose = false;
  	}
  	sleep(0.5);
  	ros::spinOnce();
  	/*if(isGetPose)
  	{
  	    sleep(3.0);
  	    isGetPose = false;
  	}*/
  }
  return 0;
}
