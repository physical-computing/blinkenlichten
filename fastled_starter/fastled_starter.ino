#include <FastLED.h>

#define LED_PIN 3
#define NUM_LEDS 1
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);
}

void loop() {
  // Fade the LED in and out
  for (int i = 0; i < 256; i++) {
    leds[0] = CRGB(i, i, i);
    FastLED.show();
    delay(10);
  }

  for (int i = 255; i >= 0; i--) {
    leds[0] = CRGB(i, i, i);
    FastLED.show();
    delay(10);
  }
}
