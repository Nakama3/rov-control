#include <Servo.h> 

//test using most of the motors 
//on 2-7 
byte alphaPin = 2;
byte bravoPin = 3;
byte charliePin = 4;
byte deltaPin =5;
byte echoPin =6;
byte foxtrotPin = 7; 

Servo alphaServo;
Servo bravoServo;
Servo charlieServo;
Servo deltaServo;
Servo echoServo; 
Servo foxtrotServo;

void setup() {
  // put your setup code here, to run once:
  alphaServo.attach(alphaPin);
  bravoServo.attach(bravoPin);
  charlieServo.attach(charliePin);
  deltaServo.attach(deltaPin);
  echoServo.attach(echoPin);
  foxtrotServo.attach(foxtrotPin);

    alphaServo.writeMicroseconds(1500); // send "stop" signal to ESC.
    bravoServo.writeMicroseconds(1500); // send "stop" signal to ESC.
    charlieServo.writeMicroseconds(1500); // send "stop" signal to ESC.
    deltaServo.writeMicroseconds(1500); // send "stop" signal to ESC.
    echoServo.writeMicroseconds(1500); // send "stop" signal to ESC.
    foxtrotServo.writeMicroseconds(1500); // send "stop" signal to ESC.


}

void loop() {
  // put your main code here, to run repeatedly:
  
   int highSignal = 1700;  //between 1100 and 1900
   int lowSignal = 1200; 

   
   
   
   alphaServo.writeMicroseconds(highSignal);
   bravoServo.writeMicroseconds(highSignal);
   charlieServo.writeMicroseconds(highSignal);
   deltaServo.writeMicroseconds(highSignal);
   echoServo.writeMicroseconds(highSignal);
   foxtrotServo.writeMicroseconds(highSignal);

   delay(1000);                  // waits for a second

   alphaServo.writeMicroseconds(lowSignal);
   bravoServo.writeMicroseconds(lowSignal);
   charlieServo.writeMicroseconds(lowSignal);
   deltaServo.writeMicroseconds(lowSignal);
   echoServo.writeMicroseconds(lowSignal);
   foxtrotServo.writeMicroseconds(lowSignal);
  delay(1000); //wait for another second 



}
