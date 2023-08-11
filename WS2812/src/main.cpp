#include <Arduino.h>
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 6
#define DATA_PIN 2
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];

void setup() { 
     FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);  // GRB ordering is assumed
}

void loop() {

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Brown;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Black;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Red;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Green;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Blue;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Yellow;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Magenta;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Cyan;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Orange;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Purple;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::White;
  FastLED.show();
}
delay(750);

for(int i=0;i<=5;i++){
  leds[i] = CRGB::Black;
  FastLED.show();
}
delay(750);
//-----------------------------------------------------------------------------------------
  // leds[0] = CRGB::Brown;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Red;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Green;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Blue;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Yellow;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Magenta;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Cyan;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Orange;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Purple;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::White;
  // FastLED.show();
  // delay(500);

  // leds[0] = CRGB::Black;
  // FastLED.show();
  // delay(500);
}