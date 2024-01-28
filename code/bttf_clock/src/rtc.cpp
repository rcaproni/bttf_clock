#include "rtc.h"

// Constructor code for DS1307
RTC::RTC() : i2c(RTC_SDA, RTC_SCL, true) {
  
}


// program RTC
void RTC::progRtcDate(disp_t displayTime){
  uint8_t temp;
  Serial.println("RTC::progRtcDate");
  if (!i2c.i2c_init()) 
    Serial.println("I2C init error");
  else
    Serial.println("I2C OK");
  delayMicroseconds(500);

  

  // program
  i2c.i2c_start(RTC_ADDR | I2C_WRITE);
  i2c.i2c_write(0); // seconds, ch=0
  i2c.i2c_write(2);

  //i2c.i2c_write(1);
  i2c.i2c_write((displayTime.min/ 10) << 4 | (displayTime.min % 10));

  // hour
  temp = ((displayTime.hour/ 10) << 4 | (displayTime.hour % 10));
  temp = temp & 0xbf; // clear bit 6 - 24h time
  //i2c.i2c_write(2);
  i2c.i2c_write(temp);

  //i2c.i2c_write(3);
  i2c.i2c_write(1); // DOW

  //i2c.i2c_write(4);
  i2c.i2c_write((displayTime.day/ 10) << 4 | (displayTime.day % 10));

  //i2c.i2c_write(5);
  i2c.i2c_write((displayTime.month/ 10) << 4 | (displayTime.month % 10));

  //i2c.i2c_write(6);
  i2c.i2c_write((displayTime.year/ 10) << 4 | (displayTime.year % 10));

  //i2c.i2c_write(7);
  //i2c.i2c_write(144);// 1Hz
  i2c.i2c_write(145);// 4KHz

  i2c.i2c_stop();

  Serial.println("BCD data");
  Serial.printf("h %x m %x d %x m %x y %x\n", temp, 
                                              (displayTime.min/ 10) << 4 | (displayTime.min % 10),
                                              (displayTime.day/ 10) << 4 | (displayTime.day % 10),
                                              (displayTime.month/ 10) << 4 | (displayTime.month % 10),
                                              (displayTime.year/ 10) << 4 | (displayTime.year % 10)
                                              );
                                              

}

// read RTC
disp_t RTC::readRtcDate(){
  uint8_t  temp;
  disp_t displayTime;
  Serial.println("RTC::readRtcDate");
  if (!i2c.i2c_init()) 
    Serial.println("I2C init error");
  else
    Serial.println("I2C OK");
  delayMicroseconds(500);

  // read
  i2c.i2c_start(RTC_ADDR | I2C_WRITE);
  // base address 0
  i2c.i2c_write(0);
  
  i2c.i2c_rep_start(RTC_ADDR | I2C_READ);
  
  temp = i2c.i2c_read(0); //sec
  Serial.println(temp);
  
   

  displayTime.min = bcdToUint8(i2c.i2c_read(0));
  displayTime.hour = bcdToUint8(i2c.i2c_read(0));
  temp = i2c.i2c_read(0); //dow
  displayTime.day = bcdToUint8(i2c.i2c_read(0));
  displayTime.month = bcdToUint8(i2c.i2c_read(0));
  displayTime.year = bcdToUint8(i2c.i2c_read(1));
  i2c.i2c_stop();

  Serial.println("RTC::readRtcDate(): date uint8_t:");
  Serial.printf("h %d m %d d %d m %d y %d\n", displayTime.hour, 
                                              displayTime.min, 
                                              displayTime.day, 
                                              displayTime.month, 
                                              displayTime.year);

  return displayTime;
}

uint8_t RTC::bcdToUint8(uint8_t bcdValue){
  return(((bcdValue >> 4) & 0x0F) * 10) + (bcdValue & 0x0F);
}
