/*
Author: Benjamin Low
 Last updated: 30 Oct 2015
 Description: Simple ADC read from rotoscope by the Teensy 3.1
 */

#include <analog.c>

#define sensorPin 16 //to actual LRF sensor

int sensorReading;

void setup() {
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
  Serial.flush();

  analogReadRes(12); //set to X bit resolution

  analogReadAveraging(32); //set to average of 32 readings
}

void loop() {

  Serial.println(analogRead(sensorPin));
  delay(20); //need to add some delay to avoid choke at bridge program

}


