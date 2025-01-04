#include <FastLED.h>

#define NUM_LEDS 2  // 2 LEDs per branch
#define LED_PIN 3

// Tilt switch pins
const int TILT_SWITCHES[] = { 4};
const int NUM_BRANCHES = 1;

CRGB leds[NUM_LEDS];
bool lastTiltStates[NUM_BRANCHES] = {false};
CRGB branchColors[NUM_BRANCHES] = {
  CRGB::Purple
};

void setup() {
  FastLED.addLeds<WS2811, LED_PIN, GRB>(leds, NUM_LEDS);
  
  // Setup tilt switch pins as inputs with internal pull-up
  for (int i = 0; i < NUM_BRANCHES; i++) {
    pinMode(TILT_SWITCHES[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i < NUM_BRANCHES; i++) {
    // Read current tilt state
    bool currentTiltState = !digitalRead(TILT_SWITCHES[i]);
    
    // Check if tilt state changed
    if (currentTiltState != lastTiltStates[i]) {
      // Update LED segment for this branch
      fillBranchLEDs(i, currentTiltState ? branchColors[i] : CRGB::Black);
      
      // Update last state
      lastTiltStates[i] = currentTiltState;
    }
  }
  
  FastLED.show();
  delay(50);  // Debounce
}

void fillBranchLEDs(int branch, CRGB color) {
  // Each branch controls 2 LEDs
  int startLED = branch * 2;
  leds[startLED] = color;
  leds[startLED + 1] = color;
}
