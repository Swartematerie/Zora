//LDR sensors
int LDRpin1 = 0;
int LDRvalue1 = 0;
int LDRpin2 = 1;
int LDRvalue2 = 0;

//MagneticReed sensors
int REEDpin1 = 12;
int REEDvalue1 = 0;
int oldREEDvalue1 = 0;
int REEDpin2 = 13; 
int REEDvalue2 = 0;
int oldREEDvalue2 = 0;
int REEDpin3 = 11; 
int REEDvalue3 = 0;
int oldREEDvalue3 = 0;
int REEDpin4 = 10; 
int REEDvalue4 = 0;
int oldREEDvalue4 = 0;

//IRsensors
#include <IRremote.h>
#define Button1 = 0xE0E0629D
const int IRsensor1 = 6; 
int IRvalue1 = 0
int oldIRvalue1 = 0;

IRrecv irrecv1(IRsensor1);
decode_results results;



void setup() {
  Serial.begin(9600);
  pinMode(LDRpin1, INPUT);
  pinMode(LDRpin2, INPUT);
  pinMode(REEDpin1, INPUT);
  pinMode(REEDpin2, INPUT);
  irrecv1.enableIRIn();
 

}

void loop() {
/*
//2 LDR sensors
LDRvalue1 = analogRead(LDRpin1);
LDRvalue2 = analogRead(LDRpin2);
  
  Serial.print("LDR1 ");
  Serial.println(LDRvalue1);
  Serial.print("LDR2 ");
  Serial.println(LDRvalue2);


 //4 Magnetic reed sensors
 REEDvalue1 = digitalRead(REEDpin1);
  if (REEDvalue1 != oldREEDvalue1) {
    if (digitalRead(REEDpin1) == LOW)
      Serial.println("REED1 0");
    else
      Serial.println("REED1 1");
    oldREEDvalue1 = REEDvalue1;
  }
  REEDvalue2 = digitalRead(REEDpin2);
  if (REEDvalue2 != oldREEDvalue2) {
    if (digitalRead(REEDpin2) == LOW)
      Serial.println("REED2 0");
    else
      Serial.println("REED2 1");
    oldREEDvalue2 = REEDvalue2;
  }
  REEDvalue3 = digitalRead(REEDpin3);
  if (REEDvalue3 != oldREEDvalue3) {
    if (digitalRead(REEDpin3) == LOW)
      Serial.println("REED3 0");
    else
      Serial.println("REED3 1");
    oldREEDvalue3 = REEDvalue3;
  }
  REEDvalue4 = digitalRead(REEDpin4);
  if (REEDvalue4 != oldREEDvalue4) {
    if (digitalRead(REEDpin4) == LOW)
      Serial.println("REED4 0");
    else
      Serial.println("REED4 1");
    oldREEDvalue4 = REEDvalue4;
  }
*/

// 2 IR sensors met 2 knopjes
if (irrecv1.decode(&results)){
  Serial.println(results.value, HEX);

    switch (results.value){
      case 0xE0E0629D:
      Serial.println("IR1 1"); // als dit geprint is moet max actie nemen.
    if (REEDvalue2 != oldREEDvalue2) {
    if (digitalRead(REEDpin2) == LOW)
      Serial.println("REED2 0");
    else
      Serial.println("REED2 1");
    oldREEDvalue2 = REEDvalue2;
      break; //Wat doet break?

     case 0xE0E0926D:
      Serial.println("IR2 1");
     break;
     }
      
 }
  irrecv1.resume();
 
delay(10);

}
