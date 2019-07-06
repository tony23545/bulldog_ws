#!/usr/bin/env python
from turtlesim_servo.msg import turtle_cmd, turtle_pose_msg
import rospy
import numpy as np
import random

def main():
	rospy.init_node('random_turtle')
	pub = rospy.Publisher("turtle_mov", turtle_cmd, queue_size=1)
	cmd = turtle_cmd()
	rate = rospy.Rate(10)
	while not rospy.is_shutdown():
		cmd = turtle_cmd(0,0)
		if random.random() > 0.9:
			cmd.acc = (random.random() - 0.5) * 50.0
		if random.random() > 0.96:
			cmd.d_angle = (random.random() - 0.5) * 10.0
		pub.publish(cmd)
		rate.sleep()


if __name__ == "__main__":
	main()