# thi_nav_launch

## Description
This repository illustrates the package move base. It contains several launch files to start a simulation, as well rviz for visualization. 
Initially, get the content of this repository and check it out in your catkin workspace, e.g. ```cd ~/catkin_ws/src``` . The command for the checkout is 
```
git clone https://github.com/christianpfitzner/thi_nav_launch.git
```

# Task 1: 
With this first task, we will bring up the move base framework we a predefined configuration. This includes a visualization in rviz, where topics are already subscribing to essential nodes. Furthermore, this example relys on the STDR simulator, which is started by another launch file. 


Start the launch file simulation.launch, 
```
roslaunch thi_nav_launch simulation.launch
```
as well as the launch file move_base.launch
```
roslaunch thi_nav_launch move_base.launch
```

# Task 2: 
In Rviz use the tool *2D NAV GOAL* to command the robot to go to this pose. 


# Task 3: 
Check via rostopic list, which topics are provided by move base. Have a look at the following topics: 
```/robot0/cmd_vel```
```/move_base/current_goal```
```/move_base_simple/goal```
```/move_base/NavfnROS/plan```


# Task 4: 
Use the template in the src folder, to write a node, which commands the robot in all six rooms. Think of a guarding robot in an exhibition. 
The prepared rosnode should be compiled already. Start it with 
```
rosrun thi_nav_launch guard_node
```


# Task 5: 
Be creative: For example, combine the planing from move base with the reactive controll of the robot. Therefore, guard the robot to all provided poses in the map, but then do a rotation on the spot with 360 degrees. You can acchieve this by publishing a direct command to the ```/robot0/cmd_vel``` topic. 

