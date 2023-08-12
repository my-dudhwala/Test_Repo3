#include <Arduino.h>

const int buttonPin = 2; // Pin number for the button
const int ledPin = 13;   // Pin number for the LED
bool ledState = false;   // Current state of the LED
bool buttonPressed = false; // Track button state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the button state
  int buttonState = digitalRead(buttonPin);
  delay(50);

  if (buttonState == LOW) {
    // If the button is pressed, update the state and toggle LED if necessary
    if (!buttonPressed) {
      buttonPressed = true;
      ledState = !ledState;
      digitalWrite(ledPin, ledState);
    }
  } else {
    // If the button is released, update the state
    buttonPressed = false;
  }
}