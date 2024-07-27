#include <Keypad.h>
#include <LedControl.h>

const byte ROWS = 4; 
const byte COLS = 4; 

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {6, 7, 8, 9}; 
byte colPins[COLS] = {2, 3, 4, 5}; 

Keypad keypadObj = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);
LedControl lc = LedControl(10, 11, 12, 1);

unsigned long previousMillisCountdown = 0;  
unsigned long previousSecond = 0;      

long csecondsLeft;
int decrement = 1;

bool explosed = false;
bool defused = false;
bool isCountingDown = false;
bool isProgrammingTime = false;

String inputKeys = ""; 
String programmedTime = ""; 

long hours = 0;
long minutes = 0;
long seconds = 0;
long hundredths = 0;

char keypadOutput[32] = {0};

byte playSound = A0;
byte a_segment = B01000000; 
byte d_segment = B00001000;

void setup() {
  
  Serial.begin(9600);

  lc.shutdown(0, false);
  lc.setIntensity(0, 10);
  lc.clearDisplay(0); 

  //Initialiser ici la logique pour gérer les actions sur sortie M12
  
  pinMode(13, OUTPUT);   
  pinMode(A1, OUTPUT);   

  startUp();
}

void startUp() {

    for (int i = 0; i < 3; ++i) {
        tone(playSound, 1000, 100);
        digitalWrite(13, HIGH);
        delay(80);
        digitalWrite(13, LOW);
        delay(150);
    }

    for (int i = 0; i < 4; ++i) {
        lc.setRow(0, i, d_segment);
        lc.setRow(0, 7 - i, a_segment);
        delay(50);
        lc.clearDisplay(0);
    }

    for (int i = 3; i >= 0; --i) {
        lc.setRow(0, i, a_segment);
        lc.setRow(0, 7 - i, d_segment);
        delay(50);
        lc.clearDisplay(0);
    }
} 

void updateDisplay() {
  long remainingTime = csecondsLeft;

  hours = remainingTime / 3600000;
  remainingTime %= 3600000;
  minutes = remainingTime / 60000;
  remainingTime %= 60000;
  seconds = remainingTime / 1000;
  hundredths = (remainingTime % 1000) / 10; 

  lc.setDigit(0, 7, hours / 10, false);
  lc.setDigit(0, 6, hours % 10, false);
  lc.setDigit(0, 5, minutes / 10, false);
  lc.setDigit(0, 4, minutes % 10, false);
  lc.setDigit(0, 3, seconds / 10, false);
  lc.setDigit(0, 2, seconds % 10, false);
  lc.setDigit(0, 1, hundredths / 10, false);
  lc.setDigit(0, 0, hundredths % 10, false);
}

void programTime() {

  if (inputKeys.length() >= 8) {

    inputKeys = inputKeys.substring(0, 8);

    programmedTime = inputKeys.substring(0, 2) + ":" + 
                     inputKeys.substring(2, 4) + ":" + 
                     inputKeys.substring(4, 6) + ":" + 
                     inputKeys.substring(6, 8);

    Serial.print("inputKeys: "); Serial.println(inputKeys);

    lc.clearDisplay(0);

    inputKeys = "";
  }
}

void startCountdown() {
  Serial.println("Starting Countdown...");

  if (programmedTime.length() == 11) { 
    hours = programmedTime.substring(0, 2).toInt();
    minutes = programmedTime.substring(3, 5).toInt();
    seconds = programmedTime.substring(6, 8).toInt();
    hundredths = programmedTime.substring(9, 11).toInt();

    csecondsLeft = ((hours * 3600) + (minutes * 60) + seconds) * 1000 + (hundredths * 10);
  } else {
    Serial.println("Invalid programmed time. Please enter a time greater than zero.");
    return;
  }

  updateDisplay();
  isCountingDown = true; 
}


void loop() {
  char key = keypadObj.getKey();

  if (key) {
    handleKeypadInput(key);
  } else if (isCountingDown) {
    handleCountdown();
  }
}

void handleKeypadInput(char key) {
  Serial.print("Key Pressed: ");
  Serial.println(key);

  if (key >= '0' && key <= '9') {
    handleNumericKey(key);
  } else {
    switch (key) {
      case 'A':
        handleKeyA();
        break;
      case 'B':
        handleKeyB();
        break;
      case 'C':
        handleKeyC();
        break;
      case 'D':
        handleKeyD();
        break;
    }
  }
}

void handleNumericKey(char key) {
  int num = key - '0';
  int displayIndex = 7 - inputKeys.length();
  lc.setDigit(0, displayIndex, num, false);
  inputKeys += key;
  tone(playSound, 2000, 50);
}

void handleKeyA() {
      Serial.println("Programming Time...");
      isProgrammingTime = true;
      inputKeys = ""; 
      programmedTime = ""; 
      lc.clearDisplay(0); 
}

void handleKeyB() {
  if (isCountingDown) {
    if (!defused) {
      decrement = 0; 
      defused = true; 
    }
  }
}

void handleKeyC() {
      isProgrammingTime = false;
      lc.setDigit(0, 7, 0, false);
      lc.clearDisplay(0);
}

void handleKeyD() {
  if (isProgrammingTime) {
    isProgrammingTime = false;
    programTime();
    Serial.print("Programmed Time: ");
    Serial.println(programmedTime);
    startCountdown();
    programmedTime = ""; 
  } else if (isCountingDown && defused) {
    decrement = 1; 
    defused = false; 
  }
}

void handleCountdown() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillisCountdown >= 10) { 
    previousMillisCountdown = currentMillis;

    if (csecondsLeft > 0 && decrement > 0) { 
      csecondsLeft -= 10; 

      if (csecondsLeft <= 0) { 
        csecondsLeft = 0;
        if (!explosed) {
          Serial.print("! DETONATING !");
          
          //Inserer ici la logique pour gérer les actions sur sortie M12

          digitalWrite(13, HIGH); 
          digitalWrite(A1, HIGH); 
          
          tone(playSound, 1000);
          explosed = true; 
        }
      }

      if (csecondsLeft / 1000 != previousSecond) {
        previousSecond = csecondsLeft / 1000;
        tone(playSound, 1000, 100); 
      }
      updateDisplay();
    }
  }
}
