# GPS-Synchronized Clock with Arduino

This project utilizes an Arduino to build a clock that automatically synchronizes to GPS time, capable of adjusting for seasonal time changes (daylight saving time and standard time). The time is displayed using a MAX7219 8-digit display module. The project has been tested on an Arduino Nano Every but is designed to be compatible with other Arduino models.

## Features

- Time synchronization with GPS signal.
- Automatic adjustment for daylight saving and standard times.
- Display on an 8-digit MAX7219 module.
- Integration of an RTC module for time backup in the absence of GPS signals.

## Required Components

- Arduino (tested on Arduino Nano Every)
- GPS Module (e.g., NEO-6M)
- RTC Module (e.g., DS3231)
- 8-digit MAX7219 Display
- Breadboard and connection wires
- Appropriate power source

## Component Setup

### Wiring

#### MAX7219 Display:
- `VCC` -> `5V` on Arduino
- `GND` -> `GND` on Arduino
- `DIN` -> `Pin D3` on Arduino
- `CS`  -> `Pin D2` on Arduino
- `CLK` -> `Pin D4` on Arduino

#### NEO-6M GPS Module:
- `VCC` -> `5V` on Arduino
- `GND` -> `GND` on Arduino
- `TX`  -> `Pin D5` on Arduino (connected to Arduino RX)
- `RX`  -> `Pin D6` on Arduino (connected to Arduino TX)

#### DS3231 RTC Module:
- `VCC` -> `5V` on Arduino
- `GND` -> `GND` on Arduino
- `SDA` -> `Pin A4` on Arduino
- `SCL` -> `Pin A5` on Arduino

## Library Installation

Install the following libraries through the Arduino IDE's Library Manager:
- `TinyGPS++` for GPS handling
- `LedControl` for driving the MAX7219 display
- `RTClib` for managing the RTC module

## Source Code

The source code is available in the `src` directory. Make sure to download all necessary files and open them with the Arduino IDE to upload them to your microcontroller.

## Usage

After uploading the program to your Arduino, ensure that the GPS module has a clear view of the sky for optimal synchronization. The clock should display the correct time after receiving GPS signals.

## License

This project is distributed under the MIT License, allowing for widespread use, modification, and distribution.

## Contributions

Contributions to this project are welcome. To contribute, please clone this repository, create a branch for your modifications, and submit a pull request.

## Credits

- `TinyGPS++` by Mikal Hart
- `LedControl` for managing the MAX7219 display
- `RTClib` by Adafruit Industries

## Author

- Joemy Bannwarth
- Foxtek Technology Systems - www.foxtek.eu

Feel free to contribute or report issues!
