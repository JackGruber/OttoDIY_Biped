#include <Arduino.h>
#include <biped.h>
#include <io_pins.h>

Biped Walker(PIN_LEFT_LEG, PIN_RIGHT_LEG, PIN_LEFT_FOOT, PIN_RIGHT_FOOT);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting Biped ..."));
  Walker.Home();
}

void loop() {
  // put your main code here, to run repeatedly:
}