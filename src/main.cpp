#include <Arduino.h>

// GPIO pin connected to pump
#define PUMP_PIN 4

// How long the pump should turn on
#define POWER_DURATION 3000

// How long to sleep (max is 72 minutes) (36e8 is 1h) (60e6 is 1m)
#define SLEEP_DURATION 36e8

// Every how many times sleeping it should turn on
#define SLEEP_INTERVAL 2

// RTC memory adresses for saving timer
#define RTC_WAKE_COUNT 24

void setup() {

  // Bump sleep counter
  uint32_t sleepCount = 0;
  if (ESP.getResetReason() == "Deep-Sleep Wake") {
    ESP.rtcUserMemoryRead(RTC_WAKE_COUNT, &sleepCount, 4);
    sleepCount++;
  }
  ESP.rtcUserMemoryWrite(RTC_WAKE_COUNT, &sleepCount, 4);

  // Turn on LED
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  // Turn on pump
  if (sleepCount % SLEEP_INTERVAL == 0) {
    pinMode(PUMP_PIN, OUTPUT);    
    digitalWrite(PUMP_PIN, LOW);
    delay(POWER_DURATION);
  }

  ESP.deepSleep(SLEEP_DURATION);
}

void loop() {}
