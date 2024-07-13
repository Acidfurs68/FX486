#include <TinyGPS++.h>
#include <SoftwareSerial.h>
#include <LedControl.h>
#include <Wire.h>
#include <RTClib.h>

// Pins for the GPS module
const int RXPin = 0, TXPin = 1;
const uint32_t GPSBaud = 9600;

// Create an instance of the TinyGPS++ object
TinyGPSPlus gps;

// Create an instance of the SoftwareSerial object
SoftwareSerial ss(RXPin, TXPin);

// Pins for the MAX7219 module
const int DIN = 10;
const int CLK = 11;
const int CS = 12;

// Create an instance of the LedControl object
LedControl lc = LedControl(DIN, CLK, CS, 1);

// Create an instance of the RTC object
RTC_DS3231 rtc;

const int timeZoneOffset = 1; // Base time zone offset in hours (adjust as needed)

// Zeller's Congruence algorithm to calculate the day of the week
int calculateWeekday(int year, int month, int day) {
  if (month < 3) {
    month += 12;
    year--;
  }
  int K = year % 100;
  int J = year / 100;
  int weekday = (day + 13 * (month + 1) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
  return (weekday + 5) % 7 + 1; // Adjusting result to be 1=Monday, 2=Tuesday, ..., 7=Sunday
}

bool isDaylightSavingTime(int day, int month, int weekday) {
  // Assuming DST starts on the last Sunday of March and ends on the last Sunday of October
  if (month < 3 || month > 10) return false; // Before March or after October, no DST
  if (month > 3 && month < 10) return true; // April to September, always DST

  int previousSunday = day - (weekday - 1); // Find the previous Sunday
  if (month == 3) return previousSunday >= 25; // DST starts on the last Sunday of March
  if (month == 10) return previousSunday < 25; // DST ends on the last Sunday of October

  return false;
}

void setup() {
  // Start the serial communication with the computer
  Serial.begin(9600);

  // Start the serial communication with the GPS module
  ss.begin(GPSBaud);

  // Initialize the MAX7219 display
  lc.shutdown(0, false);       // Wake up displays
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear display register

  // Initialize RTC
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (rtc.lostPower()) {
    Serial.println("RTC lost power, setting the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0) {
    gps.encode(ss.read());
  }

  // Check if GPS time is updated
  if (gps.time.isUpdated()) {
    updateRTCWithGPSTime();
    displayTime();
  } else {
    displayRTCTime();
  }
}

void updateRTCWithGPSTime() {
  int hour = gps.time.hour();
  int minute = gps.time.minute();
  int second = gps.time.second();
  int day = gps.date.day();
  int month = gps.date.month();
  int year = gps.date.year();
  int weekday = calculateWeekday(year, month, day);

  // Adjust for the time zone offset
  hour += timeZoneOffset;

  // Check for DST adjustment
  if (isDaylightSavingTime(day, month, weekday)) {
    hour += 1;
  }

  if (hour >= 24) hour -= 24;
  if (hour < 0) hour += 24;

  rtc.adjust(DateTime(year, month, day, hour, minute, second));
}

void displayTime() {
  // Get the current time
  int hour = gps.time.hour();
  int minute = gps.time.minute();
  int second = gps.time.second();
  int day = gps.date.day();
  int month = gps.date.month();
  int year = gps.date.year();
  int weekday = calculateWeekday(year, month, day);

  // Adjust for the time zone offset
  hour += timeZoneOffset;

  // Check for DST adjustment
  if (isDaylightSavingTime(day, month, weekday)) {
    hour += 1;
  }

  if (hour >= 24) hour -= 24;
  if (hour < 0) hour += 24;

  // Prepare the time as a string
  char timeString[9];
  sprintf(timeString, "%02d-%02d-%02d", hour, minute, second);

  // Display the time on the MAX7219
  for (int i = 0; i < 8; i++) {
    if (timeString[i] == '-') {
      lc.setChar(0, 7 - i, '-', false); // Dash
    } else {
      lc.setDigit(0, 7 - i, timeString[i] - '0', false);
    }
  }
}

void displayRTCTime() {
  DateTime now = rtc.now();

  int hour = now.hour();
  int minute = now.minute();
  int second = now.second();

  // Prepare the time as a string
  char timeString[9];
  sprintf(timeString, "%02d-%02d-%02d", hour, minute, second);

  // Display the time on the MAX7219
  for (int i = 0; i < 8; i++) {
    if (timeString[i] == '-') {
      lc.setChar(0, 7 - i, ' ', false); // Dash
    } else {
      lc.setDigit(0, 7 - i, timeString[i] - '0', false);
    }
  }
}