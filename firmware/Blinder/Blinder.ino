#define I2C_SLAVE_ADDRESS 0x3   //this slave address (0x1, 0x2, 0x3)
#define NUM_PIXELS 2
#define NEO_PIN 1
#include <TinyWireS.h>          //the ATTiny Wire library
#include <Adafruit_NeoPixel.h>

// 6 bytes
// 0 : R1
// 1 : G1
// 2 : B1
// 3 : R2
// 4 : G2
// 5 : B2

byte data[6] = { 0 };

Adafruit_NeoPixel pixels(NUM_PIXELS, NEO_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onReceive(receiveEvent);

  pixels.begin();

  pixels.clear();
  pixels.show();
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
  for (int i = 0; i<NUM_PIXELS; i++) {
    byte r = data[i*3 + 0];
    byte g = data[i*3 + 1];
    byte b = data[i*3 + 2];
    pixels.setPixelColor(i, pixels.Color(r, g, b));
  }

  pixels.show();
}