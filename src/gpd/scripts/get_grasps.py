#!/usr/bin/python


import rospy
from gpd.msg import GraspConfigList

# global variable to store grasps
grasps = []

def print_triple(name, msg):
	print(str(name) + " (" + str(msg.x) + ", " + str(msg.y) + ", " + str(msg.z) + ")")

def print_single_grasp(grasp):
	print("====printting single grasp====")
	print_triple("bottom point", grasp.bottom)
	print_triple("top point", grasp.top)
	print_triple("surface point", grasp.surface)
	print_triple("approach vector", grasp.approach)
	print_triple("binormal vector", grasp.binormal)
	print_triple("axis vector", grasp.axis)
	print_triple("sample point", grasp.sample)
	

# Callback function to receive grasps.
def callback(msg):
    global grasps
    grasps = msg.grasps
    for i in range(len(grasps)):
    	print("printing " + str(i) + " grasp")
    	print_single_grasp(grasps[i])


# ==================== MAIN ====================
# Create a ROS node.
rospy.init_node('get_grasps')

# Subscribe to the ROS topic that contains the grasps.
sub = rospy.Subscriber('/detect_grasps/clustered_grasps', GraspConfigList, callback)

# Wait for grasps to arrive.
rate = rospy.Rate(1)

while not rospy.is_shutdown():
    print '.'
    if len(grasps) > 0:
        rospy.loginfo('Received %d grasps.', len(grasps))
        break
    rate.sleep()