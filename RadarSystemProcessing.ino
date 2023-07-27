/*
   1 - GND QARA
   2 - VCC 3.3V QIRMIZI
   3 - CE Arduino pin 9 SARI
   4 - CSN Arduino pin 8 ORANGE
   5 - SCK Arduino pin 13 YASIL
   6 - MOSI Arduino pin 11 MAVI
   7 - MISO Arduino pin 12 BENOVSEYI
   8 - Nothing

 */
#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define trigPin 4
#define echoPin 5
#define servoPin 6
#define motionPin 7
#define CSN_PIN 8
#define CE_PIN   9

const uint64_t pipe = 0xE8E8F0F0E1LL;
// long duration;
int distance;
int motion;
int isSuccess;
int i=0;
int AllDatas[3];

Servo myServo; 
RF24 radio(CE_PIN, CSN_PIN);

void setup() {
  Serial.begin(57600); 
  radio.begin();
  pinMode(motionPin, INPUT); 
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT); 
  pinMode(servoPin, OUTPUT); 
  radio.openWritingPipe(pipe); //addrese connect olduq
  myServo.attach(servoPin); 
}
void loop() {
  for(i=20;i<=160;i++){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  motion = digitalRead(motionPin);
  Serial.print(motion); 
  Serial.print(":"); 
  Serial.print(i); 
  Serial.print(","); 
  Serial.print(distance); 
  Serial.print(".");
  isSuccess = radio.write(motion,i,distance);
  // Serial.print(isSuccess);
  // Serial.println("");
  // if(isSuccess) delay(1000);
  }
  for(i=160;i>20;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  motion = digitalRead(motionPin);
  Serial.print(motion);
  Serial.print(":");
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  isSuccess = radio.write(motion,i,distance);
  // Serial.print(isSuccess);
  // Serial.println("");
  }

  //  delay(500);
}

int calculateDistance(){ 
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  return distance;
}