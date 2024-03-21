# Arduino Stopwatch with Time Data Logging

This project is an advanced timing system based on Arduino, designed to accurately measure and record durations. Using two Arduino Nano boards, the system operates with one Arduino acting as a master for timing and a second Arduino as a slave for data logging.

## Features

- **Precise Timing**: Utilizes an Arduino Nano as the main timer.
- **Data Logging**: Elapsed time, date, and time are logged onto a micro SD card by a second Arduino Nano.
- **Communication**: Employs I2C and SPI buses for data transmission and logging.
- **LED Display**: Displays elapsed time on an LED display.
- **Expandable**: Easily adaptable for various timing applications.

## Required Hardware

- 2 x Arduino Nano
- 1 x RTC DS1307 Module
- 1 x Micro SD Card Module
- 1 x MAX7219 LED Display
- Jumper wires, resistors, and other basic components

## Configuration

Detailed instructions for hardware and software setup are available in the respective folders of this repository. Please refer to the `diagram` file for wiring and `Master.ino` and `Slave.ino` files for Arduino sketches.

## Installation

1. **Assemble the circuit**: Follow the provided wiring diagram to connect the components.
2. **Download the code**: Upload the provided sketches onto the two Arduino Nano boards.
3. **Set RTC time**: Set the time on the RTC DS1307 module.
4. **Insert micro SD card**: Ensure the card is formatted as FAT16 or FAT32.

## Usage

Upon powering up, the display will show 00:00:00:00. After pressing the reset button once, the system will start timing. Press the reset button to reset and save the elapsed time in a file named "DATA.txt" on the micro SD card.

## Contribution

Contributions to this project are welcome. Feel free to fork this repository, make your modifications, and submit a pull request.
