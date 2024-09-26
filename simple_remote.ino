#include <IRremote.h>
IRrecv ricevitor(A3);
//int ledpin=8;

void setup() {
   ricevitor.enableIRIn();
   pinMode(A0, OUTPUT);
   Serial.begin(9600);
}

void loop() {
    if (ricevitor.decode()) {
      Serial.println(ricevitor.decodedIRData.decodedRawData, HEX);

      if (ricevitor.decodedIRData.decodedRawData == 0xF20DFF00) { // u can change the button code to insert any specific button u like, u can get the button codes by simply serial printing the data once u push a button
        digitalWrite(A0, HIGH); // switch this with a servo/relay/transistor or anything u want
      }

      if (ricevitor.decodedIRData.decodedRawData == 0xE619FF00) {
        digitalWrite(A0, LOW);
      }

      delay(500);
      ricevitor.resume();
    }

}
