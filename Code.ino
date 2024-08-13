const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const int numLeds = 12;
const int baseDelay = 100;  // Delay between LED updates
const int flickerDelay = 50; // Delay for flickering effect

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // Bouncing Ball Effect
  for (int pos = 0; pos < numLeds; pos++) {
    digitalWrite(ledPins[pos], HIGH);
    if (pos > 0) {
      digitalWrite(ledPins[pos - 1], LOW);
    }
    delay(baseDelay);
  }

  for (int pos = numLeds - 1; pos >= 0; pos--) {
    digitalWrite(ledPins[pos], HIGH);
    if (pos < numLeds - 1) {
      digitalWrite(ledPins[pos + 1], LOW);
    }
    delay(baseDelay);
  }

  // Running Light Effect
  for (int start = 0; start < numLeds; start++) {
    for (int i = start; i < start + numLeds; i++) {
      digitalWrite(ledPins[i % numLeds], HIGH);
    }
    delay(baseDelay);
    for (int i = start; i < start + numLeds; i++) {
      digitalWrite(ledPins[i % numLeds], LOW);
    }
  }

  // Random Flicker Effect
  for (int flicker = 0; flicker < 50; flicker++) {
    int randomLed = random(numLeds);
    digitalWrite(ledPins[randomLed], HIGH);
    delay(flickerDelay);
    digitalWrite(ledPins[randomLed], LOW);
    delay(flickerDelay);
  }
}
