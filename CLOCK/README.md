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

1. **Téléchargez et installez les bibliothèques nécessaires** :
   - Téléchargez et installez la bibliothèque LedControl pour le contrôle du module MAX7219.
   - Assurez-vous d'avoir la bibliothèque Wire installée pour la communication I2C avec le module DS3231.
   - Installez également la bibliothèque RTClib pour la manipulation du module RTC DS3231.

2. **Connectez les composants conformément au schéma de câblage** :
   - Connectez les broches DIN, CS et CLK du module MAX7219 aux broches 10, 11 et 12 de l'Arduino respectivement.
   - Assurez-vous de connecter le module RTC DS3231 au bus I2C de l'Arduino (broches SDA et SCL sur Arduino Nano Every).

3. **Chargez le code sur votre Arduino** :
   - Ouvrez le fichier .ino correspondant dans l'IDE Arduino.
   - Vérifiez que vous avez sélectionné le bon type de carte et le bon port série dans l'IDE Arduino.
   - Téléversez le code sur votre Arduino.

4. **Conservez la date et l'heure dans le module DS3231** :
   - La première fois que vous chargez le code sur votre Arduino, il est recommandé d'activer la ligne de code `rtc.adjust(DateTime(année, mois, jour, heure, minute, seconde));` pour régler la date et l'heure initiales.
   - Commentez ou supprimez cette ligne de code après avoir réglé la date et l'heure pour éviter de les réinitialiser à chaque redémarrage.
   - Si vous devez ajuster la date et l'heure ultérieurement, vous pouvez réactiver cette ligne de code et la modifier en conséquence. Assurez-vous de la désactiver à nouveau après avoir effectué les réglages nécessaires.

5. **Alimentez votre Arduino** :
   - Une fois que vous avez téléversé le code et réglé la date et l'heure initiales (si nécessaire), alimentez votre Arduino.

6. **Affichage de l'heure actuelle** :
   - L'heure actuelle sera automatiquement affichée sur le module MAX7219 à l'aide du module RTC DS3231.
   - Assurez-vous que le module RTC DS3231 est alimenté en permanence pour garantir que l'heure est maintenue avec précision, même après une mise hors tension de l'Arduino.

N'hésitez pas à contribuer ou à signaler des problèmes !

## Auteur


- Joemy Bannwarth
- Foxtek Technology Systems - www.foxtek.eu


N'hésitez pas à contribuer ou à signaler des problèmes !

