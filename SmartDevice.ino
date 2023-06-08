// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;                   // Software Real Time Clock (RTC).
DateTime rightNow;                // used to store the current time.


// Servo Motor
#include <Servo.h>
Servo myservo;

#define crashSensor         7     // Define crash sensor.
#define LDR1                A0    // Define east LDR (or first LDR).
#define LDR2                A1    // Define west LDR (or second LDR).
#define potentiometer       A3    // Define potentiometer.

#define error               10    // Define error value of LDRs whether it goes below than 10.
int servoStartingPosition = 90;   // Get the default angle for the Servo motor to start rotating the Solar Cell.


void setup() {
  myservo.attach(9);                                                // Attach the Servo to pin 9 on the Arduino Uno ReV3 board.
  pinMode(crashSensor, INPUT);                                      // Input Crash Sensor.
  pinMode(LDR1, INPUT);                                             // Input east LDR (or first LDR).
  pinMode(LDR2, INPUT);                                             // Input west LDR (or second LDR).
  pinMode(potentiometer, INPUT);                                    // Input Potentiometer.

  Serial.begin(9600);                                               // Open serial communications and wait for port to open.
    while (!Serial) {
      delay(1);                                                     // Wait for serial port to connect. Needed for native USB port only.
  }


// Real Time Clock (RTC)
  rtc.begin(DateTime(F(__DATE__), F(__TIME__)));
  Serial.println("initialization done.");
  logEvent("System Initialisation...");
}


void loop() {
  activePot();
  activeCrashSensor();                                              // Loops the crashSensor function.
  solarTracker();                                                   // Loops the SolarTracker function.
  delay(1000);                                                      // Wait for 1000 miliseconds = 1 second.
// }


void logEvent(String dataToLog) {
  DateTime rightNow = rtc.now();
}


void solarTracker() {
  int LDRvalue1 = analogRead(LDR1);                                 // Get the first LDR sensor value.
  int LDRvalue2 = analogRead(LDR2);                                 // Get the second LDR sensor value.

  int compareValue1 = abs(LDRvalue1 - LDRvalue2);                   // Get the difference between first and second LDRs' values.
  int compareValue2 = abs(LDRvalue2 - LDRvalue1);                   // Get the difference between second and first LDRs' values.

  if ((compareValue1 <= error) || (compareValue2 <= error)) {       // Check both of the comparable values with error values in case that one of them got the value below the error values.
    Serial.println("Invalid value");                                // Debugging.

  } else {
    if (LDRvalue1 > LDRvalue2) {                                    // Check if the value of the first LDR is higher than second LDR.
    servoStartingPosition = --servoStartingPosition;                // Decrease the fixed angle for Servo Motor attached with Solar Cell by 1 value.
    }
    if (LDRvalue1 < LDRvalue2) {                                    // Check if the value of the first LDR is lower than second LDR.
    servoStartingPosition = ++servoStartingPosition;                // Increase the fixed angle for Sevo Motor attached with Solar Cell by 1 value.
    } 
  }

  myservo.write(servoStartingPosition);                             // Write values on the servo motor.
  delay(80);                                                        // Wait for 80 miliseconds.
}

void activePot() {
  int potentiometerValue = analogRead(potentiometer);               // Get the value of the potentiometer.
}


void activeCrashSensor() {
  int crashSensorValue = digitalRead(crashSensor);                  // Get the value of Crash Sensor button. 1 is activate, while 0 is deactivate.
} 