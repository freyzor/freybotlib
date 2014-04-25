#include "sp03.h"
#include <Arduino.h>
#include <Wire.h>

int Sp03::getVersion() {
    Wire.beginTransmission(SP03_ADDRESS);
    Wire.write(byte(SP03_VERSION));
    Wire.endTransmission();
    // read back data
    Wire.requestFrom(SP03_ADDRESS, (int) 1);
    while(Wire.available() < 1){
        // need some sort of timeout!
    }
    // fill our data    
    return (int) Wire.read();
}

//bool Sp03::isBusy() { return false; }

void Sp03::say(const char* phrase) {
	Wire.beginTransmission(SP03_ADDRESS);
    Wire.write(byte(SP03_COMMAND));
    Wire.write(byte(SP03_NOP));

    Wire.write(byte(0x00)); // volume  max 0-7 quietest
    Wire.write(byte(0x05)); // speed
    Wire.write(byte(0x03)); //  pitch

    int i = 0;
    while(phrase[i] != 0x00)
    {
    	Wire.write(byte(phrase[i++]));
    }
    Wire.write(byte(0x00));
    Wire.write(byte(SP03_SPKBUF));
    Wire.endTransmission();
}

bool Sp03::isSpeaking() {
    Wire.beginTransmission(SP03_ADDRESS);
    Wire.write(SP03_COMMAND);
    Wire.endTransmission();
    // read back data
    Wire.requestFrom(SP03_ADDRESS, (int) 1);
    while(Wire.available() < 1){
        // need some sort of timeout!
    }
    // fill our data    
    return Wire.read() != 0;
}