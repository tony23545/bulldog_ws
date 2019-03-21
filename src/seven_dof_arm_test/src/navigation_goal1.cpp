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
#include <tf/transform_listener.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
const double pi=3.141592653;


bool isGetPose = false;
geometry_msgs::Pose pose_average;
std::string fixed_frame = "/base_link";
std::string robot_link = "/base_link", map_link = "/map";
ros::Publisher navigation_goal_publisher;
class Navigation_goal_temp
{
public:
    tf::TransformListener tf_listener;
    ros::Subscriber position_sub;
    void CallBack(const geometry_msgs::Pose::ConstPtr& msg)
    {
        isGetPose = true ;
        pose_average = *msg;
        double target_x = pose_average.position.x-0.8;
        double target_y = pose_average.position.y;
        ROS_INFO("I have received the pose!");
        tf::Quaternion quat;
        quat.setRPY(0.0, 0.0, 90.0);
        tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(quat, tf::Point(target_x, target_y, 0.0)), ros::Time::now(), robot_link);
        tf::Stamped<tf::Pose> p_map;
        try{
          tf_listener.transformPose(map_link, p, p_map);
        }catch(tf2::ExtrapolationException &e)
        {
          std::cout<<"ERROR_1"<<std::endl;
          return ;
        }
        geometry_msgs::PoseStamped goal;
        tf::poseStampedTFToMsg(p, goal);
        ROS_INFO("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
              goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
              goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, 90.0);
        navigation_goal_publisher.publish(goal);

    }
    Navigation_goal_temp(ros::NodeHandle &nh)
    {
    //    position_sub = nh.subscribe("object_position_signal", 1000, CallBack);
    }
    void init_(ros::NodeHandle &nh)
    {
    	//position_sub = nh.subscribe("object_position_signal", 1000, CallBack);
    }
};
    void CallBack(const geometry_msgs::Pose::ConstPtr& msg)
    {
        isGetPose = true ;
        pose_average = *msg;
        double target_x = pose_average.position.x-0.8;
        double target_y = pose_average.position.y;
        ROS_INFO("I have received the pose!");
        tf::Quaternion quat;
        quat.setRPY(0.0, 0.0, 90.0);
        tf::Stamped<tf::Pose> p = tf::Stamped<tf::Pose>(tf::Pose(quat, tf::Point(target_x, target_y, 0.0)), ros::Time::now(), robot_link);
        geometry_msgs::PoseStamped goal;
        tf::poseStampedTFToMsg(p, goal);
        ROS_INFO("Setting goal: Frame:%s, Position(%.3f, %.3f, %.3f), Orientation(%.3f, %.3f, %.3f, %.3f) = Angle: %.3f\n", fixed_frame.c_str(),
              goal.pose.position.x, goal.pose.position.y, goal.pose.position.z,
              goal.pose.orientation.x, goal.pose.orientation.y, goal.pose.orientation.z, goal.pose.orientation.w, 90.0);
        navigation_goal_publisher.publish(goal);
    }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_goal_node");
  ros::NodeHandle nh;
  navigation_goal_publisher = nh.advertise <geometry_msgs::PoseStamped>("/move_base_simple/goal", 1, true);
  Navigation_goal_temp a(nh);
  ros::Subscriber position_sub;
  position_sub = nh.subscribe("object_position_signal", 1000, a.CallBack);
  ros::spin();
  return 0;
}
