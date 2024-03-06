#include <LedControl.h>

LedControl lc = LedControl(10, 11, 12, 1);
const int ledPin = 13;  // Broche pour la LED
const int buzzerPin = A0;  // Broche pour le buzzer

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
    // Attendre que le bouton soit relâché pour éviter les rebonds
    delay(50);
    while (digitalRead(resetPin) == LOW); // Attente active jusqu'à ce que le bouton soit relâché

    if (timingStarted) {
      pauseTimer();  // Mettre en pause le chronomètre
    } else {
      restartTimer();  // Réinitialiser et démarrer le chronomètre
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
  lc.setDigit(0, 7, (hours / 10) % 10, false); // Dixième d'heure
  lc.setDigit(0, 6, hours % 10, true);         // Heure
  lc.setDigit(0, 5, (minutes / 10) % 10, false);// Dixième de minute
  lc.setDigit(0, 4, minutes % 10, true);        // Minute
  lc.setDigit(0, 3, (seconds / 10) % 10, false);// Dixième de seconde
  lc.setDigit(0, 2, seconds % 10, true);       // Seconde
  lc.setDigit(0, 1, (milliseconds / 10) % 10, false);// Dixième de milliseconde
  lc.setDigit(0, 0, milliseconds % 10, false); // Milliseconde
}

void pauseTimer() {
  for (int i = 0; i < 2; ++i) {
    tone(buzzerPin, 1000, 100);  // Biper deux fois
    digitalWrite(ledPin, HIGH);  // Allumer la LED
    delay(100);
    digitalWrite(ledPin, LOW);  // Éteindre la LED
    delay(100);
  }
  timingStarted = false;  // Mettre en pause le chronomètre
}

void restartTimer() {
  tone(buzzerPin, 1000, 100);  // Biper une fois
  digitalWrite(ledPin, HIGH);  // Allumer la LED
  delay(150);
  digitalWrite(ledPin, LOW);  // Éteindre la LED
  timingStarted = true;  // Démarrer le chronomètre
  previousMillis = currentMillis;  // Réinitialiser le chronomètre
}
