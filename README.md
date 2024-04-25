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

## Hardware Configuration
### UNO
* D12  : Joystick 1 Switch
* D11  : Joystick 1 Switch ( Z+ pin of CNC Shield)
* A0   : Joystick 1 Vx
* A1   : Joystick 1 Vy
* A2   : Joystick 2 Vx
* A3   : Joystick 2 Vy
* GND  : Joysticks GND
* 5V   : Joysticks VCC

### NodeMCU
* D4   : Servo 1 Signal (Gripper Body)
* D3   : Servo 2 Signal (Gripper Hands)
* GND  : Servos GND
* 5V   : Servos VCC

### Serial Communication
* UNO RX -> TX ESP
* ESP RX -> TX UNO

### Power Supply
* 230V AC to
   * 12V 5Amp. DC for CNC Shield
   * 9V 1.5Amp. DC for UNO Power Jack
      * 9V to 5V (7805) for NodeMCU Vin

➥ Note : Use separate power source for Joystcks and Servos for proper Working
* Servo 5V from 7805
* Joystick's 5V from CNC Shield 

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
### Robotic Arm
![Final_Arm](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/5ceea629-4549-4ae4-bf29-42244f09ffbf)

![arm_right](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/917d1e75-4a56-4d27-aaf6-94bdaab04ea9)

![arm_left](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/d2467ff9-aef9-4def-b1d8-e327f14be0ac)


### Pick and Place operation 
![pick_place](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/c1262846-9d40-4224-8066-c5a7d9a06bc4)

### Web Dashboard
![Web Page](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/13e069b8-6bb9-43ed-ad40-7cef5e9f2e31)


### Control Unit
![control_unit](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/28810ede-4af8-4361-b89d-ecb74c230598)


### Block Diagram 
![Robotic arm block diagram](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/89051b3e-5c0b-46c1-85fb-522b4700d66f)


### FlowChart
#### Hardware - Joystick Control
![joystick ](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/8b434297-e5df-4d80-ae21-737f76a7f802)

#### Software - Web Dashboard Control
![web_flowchart ](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/8cff66b0-fc43-4432-bc10-455128d4ad6f)


### Circuit Schematic and PCB Board Connection
#### Schematic
![circuit](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/5c19b15a-6d73-494b-84ca-46671b6ae98c)

#### Top Layer
![Top_Layer](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/3ce37f41-615b-465f-a597-6a06917f58b3)

#### Buttom Layer
![Bottom_layer](https://github.com/DnyandevSawarkar/Mega_Project_Code/assets/79653351/a3045857-0c02-4f83-8ee0-639cf17d64b1)

* Note : Circuit Schematic and PCB Board Connection are only for understanding connection their no need of this PCB CNC Shield get directly attached to UNO and for mounting NodeMCU we can create ZeroPCB based PCB which directly connects to CNC shield and works on external supply obtained from 7805 as an input for servo and NodeMCU
