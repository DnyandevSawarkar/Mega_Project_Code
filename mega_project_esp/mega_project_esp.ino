#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>
const char *ssid = "Robotic_Arm"; // SSID of the ESP-01 in SoftAP mode
const char *password = "Group#23"; // Password for the SoftAP mode
ESP8266WebServer server(80);
Servo myServo;
const int servoPin = 2; // D4
int servo_index = 0;
int servo_values[] = {10, 20, 35, 45, 55, 60, 75, 80, 95, 110, 120, 130, 145, 150};
int servo_values_count = sizeof(servo_values) / sizeof(servo_values[0]);
Servo myServo1;
const int servoPin1 = 0; // D3
int servo_index1 = 0;
int servo_values1[] = {55, 60, 65, 70, 75, 80, 95, 110, 120, 130, 145, 165, 175};
int servo_values1_count = sizeof(servo_values1) / sizeof(servo_values1[0]);
void setup() {
  Serial.begin(9600);
  delay(10);
  WiFi.softAP(ssid, password);
  server.on("/receive", HTTP_POST, handleReceive);
  server.begin();
  myServo.attach(servoPin);
  myServo.write(servo_values[servo_index]);
  myServo1.attach(servoPin1);
  myServo1.write(servo_values1[servo_index1]);
}

void loop() {
  server.handleClient();
  if (Serial.available() > 0) {
    char receivedCommand = Serial.read();
    // Serial.println(receivedCommand);
    if (receivedCommand == 'e') {
      Serial.println(" U");
      servo_up();
    }
    if (receivedCommand == 'c') {
      Serial.println(" D");
      servo_down();
    }
    if (receivedCommand == 'd') {
      Serial.println(" O");
      servo_open();
    }
    if (receivedCommand == 'p') {
      Serial.println(" B");
      servo_close();
    }
  }
}

void handleReceive() {
  if (server.hasArg("content")) {
    String content = server.arg("content");
    Serial.println(content);
  } else {
    Serial.println("NULL");
  }
  server.send(200, "text/plain", "Content received successfully.");
}

void servo_up() {
  if (servo_index < servo_values_count - 1) {
    servo_index++;
    servo_write(servo_values[servo_index]);
  } else {
    Serial.println("U L R");
  }
}

void servo_down() {
  if (servo_index > 0) {
    servo_index--;
    servo_write(servo_values[servo_index]);
  } else {
    Serial.println("L L R");
  }
}

void servo_write(int ang) {
  myServo.write(ang);
  Serial.println(ang);
}

void servo_open() {
  if (servo_index1 < servo_values1_count - 1) {
    servo_index1++;
    servo_write1(servo_values1[servo_index1]);
  } else {
    Serial.println("U L R");
  }
}

void servo_close() {
  if (servo_index1 > 0) {
    servo_index1--;
    servo_write1(servo_values1[servo_index1]);
  } else {
    Serial.println("L L R");
  }
}

void servo_write1(int ang) {
  myServo1.write(ang);
  Serial.println(ang);
}
