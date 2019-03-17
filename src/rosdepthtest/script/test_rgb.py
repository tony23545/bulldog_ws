#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2


def callback(data):
	print("height: " + str(data.height))
	print("width: " + str(data.width))

def listener():
	rospy.init_node("test_camera")
	rospy.Subscriber("/camera/depth/points", PointCloud2, callback)
	rospy.spin()



if __name__ == '__main__':
	listener()