/*
Author: Benjamin Low
 Last updated: 30 Oct 2015
 Description: Simple ADC read from rotoscope
 by the Arduino
 */

#define sensorPin 0 //to actual LRF sensor

void setup() {
  pinMode(sensorPin, INPUT);

  Serial.begin(9600);
  Serial.flush();
}

void loop() {
  Serial.println(analogRead(sensorPin));
  delay(20); 
}
