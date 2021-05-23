#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(4, LOW);

  delay(3000);
  
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(4, HIGH);

  ESP.deepSleep(30e6);
}
