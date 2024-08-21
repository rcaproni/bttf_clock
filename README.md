# Back to the Future clock

  ![Alt text](images/front.jpg?raw=true "Title")

## Based in the design of jerome95: https://www.instructables.com/Back-to-the-Future-Lamp-Clock/?utm_source=newsletter&utm_medium=email

I'm big fan of BTTF trilogy. First project I decided to do when I acquired a 3D printer was the clock designed by jerome95. 
The orignal project use the aestetics from BTTF's Delorean Time Cirtuits. The clock is controleed by an ESP32 Mini and it synchronize time over internet using a NTP client.

For my design I did some changes in the original:

- Case divided in two parts to print in small Ender3 printer: Original case is one piece, but it is bigger then the maximum size of my Ender3 printer.
  Using SketchUp I divided the case in 2 parts with sizes compatibe with my printer. I created internal pins to connect the tho parts with glue.
  The STL files fo edit case can be found in the 3d folder.
  
  ![Alt text](images/divided.png?raw=true "Title")
  
- Display order: I changed the order of the displays to adapt to Brazillian time format: DD:MM YYYY AM/PM HH:MM
- ESP32 board: Original project used an ESP32 Mini. I didn't found it in my local shop so I used a NodeMcu 3.0 instead. The plan was to use the same firmware, but I did many changes at the end.
- Internal RTC: As there is an webserver, time can be congifured in it and the RTC takes care of it. The RTC module has a battery to maintain the correct time. I did small changes in the SlowSoftI2CMaster library to make it work in my hardware. Small delays added to i2c_init and i2c_start functions to improve I2C communication.

  ![Alt text](images/display_case.jpg?raw=true "Title")

- Added A sacrificial pixel to the led string. https://hackaday.com/2017/01/20/cheating-at-5v-ws2812-control-to-use-a-3-3v-data-line/

  ![Alt text](images/led_case.jpg?raw=true "Title")
  
- Webserver: The original rpoject used a NTP client to syn the time over internet. I ended up implementing an webserver with many configurations for the clock and did not use the NTP. Webserver based in Kris Kasprzak code https://github.com/KrisKasprzak/ESP32_WebPage
  - The configuration of the time and date is done by, first, clicking in the Get Local Time button. This will fill the fields with values of the current time in the device webserver is being accessed. After, clicking in
  - "Prog RTC Time" button will program the RTC module with the local time. Button "Get RTC Time" will get the curret time by RTC.
  - Led bightness and Display brightess sliders will change the brighness of the led strip and the time displays.
  - Scene setup is a TODO. The objective is to change the color and brightness nf the led strip according to current time.
  
  

![Alt text](images/webserver.png?raw=true "Title")
 

