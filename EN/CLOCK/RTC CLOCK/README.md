# Clock Display with MAX7219 and DS3231

This Arduino project utilizes a MAX7219 seven-segment display to showcase the time retrieved from a DS3231 real-time clock module. The clock updates every second, displaying hours, minutes, and seconds.

## Required Hardware

- Arduino (tested on Arduino Nano Every)
- MAX7219 Module (seven-segment display)
- DS3231 RTC Module (real-time clock)
- Connecting wires

## Required Libraries

- [LedControl](https://github.com/wayoda/LedControl) - For controlling the MAX7219 module.
- [Wire](https://www.arduino.cc/en/reference/wire) - For I2C communication with the DS3231 module.
- [RTClib](https://github.com/adafruit/RTClib) - For manipulating the DS3231 RTC module.

## Wiring Diagram

Connect the components according to the following diagram:

- MAX7219 Module:
  - DIN to pin 10 on the Arduino
  - CS to pin 11 on the Arduino
  - CLK to pin 12 on the Arduino
  - Power and ground as per the module specifications

- DS3231 RTC Module:
  - Connected via the I2C bus (SDA and SCL on Arduino Nano Every)

## Features

- Displays the current time using a seven-segment display.
- Utilizes a DS3231 RTC module to obtain real-time hours, minutes, and seconds.
- Updates the display every second.

## Usage Instructions

1. **Download and install the necessary libraries**:
   - Download and install the LedControl library for controlling the MAX7219 module.
   - Ensure the Wire library is installed for I2C communication with the DS3231 module.
   - Also, install the RTClib library for manipulating the DS3231 RTC module.

2. **Connect the components according to the wiring diagram**:
   - Connect the DIN, CS, and CLK pins of the MAX7219 module to pins 10, 11, and 12 on the Arduino, respectively.
   - Ensure you connect the DS3231 module to the I2C bus of the Arduino (SDA and SCL on Arduino Nano Every).

3. **Upload the code to your Arduino**:
   - Open the corresponding .ino file in the Arduino IDE.
   - Verify that you have selected the correct board type and serial port in the Arduino IDE.
   - Upload the code to your Arduino.

4. **Preserve the date and time in the DS3231 module**:
   - The first time you upload the code to your Arduino, it is recommended to activate the line of code `rtc.adjust(DateTime(year, month, day, hour, minute, second));` to set the initial date and time.
   - Comment or remove this line of code after setting the date and time to prevent resetting them on each restart.
   - If you need to adjust the date and time later, you can reactivate this line of code and modify it accordingly. Make sure to deactivate it again after making the necessary adjustments.

5. **Power your Arduino**:
   - Once you have uploaded the code and set the initial date and time (if necessary), power your Arduino.

6. **Display the current time**:
   - The current time will be automatically displayed on the MAX7219 module using the DS3231 RTC module.
   - Ensure that the DS3231 RTC module is powered continuously to maintain accurate time even after an Arduino power-off.

## Author

- Joemy Bannwarth
- Foxtek Technology Systems - www.foxtek.eu

Feel free to contribute or report issues!
