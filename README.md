# Robosub_Simulation
A Small Proof of Concept project to better understand the inner workings of ROS-Gazebo Integration
- All our developed code is located on the different branches for this repository. 
- the [actual_working](https://github.com/GonzagaRobotics/Robosub_Simulation/tree/actual_working) branch contains code for running of a Gazebo 1 simulation of a moving cube
- the [camera](https://github.com/GonzagaRobotics/Robosub_Simulation/tree/camera) branch contains code for running the camera in a Gazebo simulation
# How to run Gazebo and ROS from a Docker Container on You Host OS
* Download docker desktop: https://www.docker.com/products/docker-desktop  

## Windows 

* Maybe: Download and Install WSL 2 
* Download VcXsrv: https://sourceforge.net/projects/vcxsrv/  
* Launch VcXsrv after installing and on the extra settings page: check clipboard and disable access control, uncheck native opengl
* Enter `docker pull ehiga/proofofconcept`
  * this is a docker container on dockerhub
* Enter `docker run -it -e DISPLAY=host.docker.internal:0.0 -p 11345:11345 --name robosub ehiga/proofofconcept` 
* `gazebo` <- Type this command to make sure your container works 

You can use this command to start up container after: docker start -ai robosub 

## MAC: 

Download XQuartz: https://www.xquartz.org/  

## Linux:  

* enter `docker pull ehiga/proofofconcept`
* `sudo docker run -it --name robosub ehiga/proofofconcept`
* `gazebo` 

Type this command to make sure your container works 

You can use this command to start up container after: `docker start -ai robosub`

# How to run the Robosub Simulation in in Ros1/Gazebo1 Docker
1. In your docker container run “apt install git” 
2. Enter `ssh-keygen` 
3. Keep hitting enter till the random art image appears 
4. “vi /root/.ssh/id_rsa.pub” 
5. Copy the entire key 
6. Go to settings on github > ssh and gpg keys > add a new key  
7. Go back to the repo > hit the green button code > click ssh >  copy the link there 
8. Go back to your docker > git clone <copied_link> 
9. Enter `cd Robosub_Simulation` 
10. Enter`git checkout dev` 
11. Enter `cmake CMakeLists.txt`
12. Enter `make` 
13. Enter `source devel/setup.sh` 
14. Enter `roslaunch launch/gazebo.launch`
15. To reset the simulation go on gazebo to Edit > Reset Model Poses > hit play

# How to run the real sense camera in Gazebo
1. Cd to the RobosubSimulator repository saved to your computer
2. Enter `git checkout camera` 
3. Run `cmake CMakeLists.txt` 
4. Run `make`
5. Run `roslaunch launch/gazebo.launch`
  a. You should see the camera model in gazebo 
6. Run `export DISPLAY=host.docker.internal:0.0’ 
7. Run `rviz` 
8. On the bottom left press `Add` 
9. Select the `Image` topic 
10. In the `Image` topic in the left column set the topic to the `/real_sense_plugin`.  

# Extra Notes
- How to put a docker container on your external drive (from: How could I install Docker for Windows on drive E: (my SSD C: is full)? , see radicalshift’s post) 
- In copy the contents of "C:\Users\%USERNAME%\AppData\Local\Docker" to a folder in your external drive, with for example "D:\Docker_AppData" 
- Then delete the entire folder "C:\Users\%USERNAME%\AppData\Local\Docker" 
- And then run: mklink /j "C:\Users\%USERNAME%\AppData\Local\Docker" "D:\Docker_AppData" 
- this folder takes up the most space, however you can do this for other folders if you want 

