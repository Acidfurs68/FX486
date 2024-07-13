#include <LedControl.h>
#include <Wire.h>
#include <RTClib.h>

// Parameters for MAX7219
LedControl lc = LedControl(10, 11, 12, 1);

// Create the RTC object
RTC_DS3231 rtc;

void setup() {
  // Initialize communication with MAX7219
  lc.shutdown(0, false);
  lc.setIntensity(0, 8); // Adjust brightness (0 min, 15 max)
  lc.clearDisplay(0);

  // Initialize communication with DS3231
  if (!rtc.begin()) {
    Serial.println("RTC not found");
    while (1);
  }

  // Adjust date and time for the first time
  // rtc.adjust(DateTime(2024, 03, 01, 6, 10, 0));

  // To set a specific date and time
  // rtc.adjust(DateTime(2024, 2, 29, 23, 59, 0));
}

void loop() {
  DateTime now = rtc.now();

  lc.setDigit(0, 5, (now.hour() / 10), false); // Hours
  lc.setDigit(0, 4, (now.hour() % 10), false);
  lc.setDigit(0, 3, (now.minute() / 10), false); // true to display the colon (separator)
  lc.setDigit(0, 2, (now.minute() % 10), false);
  lc.setDigit(0, 1, (now.second() / 10), false); // Seconds
  lc.setDigit(0, 0, (now.second() % 10), false);

  delay(1000); // Update every second
}
