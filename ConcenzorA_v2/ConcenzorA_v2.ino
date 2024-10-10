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

int ir1 = 0;
int ir2 = 0;
//IRsensors
#include <IRremote.h>
#define Button1 = 0xE0E0629D
const int IRsensor1 = 6;
const int IRsensor2 = 7; 

IRrecv irrecv1(IRsensor1);
IRrecv irrecv2(IRsensor2);
decode_results results;

decode_results results2;


void setup() {
  Serial.begin(57600);
  pinMode(LDRpin1, INPUT);
  pinMode(LDRpin2, INPUT);
  pinMode(REEDpin1, INPUT);
  pinMode(REEDpin2, INPUT);
  irrecv1.enableIRIn();
  irrecv2.enableIRIn();

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
*/

 //2 Magnetic reed sensors
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



 
// 2 IR sensors met 2 knopjes
if (irrecv1.decode()){
  //Serial.println(results.value, HEX);
ir1 = irrecv1.decodedIRData;
    switch (ir1){
      case 0xE0E0629D:
      Serial.println("IR1 "); // als dit geprint is moet max actie nemen.
      break; //Wat doet break?

     case 0xE0E0926D:
      Serial.println("IR2 ");
     break;
     }
      
 }

  

if (irrecv2.decode()){
 // Serial.println(results.value, HEX);

  ir2 = irrecv3.decodedIRData;
    switch (ir2){
      case 0xE0E0629D:
      Serial.println("IR3");
      break; 

     case 0xE0E0926D:
      Serial.println("IR4");
     break;
     }
      
 }
  irrecv1.resume();
 irrecv2.resume();

delay(10);

}
