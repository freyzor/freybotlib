#include <Wire.h>
#include <Arduino.h>
#include <srf10.h>
#include <Commander.h>

Srf10 sonar = Srf10(0);
Commander command;

void setup() {
	Wire.begin();
	TWBR = ((F_CPU / 400000) - 16) / 2;//set the I2C speed to 400KHz
	command.begin(38400);
	delay(1000);

}

void loop() {
	Serial.print("Version: ");
	Serial.println(sonar.getVersion());
	Serial.println("Pinging...");
	sonar.ping();
	delay(100);
	Serial.print("range: ");
	Serial.println(sonar.getData());
	delay(1000);
}