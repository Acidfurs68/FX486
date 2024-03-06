Bien sûr, voici une version ajustée du README pour un projet composé de trois fichiers INO différents :

```markdown
# Chronomètre Arduino

Ce projet consiste en un chronomètre simple implémenté sur une carte Arduino, avec un affichage sur un module d'affichage LED à sept segments et des fonctionnalités supplémentaires telles que la mise en pause, la réinitialisation et des indicateurs visuels et sonores.

## Matériel requis

- Arduino (testé sur Arduino Nano Every)
- Module d'affichage LED à sept segments (utilisation de la bibliothèque LedControl)
- Buzzer
- LED (Connectée à la broche 13 sur Arduino Nano Every)
- Bouton de reset (Connecté à la broche A2 sur Arduino Nano Every)

## Bibliothèques nécessaires

- [LedControl](https://github.com/wayoda/LedControl) - Pour le contrôle du module d'affichage LED.

## Schéma de câblage

Assurez-vous de connecter les composants conformément au schéma suivant :

- Module d'affichage LED :
  - DIN à la broche 10 de l'Arduino
  - CS à la broche 11 de l'Arduino
  - CLK à la broche 12 de l'Arduino
  - Alimentation et masse selon les spécifications du module

- Buzzer :
  - Connecté à la broche A0 de l'Arduino

- LED :
  - Connectée à la broche 13 de l'Arduino

- Bouton de reset :
  - Connecté à la broche A2 de l'Arduino

## Fonctionnalités

1. **RESET_CHRONO.ino :** Ce fichier contient le code pour réinitialiser le chronomètre. Cela déclenchera un bip et un clignotement de la LED.

2. **START_STOP_CHRONO.ino :** Ce fichier contient le code pour démarrer et arrêter le chronomètre. Lorsque vous chargez ce code sur votre Arduino, cela permettra de démarrer et d'arrêter le chronomètre en appuyant sur le bouton de reset. Cela déclenchera également des bips et des clignotements appropriés en fonction de l'état du chronomètre.

3. **STOP_RESET_CHRONO.ino :** Ce fichier contient le code pour mettre en pause le chronomètre et le redémarrer. Lorsque vous chargez ce code sur votre Arduino, cela permettra de mettre en pause le chronomètre en appuyant sur le bouton de reset, puis de le redémarrer en appuyant à nouveau sur le même bouton. Cela déclenchera également des bips et des clignotements appropriés en fonction de l'état du chronomètre.

## Instructions d'utilisation

1. Téléchargez et installez les bibliothèques nécessaires (LedControl).

2. Connectez les composants conformément au schéma de câblage.

3. Chargez le code approprié sur votre Arduino à l'aide de l'IDE Arduino.

4. Alimentez votre Arduino.

5. Utilisez les boutons de reset pour contrôler les fonctionnalités du chronomètre selon le fichier INO chargé.

## Auteurs

- Joemy Bannwarth
- Foxtek Technology Systems

N'hésitez pas à contribuer ou à signaler des problèmes !
