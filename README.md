# Back to the Future clock

  ![Alt text](images/front.jpg?raw=true "Title")

Based on the design by jerome95 from [Instructables](https://www.instructables.com/Back-to-the-Future-Lamp-Clock/?utm_source=newsletter&utm_medium=email), I took on my first 3D printing project: a clock inspired by the *Back to the Future* DeLorean Time Circuits. This clock is controlled by an ESP32 Mini and syncs the time over the internet using an NTP client.

I'm a big fan of the BTTF trilogy. The first project I decided to tackle when I acquired a 3D printer was the clock designed by jerome95. The original project uses the aesthetics of BTTF's DeLorean Time Circuits. The clock is controlled by an ESP32 Mini and synchronizes the time over the internet using an NTP client.

For my design, I made some changes to the original:

- **Case modification for small printers**: The original case was too large for my Ender3, so I divided it into two parts using SketchUp. I added internal pins to ensure the two halves could be glued securely. The modified STL files are available in the 3D folder.
  
  ![Alt text](images/divided.png?raw=true "Title")
  
- Display order: I changed the order of the displays to adapt to the Brazilian time format: DD:MM YYYY AM/PM HH:MM
- ESP32 board: The original project used an ESP32 Mini, but I couldn’t find it at my local shop, so I used a NodeMcu 3.0 instead. Although I planned to use the same firmware, I ended up making many changes.
- Internal RTC: Since there is a web server, the time can be configured through it, and the RTC maintains the correct time. The RTC module has a battery to keep the time accurate. I made small changes to the SlowSoftI2CMaster library to make it work with my hardware, adding slight delays to the i2c_init and i2c_start functions to improve I2C communication.

  ![Alt text](images/display_case.jpg?raw=true "Title")

- Added A sacrificial pixel to the led string. https://hackaday.com/2017/01/20/cheating-at-5v-ws2812-control-to-use-a-3-3v-data-line/

  ![Alt text](images/led_case.jpg?raw=true "Title")
  
- Webserver: The original project used an NTP client to sync the time over the internet. I ended up implementing a web server with many configuration options for the clock and did not use the NTP. The webserver based in Kris Kasprzak code https://github.com/KrisKasprzak/ESP32_WebPage
  - The configuration of the time and date is done by first clicking the "Get Local Time" button. This will fill the fields with the current time from the device where the web server is being accessed. Then, clicking the "Prog RTC Time" button will program the RTC module with the local time. The "Get RTC Time" button will retrieve the current time from the RTC.
  - The LED brightness and display brightness sliders will adjust the brightness of the LED strip and the time displays.
  - Scene Setup is a TODO; the goal is to change the color and brightness of the LED strip according to the current time.
  
  

![Alt text](images/webserver.png?raw=true "Title")
 

