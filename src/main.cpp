// buildin
#include <Arduino.h>

// third-party
#define FASTLED_INTERNAL // disable pragma message
#include <FastLED.h>


// private, local

/*------------Notes-----------*\
Credits: Modisch Fabrications

Testing should be possible on the digispark, as it has an ATTiny85 onboard. 
Make sure to exclude Pin 3 and 4 as these are used for USB.



\*----------------------------*/

// --- statics, constants & defines

#define PIN_LEDS 3

const uint8_t N_LEDS = 12;
CRGB leds[N_LEDS];

const uint16_t MS_PER_STATE = (5 * 1000);

// --- functions

void hello_power(uint16_t t_animation_ms)
{
    for (uint8_t i = 0; i < N_LEDS; i++)
    {
        leds[i] = CRGB::White;
        FastLED.show();
        delay(t_animation_ms / N_LEDS); // 1 second for whole bar
        leds[i] = CRGB::Black;
    }
}

// directly used as brightness
enum USER_BRIGHTNESS
{
  LOW_BR = 15,
  MIDDLE_BR = 63,
  HIGH_BR = 255
};

// --------------

void setup()
{
  // init hardware
  pinMode(PIN_LEDS, OUTPUT);
  FastLED.addLeds<WS2812B, PIN_LEDS, GRB>(leds, N_LEDS);

  // init subcomponents

  delay(1000);

  // all done
  hello_power(2000);        // I = 
}

void loop()
{
  // (re)set powerlimit to 5v, 2A (unlimited)
  FastLED.setMaxPowerInVoltsAndMilliamps(5,2000); 

  fill_solid(leds, N_LEDS, CRGB::Red);    // I = 155
  FastLED.show();
  delay(MS_PER_STATE);

  fill_solid(leds, N_LEDS, CRGB::Green);  // I = 82
  FastLED.show();
  delay(MS_PER_STATE);

  fill_solid(leds, N_LEDS, CRGB::Blue); // 155
  FastLED.show();
  delay(MS_PER_STATE);

  fill_solid(leds, N_LEDS, CRGB::White);  // 445
  FastLED.show();
  delay(MS_PER_STATE);

  FastLED.setBrightness(USER_BRIGHTNESS::LOW_BR);   // 34
  FastLED.show();
  delay(MS_PER_STATE);

  FastLED.setBrightness(USER_BRIGHTNESS::MIDDLE_BR);  // 116
  FastLED.show();
  delay(MS_PER_STATE);

  FastLED.setBrightness(USER_BRIGHTNESS::HIGH_BR);    // 443
  FastLED.show();
  delay(MS_PER_STATE);

  // (re)set powerlimit to 5v, 0.1A
  FastLED.setMaxPowerInVoltsAndMilliamps(5,100);    // 90
  FastLED.show();
  delay(MS_PER_STATE);

}

