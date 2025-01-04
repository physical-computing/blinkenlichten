#include <FastLED.h>
#include <Bounce2.h>

#define NUM_LEDS 1
#define LED_PIN 3
#define BUTTON_PIN 2
#define BRIGHTNESS 255
#define LED_TYPE WS2811
#define COLOR_ORDER RGB
CRGB leds[NUM_LEDS];
Bounce button = Bounce();



void setup() {
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);  // Set brightness


  Serial.begin(9600);
  button.attach(BUTTON_PIN, INPUT_PULLUP);

  button.interval(50);
}

void loop() {
  button.update();
  if (button.changed()) {
    Serial.print("CHANGED: ");
    int deboucedInput = button.read();
    if (deboucedInput == LOW) {
      Serial.println("to LOW");
      for (int i = 255; i >= 0; i--) {
        leds[0] = CRGB(i, i, i);
        FastLED.show();
        delay(10);
      }
    } else {
      Serial.println("to HIGH");
      for (int i = 0; i < 256; i++) {
        leds[0] = CRGB(i, i, i);
        FastLED.show();
        delay(10);
      }
    }
  }
}
