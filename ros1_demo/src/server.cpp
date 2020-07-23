#include "ros/ros.h"
#include "demo/service.h"

bool call_back(demo::service::Request  &req, demo::service::Response &res)
{
  ROS_INFO("request: %s",req.data.c_str());
  // std::cout<< req.data<<std::endl;
  res.data = "got";
  return true;
}

//int server(int argc, char **argv)
//{
//  if (argc < 2) {
//      std::cout<<"set service name please"<<std::endl;
//      return 1;
//  }
//
//  std::string serviceName = argv[1];
//  std::cout <<"setted service name: "<< serviceName << "\n";

int server(std::string nodeName, std::string serviceName) {
    int argc = 0;
    char ** argv;

  ros::init(argc, argv, nodeName);
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService(serviceName, call_back);
  ros::spin();

  return 0;
}