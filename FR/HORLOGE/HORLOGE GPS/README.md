# Horloge GPS avec Arduino

Ce projet utilise un module Arduino pour construire une horloge qui se synchronise automatiquement à l'heure GPS, capable d'ajuster l'heure pour les changements saisonniers (heure d'été/heure d'hiver). L'affichage de l'heure se fait via un module d'affichage MAX7219. Le projet a été testé sur un Arduino Nano Every, mais est conçu pour être compatible avec d'autres modèles Arduino.

## Fonctionnalités

- Synchronisation de l'heure avec un signal GPS.
- Ajustement automatique de l'heure d'été et d'hiver.
- Affichage sur un module MAX7219 à 8 digits.
- Intégration d'un module RTC pour la sauvegarde de l'heure en absence de signal GPS.

## Composants Requis

- Arduino (testé sur Arduino Nano Every)
- Module GPS (ex : NEO-6M)
- Module RTC (ex : DS3231)
- Afficheur MAX7219 à 8 digits
- Breadboard et câbles de connexion
- Source d'alimentation adaptée

## Configuration des Composants

### Branchement

#### Afficheur MAX7219 :
- `VCC` -> `5V` de l'Arduino
- `GND` -> `GND` de l'Arduino
- `DIN` -> `Pin D3` de l'Arduino
- `CS`  -> `Pin D2` de l'Arduino
- `CLK` -> `Pin D4` de l'Arduino

#### Module GPS NEO-6M :
- `VCC` -> `5V` de l'Arduino
- `GND` -> `GND` de l'Arduino
- `TX`  -> `Pin D5` de l'Arduino (connecté au RX de l'Arduino)
- `RX`  -> `Pin D6` de l'Arduino (connecté au TX de l'Arduino)

#### Module RTC DS3231 :
- `VCC` -> `5V` de l'Arduino
- `GND` -> `GND` de l'Arduino
- `SDA` -> `Pin A4` de l'Arduino
- `SCL` -> `Pin A5` de l'Arduino

## Installation des Bibliothèques

Installez les bibliothèques suivantes via le gestionnaire de bibliothèques de l'IDE Arduino :
- `TinyGPS++` pour la gestion du GPS
- `LedControl` pour le pilotage de l'afficheur MAX7219
- `RTClib` pour la gestion du module RTC

## Code Source

Le code source est disponible dans le répertoire `src`. Assurez-vous de télécharger tous les fichiers nécessaires et de les ouvrir avec l'IDE Arduino pour les téléverser sur votre microcontrôleur.

## Utilisation

Après avoir téléversé le programme sur votre Arduino, assurez-vous que le module GPS a une vue claire du ciel pour une synchronisation optimale. L'horloge devrait afficher l'heure correcte après avoir capté les signaux GPS.

## Licence

Ce projet est distribué sous la licence MIT, permettant une large utilisation, modification et distribution.

## Contribution

Les contributions à ce projet sont bienvenues. Pour contribuer, veuillez cloner ce dépôt, créer une branche pour vos modifications, et soumettre une pull request.

## Crédits

- `TinyGPS++` par Mikal Hart
- `LedControl` pour la gestion de l'afficheur MAX7219
- `RTClib` par Adafruit Industries

## Auteur


- Joemy Bannwarth
- Foxtek Technology Systems - www.foxtek.eu


N'hésitez pas à contribuer ou à signaler des problèmes !
