# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "turtlesim_servo: 4 messages, 0 services")

set(MSG_I_FLAGS "-Iturtlesim_servo:/home/shengjian/bulldog_ws/src/turtlesim_servo/msg;-Istd_msgs:/opt/ros/indigo/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(turtlesim_servo_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg" NAME_WE)
add_custom_target(_turtlesim_servo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim_servo" "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg" ""
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg" NAME_WE)
add_custom_target(_turtlesim_servo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim_servo" "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg" ""
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg" NAME_WE)
add_custom_target(_turtlesim_servo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim_servo" "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg" ""
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg" NAME_WE)
add_custom_target(_turtlesim_servo_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "turtlesim_servo" "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_cpp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_cpp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_cpp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
)

### Generating Services

### Generating Module File
_generate_module_cpp(turtlesim_servo
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(turtlesim_servo_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(turtlesim_servo_generate_messages turtlesim_servo_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_cpp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_cpp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_cpp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_cpp _turtlesim_servo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_servo_gencpp)
add_dependencies(turtlesim_servo_gencpp turtlesim_servo_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_servo_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_lisp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_lisp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_lisp(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
)

### Generating Services

### Generating Module File
_generate_module_lisp(turtlesim_servo
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(turtlesim_servo_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(turtlesim_servo_generate_messages turtlesim_servo_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_lisp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_lisp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_lisp _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_lisp _turtlesim_servo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_servo_genlisp)
add_dependencies(turtlesim_servo_genlisp turtlesim_servo_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_servo_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_py(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_py(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
)
_generate_msg_py(turtlesim_servo
  "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
)

### Generating Services

### Generating Module File
_generate_module_py(turtlesim_servo
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(turtlesim_servo_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(turtlesim_servo_generate_messages turtlesim_servo_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_py _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/turtle_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_py _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_cmd.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_py _turtlesim_servo_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/turtlesim_servo/msg/camera_pose_msg.msg" NAME_WE)
add_dependencies(turtlesim_servo_generate_messages_py _turtlesim_servo_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(turtlesim_servo_genpy)
add_dependencies(turtlesim_servo_genpy turtlesim_servo_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS turtlesim_servo_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/turtlesim_servo
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(turtlesim_servo_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/turtlesim_servo
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(turtlesim_servo_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/turtlesim_servo
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(turtlesim_servo_generate_messages_py std_msgs_generate_messages_py)
endif()
