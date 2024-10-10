//#8 rumBottles
int rum1 = 3;
int rum2 = 4;
int rum3 = 5;
int rum4 = 6;
int bottomUp1;
int bottomUp2;
int bottomUp3;
int bottomUp4;

void setup() {
 Serial.begin(9600);
 pinMode(rum1, INPUT_PULLUP);
 pinMode(rum2, INPUT_PULLUP);
 pinMode(rum3, INPUT_PULLUP);
 pinMode(rum4, INPUT_PULLUP);

}

void loop() {
  /*
  bottomUp1 = digitalRead(rum1);
  if(bottomUp1 == HIGH){
    Serial.println("rum1");
  }
    bottomUp2 = digitalRead(rum2);
  if(bottomUp2 == HIGH){
    Serial.println("rum2");
  }  
  bottomUp3 = digitalRead(rum3);
  if(bottomUp3 == HIGH){
    Serial.println("rum3");
  }
  */  
  bottomUp4 = digitalRead(rum4);
  if(bottomUp4 == HIGH){
    Serial.println("rum4");
  }
  
  }
