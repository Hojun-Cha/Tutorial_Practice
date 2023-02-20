#include "ros/ros.h" // ROS 관련 헤더
#include "ik_apply/target_msg.h" // 커스텀 메시지 헤더

#include "std_msgs/Header.h"
#include "geometry_msgs/Point.h"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "start_node"); // ROS 초기화, node 이름 지정
  ros::NodeHandle nh;
  ros::Publisher eef_coordinate_pub = nh.advertise<ik_apply::target_msg>("eef_coordinate_topic", 1);

  ros::Rate loop_rate(1); // 1Hz로 실행

  int count = 0;
  while (ros::ok())
  {
    /**
     * This is a message object. Stuff it with data, and then publish it.
     */
    ik_apply::target_msg t_msg;

    t_msg.eef_point.x = 0.1; //원하는 End-Effector 좌표값 지정
    t_msg.eef_point.y = 0.15; //원하는 End-Effector 좌표값 지정
    t_msg.eef_point.z = 0.25; //원하는 End-Effector 좌표값 지정

    ROS_INFO("Set desired end-effector xyz coordinate");
    ROS_INFO("eef_point_x : %.3f\n",t_msg.eef_point.x); // End-Effecotr 좌표값 터미널 출력
    ROS_INFO("eef_point_y : %.3f\n",t_msg.eef_point.y);
    ROS_INFO("eef_point_z : %.3f\n",t_msg.eef_point.z);

    eef_coordinate_pub.publish(t_msg);
    ros::spinOnce();
    loop_rate.sleep();
    count++;


  }

  return 0;
}
