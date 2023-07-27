/*
nRF24L01:
   1 - GND
   2 - VCC 3.3V !!! 5V DEĞİL !!!
   3 - CE Arduino pin 9
   4 - CSN Arduino pin 8
   5 - SCK Arduino pin 13
   6 - MOSI Arduino pin 11
   7 - MISO Arduino pin 12
   8 - Nothing
 */
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN   9
#define CSN_PIN 8
#define KEY1 67
#define KEY2 67
#define KEY3 67
 

const uint64_t pipe = 0xE8E8F0F0E1LL; // adress
 
RF24 radio(CE_PIN, CSN_PIN); // 
 
int AllDatas[] = {KEY1, KEY2, KEY3}; // keylerimiz

void setup()   
{
  Serial.begin(57600);
  delay(1000);

  
  Serial.println("Nrf24L01 Alıcı Başlatılıyor");
  radio.begin();
  radio.openReadingPipe(1, pipe);
  radio.startListening();
}
 
void loop()   
{
 
  if ( radio.available() ) 
  {
    // Serial.println("Hehhhh ");
    bool done = false;
    // while (!done) 
    // {
      radio.read( AllDatas, sizeof(AllDatas) ); 
      if(AllDatas[1] != 0 || AllDatas[0] != 0){
        Serial.println(sizeof(AllDatas));
        Serial.print("KEY0 = ");
      Serial.println(AllDatas[0]);
        Serial.print("KEY1 = ");
      Serial.println(AllDatas[1]);
        Serial.print("KEY2 = ");
      Serial.println(AllDatas[2]);
      }
    // }
  }
 
  // else
  // {
  //   Serial.println("Verici Bulunamadı");
  //   AllDatas[0] = 9090;
  //   AllDatas[1] = 9090;
 
  // }
 
}
 