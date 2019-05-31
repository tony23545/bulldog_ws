#!/usr/bin/env python
import rospy
from sensor_msgs.msg import Image
from sensor_msgs.msg import PointCloud2
from mask_rcnn_ros.srv import MaskDetect 
from gpd.srv import detect_grasps
from gpd.srv import pc_transform
from gpd.msg import CloudIndexed
from gpd.msg import GraspConfigList
from geometry_msgs.msg import Point
from geometry_msgs.msg import PointStamped
from std_msgs.msg import Int64

import tf2_ros
import tf2_py as tf2
from tf2_sensor_msgs.tf2_sensor_msgs import do_transform_cloud

import sys
import moveit_commander
import moveit_msgs.msg
import geometry_msgs.msg

import tf
import math
import IPython

if __name__ == "__main__":
	rospy.init_node("test_service")

	print("getting image...")
	image = rospy.wait_for_message("/camera/rgb/image_raw", Image)
	pc2 = rospy.wait_for_message("/camera/depth/points", PointCloud2)
	'''
	tf_buffer = tf2_ros.Buffer()
	tf_listener = tf2_ros.TransformListener(tf_buffer)

	trans = tf_buffer.lookup_transform("base_link", pc2.header.frame_id, rospy.Time(), rospy.Duration(2.0))
	pc2_new = do_transform_cloud(pc2, trans)
	'''
	try:
		mask_srv = rospy.ServiceProxy("pc_transform_srv", pc_transform)
		pc_transform_res = mask_srv(pc2)
	except rospy.ServiceException, e:
		print "service call failed: %s"%e
	print("transformed pc")
	
	pc2 = pc_transform_res.out_cloud
	
	print("waiting for service...")
	rospy.wait_for_service("mask_rcnn_srv")
	try:
		print("calling mask_rcnn")
		mask_srv = rospy.ServiceProxy("mask_rcnn_srv", MaskDetect)
		response = mask_srv(image)
	except rospy.ServiceException, e:
		print "service call failed: %s"%e


	cloudindexed = CloudIndexed()
	if len(response.result.masks) > 0:
		j = 0
		while j < len(response.result.class_names):
			if response.result.class_names[j] == 'bottle':
				break
			j = j+1
		if j == len(response.result.class_names):
			print("no bottle found!")

		mask = response.result.masks[j]
		for i in range(mask.step * mask.height):
			if mask.data[i] == '\xff':
				cloudindexed.indices.append(Int64(i))



	cloudindexed.cloud_sources.cloud = pc2
	cloudindexed.cloud_sources.view_points.append(Point(0,0,0))
	cloudindexed.cloud_sources.camera_source.append(Int64(0))

	print("generating grasp...")
	rospy.wait_for_service("/detect_grasps_server/detect_grasps")
	detect_grasp = rospy.ServiceProxy("/detect_grasps_server/detect_grasps", detect_grasps)
	gpd_response = detect_grasp(cloudindexed)
	IPython.embed()
	#get transform from camera to bask link
	#listener = tf.TransformListener()
	#listener.waitForTransform(pc2.header.frame_id, "base_link", rospy.Time(), rospy.Duration(2.0))
	#(trans, rot) = listener.lookupTransform("base_link", pc2.header.frame_id, rospy.Time.now(), rospy.Duration(2.0))
	'''
	bottom_stamped = PointStamped()
	bottom_stamped.header.frame_id = pc2.header.frame_id
	bottom_stamped.header.stamp = rospy.Time(0)
	bottom_stamped.point = gpd_response.grasp_configs.grasps[0].bottom
	#p = listener.transformPoint("base_link", bottom_stamped)'''
	robot = moveit_commander.RobotCommander()
	group = moveit_commander.MoveGroupCommander("left_arm")

	pose_target = geometry_msgs.msg.Pose()
	pose_target.orientation.x = 0
	pose_target.orientation.y = 0
	pose_target.orientation.z = 0.6
	pose_target.orientation.w = 0.8

	pose_target.position = gpd_response.grasp_configs.grasps[0].bottom
	group.set_pose_target(pose_target)

	plan1 = group.plan()

	print "============ Waiting while RVIZ displays plan1..."
	#rospy.sleep(5)

	
	IPython.embed()
	