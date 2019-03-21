# Install script for directory: /home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/shengjian/bulldog_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/shengjian/bulldog_ws/build/bulldog_simulator/bulldog_gazebo/catkin_generated/installspace/bulldog_gazebo.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bulldog_gazebo/cmake" TYPE FILE FILES
    "/home/shengjian/bulldog_ws/build/bulldog_simulator/bulldog_gazebo/catkin_generated/installspace/bulldog_gazeboConfig.cmake"
    "/home/shengjian/bulldog_ws/build/bulldog_simulator/bulldog_gazebo/catkin_generated/installspace/bulldog_gazeboConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bulldog_gazebo" TYPE FILE FILES "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/package.xml")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/etc/catkin/profile.d" TYPE FILE FILES "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/env-hooks/50.bulldog_gazebo.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/bulldog_gazebo" TYPE PROGRAM FILES
    "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/scripts/setup_sim_positions"
    "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/scripts/dual_ur5_moveit_demo"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/bulldog_gazebo" TYPE DIRECTORY FILES
    "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/launch"
    "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/worlds"
    "/home/shengjian/bulldog_ws/src/bulldog_simulator/bulldog_gazebo/urdf"
    )
endif()

