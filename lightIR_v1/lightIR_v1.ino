#include <IRremote.h>
#define Button1 = 0xE0E0629D

int sensorPin = 0;
int value = 0;
int sensorPin2 = 1;
int value2 = 0;

const int IRsensor1 = 6;
int IRvalue1 = 0; //Hoe pas ik deze waarde aan?  
int IRvalue2 = 0;
const int IRsensor2 = 7; 
int IRvalue3 = 0;
int IRvalue4 = 0; 

IRrecv irrecv1(IRsensor1);
IRrecv irrecv2(IRsensor2);
decode_results results;


void setup() {
  Serial.begin(57600);
 // pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);
  irrecv1.enableIRIn();
  irrecv2.enableIRIn();

}

void loop() {
 //2 LDR sensors
  value = analogRead(sensorPin);
  value2 = analogRead(sensorPin2);

// 2 IR sensors met 2 knopjes
if (irrecv1.decode(&results)){
  Serial.println(results.value, HEX);

    switch (results.value){
      case 0xE0E0629D:
      Serial.print("IR 1");
      Serial.println(IRvalue1);
      break; 

     case 0xE0E0926D:
      Serial.print("IR 2");
      Serial.println(IRvalue2);
     }
     break; 
 }
 irrecv1.resume();
 }  

 if (irrecv2.decode(&results)){
  Serial.println(results.value, HEX);

    switch (results.value){
      case 0xE0E0629D:
      Serial.print("IR 3");
      Serial.println(IRvalue3);
      break; 

     case 0xE0E0926D:
      Serial.print("IR 4");
      Serial.println(IRvalue4);
     }
     break; 
 }
 irrecv1.resume();
 }


  Serial.print("LDR1 ");
  Serial.println(value);
  Serial.print("LDR1 ");
  Serial.println(value2);

 /* if (value2 > 0) {
    digitalWrite(ledPin, HIGH);
                      }
  else {
    digitalWrite(ledPin, LOW);
         }
 */
  delay(100);

}
