/* Copyright 2018 JIRo */

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>

#include <sstream>

#include <opencv2/highgui/highgui.hpp>

int main(int argc, char **argv) {
  ros::init(argc, argv, "image_publisher");
  ros::NodeHandle nh;
  image_transport::ImageTransport it(nh);
  image_transport::Publisher pub = it.advertise("cam_pub", 1);

  int cam_device;

  if (argc < 2) {  // Defines default device cam equal zero
    nh.param("cam_device", cam_device, 0);
  } else {
    std::istringstream cam_deviceCmd(argv[1]);
    if (!(cam_deviceCmd >> cam_device)) {
      return 1;
    }
  }

  cv::VideoCapture cap(cam_device);

  if (!cap.isOpened()) {
    std::cout << "Device not find" << std::endl;
    return 1;
  }

  cv::Mat frame;
  sensor_msgs::ImagePtr msg;

  int image_show;

  nh.param("image_show", image_show, 0);

  while (nh.ok()) {
    cap >> frame;

    if (image_show) {
      cv::imshow("Cam View", frame);
      cv::waitKey(30);
    }

    if (!frame.empty()) {
      msg = cv_bridge::CvImage(std_msgs::Header(), "bgr8", frame)
          .toImageMsg();
      pub.publish(msg);
    }
  }
}
