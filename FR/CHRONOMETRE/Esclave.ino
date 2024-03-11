#include <Wire.h>
#include <SPI.h>
#include <SD.h>

int tourCount = 0; // Variable globale pour suivre le nombre de tours

void setup() {
  Wire.begin(0x08); // Adresse de ce Nano en tant qu'esclave I2C
  Wire.onReceive(receiveEvent); // Fonction appelée lors de la réception de données I2C
  SPI.begin(); // Initialise le bus SPI
  SD.begin(); // Initialise le module de carte SD
  Serial.begin(9600);
  Serial.println("Enregistreur SD prêt.");
}

void loop() {
  // Traitement de fond
}

void receiveEvent(int howMany) {
  String receivedData;
  while (Wire.available()) { 
    char c = Wire.read();
    receivedData += c;
  }

  tourCount++; // Incrémenter le compteur de tours
  String message = "Mesure " + String(tourCount) + " -> " + receivedData;
  //Serial.println("Reçu via I2C : " + message);
  writeToSD(message);
}

void writeToSD(const String& data) {
  File myFile = SD.open("data.txt", FILE_WRITE);
  if (myFile) {
    Serial.println("Écriture sur SD : " + data);
    myFile.println(data);
    myFile.close();
  } else {
    Serial.println("Erreur d'ouverture du fichier sur SD.");
  }
}