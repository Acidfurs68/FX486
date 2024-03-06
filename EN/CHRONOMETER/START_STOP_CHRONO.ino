#include <LedControl.h>

LedControl lc = LedControl(10, 11, 12, 1);
const int ledPin = 13;    // Pin for the LED
const int buzzerPin = A0; // Pin for the buzzer

int resetPin = A2;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long elapsedTime = 0;
bool timingStarted = false;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  displayTime(0, 0, 0, 0);

  pinMode(resetPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  currentMillis = millis();

  if (digitalRead(resetPin) == LOW) {
    // Wait for the button to be released to avoid bouncing
    delay(50);
    while (digitalRead(resetPin) == LOW); // Active waiting until the button is released

    if (timingStarted) {
      pauseTimer(); // Pause the timer
    } else {
      startTimer(); // Start the timer
    }
  }

  if (timingStarted) {
    elapsedTime = currentMillis - previousMillis;
    int hours = elapsedTime / 3600000;
    int minutes = (elapsedTime / 60000) % 60;
    int seconds = (elapsedTime / 1000) % 60;
    int milliseconds = elapsedTime % 1000 / 10;

    displayTime(hours, minutes, seconds, milliseconds);

  }
}

void displayTime(int hours, int minutes, int seconds, int milliseconds) {
  lc.setDigit(0, 7, (hours / 10) % 10, false); // Tenth of an hour
  lc.setDigit(0, 6, hours % 10, true);         // Hour
  lc.setDigit(0, 5, (minutes / 10) % 10, false);// Tenth of a minute
  lc.setDigit(0, 4, minutes % 10, true);        // Minute
  lc.setDigit(0, 3, (seconds / 10) % 10, false);// Tenth of a second
  lc.setDigit(0, 2, seconds % 10, true);       // Second
  lc.setDigit(0, 1, (milliseconds / 10) % 10, false);// Tenth of a millisecond
  lc.setDigit(0, 0, milliseconds % 10, false); // Millisecond
}

void pauseTimer() {
  // Blink and beep twice
  for (int i = 0; i < 2; i++) {
    tone(buzzerPin, 1000, 100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  noTone(buzzerPin);
  timingStarted = false; // Pause the timer
}

void startTimer() {
  // Blink and beep once
  for (int i = 0; i < 1; i++) {
    tone(buzzerPin, 1000, 100);
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  noTone(buzzerPin);
  timingStarted = true; // Start the timer
  previousMillis = currentMillis - elapsedTime; // Restart the timer from the current time
}
