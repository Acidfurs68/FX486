#include <LedControl.h>
#include <Wire.h>
#include <RTClib.h>

LedControl lc = LedControl(10, 11, 12, 1);

RTC_DS1307 rtc;

int resetPin = A2;
int buzzerPin = A0;
int ledPin = 13; 
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long elapsedTime = 0;
bool timingStarted = false;
bool buttonState = HIGH;
unsigned long debounceDelay = 20;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  Wire.begin();  // Initialise le bus I2C
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  displayTime(0, 0, 0, 0);

  pinMode(resetPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  rtc.adjust(DateTime(2024, 03, 10, 20, 19, 0));
}

void writeToSD(const String& data) {
    Wire.beginTransmission(0x8);
    Wire.write(data.c_str());
    int result = Wire.endTransmission();

    if (result == 0) {
        Serial.println("Données écrites sur la SD : " + data);
    } else {
        Serial.println("Erreur d'écriture sur la SD");
    }
}

void loop() {
  currentMillis = millis();

  if (digitalRead(resetPin) == LOW) {
    Serial.println("Reset");
    // Attendre que le bouton soit relâché pour éviter les rebonds
    delay(50); 
    while (digitalRead(resetPin) == LOW); // Attente active jusqu'à ce que le bouton soit relâché

    elapsedTime = currentMillis - previousMillis;
    String formattedTime = formatTime(elapsedTime); // Convertit elapsedTime en format HH:MM:SS:cc
    DateTime now = rtc.now();  // Récupérer la date et l'heure actuelles depuis le module RTC
    String formattedDateTime = formatDateTime(now);  // Convertir la date et l'heure en une chaîne de caractères formatée
    String fullData = formattedTime + " " + formattedDateTime;  // Concaténer la chaîne de temps et la chaîne de date / heure séparées par une virgule
    writeToSD(fullData);

    previousMillis = currentMillis; // Réinitialiser le chronomètre
    timingStarted = true; // Démarrer le chronométrage
    // Produire un bip sonore et clignoter la LED deux fois
    beepAndBlink();
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

String formatDateTime(DateTime now) {
  char dateTime[25];
  // Formatage de la date sous la forme DD/MM/YYYY HH:MM:SS
  sprintf(dateTime, "(%02d/%02d/%04d %02dh%02d)", now.day(), now.month(), now.year(), now.hour(), now.minute());
  return String(dateTime);
}

String formatTime(unsigned long ms) {
    unsigned long totalSeconds = ms / 1000;
    unsigned long totalMinutes = totalSeconds / 60;
    unsigned long hours = totalMinutes / 60;
    unsigned long minutes = totalMinutes % 60;
    unsigned long seconds = totalSeconds % 60;
    unsigned long centiseconds = (ms % 1000) / 10;

    char buffer[11];
    sprintf(buffer, "[%02lu:%02lu:%02lu:%02lu]", hours, minutes, seconds, centiseconds);
    return String(buffer);
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

void beepAndBlink() {
  for (int i = 0; i < 2; ++i) {
    analogWrite(buzzerPin, 1000);  // Utilisez une valeur PWM pour produire un son
    digitalWrite(ledPin, HIGH);  // Allumer la LED
    delay(100);  // Maintenir le son et l'état allumé pendant 100 ms
    analogWrite(buzzerPin, 0);    // Arrêter le son
    digitalWrite(ledPin, LOW);   // Éteindre la LED
    delay(100);  // Maintenir l'état éteint pendant 100 ms
  }
}
