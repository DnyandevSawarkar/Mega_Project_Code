# Mega_Project_Code
# Name : Design and Development of Robotic ARM for Educational Purpose.
## Description
* Creating Platforms for Student having interest in Robotics or Cording.
* Platform to teach and demonstrate Ladder Coding.
* Controlling Robotic Arm using Joystick's to attract Small Class Student's.
## Information
➥ Application Creator:
 * icon.rc                      : Icon file path container for icon.res.
 * icon.res                     : Icon file for the application.
 * icon256x256.ico              : Icon file
 * Robotic Arm Controller.c     : Main C file of the application.
 * Robotic Arm Controller.exe   : Main executable file of the application.

➥ Backend:
 *    backend.py        : Get  data from the front end and send it to the esp-01 microcontroller.
 *    text.txt          : File that will be read by the esp-01, contains a block controller for the robotic arm.

➥ Body Parts STL:
 * STL Files Body and Gripper parts of the robotic arm.

➥ Frontend:
 *    index.html        : The main page of the website where you can write in an input field what command do you want to execute on the robotic arm.
 *    styles.css        : Stylesheet of the web page.
 *    script.js         : Functions related with the user interface (buttons,blocks,interconnecting link with backend.

➥ Mega Project ESP: 
 *    ESP-01 code to get the data sent by the backend and send it UNO for excutiong.
 *    Control Servo motors of Gripper according UNO feedbacks .
 *    Give feedback to UNO  about the execution status of gripper  movements.

➥ Mega Project UNO: 
 *    Uno Code to execute commands received from ESP.
 *    Controll Stepper Motor of required part.
 *    Send Command to ESP for execution Gripper Movements.
 *    Monitor Joystick and Robotic Arm.

➥ Py_Module_Installer:
 *    req.c            : C code which contains list of python module required for backend.
 *    req.exe          : Excutalbe exe file which will install all the required python module.


## How To Run
* Install Python 3.7.3.
* Clone git repository.
* Install all the required python module using req.exe file.
* Power on Roboic Arm Control Unit
* Open Robotic Arm Controller.exe
* Connect System to NodeMCU Wi-Fi 
    * SSID : Robotic_Arm 
    * Password : Robotic_Arm.

## Testing
### 1) Software Application.
* Create Ladder Code to Controll Robotic Arm and Press Submite Button.
* Observe Robotic Arm Movement.

### 2) Hardware Application 
* Controll Robotic Arm by Using Joystick's.

## Pictures
* Robotic Arm
![alt text](https://github.com/[username]/[reponame]/blob/[branch]/image.jpg?raw=true)

* Pick and Place operation 
![alt text](https://github.com/[username]/[reponame]/blob/[branch]/image.jpg?raw=true)