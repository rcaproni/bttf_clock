Back to the Future clock, ispired by the hork of jerome95: https://www.instructables.com/Back-to-the-Future-Lamp-Clock/?utm_source=newsletter&utm_medium=email

I'm big fan of BTTF trilogy. First project I decided to do when I acquired a 3D printer was the clock designed by jerome95. 
The orignal project use the aestetics from BTTF's Delorean Time Cirtuits. The clock is controleed by an ESP32 Mini and it synchronize time over internet using a NTP client.

For my design I did some changes in the original:

- Case divided in two parts to print in small Ender3 printer: Original case is one piece, but it is bigger then the maximum size of my Ender3 printer. Using SketchUp I divided the case in 2 parts with sizes compatibe with my printer. I created internal pins
  to connect the tho parts with glue.
  ![Alt text](images/divided.png?raw=true "Title")
  
- Display order: I changed the order of the displays to adapt to Brazillian time format: DD:MM YYYY AM/PM HH:MM
- ESP32 board: Original project used an ESP32 Mini. I didn't found it in my local shop so I used a NodeMcu 3.0 instead. The pan was to use the same firmware, but I did many changes at the end.
- Webserver: The original rpoject used a NTP client to syn the time over internet. I ended up implementing an webserver with many configurations for the clock and did not use the NTP. 
- Internal RTC: As there is an webserver, time cn be congifured in it and the RTC takes care of it. The RTC module has a battery to maintain the correct time.
