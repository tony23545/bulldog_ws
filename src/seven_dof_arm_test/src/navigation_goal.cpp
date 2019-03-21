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
#include "geometry_msgs/Twist.h"
#include "sensor_msgs/LaserScan.h"
#include "nav_msgs/GetPlan.h"
#include <tf/transform_listener.h>
#include <iostream>
#include <geometry_msgs/PoseStamped.h>
#include <string>
#include <cmath>
const double pi=3.141592653;

std::string laser_topic = "scan";

ros::Publisher pub;

bool hit = false;

float min_tolerant_range = 0.1;
float move_step = 0.1;
float sleep_interval = 0.4;
void CallBack_laserscan(const sensor_msgs::LaserScan &msg)
{
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
   //ROS_INFO("%d %f %f %f %f", hit?1:0, msg.range_min, msg.range_max, minrange, maxrange);
   if(minrange < min_tolerant_range)
     hit = true;
}

void move_Foward()
{
    geometry_msgs::Twist m;
    m.linear.x = move_step;
    pub.publish(m);
    ROS_INFO("MOVE_FORWARD");
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_goal_node");
  ros::NodeHandle nh;

  ros::Subscriber laser_sub = nh.subscribe("scan", 1000, CallBack_laserscan);
  pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  if(ros::ok())
    ros::spinOnce();
  while(ros::ok())
  {
    if(!hit)
    {
        move_Foward();
    }
    ros::spinOnce();
    sleep(sleep_interval);
  }

  return 0;
}
