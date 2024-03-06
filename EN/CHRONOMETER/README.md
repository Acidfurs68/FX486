# Arduino Stopwatch

This project involves a simple stopwatch implemented on an Arduino board, featuring a display on a seven-segment LED module and additional functionalities such as pause, reset, and visual/auditory indicators.

## Required Hardware

- Arduino (tested on Arduino Nano Every)
- Seven-segment LED display module (using the LedControl library)
- Buzzer
- LED (Connected to pin 13 on Arduino Nano Every)
- Reset button (Connected to pin A2 on Arduino Nano Every)

## Required Libraries

- [LedControl](https://github.com/wayoda/LedControl) - For controlling the LED display module.

## Wiring Diagram

Make sure to connect the components according to the following diagram:

- LED display module:
  - DIN to pin 10 on the Arduino
  - CS to pin 11 on the Arduino
  - CLK to pin 12 on the Arduino
  - Power and ground as per the module specifications

- Buzzer:
  - Connected to pin A0 on the Arduino

- LED:
  - Connected to pin 13 on the Arduino

- Reset button:
  - Connected to pin A2 on the Arduino

## Features

1. **RESET_CHRONO.ino:** This file contains the code to reset the stopwatch. This will trigger a beep and LED blinking.

2. **START_STOP_CHRONO.ino:** This file contains the code to start and stop the stopwatch. When you upload this code to your Arduino, it will enable you to start and stop the stopwatch by pressing the reset button. It will also trigger appropriate beeps and LED blinking based on the stopwatch's state.

3. **STOP_RESET_CHRONO.ino:** This file contains the code to pause the stopwatch and restart it. When you upload this code to your Arduino, it will allow you to pause the stopwatch by pressing the reset button and then restart it by pressing the same button again. It will also trigger appropriate beeps and LED blinking based on the stopwatch's state.

## Usage Instructions

1. Download and install the required libraries (LedControl).

2. Connect the components according to the wiring diagram.

3. Upload the appropriate code to your Arduino using the Arduino IDE.

4. Power your Arduino.

5. Use the reset buttons to control the stopwatch's functionalities based on the loaded INO file.

## Authors

- Joemy Bannwarth
- Foxtek Technology Systems - www.foxtek.eu

Feel free to contribute or report issues!
