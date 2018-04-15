
#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#include <Servo.h>


Servo alpha_servo;
Servo bravo_servo;
Servo charlie_servo;
Servo delta_servo;



byte alpha_pin = 7; 
byte bravo_pin = 6;
byte charlie_pin = 5;
byte delta_pin = 3;

int signal = 1700; 

void setup() {
  // put your setup code here, to run once:
  alpha_servo.attach(alpha_pin);
  bravo_servo.attach(bravo_pin);
  charlie_servo.attach(charlie_pin);
  delta_servo.attach(delta_pin);

    alpha_servo.writeMicroseconds(1500);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(1500);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    state = Serial.read(); 
  }
  switch(state){
    case 1: forward(); break; 
    case 2: backward(); break; 
    case 3: left(); break; 
    case 4: right(); break; 
    case 0: st(); break;
    default: st(); break; 
  }
}
void forward(){
  alpha_servo.writeMicroseconds(signal);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(1500);
}
void backward(){
  bravo_servo.writeMicroseconds(signal);
  alpha_servo.writeMicroseconds(1500);

  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(1500); 
}
void left(){
  alpha_servo.writeMicroseconds(1500);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(signal);
  delta_servo.writeMicroseconds(1500);
}
void right(){
    alpha_servo.writeMicroseconds(1500);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(signal);
}
void st(){
  alpha_servo.writeMicroseconds(1500);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(1500);
}
}

