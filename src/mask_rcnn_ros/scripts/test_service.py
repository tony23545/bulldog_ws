#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2
from mask_rcnn_ros.srv import MaskDetect
import IPython

if __name__ == "__main__":
	rospy.init_node("test_service")

	if not rospy.is_shutdown():
		print("getting image...")
		image = rospy.wait_for_message("/camera/rgb/image_raw", Image)
		pc2 = rospy.wait_for_message("/camera/depth/points", PointCloud2)
	
	print("waiting for service...")
	rospy.wait_for_service("mask_rcnn_srv")
	try:
		mask_srv = rospy.ServiceProxy("mask_rcnn_srv", MaskDetect)
		response = mask_srv(image)

		#get index from mask
		indices = []
		if len(response.result.masks) > 0:
			mask = response.result.masks[0]
			for i in range(mask.step * mask.height):
				if mask.data[i] == '\xff':
					indices.append(i)
			print(len(indices))
		else:
			print("detect nothing")

		IPython.embed()
		
	except rospy.ServiceException, e:
		print "service call failed: %s"%e


