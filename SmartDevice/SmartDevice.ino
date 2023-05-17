// SD Card Module
#include <SPI.h>
#include <SD.h>

// Real Time Clock (RTC)
#include "RTClib.h"
RTC_Millis rtc;     // Software Real Time Clock (RTC)
DateTime rightNow;  // used to store the current time.

// SD Card - Confirm Pin
#define SDpin 10

void setup() {

  // put your setup code here, to run once:
  
  Serial.begin(9600);  // Open serial communications and wait for port to open:
  while (!Serial) {
    delay(1);  // wait for serial port to connect. Needed for native USB port only
  }

  // SD Card initialisation
  Serial.print("Initializing SD card...");
  if (!SD.begin(SDpin)) {
    Serial.println("initialization failed!");
    while (1)
      ;
  }
}

void loop() {

  // put your main code here, to run repeatedly:

  rotaryPotentiometer();
  servoMotor();
  LDR();
  crashSensor();
  LED_Display();
  piezoButton();
  SolarTracker();

  delay(500);

}

/*

Using the Potentiometer, determines at which bytes the device will start to opearated.
@params none.
@return none.

*/
void rotaryPotentiometer() {

}

/*

If the Servo Motor is activated, rotate the Solar Panel so that it can observe the Sun in multi-direction.
@params none.
@return none.

*/
void servoMotor() {

}

/*

If the LDRs are activated, detects the highest possible light levels.
@params none.
@return none.

*/
void LDR() {

}

/*

If the Crash Sensor being pressed, operates the Solar Panel.
@params none.
@return none.

*/
void crashSensor() {

}


/*

When the Solar Panel started to observing and converting the Sun energies into electricity, shows the amount of it onto a LED displayer.
@params none.
@return none.

*/
void LED_Display() {

}


/*

When the Solar Panel detected where the Sun is, play a confirm sound from the Buzzer.
@params none.
@return none.

*/
void piezoButton() {

}


// https://circuitdigest.com/microcontroller-projects/building-your-own-sun-tracking-solar-panel-using-arduino link to follow on with the project.
// https://circuitdigest.com/microcontroller-projects/arduino-solar-panel-tracker another one.