# Micromouse-Simulator

Project Description:
The program is a Micromouse robot competition simulator. The robot's task is to find the shortest path from one point to another in a maze. The robot is based on three distance sensors placed on the front of the robot, on the left and on the right. The robot knows its own orientation, position and has a certain speed of movement. The Flood Fill algorithm was used to solve the maze. The program can generate a random maze of 16x16 dimensions. The Recursive Backtracking algorithm was used to generate the maze. The program includes a UI that allows intuitive control of the robot's passage.

Installation instruction:
a. Download the project from the repository.
b. Extract the downloaded files to a folder.
c. Open the project file in Qt Creator.
d. Build the project by clicking the Build button in Qt Creator.
e. Run the project by clicking the Run button in Qt Creator or by executing the generated executable file.

Usage:
On the left side of the program window you can see an "outside" view of the maze, which 
presents the robot walking through the maze. On the right side, the maze from the current state is presented 
stored in the robot's memory, along with values showing the operation of the Flood Fill algorithm. At the bottom of the program window 
of the program are buttons for controlling the application and the robot's travel time is displayed. The reset button 
positions returns the robot to its starting position. This allows the robot to repeat the trip until it 
finding the shortest route. The reset memory button deletes the memorized maze from the memory of the 
robot, and also restores it to the start position. Pressing the "Generate" button generates a 
a new random maze. The program implements a block on generating a new maze when the robot 
is in the process of traversing.

Contact:
j.wojtowicz0105@gmail.com
