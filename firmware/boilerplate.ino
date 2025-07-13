/*
This code implements a very basic i2c slave device for the attiny85.
This can be used as a base for all basic rgb pan tilt lights and it should
function relatively predictably. Update light just needs to be changed for
the specific light to do what you want, and when flashing, make sure to assign
a different slave adress* to each light, lest you have conflicting adresses.

*I couldn't think of a better way to do this :(
*/

#define I2C_SLAVE_ADDRESS 0x3   //this slave address (0x1, 0x2, 0x3)
#include <TinyWireS.h>          //the ATTiny Wire library

// 5 bytes
// 1 : R
// 2 : G
// 3 : B
// 4 : PAN
// 5 : TILT
byte data[5] = { 0 };

void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onReceive(receiveEvent);
}

void loop() {
  // put your main code here, to run repeatedly:
  TinyWireS_stop_check();
}

// i is num bytes received
void receiveEvent(int numBytes)
{
  if (numBytes > sizeof(data)) {
    return;
  }
  for (byte i=0; i<numBytes; i++) {
    data[i] = TinyWireS.read();
  }
  updateLight();
}

void updateLight() {
  // light specific code here
}