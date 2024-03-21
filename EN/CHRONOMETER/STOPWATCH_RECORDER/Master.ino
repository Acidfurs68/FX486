#include <LedControl.h>
#include <Wire.h>
#include <RTClib.h>

LedControl lc = LedControl(10, 11, 12, 1);

RTC_DS1307 rtc;

int resetPin = A2;
int buzzerPin = A0;
int ledPin = 13; 
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
unsigned long elapsedTime = 0;
bool timingStarted = false;
bool buttonState = HIGH;
unsigned long debounceDelay = 20;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  Wire.begin();  // Initialize the I2C bus
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
  displayTime(0, 0, 0, 0);

  pinMode(resetPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

  // Uncomment the following line to adjust the RTC date and time
  // rtc.adjust(DateTime(2024, 03, 11, 19, 49, 0));
}

void writeToSD(const String& data) {
    Wire.beginTransmission(0x8);
    Wire.write(data.c_str());
    int result = Wire.endTransmission();

    if (result == 0) {
        Serial.println("Transfer to SD: " + data);
    } else {
        Serial.println("Error writing to SD");
    }
}

void loop() {
  currentMillis = millis();

  if (digitalRead(resetPin) == LOW) {
    // Uncomment below for reset debug message
    // Serial.println("Reset");
    // Wait for button release to avoid bouncing
    delay(50); 
    while (digitalRead(resetPin) == LOW); // Active wait until the button is released

    elapsedTime = currentMillis - previousMillis;
    String formattedTime = formatTime(elapsedTime); // Converts elapsedTime to HH:MM:SS:cc format
    DateTime now = rtc.now();  // Retrieve current date and time from the RTC module
    String formattedDateTime = formatDateTime(now);  // Convert date and time to a formatted string
    String fullData = formattedTime + " " + formattedDateTime;  // Concatenate the time string and the date/time string separated by a comma
    writeToSD(fullData);

    previousMillis = currentMillis; // Reset the timer
    timingStarted = true; // Start timing
    // Emit a sound and blink the LED twice
    beepAndBlink();
  }

  if (timingStarted) {
    elapsedTime = currentMillis - previousMillis;
    int hours = elapsedTime / 3600000;
    int minutes = (elapsedTime / 60000) % 60;
    int seconds = (elapsedTime / 1000) % 60;
    int milliseconds = elapsedTime % 1000 / 10;

    displayTime(hours, minutes, seconds, milliseconds);
  }
}

String formatDateTime(DateTime now) {
  char dateTime[25];
  // Formatting the date in the format DD/MM/YYYY HH:MM:SS
  sprintf(dateTime, "(%02d/%02d/%04d %02dh%02d)", now.day(), now.month(), now.year(), now.hour(), now.minute());
  return String(dateTime);
}

String formatTime(unsigned long ms) {
    unsigned long totalSeconds = ms / 1000;
    unsigned long totalMinutes = totalSeconds / 60;
    unsigned long hours = totalMinutes / 60;
    unsigned long minutes = totalMinutes % 60;
    unsigned long seconds = totalSeconds % 60;
    unsigned long centiseconds = (ms % 1000) / 10;

    char buffer[11];
    sprintf(buffer, "[%02lu:%02lu:%02lu:%02lu]", hours, minutes, seconds, centiseconds);
    return String(buffer);
}

void displayTime(int hours, int minutes, int seconds, int milliseconds) {
  lc.setDigit(0, 7, (hours / 10) % 10, false); // Tenth of an hour
  lc.setDigit(0, 6, hours % 10, true);         // Hour
  lc.setDigit(0, 5, (minutes / 10) % 10, false);// Tenth of a minute
  lc.setDigit(0, 4, minutes % 10, true);        // Minute
  lc.setDigit(0, 3, (seconds / 10) % 10, false);// Tenth of a second
  lc.setDigit(0, 2, seconds % 10, true);       // Second
  lc.setDigit(0, 1, (milliseconds / 10) % 10, false);// Tenth of a millisecond
  lc.setDigit(0, 0, milliseconds % 10, false); // Millisecond
}

void beepAndBlink() {
  for (int i = 0; i < 2; ++i) {
    analogWrite(buzzerPin, 1000);  // Use a PWM value to produce a sound
    digitalWrite(ledPin, HIGH);  // Turn on the LED
    delay(100);  // Keep the sound and the light on for 100 ms
    analogWrite(buzzerPin, 0);    // Stop the sound
    digitalWrite(ledPin, LOW);   // Turn off the LED
    delay(100);  // Keep the state off for 100 ms
  }
}
