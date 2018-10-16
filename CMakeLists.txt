cmake_minimum_required(VERSION 2.8.3)
project(picture_server)
# add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  cv_bridge
  image_transport
  roscpp
  sensor_msgs
  std_msgs
  message_generation
  visualization_msgs
)

find_package(OpenCV REQUIRED)
add_service_files(FILES image_cmd.srv)
generate_messages(DEPENDENCIES)
catkin_package()
include_directories(${catkin_INCLUDE_DIRS})

add_executable(cam_publisher src/cam_publisher.cpp)
target_link_libraries(cam_publisher ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(cam_publisher picture_server_generate_messages_cpp)

add_executable(cam_subscriber src/cam_subscriber.cpp)
target_link_libraries(cam_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBS})
add_dependencies(cam_subscriber picture_server_generate_messages_cpp)

add_executable(marker_mesh src/marker_mesh.cpp)
target_link_libraries(marker_mesh ${catkin_LIBRARIES})
