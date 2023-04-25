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

MAC: 

Download XQuartz: https://www.xquartz.org/  

Linux:  

* enter `docker pull ehiga/proofofconcept`
* `sudo docker run -it --name robosub ehiga/proofofconcept`
* `gazebo` 

Type this command to make sure your container works 

You can use this command to start up container after: `docker start -ai robosub`

-------------------------------- 

- How to put a docker container on your external drive (from: How could I install Docker for Windows on drive E: (my SSD C: is full)? , see radicalshift’s post) 

- In copy the contents of "C:\Users\%USERNAME%\AppData\Local\Docker" to a folder in your external drive, with for example "D:\Docker_AppData" 

- Then delete the entire folder "C:\Users\%USERNAME%\AppData\Local\Docker" 

- And then run: mklink /j "C:\Users\%USERNAME%\AppData\Local\Docker" "D:\Docker_AppData" 

- this folder takes up the most space, however you can do this for other folders if you want 

