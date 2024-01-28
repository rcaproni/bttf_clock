#include "strip.h"

// Constructor code for led strip
Strip::Strip() : pixels(NUMPIXELS, LEDSTRIP, NEO_GRB + NEO_KHZ400){
  pinMode(LEDSTRIP, OUTPUT);
}

// update led strip
void Strip::update(){
  Serial.println("Strip::Update");
  progColor();  
  progBrightness();
  pixels.show();  // neopixel update
}

void Strip::setColor(uint8_t color){
  stripColor = color;
  Serial.println("Strip::setColor: ");
  Serial.println(stripColor);
}

void Strip::setBrightness(uint8_t bright){
  stripBright = bright;
  Serial.println("Strip::setBrightness: ");
  Serial.println(bright);
  Serial.println(stripBright);
}



// led strip scene
// many scenes are hard coded.
// set the variavle stripColor will change the scene
void Strip::progColor(){
  // GRB
  //stripColor=0;
  Serial.println("Strip::progColor = ");
  Serial.println(stripColor);
  pixels.setPixelColor(0, pixels.Color(0, 0, 0)); // level shifter pixel. always off
  switch (stripColor) {
    case 0: 
      for(int i=1; i<13;i++){
        pixels.setPixelColor(i, pixels.Color(255,0,0));
      }
      for(int i=13; i<25;i++){
        pixels.setPixelColor(i, pixels.Color(160,160,0));
      }
      for(int i=25; i<37;i++){
        pixels.setPixelColor(i, pixels.Color(255,0,0));
      }
      //pixels.show();
    break;

    case 1:
      for(int i=1; i<13;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,255));
      }
      for(int i=13; i<25;i++){
        pixels.setPixelColor(i, pixels.Color(200,250,255));
      }
      for(int i=24; i<37;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,255));
      }
      //pixels.show();
    break;

    case 2:
      pixels.clear();
      for(int i=0; i<12;i++){
        pixels.setPixelColor(i, pixels.Color(255,0,10));
      }
      for(int i=13; i<25;i++){
        pixels.setPixelColor(i, pixels.Color(0,10,255));
      }
      for(int i=24; i<37;i++){
        pixels.setPixelColor(i, pixels.Color(255,0,10));
      }
      //pixels.show();
    break;

    case 3:
      pixels.clear();
      for(int i=0; i<37;i++){
        pixels.setPixelColor(i, pixels.Color(0,0,0));
      }
      //pixels.show();
      break;

    }
}


void Strip::progBrightness(){
  Serial.println("Strip::progBrightness = ");
  Serial.println(stripBright);
  pixels.setBrightness(stripBright);
  //pixels.show();
}


