# Minuteur à Compte à Rebours Programmable Arduino

![7be9ab2a-c982-4633-9d86-b7a25706d5da](https://github.com/Acidfurs68/FX486_V1/assets/153730800/561f6355-0b7a-4577-b27d-d51a5cb9047f)

Ce projet consiste en un minuteur à compte à rebours programmable basé sur la plateforme Arduino. 
Il permet aux utilisateurs de définir une durée de compte à rebours en heures, minutes, secondes et centièmes de seconde, puis de lancer le compte à rebours. 
Le minuteur affiche ensuite le temps restant sur un afficheur 8 chiffres à LED et émet un bip à chaque seconde de décompte.

## Fonctionnalités

- Programmation facile du temps de compte à rebours.
- Affichage du temps restant sur un afficheur 8 chiffres à LED.
- Bips sonores à chaque seconde de décompte.
- Possibilité d'arrêter et relancer le compte à rebours en marche.

## Matériel Requis

- Arduino (par exemple, Arduino Nano)
- Afficheur 8 chiffres à LED compatible MAX7219
- Clavier matriciel 4x4
- Haut-parleur ou buzzer
- Composants électroniques de base (résistances, fils, etc.)

## Prérequis

Avant de commencer, assurez-vous d'avoir installé l'environnement de développement Arduino sur votre ordinateur. Vous aurez également besoin des bibliothèques suivantes :

- Bibliothèque Keypad : [https://github.com/Chris--A/Keypad](https://github.com/Chris--A/Keypad)
- Bibliothèque LedControl : [https://github.com/wayoda/LedControl](https://github.com/wayoda/LedControl)

## Installation

1. Assurez-vous d'avoir l'environnement de développement Arduino installé sur votre ordinateur.

2. Installez les bibliothèques nécessaires : `Keypad` et `LedControl`. Vous pouvez les trouver dans les liens fournis dans le code source.

3. Connectez votre carte Arduino aux composants conformément au schéma de câblage fourni dans la documentation.

4. Chargez le code dans l'Arduino IDE et téléversez-le sur votre carte Arduino.

## Utilisation

### Programmation de la durée

- Un appuie sur la touche "A" permet d'entrer en mode de programmation. Vous pouvez commencer à entrer la durée du compte à rebours.

- Utilisez les touches numériques (0-9) du clavier matriciel pour entrer la durée du compte à rebours au format "HHMMSScc", où HH représente les heures, MM les minutes, SS les secondes et cc les centièmes de seconde.

### Démarrer le compte à rebours

- Appuyez sur la touche "D" pour démarrer le compte à rebours. L'afficheur affichera la durée restante.

- Le minuteur émettra un bip sonore à chaque seconde de décompte.

### Arrêter ou relancer le compte à rebours

- Appuyez sur la touche "B" pour arrêter le compte à rebours en cours. Le minuteur s'arrêtera, mais la durée programmée restera affichée.

- Appuyez sur la touche "D" pour relancer le compte à rebours en cours. 

### Réinitialiser et reprogrammer

- En mode programmation, pour effacer la durée programmée et recommencer, appuyez sur la touche "C", et vous pourrez recommencer le processus de programmation.

## Contributions

Si vous souhaitez contribuer à ce projet, suivez les étapes de contribution mentionnées dans le README. Assurez-vous de respecter les normes de codage et les directives de contribution.

## Licence

Ce projet est sous licence XYZ. Pour plus de détails, consultez le fichier `LICENSE.md`.
