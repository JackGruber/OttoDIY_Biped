#include <Arduino.h>
#include <biped.h>
#include <io_pins.h>
#include <settings.h>

Biped Walker(PIN_LEFT_LEG, PIN_RIGHT_LEG, PIN_LEFT_FOOT, PIN_RIGHT_FOOT);

void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting Biped ..."));
  Walker.TrimServos(SERVO_TRIM_LEFT_LEG, SERVO_TRIM_RIGHT_LEG, SERVO_TRIM_LEFT_FOOT, SERVO_TRIM_RIGHT_FOOT);
  Walker.Home();
}

void loop() {
  // put your main code here, to run repeatedly:
}