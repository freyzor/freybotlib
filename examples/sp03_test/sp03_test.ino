#include <Wire.h>
#include <Arduino.h>
#include <sp03.h>
#include <Commander.h>

Sp03 speech;
Commander command;

void setup() {
	Wire.begin();
	TWBR = ((F_CPU / 400000) - 16) / 2;//set the I2C speed to 400KHz
	command.begin(38400);
	delay(1000);
	Serial.print("Device address is: ");
	Serial.println(SP03_ADDRESS);
}

void loop() {
	Serial.println("Saying 'Hello'");
	speech.say("Hello");
	delay(2000);
	Serial.println("Saying 'This is a very messed up chip tune'");
	speech.say("This is a very messed up chip tune");
	delay(3000);
}