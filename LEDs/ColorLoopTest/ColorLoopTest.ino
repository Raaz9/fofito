/**
 * Modified  version based on the MakeBlock official libraries 
 * Copyright (C), 2012-2016, MakeBlock
 */
#include "MeAuriga.h"
 
//#define RGBLED_PORT PORT_6
#define RGBLED_PIN                          44

MeRGBLed led;

float j, f, k;

void setup()
{
#ifdef RGBLED_PORT
led.reset(RGBLED_PORT);
#else
led.setpin(RGBLED_PIN);
#endif
}

void loop()
{
  color_loop();
}

void color_loop()
{
  for(uint8_t t = 1; t < 15; t++)
  {
    uint8_t red	= 64 * (1 + sin(t / 2.0 + j / 4.0) );
    uint8_t green = 64 * (1 + sin(t / 1.0 + f / 9.0 + 2.1) );
    uint8_t blue = 64 * (1 + sin(t / 3.0 + k / 14.0 + 4.2) );
    led.setColorAt(t, red, green, blue);
  }
  led.show();
  j += random(1, 6) / 6.0;
  f += random(1, 6) / 6.0;
  k += random(1, 6) / 6.0;
}

