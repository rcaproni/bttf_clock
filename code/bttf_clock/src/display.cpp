#include "display.h"

//Display class. Handles all the displays and associated functions


// Constructor code for TM1637 displays
// Initialize 3 displays
Display::Display() : disp0(DISP_CLK, DISP_D0), 
                     disp1(DISP_CLK, DISP_D1),
                     disp2(DISP_CLK, DISP_D2){
  
  
}


// print time in the display
void Display::printTime(disp_t displayTime){
  // rtc format is 24 hour
  // after noon, switch on PM led
  // adjust hour to be printed
  if(displayTime.hour == 12){
    pinMode(LED_AM, OUTPUT);
    pinMode(LED_PM, OUTPUT);
    digitalWrite(LED_AM, HIGH);
    digitalWrite(LED_PM, LOW);
  }
  if(displayTime.hour > 12){
    pinMode(LED_AM, OUTPUT);
    pinMode(LED_PM, OUTPUT);
    digitalWrite(LED_AM, HIGH);
    digitalWrite(LED_PM, LOW);
    displayTime.hour = displayTime.hour-12;
  }
  //    
  else{
    pinMode(LED_AM, OUTPUT);
    pinMode(LED_PM, OUTPUT);
    digitalWrite(LED_AM, LOW);
    digitalWrite(LED_PM, HIGH);
  }

  // print values in the displays
  disp0.showNumberDecEx(displayTime.day,0b01000000,true,2,0);
  disp0.showNumberDecEx(displayTime.month ,0b01000000,true,2,2);
  disp1.showNumberDecEx(displayTime.year + 2000, 0b00000000,true);  //adjust year
  disp2.showNumberDecEx(displayTime.hour,0b01000000,true,2,0);
  disp2.showNumberDecEx(displayTime.min,0b01000000,true,2,2);

  // debug
  Serial.println("Display::printTime date uint8_t:");
  Serial.printf("h %d m %d d %d m %d y %d\n", displayTime.hour, 
                                              displayTime.min, 
                                              displayTime.day, 
                                              displayTime.month, 
                                              displayTime.year);
  
  // uipdate brightness
  disp0.setBrightness(dispBright);
  disp1.setBrightness(dispBright);
  disp2.setBrightness(dispBright);
}


// update brightness for the displays
void Display::setBrightness(uint8_t bright){
  Serial.println("Display::setBrightness = ");
  Serial.println(bright);
  disp0.setBrightness(bright);
  disp1.setBrightness(bright);
  disp2.setBrightness(bright);
}


