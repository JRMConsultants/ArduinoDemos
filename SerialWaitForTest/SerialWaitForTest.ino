/*
 * Simple demo that reads from the software serial port and waits for a string
 */

#include <SoftwareSerial.h>

#define BAUDRATE 115200
#define SSBAUDRATE 57600

SoftwareSerial mySerial(10, 11); // RX, TX

// Buffer to store incoming commands from serial port
String inData;

void setup() {
    Serial.begin(BAUDRATE);
      while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
    Serial.println("Rready.");
    mySerial.begin(SSBAUDRATE);
}

void loop() {
    while (mySerial.available() > 0) {
      char received = mySerial.read();
      inData += received;
        // Process message when new line character is recieved
        if (received == '\n' || received == ':')
        {
            Serial.print("Arduino Received: ");
            Serial.println(inData);
            if (!inData.endsWith("\n")) {
              Serial.println();
            }
            
            if (inData.indexOf("login:") != -1) {
              Serial.println("FOUND LOGIN PROMPT");
            }

            inData = ""; // Clear recieved buffer
        }
    }
}
