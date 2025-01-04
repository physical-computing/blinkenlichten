#include <FastLED.h>

#define NUM_LEDS 1
#define LED_PIN 3
#define LDR_PIN A0

#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
int ivmin = 1023;
int ivmax = 0;
int ovmin = 0;
int ovmax = 255;



void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);  // Set brightness
  Serial.begin(9600);
}

void loop() {
  int ldr = analogRead(LDR_PIN);
  Serial.println(ldr);
    // calibrate
  if (ldr < ivmin) {
    ivmin = ldr;
  }
  if (ldr > ivmax) {
    ivmax = ldr;
  }

  int ldr_mapped = map(ldr, ivmin, ivmax, ovmax, ovmin);
  leds[0] = CRGB(ldr_mapped, ldr_mapped, ldr_mapped);
  FastLED.show();
  delay(10);


}
