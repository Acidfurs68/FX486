#include <LedControl.h>
#include <Wire.h>
#include <RTClib.h>

// Paramètres pour MAX7219
LedControl lc = LedControl(10, 11, 12, 1);

// Création de l'objet RTC
RTC_DS3231 rtc;

void setup() {
  // Initialisation de la communication avec le MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8); // Régler la luminosité (0 min, 15 max)
  lc.clearDisplay(0);

  // Initialisation de la communication avec le DS3231
  if (!rtc.begin()) {
    Serial.println("RTC introuvable");
    while (1);
  }

  // Ajuster la date et l'heure la première fois
  //rtc.adjust(DateTime(2024, 03, 01, 6, 10, 0));

  // Pour régler une date et une heure spécifique
  // rtc.adjust(DateTime(2024, 2, 29, 23, 59, 0));
}

void loop() {
  DateTime now = rtc.now();

  lc.setDigit(0, 5, (now.hour() / 10), false); // Heure
  lc.setDigit(0, 4, (now.hour() % 10), false);
  lc.setDigit(0, 3, (now.minute() / 10), false); // true pour afficher le point (séparateur)
  lc.setDigit(0, 2, (now.minute() % 10), false);
  lc.setDigit(0, 1, (now.second() / 10), false); // Secondes
  lc.setDigit(0, 0, (now.second() % 10), false);

  delay(1000); // Mise à jour toutes les secondes
}
