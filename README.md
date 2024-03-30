# Mega_Project_Code
## Information
➥ Backend:
 *    backend.py        : Get  data from the front end and send it to the esp-01 microcontroller
 *    text.txt          : File that will be read by the esp-01, contains a block controller for the robotic arm

➥ Frontend:
 *    index.html        : The main page of the website where you can write in an input field what command do you want to execute on the robotic arm
 *    styles.css        : Stylesheet of the web page
 *    script.js         : Functions related with the user interface (buttons,blocks,interconnecting link with backend)

➥ Mega Project ESP     : 
 *    ESP-01 code to get the data sent by the backend and send it UNO for excutiong
 *    Control Servo motors of Gripper according UNO feedbacks 
 *    Give feedback to UNO  about the execution status of gripper  movements

➥ Mega Project UNO     : 
 *    Uno Code to execute commands received from ESP,
 *    Controll Stepper Motor of required part
 *    Send Command to ESP for execution Gripper Movements
 *    Monitor Joystick and Robotic Arm 

## How To Run
* Open indec.html
* Run Backend.py file
* Connect UNO to System
* Connect System to ESP-01 Wi-Fi : Robotic_Arm Password : Robotic_Arm
* Connect External Power Supply to CNC Shield (12V-5Amp)

## Testing
### 1) Software Application 
* Create Ladder Code to Controll Robotic Arm and Press Submite Button
* Observe Robotic Arm Movement

### 2) Hardware Application 
* Controll Robotic Arm by Using Joystick's 
