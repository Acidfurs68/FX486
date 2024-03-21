#include <IRremote.h>

IRsend irsend;
const int IR_LED_PIN = 3;
const int BUTTON_PIN = 2;

void setup() {
  pinMode(IR_LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  irsend.begin(IR_LED_PIN);
}

void loop() {
  if (digitalRead(BUTTON_PIN) == LOW) {
    unsigned long startTime = millis(); // Enregistrer le temps de début

    while (millis() - startTime < 500) { // Continuer pendant 2 secondes
      irsend.sendSony(0xA90, 12); // Exemple de code Sony de 12 bits
      delay(50); // Délai court pour permettre à l'émetteur de se reposer et éviter la surchauffe
    }

    while (digitalRead(BUTTON_PIN) == LOW); // Attendre que le bouton soit relâché
  }
}