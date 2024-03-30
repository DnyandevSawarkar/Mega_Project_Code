# Mega_Project_Code
 
➥ Backend:
    ● backend.py        : Get  data from the front end and send it to the esp-01 microcontroller
    ● text.txt          : File that will be read by the esp-01, contains a block controller for the robotic arm

➥ Frontend:
    ● index.html        : The main page of the website where you can write in an input field what command do you want to execute on the robotic arm
    ● styles.css        : Stylesheet of the web page
    ● script.js         : Functions related with the user interface (buttons,blocks,interconnecting link with backend)

➥ Mega Project ESP     : ● ESP-01 code to get the data sent by the backend and send it UNO for excutiong
                          ● Control Servo motors of Gripper according UNO feedbacks 
                          ● Give feedback to UNO  about the execution status of gripper  movements

➥ Mega Project UNO     : ● Uno Code to execute commands received from ESP,
                          ● Controll Stepper Motor of required part
                          ● Send Command to ESP for execution Gripper Movements 