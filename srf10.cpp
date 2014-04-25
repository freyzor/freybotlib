#include "srf10.h"
#include <Arduino.h>
#include <Wire.h>

/** Constructor */
Srf10::Srf10(unsigned char device){
    _device = device;
    _lastping = millis();
}

/** = version of sonar sonar */
int Srf10::getVersion() {
    Wire.beginTransmission(SRF_ADDR+_device);
    Wire.write(SRF_COMMAND);
    Wire.endTransmission();
    // read back data
    Wire.requestFrom(SRF_ADDR+_device, (int) 1);
    while(Wire.available() < 1){
        // need some sort of timeout!
    }
    // fill our data    
    return (int) Wire.read();
}

/** We must ping the sonar before we can read it back. */
void Srf10::ping(){
    // write command to read in CM
    Wire.beginTransmission(SRF_ADDR+_device);
    Wire.write(byte(SRF_COMMAND));
    Wire.write(byte(SRF_CMD_CM));
    Wire.endTransmission();
}

/** = a reading from a sonar, should call ping first. */
int Srf10::getData(){
    int distance;
    Wire.beginTransmission(SRF_ADDR+_device);
    Wire.write(byte(SRF_ECHO_H));
    Wire.endTransmission();
    // read back data
    Wire.requestFrom(SRF_ADDR+_device, (int) 2);
    while(Wire.available() < 2){
        // need some sort of timeout!
    }
    distance = Wire.read();
    distance = distance << 8;
    distance |= Wire.read();
    return distance;
}

bool Srf10::isPingDone() {
	return (millis() - _lastping) > PING_DURATION_MS;
}

/** Change address of SRF 08
int Srf10ChangeAddr(unsigned char oldAddr, unsigned char newAddr){
    i2cStart(SRF_ADDR + I2C_WRITE + (2 * oldAddr));
    i2cWrite(SRF_COMMAND);
    i2cWrite(0xA0);
    i2cStop();   
    i2cStart(SRF_ADDR + I2C_WRITE + (2 * oldAddr));
    i2cWrite(SRF_COMMAND);
    i2cWrite(0xAA);
    i2cStop();   
    i2cStart(SRF_ADDR + I2C_WRITE + (2 * oldAddr));
    i2cWrite(SRF_COMMAND);
    i2cWrite(0xA5);
    i2cStop();   
    i2cStart(SRF_ADDR + I2C_WRITE + (2 * oldAddr));
    i2cWrite(SRF_COMMAND);
    // actually send address
    i2cWrite(SRF_ADDR + (2 * newAddr));
    i2cStop(); 
} NOTE THIS CODE WORKS, BUT IS NOT STANDARD TO INCLUDE. */

