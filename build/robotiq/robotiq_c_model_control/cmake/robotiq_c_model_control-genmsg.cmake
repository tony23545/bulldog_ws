# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "robotiq_c_model_control: 2 messages, 0 services")

set(MSG_I_FLAGS "-Irobotiq_c_model_control:/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(genlisp REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(robotiq_c_model_control_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg" NAME_WE)
add_custom_target(_robotiq_c_model_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotiq_c_model_control" "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg" ""
)

get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg" NAME_WE)
add_custom_target(_robotiq_c_model_control_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "robotiq_c_model_control" "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg" ""
)

#
#  langs = gencpp;genlisp;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotiq_c_model_control
)
_generate_msg_cpp(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotiq_c_model_control
)

### Generating Services

### Generating Module File
_generate_module_cpp(robotiq_c_model_control
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotiq_c_model_control
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(robotiq_c_model_control_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(robotiq_c_model_control_generate_messages robotiq_c_model_control_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_cpp _robotiq_c_model_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_cpp _robotiq_c_model_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotiq_c_model_control_gencpp)
add_dependencies(robotiq_c_model_control_gencpp robotiq_c_model_control_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotiq_c_model_control_generate_messages_cpp)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotiq_c_model_control
)
_generate_msg_lisp(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotiq_c_model_control
)

### Generating Services

### Generating Module File
_generate_module_lisp(robotiq_c_model_control
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotiq_c_model_control
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(robotiq_c_model_control_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(robotiq_c_model_control_generate_messages robotiq_c_model_control_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_lisp _robotiq_c_model_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_lisp _robotiq_c_model_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotiq_c_model_control_genlisp)
add_dependencies(robotiq_c_model_control_genlisp robotiq_c_model_control_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotiq_c_model_control_generate_messages_lisp)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control
)
_generate_msg_py(robotiq_c_model_control
  "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control
)

### Generating Services

### Generating Module File
_generate_module_py(robotiq_c_model_control
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(robotiq_c_model_control_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(robotiq_c_model_control_generate_messages robotiq_c_model_control_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_output.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_py _robotiq_c_model_control_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/shengjian/bulldog_ws/src/robotiq/robotiq_c_model_control/msg/CModel_robot_input.msg" NAME_WE)
add_dependencies(robotiq_c_model_control_generate_messages_py _robotiq_c_model_control_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(robotiq_c_model_control_genpy)
add_dependencies(robotiq_c_model_control_genpy robotiq_c_model_control_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS robotiq_c_model_control_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotiq_c_model_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/robotiq_c_model_control
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotiq_c_model_control)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/robotiq_c_model_control
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control)
  install(CODE "execute_process(COMMAND \"/usr/bin/python\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control
    DESTINATION ${genpy_INSTALL_DIR}
    # skip all init files
    PATTERN "__init__.py" EXCLUDE
    PATTERN "__init__.pyc" EXCLUDE
  )
  # install init files which are not in the root folder of the generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control
    DESTINATION ${genpy_INSTALL_DIR}
    FILES_MATCHING
    REGEX "${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/robotiq_c_model_control/.+/__init__.pyc?$"
  )
endif()
