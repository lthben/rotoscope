/*
Author: Benjamin Low
<<<<<<< HEAD
 Last updated: 30 Oct 2015
 Description: Simple ADC read from rotoscope by the Teensy 3.1
=======
 Last updated: 29 Oct 2015
 Description: Simple ADC read from rotoscope
 by the Teensy 3.1
>>>>>>> origin/master
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

<<<<<<< HEAD
  Serial.println(analogRead(sensorPin));
  delay(20); //need to add some delay to avoid choke at bridge program
=======
        sensorReading = analogRead(sensorPin);
//        sensorReading = map(sensorReading, 0, 4096, 200, 10000); //from 10 bit ADC resolution to sensor reading in mm 
>>>>>>> origin/master

}


