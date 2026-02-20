# SmokeDetection-Alert-embedded
Smoke detection and alert system using Microcontrollers and Embedded C
# Smoke Detection and Alert System

# Description
This project implements a *microcontroller-based smoke and fire detection system*.  
It detects smoke or gas in a room, triggers alarms using LEDs and buzzer, and automatically ventilates the room to reduce fire hazards.  
This embedded system enhances safety and provides an automated response to fire emergencies.

# Features
- Real-time smoke/gas detection  
- Visual alert using LEDs  
- Audio alert using buzzer  
- Automatic ventilation on detecting fire  
- Embedded system implementation for fast and reliable response  

# Hardware / Components Used
- Microcontroller (Arduino)  
- Smoke / Gas sensor (MQ-2 )  
- LEDs (Red / Yellow)  
- Buzzer  
- Servo motor/ Fan for ventilation  
- Resistors  
- Breadboard / Connecting wires  

# Software / Tools Used
- Arduino IDE / Embedded C  
- Simulation software (Wokwi Simulator)  

# Working
1. Smoke / Gas sensor continuously monitors the room environment.  
2. If smoke is detected:  
   - LEDs light up  
   - Buzzer sounds an alarm  
3. Automatic ventilation is activated to reduce smoke and prevent fire damage.  
4. System continues to monitor the room for safety.  

# Code
The Arduino / Embedded C code for this project is available in smoke_detection_system.ino.  

// Example snippet
#include <Servo.h>
int smokeSensor = A0; 
int buzzer = 9; 
int redLed = 13;
Servo fan;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(redLed, OUTPUT);
  fan.attach(6);
  Serial.begin(9600);
}

void loop() {
  int smokeLevel = analogRead(smokeSensor);
  Serial.println(smokeLevel);
  
  if(smokeLevel > 300) { // threshold
    digitalWrite(redLed, HIGH);
    digitalWrite(buzzer, HIGH);
    fan.write(90); // ventilate
  } else {
    digitalWrite(redLed, LOW);
    digitalWrite(buzzer, LOW);
    fan.write(0); // fan off
  }
  delay(1000);
}
