#include "ros/ros.h"
#include "demo/service.h"
#include <cstdlib>
#include <string>

//int client(int argc, char **argv) {
//ros::init(argc, argv, "client");
//
//if (argc != 4)
//{
//ROS_INFO("1st: waiting time;  2nd: service name; 3rd: message");
//return 1;
//}
//
//int waitingTime = std::stoi(argv[1]);
//std::cout<<waitingTime<<std::endl;
//std::string serviceName = argv[2];
//std::string message = argv[3];
int client(std::string nodeName, std::string serviceName, std::string message, double waitingTime) {
    int argc = 0;
    char ** argv;

  ros::init(argc, argv, nodeName);

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<demo::service>(serviceName);
  demo::service srv;
  srv.request.data = message;

  if (ros::service::waitForService(serviceName, ros::Duration(waitingTime))) {
 	  if (client.call(srv))
	  {
	    ROS_INFO("response: %s", srv.response.data.c_str());
	  }
	  else
	  {
  		ROS_ERROR("Failed to call service %s", serviceName.c_str());
	    return 1;
	  }
  } else {
  		ROS_ERROR("Failed to find service %s", serviceName.c_str());
	    return 1;
  }
  

  return 0;
}