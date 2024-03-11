# Chronomètre Arduino avec Enregistrement de Données Temporelles

Ce projet est un système de chronométrage avancé basé sur Arduino, conçu pour mesurer et enregistrer avec précision les durées. Utilisant deux Arduino Nano, le système fonctionne avec un Arduino agissant en tant que maître pour le chronométrage et un second Arduino en tant qu'esclave pour enregistrer les données.

## Fonctionnalités

- **Chronométrage Précis** : Utilise un Arduino Nano comme minuteur principal.
- **Enregistrement de Données** : Le temps écoulé, la date et l'heure sont enregistrés sur une carte micro SD par un second Arduino Nano.
- **Communication** : Emploie les bus I2C et SPI pour la transmission et l'enregistrement des données.
- **Affichage LED** : Affiche le temps écoulé sur un afficheur à LED.
- **Extensible** : Facilement modifiable pour diverses applications de chronométrage.

## Matériel Nécessaire

- 2 x Arduino Nano
- 1 x Module RTC DS1307
- 1 x Module de carte micro SD
- 1 x Afficheur LED MAX7219
- Câbles de connexion, résistances, et autres composants de base

## Configuration

Les instructions détaillées pour la configuration matérielle et logicielle sont disponibles dans les dossiers correspondants de ce dépôt. Veuillez vous référer au fichier `diagrame` pour le câblage et aux fichier `Maitre.ino` et `Esclave.ino` pour les sketches Arduino.

## Installation

1. **Assembler le circuit** : Suivez le schéma de câblage fourni pour connecter les composants.
2. **Télécharger le code** : Téléchargez les sketches fournis sur les deux Arduino Nano.
3. **Configurer l'heure du RTC** : Réglez l'heure sur le module RTC DS1307.
4. **Insérer la carte micro SD** : Assurez-vous que la carte est formatée en FAT16 ou FAT32.

## Utilisation

Après la mise sous tension, l'afficheur affiche 00:00:00:00, apres un premier appuie sur le bouton reset, le système commencera à chronométrer. Appuyez sur le bouton reset pour reinitialiser et enregistrer le temps écoulé dans le fichier generer et nommer "DATA.txt" sur la carte micro SD.

## Contribution

Les contributions à ce projet sont les bienvenues. N'hésitez pas à fork ce dépôt, à apporter vos modifications et à soumettre une pull request.

## Licence

Ce projet est distribué sous la licence MIT. Voir le fichier `LICENSE` pour plus d'informations.
