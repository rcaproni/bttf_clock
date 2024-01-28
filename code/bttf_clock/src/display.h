// display class
// Use a slight altered version of TM1637Display. This changes will allow rtc and TM boards share SCL pin. 

#pragma once
#include <Arduino.h>
#include "myTM1637Display.h"

// pin map
#define DISP_CLK 16
#define DISP_D0 12
#define DISP_D1 14
#define DISP_D2 13
// clock leds
#define LED_AM 4
#define LED_PM 0

// struct for time/data vars
typedef struct{
  uint8_t day;
  uint8_t month;
  uint8_t year;
  uint8_t hour;
  uint8_t min;
} disp_t;


class Display {
  public:
    void printTime(disp_t displayTime); // print time in the displays,m set correct am pm led, update brightness
    void setBrightness(uint8_t bright); // update brightness var
    Display();                          // constructor
  private:
    myTM1637Display disp0;  // display objects
    myTM1637Display disp1;
    myTM1637Display disp2;
    uint8_t dispBright=3;   // brightness var for all displays
};