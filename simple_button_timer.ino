#include <Servo.h>

const int buttonPin = 2;   
const int servoPin = 3;     
const unsigned long countdownDuration = 1000; //10 secs

Servo myServo;
bool countdownStarted = false;
unsigned long countdownStartTime = 0;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); 
  myServo.attach(servoPin);         
}

void loop() {
  if (digitalRead(buttonPin) == LOW && !countdownStarted) {
    startCountdown();
  }

  if (countdownStarted) {
    unsigned long elapsedTime = millis() - countdownStartTime;
    if (elapsedTime >= countdownDuration) {
      endCountdown();
    }
  }
}

void startCountdown() {
  myServo.write(0); // u can easily replace the servo with a relay or a transistor, i couldnt at the moment
  
  countdownStarted = true;
  countdownStartTime = millis();
}

void endCountdown() {
  myServo.write(90);         
  
  countdownStarted = false;
}
