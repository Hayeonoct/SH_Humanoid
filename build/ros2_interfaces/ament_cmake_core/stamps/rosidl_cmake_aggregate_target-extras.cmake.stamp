# generated from rosidl_cmake/cmake/rosidl_cmake_aggregate_target-extras.cmake.in

# Create a convenience aggregate target ros2_interfaces::ros2_interfaces
# that links all generated interface targets, so downstream packages can use
# a single modern CMake target name instead of ${ros2_interfaces_TARGETS}.
if(ros2_interfaces_TARGETS AND NOT TARGET ros2_interfaces::ros2_interfaces)
  add_library(ros2_interfaces::ros2_interfaces INTERFACE IMPORTED)
  set_target_properties(ros2_interfaces::ros2_interfaces PROPERTIES
    INTERFACE_LINK_LIBRARIES "${ros2_interfaces_TARGETS}")
endif()
