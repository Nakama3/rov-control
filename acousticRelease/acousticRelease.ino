/**
MODULE: Electret Microphone Amplifier - MAX4466 with Adjustable Gain 
READS FREQUENCY FROM MICROPHONE AMPLIFIER 
**/

#include <Wire.h>
#include <Adafruit_DRV2605.h>

int soundSensorPIN = A0; 
Adafruit_DRV2605 drv;

//until when should we incrememt?? temp 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  drv.begin();
  drv.selectLibrary(1);
  drv.setMode(DRV2605_MODE_INTTRIG);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.begin("began"); 
   //variable for current sensor value
   unsigned long currentFreq = analogRead(soundSensorPIN);
   //calculate change in sensor value
   Serial.print("frequency: " + currentFreq);   
   if(currentFreq == 100)
   {
    Serial.print("hello"); 
   }
}


