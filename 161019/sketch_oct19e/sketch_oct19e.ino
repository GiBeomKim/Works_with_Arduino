//블루투스 통신

#include <SoftwareSerial.h>
#define rxPin 12
#define txPin 13
#define LED 3
int ledBright = 255;
SoftwareSerial swSerial(rxPin, txPin);
int data;

void changeBrightLED(){
  if (ledBright <= 0){
    ledBright = 0;
    }
  if (ledBright >= 255){
    ledBright = 255;
    }
    analogWrite(LED, ledBright);
  }

void setup(){
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  changeBrightLED();
  }

void loop(){
  if (swSerial.available()){
    data = swSerial.read();
    switch(data){
      case 'U':
        ledBright +=10;
        changeBrightLED();
        break;
      case 'D' :
        ledBright -= 10;
        changeBrightLED();
        break;
      }
    }
    delay(50);
  }
