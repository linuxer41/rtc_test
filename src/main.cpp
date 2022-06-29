#include <Arduino.h>
#include <Wire.h>
#include "RTClib.h"

RTC_DS1307 rtc;

const byte SQWinput = 2;

void Isr();
long counter = 0;

void setup () {
  Serial.begin(115200);
  rtc.begin(); //Inicializamos el RTC
  Serial.println("Estableciendo Hora y fecha...");
  // rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  // Serial.println("DS1307 actualizado con la hora y fecha que se compilo este programa:");
  // Serial.print("Fecha = ");
  // Serial.print(__DATE__);
  // Serial.print("  Hora = ");
  // Serial.println(__TIME__);
  rtc.begin();
  rtc.writeSqwPinMode(DS1307_SquareWave1HZ);
  pinMode(SQWinput, INPUT);                                                // Configure the SQWinput pin as an INPUT to monitor the SQW pin of the DS3231.
  digitalWrite(SQWinput, HIGH);                                            // Enable the internal pull-up resistor, since the SQW pin on the DS3231 is an Open Drain output.
  // attachInterrupt(digitalPinToInterrupt(SQWinput), Isr, FALLING); // Configure SQWinput (pin 2 of the Arduino) for use by the Interrupt Service Routine (Isr)
  attachInterrupt(0, Isr, RISING); // Configure SQWinput (pin 2 of the Arduino) for use by the Interrupt Service Routine (Isr)
  
}

void loop () {
  // DateTime now = rtc.now();
  // Serial.print("Fecha = ");
  // Serial.print(now.month());
  // Serial.print("/");
  // Serial.print(now.day());
  // Serial.print("/");
  // Serial.print(now.year());
  // Serial.print("  Hora = ");
  // Serial.print(now.hour());
  // Serial.print(":");
  // Serial.print(now.minute());
  // Serial.print(":");
  // Serial.print(now.second());
  Serial.println("hola mundo");
  delay(1000);
}
void Isr () {
    counter++;
    Serial.print("Interrupt: ");
    Serial.println(counter);
}