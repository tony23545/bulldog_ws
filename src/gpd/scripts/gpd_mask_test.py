#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2
from mask_rcnn_ros.srv import MaskDetect
from gpd.srv import detect_grasps
from gpd.msg import CloudIndexed
from gpd.msg import GraspConfigList
from geometry_msgs.msg import Point
from std_msgs.msg import Int64
import IPython

if __name__ == "__main__":
	rospy.init_node("test_service")

	print("getting image...")
	image = rospy.wait_for_message("/camera/rgb/image_raw", Image)
	pc2 = rospy.wait_for_message("/camera/depth/points", PointCloud2)
	
	print("waiting for service...")
	rospy.wait_for_service("mask_rcnn_srv")
	try:
		mask_srv = rospy.ServiceProxy("mask_rcnn_srv", MaskDetect)
		response = mask_srv(image)
	except rospy.ServiceException, e:
		print "service call failed: %s"%e

	cloudindexed = CloudIndexed()
	if len(response.result.masks) > 0:
		mask = response.result.masks[0]
		for i in range(mask.step * mask.height):
			if mask.data[i] == '\xff':
				cloudindexed.indices.append(Int64(i))

	cloudindexed.cloud_sources.cloud = pc2
	cloudindexed.cloud_sources.view_points.append(Point(0,0,0))
	cloudindexed.cloud_sources.camera_source.append(Int64(0))

	print("generating grasp...")
	rospy.wait_for_service("/detect_grasps_server/detect_grasps")
	detect_grasp = rospy.ServiceProxy("/detect_grasps_server/detect_grasps", detect_grasps)
	graspConfigList = detect_grasp(cloudindexed)
	IPython.embed()