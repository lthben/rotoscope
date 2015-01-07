/*
Author: Benjamin Low
 Date: 7 Jan 2015
 Description: Simple ADC read from rotoscope
 by the Teensy 3.1
 */

#include <analog.c>

#define sensorPin 14
#define ledPin 6

int sensorReading;
boolean blinkState; //for the LED just to show circuit is working

void setup() { 
        Serial.begin(9600);
        Serial.flush();

        analogReadRes(12); //set to X bit resolution
        analogReadAveraging(10000); //set to average of X readings
}

void loop(){
        
        sensorReading = analogRead(sensorPin);
        
        Serial.print("ADC reading: ");
        Serial.println(sensorReading); 
        
        blinkState = !blinkState;
        
        if (blinkState) {
                digitalWrite(ledPin, HIGH);
        } else {
                digitalWrite(ledPin, LOW);        
        }
        
        delay(100); 
}



