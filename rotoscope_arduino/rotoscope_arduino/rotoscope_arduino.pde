#include <stdio.h>

#define sensorPin  0//analog pin
#define ledPin 13//digital pin

const int numofReadings= 20;
int arrayReadings[numofReadings];//readings from analog input, average by 20
int averageSensorValue=0;
int totalValue=0;
int index=0;//current index of readings

void setup() { 
  Serial.begin(9600);
  Serial.flush();
  
  //initialization
  for(int i=0; i<numofReadings;i++){
       arrayReadings[i] = 0;
  }
  
  //Serial.println("start");
} 

void loop(){
  // read the value from the sensor:
  totalValue= totalValue - arrayReadings[index];        
  arrayReadings[index] = analogRead(sensorPin);
  totalValue = totalValue + arrayReadings[index];  
  index = index + 1;
  if (index >= numofReadings){//already read numofReadings, average it
    index = 0;
    averageSensorValue = totalValue/numofReadings;
    Serial.println(averageSensorValue);
  }    
  delay(15); 
  
}


