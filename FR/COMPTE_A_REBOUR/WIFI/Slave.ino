#include <Wire.h>
#include <LedControl.h>

const int DIN_PIN = 10;
const int CLK_PIN = 11;
const int CS_PIN = 12;
LedControl lc = LedControl(DIN_PIN, CLK_PIN, CS_PIN, 1);

const int LED_PIN = 13;
const int BUZZER_PIN = A0;
const int RELAY_PIN = A1;

unsigned long duration = 0; // Durée de la minuterie en millisecondes
unsigned long startTime = 0; // Temps de démarrage de la minuterie
unsigned long pauseTime = 0; // Temps de pause de la minuterie
unsigned long remainingTime = 0; // Temps restant
bool timerActive = false; // État de la minuterie
bool timerPaused = false; // État de pause
bool effectActive = false; // État de l'effet sonore et visuel

unsigned long effectStartTime = 0; // Temps de début de l'effet
int effectState = 0; // État actuel de l'effet
char currentCommand = 0; // Commande actuelle à exécuter après l'effet

void setup() {
  Serial.begin(115200); // Initialiser la communication série
  Wire.begin(8); // Joindre le bus I2C en tant qu'esclave avec l'adresse 8
  Wire.onReceive(receiveEvent);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void loop() {
  if (effectActive) {
    handleEffects();
  } else if (timerActive && !timerPaused) {
    unsigned long currentTime = millis();
    if (currentTime - startTime >= duration) {
      timerActive = false;
      displayTime(0);
      Serial.println("Minuterie terminée");
    } else {
      displayTime(duration - (currentTime - startTime));
    }
  }
}

void receiveEvent(int howMany) {
  uint8_t buffer[8];
  for (int i = 0; i < howMany; i++) {
    buffer[i] = Wire.read();
  }

  if (buffer[howMany - 1] == 'S') { // Commande SET
    int hours = buffer[0];
    int minutes = buffer[1];
    int seconds = buffer[2];
    int milliseconds = (buffer[3] << 8) | buffer[4];
    duration = ((unsigned long)hours * 3600000) + ((unsigned long)minutes * 60000) + (seconds * 1000) + milliseconds;
    remainingTime = duration; // Initialiser remainingTime à la durée totale
    displayTime(duration);
    Serial.println("Données SET reçues");
  }

  if (buffer[0] == 'T') { // Commande START
    currentCommand = 'T';
    startEffect(); // Effet sonore et visuel pour START
    Serial.println("Commande START reçue - Démarrage après l'effet");
  }

  if (buffer[0] == 'P') { // Commande PAUSE
    if (timerActive && !timerPaused) {
      pauseTime = millis();
      remainingTime = duration - (pauseTime - startTime);
      timerPaused = true;
      timerActive = false;
      currentCommand = 'P';
      pauseEffect(); // Effet sonore et visuel pour PAUSE
      Serial.println("Commande PAUSE reçue - Pause après l'effet");
    }
  }

  if (buffer[0] == 'U') { // Commande RESUME
    if (timerPaused) {
      currentCommand = 'U';
      resumeEffect(); // Effet sonore et visuel pour RESUME
      Serial.println("Commande RESUME reçue - Reprise après l'effet");
    }
  }

  if (buffer[0] == 'R') { // Commande RESET
    timerActive = false;
    timerPaused = false;
    duration = 0;
    remainingTime = 0;
    displayTime(0);
    Serial.println("Commande RESET reçue");
  }
}

void startEffect() {
  effectActive = true;
  effectStartTime = millis();
  effectState = 1;
}

void pauseEffect() {
  effectActive = true;
  effectStartTime = millis();
  effectState = 1;
}

void resumeEffect() {
  effectActive = true;
  effectStartTime = millis();
  effectState = 1;
}

void handleEffects() {
  unsigned long currentTime = millis();
  switch (effectState) {
    case 1:
      digitalWrite(LED_PIN, HIGH);
      digitalWrite(BUZZER_PIN, HIGH);
      digitalWrite(RELAY_PIN, HIGH);
      if (currentTime - effectStartTime >= 100) {
        digitalWrite(LED_PIN, LOW);
        digitalWrite(BUZZER_PIN, LOW);
        digitalWrite(RELAY_PIN, LOW);
        effectState = 2;
        effectStartTime = currentTime;
      }
      break;
    case 2:
      if (currentTime - effectStartTime >= 100) {
        if (currentCommand == 'P') {
          for (int i = 0; i < 2; i++) {
            digitalWrite(LED_PIN, HIGH);
            digitalWrite(BUZZER_PIN, HIGH);
            digitalWrite(RELAY_PIN, HIGH);
            delay(100);
            digitalWrite(LED_PIN, LOW);
            digitalWrite(BUZZER_PIN, LOW);
            digitalWrite(RELAY_PIN, LOW);
            delay(100);
          }
        }
        effectActive = false;
        executeCommand();
      }
      break;
  }
}

void executeCommand() {
  if (currentCommand == 'T') {
    startTime = millis();
    timerActive = true;
    timerPaused = false;
  } else if (currentCommand == 'U') {
    startTime = millis();
    timerActive = true;
    timerPaused = false;
  }
  currentCommand = 0;
}

void displayTime(unsigned long time) {
  int milliseconds = time % 1000;
  int seconds = (time / 1000) % 60;
  int minutes = (time / 60000) % 60;
  int hours = (time / 3600000) % 24;

  lc.setDigit(0, 7, hours / 10, false);
  lc.setDigit(0, 6, hours % 10, false);
  lc.setDigit(0, 5, minutes / 10, false);
  lc.setDigit(0, 4, minutes % 10, false);
  lc.setDigit(0, 3, seconds / 10, false);
  lc.setDigit(0, 2, seconds % 10, false);
  lc.setDigit(0, 1, milliseconds / 100, false);
  lc.setDigit(0, 0, (milliseconds / 10) % 10, false);
}
