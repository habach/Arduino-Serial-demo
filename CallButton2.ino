#include "Arduino.h"
#include "mycout.h"

String inputString = "", inputString1 = "";    // a string to hold incoming data
volatile boolean stringComplete = false;
volatile boolean stringComplete1 = false; // whether the string is complete
char ch;

void setup() {
	Serial.begin(9600);
	Serial1.begin(115200);
	inputString.reserve(200);
	inputString1.reserve(200);
	Serial << "hello, this is Serial! Send something to me pls.\n";
	delay(100);
	Serial1 << "aloha, this is Serial 1! Send something to me pls.\n";
}

// The loop function is called in an endless loop
void loop() {
		if (stringComplete) {
			Serial << "Serial 0 data: " << inputString << "\n";
			stringComplete = false;
			inputString = "";
		}
		if (stringComplete1) {
			Serial1 << "Serial 1 data: " << inputString1 << "\n";
			stringComplete1 = false;
			inputString1 = "";
		}
}
void serialEvent() {
	while (Serial.available()) {
		ch = (char) Serial.read();
		inputString += ch;
		if (ch == '\n' || ch == '\r') stringComplete = true;
	}
}
void serialEvent1() {
	while (Serial1.available()) {
		ch = (char) Serial1.read();
		inputString1 += ch;
		if (ch == '\n' || ch == '\r') stringComplete1 = true;
	}
}
