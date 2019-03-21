# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "mask_rcnn_ros: 1 messages, 1 services")

set(MSG_I_FLAGS "-Imask_rcnn_ros:/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(mask_rcnn_ros_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv" NAME_WE)
add_custom_target(_mask_rcnn_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "mask_rcnn_ros" "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv" "std_msgs/Int64:std_msgs/Header:sensor_msgs/Image"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg" NAME_WE)
add_custom_target(_mask_rcnn_ros_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "mask_rcnn_ros" "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg" "sensor_msgs/Image:std_msgs/Header:sensor_msgs/RegionOfInterest"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Services
_generate_srv_cpp(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Module File
_generate_module_cpp(mask_rcnn_ros
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mask_rcnn_ros
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(mask_rcnn_ros_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(mask_rcnn_ros_generate_messages mask_rcnn_ros_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_cpp _mask_rcnn_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_cpp _mask_rcnn_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mask_rcnn_ros_gencpp)
add_dependencies(mask_rcnn_ros_gencpp mask_rcnn_ros_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mask_rcnn_ros_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Services
_generate_srv_lisp(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Module File
_generate_module_lisp(mask_rcnn_ros
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mask_rcnn_ros
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(mask_rcnn_ros_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(mask_rcnn_ros_generate_messages mask_rcnn_ros_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_lisp _mask_rcnn_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_lisp _mask_rcnn_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mask_rcnn_ros_genlisp)
add_dependencies(mask_rcnn_ros_genlisp mask_rcnn_ros_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mask_rcnn_ros_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/RegionOfInterest.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Services
_generate_srv_py(mask_rcnn_ros
  "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/Image.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros
)

### Generating Module File
_generate_module_py(mask_rcnn_ros
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(mask_rcnn_ros_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(mask_rcnn_ros_generate_messages mask_rcnn_ros_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/srv/MaskDetect.srv" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_py _mask_rcnn_ros_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/mask_rcnn_ros/msg/Result.msg" NAME_WE)
add_dependencies(mask_rcnn_ros_generate_messages_py _mask_rcnn_ros_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(mask_rcnn_ros_genpy)
add_dependencies(mask_rcnn_ros_genpy mask_rcnn_ros_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS mask_rcnn_ros_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mask_rcnn_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/mask_rcnn_ros
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(mask_rcnn_ros_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(mask_rcnn_ros_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mask_rcnn_ros)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/mask_rcnn_ros
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(mask_rcnn_ros_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(mask_rcnn_ros_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/mask_rcnn_ros/.+/__init__.pyc?$"
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(mask_rcnn_ros_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(mask_rcnn_ros_generate_messages_py sensor_msgs_generate_messages_py)
endif()
