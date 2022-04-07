#include "asm.h"
#include <DS3231.h> // https://github.com/NorthernWidget/DS3231 (v1.0.7)
#include <Wire.h>

#define clock_vcc 17
#define clock_gnd 16
#define button_pin 4

bool century = false;
bool h12Flag;
bool pmFlag;
byte hour;
byte minute;
byte second;

DS3231 clock;

void setupClock() {
  clock.setClockMode(false);  // set to 24h format
  clock.setYear(22);
  clock.setMonth(4);
  clock.setDate(3);
  clock.setDoW(1);
  clock.setHour(0);
  clock.setMinute(3);
  clock.setSecond(0);
}

void printClock(byte clock_hour, byte clock_minute, byte clock_second) {
  Serial.print(clock_hour);
  Serial.print(":");
  Serial.print(clock_minute);
  Serial.print(":");
  Serial.println(clock_second);
}

void activate_siren_with_delay() {
  activate_siren();
  delay(6000);
  deactivate_siren();
}

void setup() {
  asm_setup();
  pinMode(clock_vcc, OUTPUT);
  pinMode(clock_gnd, OUTPUT);
  digitalWrite(clock_vcc, HIGH);
  digitalWrite(clock_gnd, LOW);
  Wire.begin();
  // Serial.begin(9600);
  // setupClock();
}

void loop() {
  if (digitalRead(button_pin)) {
    deactivate_siren();
    delay(1000);
    hour = clock.getHour(h12Flag, pmFlag); // 24h format
    minute = clock.getMinute();
    second = clock.getSecond();
    // printClock(hour, minute, second);
    if (hour == 7 and minute == 5 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 7 and minute == 10 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 9 and minute == 15 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 9 and minute == 20 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 12 and minute == 45 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 12 and minute == 50 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 14 and minute == 55 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 15 and minute == 0 and second == 0) {
      activate_siren_with_delay();
    }
    else if (hour == 16 and minute == 40 and second == 0) {
      activate_siren_with_delay();
    }
  }
  else {
    activate_siren();
  }
}
