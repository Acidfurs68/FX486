# Smartphone-Controlled Programmable Timer with Arduino ESP32 and Nano Every

## Project Description
This project showcases a smartphone-controlled programmable timer using an Arduino ESP32 and an Arduino Nano Every. The ESP32 acts as a Wi-Fi access point, allowing you to configure and control the timer via a web interface accessible from your mobile phone. The Arduino Nano Every manages the timer and provides visual and audible notifications using LEDs, a buzzer, and a MAX7219 7-segment display.

## Features
- **Wi-Fi Control**: Configure and control the timer via a web interface accessible from a smartphone.
- **Notifications**: LEDs, a buzzer, and a MAX7219 7-segment display provide notifications for start, pause, resume, and reset actions.
- **Simple Commands**: Easily set the timer and control its functions with intuitive web controls.

## Hardware Used
- **Arduino ESP32**: For Wi-Fi connectivity and the web interface.
- **Arduino Nano Every**: For timer control.
- **MAX7219 7-Segment Display**: To display timer information.
- **LEDs**: For visual notifications.
- **Buzzer**: For audible notifications.
- **Relay**: To control other devices if necessary.
- **Connections and Wiring**: To assemble all components.

## Connection Diagram
- **ESP32** connected to Wi-Fi and communicating via I2C with the **Nano Every**.
- **MAX7219 7-Segment Display** connected to the Nano Every:
  - **DIN**: Pin 10
  - **CLK**: Pin 11
  - **CS**: Pin 12
- **LEDs** and **Buzzer** connected to the digital output pins of the **Nano Every**.

## Installation
1. **Clone this repository**
2. **Open the project in the Arduino IDE**.
3. **Upload the Master code to the Arduino ESP32** and the Slave to the Arduino Nano Every.

## Usage
1. **Connect to the Wi-Fi network** created by the ESP32 (SSID: FOXTEK, Password: 12345678).
2. **Access the web interface** by entering the IP address shown in the serial monitor (typically `192.168.4.1`).
3. **Configure and control the timer** via the web interface.

## Source Code
The source code for this project is available in this repository. Feel free to modify and adapt it to your needs.

## Contributing
Contributions are welcome! If you have any improvement ideas or corrections, feel free to open an issue or a pull request.

## License
This project is licensed under the MIT License. See the [LICENSE] file for more details.

---

### Tags
Arduino, ESP32, Nano Every, IoT, Timer, Web Interface, Smartphone, Hackaday

---

Thank you for checking out this project! If you have any questions or suggestions, feel free to contact me.

---
