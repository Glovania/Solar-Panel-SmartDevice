//SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.


// Servo Motor
#include <Servo.h>
Servo myservo;

// Crash Sensor / Button
#define crashSensor 7

// LDR direction detacting
int eastLDR = 0;
int westLDR = 1;

// Default direction for the Solar Cell
int east = 0;
int west = 0;

// Debug 
int error = 0;

int calibration = 600;
int servoposition = 90;


void setup() {
  //Attach the Sevo to pin 9 in the Arduino Uno board.
  myservo.attach(9);
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
    while (!Serial) {
    // Wait for serial port to connect. Needed for native USB port only
      delay(1);
  // Input crashSensor button
  pinMode(crashSensor, INPUT);
  }

// SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    while (1);
  }

// Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
}


void loop() {
  // Determine the value of Crash Sensor button. 1 is activate, while 0 is deactivate.
  int crashSensorValue = digitalRead(crashSensor);
  // Solar Tracker function
  east = calibration + analogRead(eastLDR);
  west = analogRead(westLDR);
  if (east < 350 && west < 350)
  {
    while (servoposition <= 150)
    {
      servoposition++;
      myservo.write(servoposition);
      delay(100);
    }
  }

  error = east - west;
  if (error > 15)
  {
    if (servoposition <= 150)
    {
      servoposition++;
      myservo.write(servoposition);
    }
  }

  else if (error < -15)
  {
    if (servoposition > 20)
    {
      servoposition--;
      myservo.write(servoposition);
    }
  }
  delay(100);
}


void logEvent(String dataToLog) {
  DateTime rightNow = rtc.now();
}