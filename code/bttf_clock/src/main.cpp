// BBTF clock ESP32 code -  Based in the original work of jerome95: https://www.instructables.com/Back-to-the-Future-Lamp-Clock/
// Webserver based on code from here: https://github.com/KrisKasprzak/ESP32_WebPage
// Get time from RTC instead of NTP server. Uses webserver for configuration and time adjustment.
// Author: Rodolfo Caproni
// License: MIT
// Version: 1.0
// Date: 2023-01-28


#include <Arduino.h>

#include "display.h"
#include "rtc.h"
#include "strip.h"
#include "webserver.h"

// switch analog input
#define SWITCH A0

WebServer webserver;
RTC rtc;
disp_t dispTime;

/**
 * Check the status of the switch.
 *
 * @return HIGH if the switch is pressed, LOW if the switch is open
 */
bool check_switch(){
  if(analogRead(SWITCH) > 1000){
    Serial.println("switch pressed\n");
    return HIGH;
  }
  else{
    Serial.println("switch open\n");
    return LOW;
  }
}


/**
 * Function to set up the pins, serial, and webserver.
  */
void setup() {
  // pins setup
  pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output
  pinMode(SWITCH, INPUT);

  // serial setup
  Serial.begin(9600);
  Serial.println("Serial ON");

  // init webserver
  webserver.init();
}


/**
 * This function runs a loop that checks a switch, reads the real-time clock date,
 * prints the time to the display, handles any incoming webserver commands, and
 * then introduces a delay before the loop restarts.
 */
void loop() {
  check_switch();
  dispTime = rtc.readRtcDate();
  delay(500);
  webserver.printTime(dispTime);
  delay(500);
  webserver.handleClient();
  delay(3000);
}
