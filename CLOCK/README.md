# Affichage d'Horloge avec MAX7219 et DS3231

Ce projet Arduino utilise un afficheur à sept segments MAX7219 pour afficher l'heure récupérée à partir d'un module horloge en temps réel DS3231. L'horloge est mise à jour chaque seconde et affiche les heures, les minutes et les secondes.

## Matériel requis

- Arduino (testé sur Arduino Nano Every)
- Module MAX7219 (afficheur à sept segments)
- Module RTC DS3231 (horloge en temps réel)
- Fils de connexion

## Bibliothèques nécessaires

- [LedControl](https://github.com/wayoda/LedControl) - Pour le contrôle du module MAX7219.
- [Wire](https://www.arduino.cc/en/reference/wire) - Pour la communication I2C avec le module DS3231.
- [RTClib](https://github.com/adafruit/RTClib) - Pour la manipulation du module RTC DS3231.

## Schéma de câblage

Connectez les composants conformément au schéma suivant :

- Module MAX7219 :
  - DIN à la broche 10 de l'Arduino
  - CS à la broche 11 de l'Arduino
  - CLK à la broche 12 de l'Arduino
  - Alimentation et masse selon les spécifications du module

- Module RTC DS3231 :
  - Connecté via le bus I2C (SDA et SCL sur Arduino Nano Every)

## Fonctionnalités

- Affiche l'heure actuelle en utilisant un afficheur à sept segments.
- Utilise un module RTC DS3231 pour obtenir l'heure en temps réel.
- Met à jour l'affichage toutes les secondes.

## Instructions d'utilisation

1. Téléchargez et installez les bibliothèques nécessaires (LedControl, Wire, RTClib).

2. Connectez les composants conformément au schéma de câblage.

3. Chargez le code sur votre Arduino à l'aide de l'IDE Arduino.

4. Alimentez votre Arduino.

5. L'heure actuelle sera affichée en utilisant le module MAX7219.

## Auteur

- [Votre nom]

N'hésitez pas à contribuer ou à signaler des problèmes !

