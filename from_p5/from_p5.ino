#include <FastLED.h>

#define NUM_LEDS 3
#define LED_PIN 3

#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);  // Set brightness
  Serial.begin(9600);
}

void loop() {


  if (Serial.available() >= 3) {  // Wait for all 3 bytes
    byte data[3];
    Serial.readBytes(data, 3);

    // Set LED colors based on data
    for (int i = 0; i < 3; i++) {
      leds[i] = data[i] ? CRGB::White : CRGB::Black;  // White for 1, off for 0
    }
    FastLED.show();  // Update the LEDs
    delay(10);
    // Print received values
    // Serial.print("[");
    // for (int i = 0; i < 3; i++) {
    //   Serial.print(data[i]);
    //   if (i < 2) Serial.print(",");
    // }
    // Serial.println("]");

  }
  
}
