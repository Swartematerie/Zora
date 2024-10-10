#include <IRremote.h>
#define Button1 = 0xE0E0629D

const int RECV_PIN = 6;
const int ledPin = 13;
const int ledPin2 = 13;
int togglestate = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;



void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
 if (irrecv.decode(&results)){
  Serial.println(results.value, HEX);

    switch (results.value){
      case 0xE0E0629D:
      Serial.println("IR 1");
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(ledPin, LOW);
      break; 

     case 0xE0E0926D:
     if(togglestate==0){
      digitalWrite(ledPin2, HIGH);
      Serial.println("IR 2");
      togglestate=1;
     }
     else{
      digitalWrite(ledPin2, LOW);
      togglestate=0;
     }
     break; 
 }
 irrecv.resume();
 }  
}
