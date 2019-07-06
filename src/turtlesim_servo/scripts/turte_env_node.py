#!/usr/bin/env python
import cv2
from cv_bridge import CvBridge
import numpy as np
import rospy
from turtlesim_servo.msg import turtle_cmd,camera_cmd, turtle_pose_msg, camera_pose_msg
from sensor_msgs.msg import Image
from std_msgs.msg import Int64

import IPython

class turtle_env:
	def __init__(self, turtle):
		self._cv_bridge = CvBridge()

		#blank black background
		self._bg_width = 256
		self._bg_height = 256
		self._background = np.zeros((256, 256, 3), np.uint8)

		#turtle
		self._turtle_xpose = self._bg_height / 2
		self._turtle_ypose = self._bg_width  / 2
		self._double_xpose = self._bg_height / 2.0
		self._double_ypose = self._bg_width  / 2.0
		self._turtle_angle = 0.0
		self._turtle_origin_image = turtle
		self._turtle_rotated_image = turtle
		self._turtle_xsize = turtle.shape[0]
		self._turtle_ysize = turtle.shape[1]

		#turtle_dynamic
		self._interval = 0.02
		self._pub_rate = 50
		self._vel = 10.0
		self._vel_limit = 5.0
		
		#camara
		self._camera_xpose = self._bg_height / 2
		self._camera_ypose = self._bg_width  / 2
		self._camera_xvision = 50
		self._camera_yvision = 50

		#env image
		self._env_view = self._background
		self._camera_view = np.zeros((self._camera_xvision, self._camera_yvision), np.uint8)

		#command related
		rospy.Subscriber("turtle_mov", turtle_cmd, self.turtle_callback, queue_size=1)
		rospy.Subscriber("camera_mov", camera_cmd, self.camera_callback, queue_size=1)

		self._env_image_pub = rospy.Publisher("env_view", Image, queue_size=1)
		self._cam_image_pub = rospy.Publisher("cam_view", Image, queue_size=1)
		self._turtle_pose_pub = rospy.Publisher("turtle_pose", turtle_pose_msg, queue_size=1)
		self._camera_pose_pub = rospy.Publisher("camera_pose", camera_pose_msg, queue_size=1)
		self._camera_pose_pub = rospy.Publisher("camera_pose", camera_pose_msg, queue_size=1)
		self._collision_pub = rospy.Publisher("collision", Int64, queue_size=1)

	def run(self):
		rate = rospy.Rate(self._pub_rate)
		while not rospy.is_shutdown():
			#update turtle position
			self._double_xpose = self._double_xpose - self._vel * np.cos(self._turtle_angle * np.pi / 180.0) * self._interval
			self._double_ypose = self._double_ypose - self._vel * np.sin(self._turtle_angle * np.pi / 180.0) * self._interval
			self._turtle_xpose = np.floor(np.min((np.max((self._double_xpose, np.ceil(self._turtle_xsize / 2.0))), np.floor(self._bg_height - self._turtle_xsize / 2))))
			self._turtle_ypose = np.floor(np.min((np.max((self._double_ypose, np.ceil(self._turtle_ysize / 2.0))), np.floor(self._bg_width - self._turtle_ysize / 2))))

			self.update_env_view()
			#update camera
			self.update_camera_view()
			#publish image
			env_msg = self._cv_bridge.cv2_to_imgmsg(self._env_view, 'bgr8')
			cam_msg = self._cv_bridge.cv2_to_imgmsg(self._camera_view, 'bgr8')
			self._env_image_pub.publish(env_msg)
			self._cam_image_pub.publish(cam_msg)

			self._turtle_pose_pub.publish(turtle_pose_msg(self._double_xpose, self._double_ypose, self._turtle_angle))
			self._camera_pose_pub.publish(camera_pose_msg(self._camera_xpose, self._camera_ypose))

			rate.sleep()

	def rotate_image(self, mat, angle):
		"""
		Rotates an image (angle in degrees) and expands image to avoid cropping
		"""

		height, width = mat.shape[:2] # image shape has 3 dimensions
		image_center = (width/2, height/2) # getRotationMatrix2D needs coordinates in reverse order (width, height) compared to shape

		rotation_mat = cv2.getRotationMatrix2D(image_center, angle, 1.)

		# rotation calculates the cos and sin, taking absolutes of those.
		abs_cos = abs(rotation_mat[0,0]) 
		abs_sin = abs(rotation_mat[0,1])

		# find the new width and height bounds
		bound_w = int(height * abs_sin + width * abs_cos)
		bound_h = int(height * abs_cos + width * abs_sin)

		# subtract old image center (bringing image back to origo) and adding the new image center coordinates
		rotation_mat[0, 2] += bound_w/2 - image_center[0]
		rotation_mat[1, 2] += bound_h/2 - image_center[1]

		# rotate image with the new bounds and translated rotation matrix
		rotated_mat = cv2.warpAffine(mat, rotation_mat, (bound_w, bound_h))
		return rotated_mat

	def update_env_view(self):
		self._env_view = self._background.copy()

		x1 = np.floor(self._turtle_xpose - self._turtle_xsize / 2.0)
		x2 = np.floor(self._turtle_xpose + self._turtle_xsize / 2.0)
		y1 = np.floor(self._turtle_ypose - self._turtle_ysize / 2.0)
		y2 = np.floor(self._turtle_ypose + self._turtle_ysize / 2.0)
		#IPython.embed()
		self._env_view[int(x1):int(x2),int(y1):int(y2)] = self._turtle_rotated_image

	def update_camera_view(self):
		self._camera_view = self._env_view[self._camera_xpose - self._camera_xvision/2:
										   self._camera_xpose + self._camera_xvision/2,
										   self._camera_ypose - self._camera_yvision/2:
										   self._camera_ypose + self._camera_yvision/2,]

	def turtle_callback(self, msg):
		#update turtle dynamic based on acceleration
		self._vel = np.max((np.min((self._vel + msg.acc, self._vel_limit)), 0.0))
		#angle between -60 ~ 60
		self._turtle_angle = self._turtle_angle + msg.d_angle
		self._turtle_rotated_image = self.rotate_image(self._turtle_origin_image, self._turtle_angle)
		self._turtle_xsize = self._turtle_rotated_image.shape[0]
		self._turtle_ysize = self._turtle_rotated_image.shape[1]

	def camera_callback(self, msg):
		newx = self._camera_xpose + dx
		newy = self._camera_ypose + dy
		#keep camera view within the env
		self._camera_xpose = np.min(np.max(newx, self._camera_xvision/2), self.__bg_height - self._camera_xvision/2)
		self._camera_ypose = np.min(np.max(newy, self._camera_yvision/2), self.__bg_width - self._camera_yvision/2)

def main():
	rospy.init_node('turtle_env')
	image_dir = '../images/'
	turtle_image = ['box-turtle.png', 'diamondback.png', 'electric.png', 'fuerte.png', 'groovy.png']
	image_path = image_dir + turtle_image[0]

	turtle = cv2.imread(image_path)

	i = 0
	while(np.sum(turtle[0, i]==[255,255,255])==3):
		i = i + 1
	j=44
	while(np.sum(turtle[0, j]==[255,255,255])==3):
		j = j - 1
	new_turtle = turtle[:, i:j+1, :]

	env = turtle_env(new_turtle)
	env.run()

if __name__ == "__main__":
	main()