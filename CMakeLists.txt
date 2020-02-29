cmake_minimum_required(VERSION 2.8.3)
project(nxp_demo)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

catkin_package()

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(${PROJECT_NAME} src/nxp_demo_node.cpp)
target_link_libraries(${PROJECT_NAME} ${catkin_LIBRARIES})