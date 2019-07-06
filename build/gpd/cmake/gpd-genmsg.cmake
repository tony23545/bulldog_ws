# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "gpd: 6 messages, 2 services")

set(MSG_I_FLAGS "-Igpd:/home/shengjian/bulldog_ws/src/gpd/msg;-Igeometry_msgs:/opt/ros/indigo/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/indigo/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(gpd_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv" "sensor_msgs/PointField:sensor_msgs/PointCloud2:std_msgs/Header"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg" "geometry_msgs/Point:sensor_msgs/PointField:gpd/CloudSources:sensor_msgs/PointCloud2:std_msgs/Header:std_msgs/Int64"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg" "geometry_msgs/Point:sensor_msgs/PointField:sensor_msgs/PointCloud2:std_msgs/Header:std_msgs/Int64"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg" "std_msgs/Float32:geometry_msgs/Vector3:gpd/GraspConfig:std_msgs/Header:geometry_msgs/Point"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv" "geometry_msgs/Point:std_msgs/Float32:gpd/CloudIndexed:sensor_msgs/PointField:geometry_msgs/Vector3:gpd/CloudSources:sensor_msgs/PointCloud2:std_msgs/Header:std_msgs/Int64:gpd/GraspConfigList:gpd/GraspConfig"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg" "geometry_msgs/Vector3:geometry_msgs/Point:std_msgs/Float32"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg" "std_msgs/Header:geometry_msgs/Point"
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg" NAME_WE)
add_custom_target(_gpd_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "gpd" "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg" "geometry_msgs/Point:sensor_msgs/PointField:gpd/CloudSources:sensor_msgs/PointCloud2:std_msgs/Header:std_msgs/Int64"
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_msg_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)

### Generating Services
_generate_srv_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)
_generate_srv_cpp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
)

### Generating Module File
_generate_module_cpp(gpd
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(gpd_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(gpd_generate_messages gpd_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg" NAME_WE)
add_dependencies(gpd_generate_messages_cpp _gpd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gpd_gencpp)
add_dependencies(gpd_gencpp gpd_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gpd_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_msg_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)

### Generating Services
_generate_srv_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)
_generate_srv_lisp(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
)

### Generating Module File
_generate_module_lisp(gpd
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(gpd_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(gpd_generate_messages gpd_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg" NAME_WE)
add_dependencies(gpd_generate_messages_lisp _gpd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gpd_genlisp)
add_dependencies(gpd_genlisp gpd_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gpd_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_msg_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)

### Generating Services
_generate_srv_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)
_generate_srv_py(gpd
  "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Float32.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointField.msg;/opt/ros/indigo/share/geometry_msgs/cmake/../msg/Vector3.msg;/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg;/opt/ros/indigo/share/sensor_msgs/cmake/../msg/PointCloud2.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/indigo/share/std_msgs/cmake/../msg/Int64.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg;/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
)

### Generating Module File
_generate_module_py(gpd
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(gpd_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(gpd_generate_messages gpd_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/pc_transform.srv" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudIndexed.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSources.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfigList.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/srv/detect_grasps.srv" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/GraspConfig.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/SamplesMsg.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/gpd/msg/CloudSamples.msg" NAME_WE)
add_dependencies(gpd_generate_messages_py _gpd_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(gpd_genpy)
add_dependencies(gpd_genpy gpd_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS gpd_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/gpd
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(gpd_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(gpd_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(gpd_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/gpd
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(gpd_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(gpd_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(gpd_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/gpd
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(gpd_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(gpd_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(gpd_generate_messages_py std_msgs_generate_messages_py)
endif()
