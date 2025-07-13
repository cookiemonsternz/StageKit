#define I2C_SLAVE_ADDRESS 0x3   //this slave address (0x1, 0x2, 0x3)
#define PWM_PERIOD 2000 // period in microseconds, 2000us is 500Hz
#include <TinyWireS.h>          //the ATTiny Wire library

// 3 bytes
// 0 : R
// 1 : G
// 2 : B
byte data[3] = { 0 };

uint32_t lastPwmCycle = 0;

void setup() {
  TinyWireS.begin(I2C_SLAVE_ADDRESS);
  TinyWireS.onReceive(receiveEvent);

  pinMode(1, OUTPUT); // R
  pinMode(3, OUTPUT); // G
  pinMode(4, OUTPUT); // B
}

void loop() {
  // put your main code here, to run repeatedly:
  TinyWireS_stop_check();
  updateSoftwarePWM();
}

void updateSoftwarePWM() {
  uint8_t duty_cycle = byte(255) - data[2];
  uint32_t now = micros();
  uint32_t phase = (now - lastPwmCycle) % PWM_PERIOD;
  if (phase == 0) {
    lastPwmCycle = now;
  }

  if (phase < (duty_cycle * PWM_PERIOD) / 255) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }
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
  // rgb par is kinda stupid, in that we need to pull pins low to increase brightness
  // so we need to analog write inverse ish (255-val)
  // PB4 doesn't have pwm, so software pwm handles it
  // pinout is as follows
  // PB1 : R
  // PB3 : G
  // PB4 : B
  byte r_value = byte(255) - data[0];
  byte g_value = byte(255) - data[1];
  analogWrite(1, r_value);
  analogWrite(3, g_value);
}