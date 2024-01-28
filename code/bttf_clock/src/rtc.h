#pragma once
#include <Arduino.h>
#include <mySlowSoftI2CMaster.h>
#include "display.h" // for typedef disp_t

// RTC
// RTC clk is shared with display clock pin
#define RTC_SDA 2
#define RTC_SCL 16
#define RTC_ADDR 0xD0 // DS1307




class RTC {
  public:
    RTC();
    void progRtcDate(disp_t displayTime);
    disp_t readRtcDate();

  private:
    //SlowSoftI2CMaster i2c;
    mySlowSoftI2CMaster i2c;
    uint8_t bcdToUint8(uint8_t bcdValue);
};