cmake_minimum_required(VERSION 2.8.3)
project(picture_server)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    cv_bridge
    image_transport
    )

find_package(OpenCV REQUIRED)
include_directories(${catkin_INCLUDE_DIRS})

add_executable(cam_publisher src/cam_publisher.cpp)
target_link_libraries(cam_publisher ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(cam_subscriber src/cam_subscriber.cpp)
target_link_libraries(cam_subscriber ${catkin_LIBRARIES} ${OpenCV_LIBS})

add_executable(marker_mesh src/marker_mesh.cpp)
target_link_libraries(marker_mesh ${catkin_LIBRARIES})
