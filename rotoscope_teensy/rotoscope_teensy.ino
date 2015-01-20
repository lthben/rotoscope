/*
Author: Benjamin Low
 Date: 7 Jan 2015
 Description: Simple ADC read from rotoscope
 by the Teensy 3.1
 */

#include <analog.c>

//#define sensorPin 14 //for testing pot
#define sensorPin 16 //to actual LRF sensor
//#define ledPin 6

int sensorReading;
const int NUM_READINGS = 20; //number of readings to average. The higher the number, the more stable the reading subject to CPU latency.
const long SAMPLING_TIME_INTERVAL = 100; //time interval between each reading output in milliseconds to avoid the use of delay()
long prev_time; //the last time a reading was reported 
int readings [NUM_READINGS];
int array_index;
int sum_of_readings;

void setup() {
       // pinMode(ledPin, OUTPUT);
        pinMode(sensorPin, INPUT);

        Serial.begin(9600);
        Serial.flush();

        analogReadRes(12); //set to X bit resolution

        analogReadAveraging(100); //set to average of X readings

        //digitalWrite(ledPin, HIGH);
}

void loop(){

        sensorReading = analogRead(sensorPin);
        sensorReading = map(sensorReading, 0, 4096, 200, 10000); //from 10 bit ADC resolution to sensor reading in mm 
        
        //override the previous reading contained at the array index
        sum_of_readings -= readings[array_index];
        sum_of_readings += sensorReading;
        readings[array_index] = sensorReading;
        
        array_index++;
        
        if (array_index >= NUM_READINGS) {
          array_index = 0;       
        }

        if (millis() - prev_time > SAMPLING_TIME_INTERVAL) {
                
                sensorReading = sum_of_readings / NUM_READINGS;

                //Serial.print("distance: ");
                Serial.println(sensorReading); 

                prev_time = millis();
        }
}





