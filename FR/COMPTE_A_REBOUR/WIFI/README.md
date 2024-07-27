# Minuterie Programmable Pilotée par Smartphone avec Arduino ESP32 et Nano Every

## Description du Projet
Ce projet présente une minuterie programmable contrôlée via un smartphone en utilisant un Arduino ESP32 et un Arduino Nano Every. L'ESP32 agit comme un point d'accès Wi-Fi, permettant de configurer et de contrôler la minuterie via une interface web accessible depuis votre téléphone portable. L'Arduino Nano Every gère la minuterie et fournit des notifications visuelles et sonores à l'aide de LEDs, d'un buzzer et d'un afficheur à segment MAX7219.

## Caractéristiques
- **Contrôle via Wi-Fi** : Configurez et contrôlez la minuterie via une interface web accessible depuis un smartphone.
- **Notifications** : Des LEDs, un buzzer et un afficheur à segment MAX7219 fournissent des notifications pour les actions de démarrage, de pause, de reprise et de réinitialisation.
- **Commandes Simples** : Réglez facilement la minuterie et contrôlez ses fonctions avec des commandes intuitives via l'interface web.

## Matériel Utilisé
- **Arduino ESP32** : Pour la connexion Wi-Fi et l'interface web.
- **Arduino Nano Every** : Pour le contrôle de la minuterie.
- **Afficheur à Segment MAX7219** : Pour afficher les informations de la minuterie.
- **LEDs** : Pour les notifications visuelles.
- **Buzzer** : Pour les notifications sonores.
- **Relais** : Pour contrôler d'autres dispositifs si nécessaire.
- **Connexions et Câblages** : Pour assembler tous les composants.

## Schéma de Connexion
- **ESP32** connecté au Wi-Fi et communiquant via I2C avec le **Nano Every**.
- **Afficheur à Segment MAX7219** connecté au Nano Every :
  - **DIN** : Broche 10
  - **CLK** : Broche 11
  - **CS** : Broche 12
- **LEDs** et **Buzzer** connectés aux broches de sortie numérique du **Nano Every**.

## Installation
1. **Clonez ce dépôt** 
2. **Ouvrez le projet dans l'IDE Arduino**.
3. **Téléversez le code Maitre sur l'Arduino ESP32** et l'Esclave sur l'Arduino Nano Every.

## Utilisation
1. **Connectez-vous au réseau Wi-Fi** créé par l'ESP32 (SSID: FOXTEK, Mot de passe: 12345678).
2. **Accédez à l'interface web** en entrant l'adresse IP affichée dans le moniteur série (généralement `192.168.4.1`).
3. **Configurez et contrôlez la minuterie** via l'interface web.

## Code Source
Le code source de ce projet est disponible dans ce dépôt. N'hésitez pas à le modifier et à l'adapter à vos besoins.

## Contribuer
Les contributions sont les bienvenues ! Si vous avez des idées d'amélioration ou des corrections à proposer, n'hésitez pas à ouvrir une issue ou une pull request.

## License
Ce projet est sous licence MIT. Voir le fichier [LICENSE] pour plus de détails.

---

### Tags
Arduino, ESP32, Nano Every, IoT, Minuterie, Interface Web, Smartphone, Hackaday

---

Merci d'avoir consulté ce projet ! Si vous avez des questions ou des suggestions, n'hésitez pas à me contacter.

---
