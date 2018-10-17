/* Copyright 2018 JIRo */

#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise
      <visualization_msgs::Marker>("visualization_marker", 0);

  while (ros::ok()) {
    visualization_msgs::Marker marker;
    marker.header.frame_id = "/my_frame";
    marker.header.stamp = ros::Time();
    marker.ns = "basic_shapes";
    marker.id = 0;
    marker.type = visualization_msgs::Marker::MESH_RESOURCE;
    marker.action = visualization_msgs::Marker::ADD;

    marker.mesh_resource = "file:///home/eberty/a.3ds";
    // marker.mesh_resource =
    // QFileDialog::getOpenFileName(0,"Open File",QString::null,QString::null);

    marker.scale.x = 1.0;
    marker.scale.y = 1.0;
    marker.scale.z = 1.0;
    marker.mesh_use_embedded_materials = true;
    marker_pub.publish(marker);
  }
}
