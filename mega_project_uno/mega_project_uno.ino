#include <AccelStepper.h>
const int JoyX = A0; // Analog pin of joystick for Body 
const int JoyS = A1; // Analog pin of joystick for Servo
const int JoyY = A2; // Analog pin of joystick for Arm
const int JoyZ = A3; // Analog pin of joystick for Base
const int deadzone = 30;
long receivedMMdistance = 0;
char receivedCommand;
bool newData, runallowed = false;
const int open_sw = 12;
const int close_sw = 13;
const unsigned long debounceDelay = 50;  
unsigned long lastDebounceTime = 0;
int openSwState = HIGH;                 
int closeSwState = HIGH;                 
int lastOpenSwState = HIGH;              
int lastCloseSwState = HIGH;  
int openSwReading, closeSwReading, joyXValue, joyYValue, joyZValue, JoySValue , X, Y, Z, S;
AccelStepper stepper_x(1, 2, 5);
AccelStepper stepper_y(1, 3, 6);
AccelStepper stepper_z(1, 4, 7);
void setup() {
  pinMode(open_sw, INPUT);
  pinMode(close_sw, INPUT);
  digitalWrite(open_sw, HIGH);
  digitalWrite(close_sw, HIGH);
  stepper_x.setMaxSpeed(100.0);
  stepper_y.setMaxSpeed(100);
  stepper_z.setMaxSpeed(100);
  stepper_x.setAcceleration(100);
  stepper_y.setAcceleration(100);
  stepper_z.setAcceleration(100);
  Serial.begin(9600);
}
/////////////////////////////////////////////////////////////
void body_forward() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_x.move(10); 
}
void body_backward() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_x.move(-10); 
}
////////////////////////////////////////////////////////////
void arm_forward() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_y.move(10); 
}
void arm_backward() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_y.move(-10); 
}
//////////////////////////////////////////////////////////
void rotate_left() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_z.move(10); 

}
void rotate_right() {
  runallowed = true;
  receivedMMdistance = 10;
  stepper_z.move(-10); 
}
////////////////////////////////////////////////////////
void servo_up() {
  Serial.println('e');
}
void servo_down() {
  Serial.println('c');
}
//////////////////////////////////////////////////////
void servo_open() {
    Serial.println('d');
}
void servo_close() {
    Serial.println('p');
}
//////////////////////////////////////////////////////////////
void handleOpenSwitch() {
  if (openSwState == LOW && lastOpenSwState == HIGH) {
    servo_open();
  }
}
void handleCloseSwitch() {
  if (closeSwState == LOW && lastCloseSwState == HIGH) {
    servo_close();
  }
}
/////////////////////////////////////////////////////////////
void stop() {
  runallowed = false;
  stepper_x.setCurrentPosition(0); 
  stepper_y.setCurrentPosition(0);
  stepper_z.setCurrentPosition(0); 
  stepper_x.stop();
  stepper_y.stop();
  stepper_z.stop();
}
/////////////////////////////////////////////////////////////
void joystick() {
  openSwReading = digitalRead(open_sw);
  closeSwReading = digitalRead(close_sw);
  joyXValue = analogRead(JoyX);
  joyYValue = analogRead(JoyY);
  joyZValue = analogRead(JoyZ);
  JoySValue = analogRead(JoyS);
  delay(5);
  ///////////////////////////////////////////////
  if (millis() - lastDebounceTime > debounceDelay) {
    lastDebounceTime = millis();
    if (openSwReading != openSwState) {
      openSwState = openSwReading;
      handleOpenSwitch();
    }
    if (closeSwReading != closeSwState) {
      closeSwState = closeSwReading;
      handleCloseSwitch();
    }
  }
  /////////////////////////////////////////////
  lastOpenSwState = openSwReading;
  lastCloseSwState = closeSwReading;
  ////////////////////////////////////////////
  if ((400 < joyXValue) && (joyXValue <= 600))
    X = 0;
  if ((601 <= joyXValue) && (joyXValue <= 1024))
    X = 1; 
  if ((0 <= joyXValue) && (joyXValue <= 399))
    X = -1;
  ///////////////************///////////////
  if ((400 < joyZValue) && (joyZValue <= 600))
    Z = 0;
  if ((601 <= joyZValue) && (joyZValue <= 1024))
    Z = 1; 
  if ((0 <= joyZValue) && (joyZValue <= 399))
    Z = -1;
  ///////////////************////////////////
  if ((400 < joyYValue) && (joyYValue <= 600))
    Y = 0;
  if ((601 <= joyYValue) && (joyYValue <= 1024))
    Y = -1; 
  if ((0 <= joyYValue) && (joyYValue <= 399))
    Y = 1;
  ///////////////************////////////////
  if ((400 < JoySValue) && (JoySValue <= 600))
    S = 0;
  if ((601 <= JoySValue) && (JoySValue <= 1024))
    S = -1; 
  if ((0 <= JoySValue) && (JoySValue <= 399))
    S = 1;
  ///////////////////////////////////////////
  if (X == 1)
    body_forward();
  /////////////////////
  else if (X == -1)
    body_backward();
  /////////////////////
  else if (Y == 1)
    arm_forward();
  /////////////////////
  else if (Y == -1)
    arm_backward();
  /////////////////////
  else if (Z == 1)
    rotate_left();
  /////////////////////
  else if (Z == -1)
    rotate_right();
  ////////////////////
  else if (S == 1)
    servo_up();
  /////////////////////
  else if (S == -1)
    servo_down();
  /////////////////////
  else
    stop(); 
}
////////////////////////////////////////////////////////
void checkSerial(){
  if (Serial.available() > 0) 
  {
    receivedCommand = Serial.read(); 
    newData = true; 
  }
  if(newData == true){
    /////////////////////////////////////////
    if(receivedCommand == 'q'){
      Serial.println("S1"); 
      body_forward();
    }
    //////////////////
    if(receivedCommand == 'w'){
      Serial.println("S1`"); 
      body_backward(); 
    }
    ////////////////////////////////////////////
    if(receivedCommand == 'a'){
      Serial.println("S2"); 
      arm_forward();
    }
    //////////////////
    if(receivedCommand == 's'){
      Serial.println("S2`"); 
      arm_backward();
    }
    //////////////////////////////////////////////
    if(receivedCommand == 'z'){
      Serial.println("S3"); 
      rotate_left(); 
    }
    //////////////////
    if(receivedCommand == 'x'){
      Serial.println("S3`"); 
      rotate_right();
    }
    ////////////////////////////////////////////
    if(receivedCommand == 'e'){
      servo_up();
    }
    //////////////////
    if(receivedCommand == 'c'){
      servo_down();
    }
    //////////////////////////////////////////
    if(receivedCommand == 'p'){
      servo_open();
    }
    //////////////////
    if(receivedCommand == 'd'){
      servo_close();
    }
    ////////////////////////////////////////
    if(receivedCommand == 'f'){
      Serial.println("STOP "); 
      stop();
    }
    ////////////////////////////////////////
  }
  newData = false;
}
//////////////////////////////////////////////////////////////
void continuousRun() 
{
  if (runallowed == true)
  {
    if ((abs(stepper_x.currentPosition()) < receivedMMdistance)||(abs(stepper_y.currentPosition()) < receivedMMdistance)||(abs(stepper_z.currentPosition()) < receivedMMdistance)) //abs() is needed because of the '<'
    {
      stepper_x.run(); 
      stepper_y.run();
      stepper_z.run();
    }
    else 
    {
      runallowed = false; 
    }
  }
  else
  {
    return;
  }
}
//////////////////////////////////////////////////////////////
void loop()
{
  checkSerial();
  continuousRun(); 
  joystick();
}