#ifndef FASTLED_DEFS_H
#define FASTLEF_DEFS_H
#pragma once

//#define CLARINET
//#define SAX
//#define GLOVE
#define GUITAR

#ifdef SAX
#define DATA_PIN    21
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    119
#define DATA_PIN2   12
#define LED_TYPE2    WS2812B
#define COLOR_ORDER2 RGB
#define NUM_LEDS2    30
#define LED_BRIGHTNESS  85
#endif

#ifdef CLARINET
#define DATA_PIN    4
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    62
#define DATA_PIN2   12
#define LED_TYPE2    WS2812B
#define NUM_LEDS2  24
#define COLOR_ORDER2 GRB
#define LED_BRIGHTNESS  120
#endif

#ifdef GUITAR
#define DATA_PIN    12
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    144
#define LED_BRIGHTNESS  90
#endif


#ifdef GLOVE
#define DATA_PIN    12
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define NUM_LEDS    24
#define LED_BRIGHTNESS  120
#endif



CRGB leds[NUM_LEDS];
CRGB snapshotLeds[NUM_LEDS]; ; //for snapshot

#ifdef SAX
#include "CRGBW.h"
CRGBW leds2[NUM_LEDS];
CRGB * leds2RGB = (CRGB *)&leds2[0];
#endif

//Helper functions
void setBrightnessFactor(float value)
{
  FastLED.setBrightness((int)(value * 255));
}

void setFullColor(CRGB color)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = color;
    #ifdef SAX
     leds2[i] = CRGBW(leds[i].r, leds[i].g, leds[i].b, 0);
     #endif
  }

  FastLED.show();
}

void setRange(int startIndex, int endIndex, CRGB color, bool unique = false)
{
  if (unique) FastLED.clear();

  if (startIndex > endIndex)
  {
    FastLED.show();
    return;
  }

  if (startIndex < 0) startIndex = 0;
  if (startIndex >= NUM_LEDS) startIndex = NUM_LEDS - 1;
  if (endIndex < 0) endIndex = 0;
  if (endIndex >= NUM_LEDS) endIndex = NUM_LEDS - 1;

  for (int i = startIndex; i <= endIndex; i++)
  {
    leds[i] = color;
     #ifdef SAX
     leds2[i] = CRGBW(leds[i].r, leds[i].g, leds[i].b, 0);
     #endif
  }

  FastLED.show();
}

void setLed(int index, CRGB color, bool unique = false)
{
  if (unique) FastLED.clear();

  if (index < 0 || index >= NUM_LEDS)
  {
    FastLED.show();
    return;
  }

  leds[index] = color;
   #ifdef SAX
   leds2[index] = CRGBW(leds[index].r, leds[index].g, leds[index].b, 0);
   #endif
  FastLED.show();
}

void simpleSetLed(int index, CRGB color)
{
  leds[index] = color;
   #ifdef SAX
   leds2[index] = CRGBW(leds[index].r, leds[index].g, leds[index].b, 0);
   #endif
}


//Helper
int getRandomNumber(int startNum, int endNum) {
  randomSeed(ESP.getEfuseMac());
  return random(startNum, endNum);
}

void initSnapshot()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    snapshotLeds[i] = CHSV(getRandomNumber(0, 255), 255, 255);
  }
}

void takeSnapshot()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    snapshotLeds[i] = CRGB(leds[i]);
  }
}

void showSnapshot()
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    leds[i] = CRGB(snapshotLeds[i]);
  }
}

#endif
