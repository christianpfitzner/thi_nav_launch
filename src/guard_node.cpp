


#include <ros/ros.h>
#include <move_base/move_base.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <move_base_msgs/MoveBaseGoal.h>
#include <actionlib/client/simple_action_client.h>

#include <geometry_msgs/Point.h>


typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

std::vector<geometry_msgs::Point> g_goals; 


/**
 * Main function of ros node
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char **argv)
{
  // initialize ros node with name reactive_laser
  ros::init(argc, argv, "guard_node");
  ros::NodeHandle nh;

  geometry_msgs::Point p1;  p1.x = 3.6;  p1.y = 3.0;
  geometry_msgs::Point p2;  p2.x = 10.0; p2.y = 3.0; 
  geometry_msgs::Point p3;  p3.x = 16.0; p3.y = 3.0; 
  geometry_msgs::Point p4;  p4.x = 16.0; p4.y = 11.0; 
  geometry_msgs::Point p5;  p5.x = 10.0; p5.y = 11.0; 
  geometry_msgs::Point p6;  p6.x = 3.5;  p6.y = 11.0; 
  g_goals.push_back(p1);
  g_goals.push_back(p2); 
  g_goals.push_back(p3); 
  g_goals.push_back(p4); 
  g_goals.push_back(p5); 
  g_goals.push_back(p6); 



  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);

  //wait for the action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id    = "map";
  goal.target_pose.header.stamp       = ros::Time::now();

  for(const auto g : g_goals)
  {
    goal.target_pose.pose.position.x    = g.x;
    goal.target_pose.pose.position.y    = g.y;
    goal.target_pose.pose.orientation.w = 1.0;
    
    
    
    ROS_INFO("Sending goal");


    ac.sendGoal(goal);
    ac.waitForResult();

    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
      ROS_INFO("Reached goal. ");
    else
      ROS_INFO("Can not access goal. ");
  
  }


  return 0;
}