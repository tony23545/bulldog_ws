#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2


def callback(data):
	print("height: " + str(data.height))
	print("width: " + str(data.width))
	print("point_step: " + str(data.point_step))
	print("row_step: " + str(data.row_step))
	print("feild1: " + data.fields[0].name + "  " + str(data.fields[0].count) + "   " + str(data.fields[0].datatype))
	print("feild2: " + data.fields[1].name + "  " + str(data.fields[1].count) + "   " + str(data.fields[1].datatype))
	print("feild3: " + data.fields[2].name + "  " + str(data.fields[2].count) + "   " + str(data.fields[2].datatype))
	print("feild4: " + data.fields[3].name + "  " + str(data.fields[3].count) + "   " + str(data.fields[3].datatype))

def listener():
	rospy.init_node("test_camera")
	rospy.Subscriber("/camera/depth/points", PointCloud2, callback)
	rospy.spin()



if __name__ == '__main__':
	listener()