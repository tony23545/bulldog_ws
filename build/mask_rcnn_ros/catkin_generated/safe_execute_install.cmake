execute_process(COMMAND "/home/shengjian/bulldog_ws/build/mask_rcnn_ros/catkin_generated/python_distutils_install.sh" RESULT_VARIABLE res)

if(NOT res EQUAL 0)
  message(FATAL_ERROR "execute_process(/home/shengjian/bulldog_ws/build/mask_rcnn_ros/catkin_generated/python_distutils_install.sh) returned error code ")
endif()
