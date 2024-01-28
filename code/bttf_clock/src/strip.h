// led strip control

#pragma once
#include <Arduino.h>
#include "Adafruit_NeoPixel.h"

// led strip
#define LEDSTRIP 5  // gpio for led strip
#define NUMPIXELS 37  // 36 led plus one "sacrificial" led for voltage level shifter



class Strip {
  public:
    void setColor(uint8_t color);       // set strip color scene
    void setBrightness(uint8_t bright); // set srtip brightness
    void update();                      // update color and brightness
    Strip();                            // constructor
  private:
    uint8_t stripColor = 0;             // default scene color
    uint8_t stripBright = 50;           // defaul brightness
    Adafruit_NeoPixel pixels;           // neopixel object
    void progColor();                   // program color into leds
    void progBrightness();              // program brightness into leds
};







