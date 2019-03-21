# bulldog_ws
## sources of important packages
[Grasp Pose Detection (GPD)](https://github.com/atenpas/gpd)  
[mask_rcnn](https://github.com/matterport/Mask_RCNN)  
[mask_rcnn_ros](https://github.com/qixuxiang/mask_rcnn_ros)
## Steps to setup:  
cd bulldog_ws/gpg   
mkdir build && cd build  
cmake ..  
make  
sudo make install  
cd ..  
catkin_make  
## Test Mask_rcnn_ros pkg
roslaunch bulldog_gazebo bulldog_empty_world.launch  
(manually add something in the vision of the robot, like a can of beer)  
roslaunch mask_rcnn_ros simply.launch  
rosrun mask_rcnn_ros test_mask_service.py  
## Test Mask_rcnn_ros with GPD
roslaunch bulldog_gazebo bulldog_empty_world.launch  
(manually add something in the vision of the robot, like a can of beer)  
roslaunch mask_rcnn_ros simply.launch  
roslaunch gpd grasp_detection_service.launch  
rosrun gpd gpd_mask_test.py  
