/*
Author: Benjamin Low
 Last updated: 7 Oct 2015
 Description: Simple ADC read from rotoscope
 by the Teensy 3.1
 */

#include <analog.c>

#define sensorPin 16 //to actual LRF sensor

int sensorReading;

void setup() {
        pinMode(sensorPin, INPUT);

        Serial.begin(9600);
        Serial.flush();

        analogReadRes(12); //set to X bit resolution

        analogReadAveraging(100); //set to average of X readings
}

void loop(){

        sensorReading = analogRead(sensorPin);
        sensorReading = map(sensorReading, 0, 4096, 200, 10000); //from 10 bit ADC resolution to sensor reading in mm 

        Serial.println(sensorReading);

        delay(15); //prevent possible choking at the Processing bridge
}





