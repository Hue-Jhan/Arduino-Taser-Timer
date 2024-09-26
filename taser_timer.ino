#include "SevSeg.h"

SevSeg sevseg;
const int buzzerPin = 0;
const int pinBomba = A5;
const unsigned long countdownDuration = 10000; // 10 seconds

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(pinBomba, OUTPUT);
  
  byte numDigits = 4;
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {9, 2, 3, 5, 6, 8, 7, 4};
  
  bool resistorsOnSegments = false;
  byte hardwareConfig = COMMON_ANODE; // Change to COMMON_CATHODE if ur using a common cathode display
  bool updateWithDelays = false;
  bool leadingZeros = true; // Display leading zeros
  bool disableDecPoint = true; // Disable the decimal point

  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments,
               updateWithDelays, leadingZeros, disableDecPoint);
  sevseg.setBrightness(90);
}

void loop() {
  unsigned long startTime = millis();
  unsigned long endTime = startTime + countdownDuration;

  while (millis() < endTime) {
    unsigned long remainingTime = endTime - millis(); 
    displayCountdown(remainingTime);
  }

  digitalWrite(pinBomba, HIGH);
  tone(buzzerPin, 700, 1000);
  delay(2000);
  digitalWrite(pinBomba, LOW);
}

void displayCountdown(unsigned long remainingTime) {
  unsigned long seconds = remainingTime / 1000;
  unsigned int minutes = seconds / 60;
  unsigned int secondsLeft = seconds % 60;
  
  // Convert minutes and seconds to a 4-digit number
  unsigned int displayNumber = minutes * 100 + secondsLeft;
  sevseg.setNumber(displayNumber, 0);
  sevseg.refreshDisplay();
}
