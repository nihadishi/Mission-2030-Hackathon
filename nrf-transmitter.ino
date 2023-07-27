/*
nRF24L01 Modül Bağlantıları:
   1 - GND
   2 - VCC 3.3V 
   3 - CE Arduino pin 9
   4 - CSN Arduino pin 8
   5 - SCK Arduino pin 13
   6 - MOSI Arduino pin 11
   7 - MISO Arduino pin 12
   8 - Kullanmıyoruz
 */

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 8
#define TRIG_PIN 2
#define ECHO_PIN 3

const uint64_t pipe = 0xE8E8F0F0E1LL;
 
RF24 radio(CE_PIN, CSN_PIN); // 

int verilerim[2];
 
void setup()
{
  Serial.begin(57600); 
  radio.begin();

  // pinMode(TRIG_PIN, OUTPUT);
  // pinMode(ECHO_PIN, INPUT);

  radio.openWritingPipe(pipe); //addrese connect olduq
}
 
void loop()
{

  // digitalWrite(TRIG_PIN, LOW);
  // delayMicroseconds(2);
  // digitalWrite(TRIG_PIN, HIGH);
  // delayMicroseconds(10);
  // digitalWrite(TRIG_PIN, LOW);
  // long duration = pulseIn(ECHO_PIN, HIGH);
  // float distance_cm = duration * 0.0343 / 2;

  verilerim[0]= 123;
  verilerim[1]= 567;

 int a =  radio.write( verilerim, sizeof(verilerim) );
 Serial.println(a);
  delay(500);
 
}