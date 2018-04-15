#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008
#include <Servo.h>
#define UDP_TX_PACKET_MAX_SIZE 768 //Fix the fact that someone made the UDP packet size well below standard frame sizes...

//Server for the Shuttlecock client
// Define device details
byte mac[] = {  
  0xDE, 0xAD, 0xBE, 0xEF, 0xAE, 0xED };
IPAddress ip(192, 168, 1, 107); //change this 

unsigned int localPort = 8888;      // local port to listen on

// buffers for receiving and sending data
char packetBuffer[UDP_TX_PACKET_MAX_SIZE]; //buffer to hold incoming packet,
char  ReplyBuffer[] = "Responce: OK ";       // a string to send back

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

Servo alpha_servo;
Servo bravo_servo;
Servo charlie_servo;
Servo delta_servo;
Servo echo_servo;
Servo foxtrot_servo; 

//Servo claw_servo;
//Servo clawrot_servo;

//REMEMBER, THE MOTOR MAPPINGS HERE ASSUME THAT YOU MAPPED ALPHA AND BRAVO TO FORWARD AND BACK
//2017, WE DIDN'T DO THIS. TO FIX IT, WE PUT A PATCH ON THE SURFACE CODE. THIS CODE REMAINS UNAFFECTED DUE TO THE FACT
//THAT ARDUINOS ARE REALLY SLOW RELATIVE TO THE BBB.

// 6 t100 motors
byte alpha_pin = 7; 
byte bravo_pin = 6;
byte charlie_pin = 5;
byte delta_pin = 3;
byte echo_pin = 4 ; 
byte foxtrot_pin = 2 ;


//byte claw_pin = 9;
//byte clawrot_pin = 8;

void setup() {
  // start the Ethernet and UDP:
  Ethernet.begin(mac,ip);
  Udp.begin(localPort);
  Serial.begin(9600);
  
  alpha_servo.attach(alpha_pin);
  bravo_servo.attach(bravo_pin);
  charlie_servo.attach(charlie_pin);
  delta_servo.attach(delta_pin);
  echo_servo.attach(echo_pin);
  foxtrot_servo.attach(foxtrot_pin);
  //claw_servo.attach(claw_pin);
  //clawrot_servo.attach(clawrot_pin);
  
  alpha_servo.writeMicroseconds(1500);
  bravo_servo.writeMicroseconds(1500);
  charlie_servo.writeMicroseconds(1500);
  delta_servo.writeMicroseconds(1500);
  echo_servo.writeMicroseconds(1500);
  foxtrot_server.writeMicroseconds(1500); 
  
  //claw_servo.write(0);
  //clawrot_servo.write(0);
  delay(1000);
}

void loop() {
  // if there's data available, read a packet
  int packetSize = Udp.parsePacket();
  int alpha_power;
  int bravo_power;
  int charlie_power;
  int delta_power;
  int echo_power; 
  int foxtrot_power; 
  
 
  
  //int claw;
  //int clawrot;
  
  String tmp;
  
  String packetinfo;
  
  if(packetSize)
  {
    //Serial.print("Received packet of size ");
    //Serial.println(packetSize);
    //Serial.print("From ");
    //IPAddress remote = Udp.remoteIP();
    //for (int i =0; i < 4; i++)
    //{
      //Serial.print(remote[i], DEC);
      //if (i < 3)
      //{
        //Serial.print(".");
      //}
    //}
    //Serial.print(", port ");
    //Serial.println(Udp.remotePort());

    // read the packet into packetBufffer
    //Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    //Serial.println("Contents:");
    
    Serial.println(packetBuffer);

    //Convert our packet to an interger for further outputting
    Udp.read(packetBuffer,UDP_TX_PACKET_MAX_SIZE);
    packetinfo = packetBuffer;
    //Serial.println("Recieved new motor power values. They are: ");
    Serial.println(packetinfo);
    tmp = packetinfo.substring(0,4);
    alpha_power = atoi(tmp.c_str());
    tmp = packetinfo.substring(5,9);
    bravo_power = atoi(tmp.c_str());
    tmp = packetinfo.substring(10,14);    
    charlie_power = atoi(tmp.c_str());
    tmp = packetinfo.substring(15,19);
    delta_power = atoi(tmp.c_str());
    tmp = packetinfo.substring(20,23);
    //claw = atoi(tmp.c_str());
    tmp = packetinfo.substring(24,27);
    echo_power = atoi(tmp.c_str());
    //clawrot = atoi(tmp.c_str());
    tmp = packetinfo.substri(28,31);
    foxtrot_power = atoi(tmp.c_str());
    
    
    alpha_servo.writeMicroseconds(alpha_power);
    bravo_servo.writeMicroseconds(bravo_power);
    charlie_servo.writeMicroseconds(charlie_power);
    delta_servo.writeMicroseconds(delta_power);
    echo_servo.writeMicroseconds(echo_power); 
    foxtrot_servo.writeMicroseconds(foxtrot_power);
    
    
    //claw_servo.write(claw);
    //clawrot_servo.write(clawrot);
    
    // send a reply, to the IP address and port that sent us the packet we received
   // Udp.beginPacket(Udp.remoteIP(), Udp.remotePort());
   // Udp.write(ReplyBuffer);
  //  Udp.endPacket();
  }
  
  
  
}
