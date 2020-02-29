#include <ros/ros.h>
#include <std_msgs/String.h>
#include <ros/subscriber.h>
#include <string>

ros::Subscriber autoware_sub;

// Assuimg autoware topic we want to subscribe to has message std_msgs::String (just a concept, and is easir to test :D)
void autowareCallback(const std_msgs::String::ConstPtr str) {
  ROS_DEBUG_STREAM("got message");
}

// if publisher is not active certain amount, output error message
void timerCallback(const ros::TimerEvent&){
  if(autoware_sub.getNumPublishers() == 0)
    ROS_ERROR_STREAM("Publisher is not active");

  /* if we don't want to have an actual subscriber we can also use following commented 
  code that checks list of all the topics that have a publisher */
  // auto topic_found = false;
  // ros::master::V_TopicInfo topic_infos;
  // ros::master::getTopics(topic_infos);
  // for(auto const &topic_info: topic_infos)
  // {
  //   if(std::string("/str_topic")==(std::string(topic_info.name)))
  //   {
  //     topic_found = true;
  //     break;
  //   }
  // }
  // if(!topic_found)
  //   ROS_ERROR_STREAM("Publisher is not active");
}

int main(int argc, char **argv) {
  constexpr static const char *autoware_topic_name = "input/topic";
  ros::init(argc, argv, "NXPDemo");
  ros::NodeHandle nh;

  autoware_sub =
      nh.subscribe(autoware_topic_name, 5, autowareCallback);

  ros::Timer node_check = nh.createTimer(ros::Duration(1.0), timerCallback);
  ros::spin();
}
