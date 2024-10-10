#include "LedControl.h"

//DIN 6, CLK 7, CS 5
LedControl lc = LedControl(6, 7, 5, 3);

unsigned long delaytime = 100;

//Declaration Joystick
int Xpin = A1;
int Ypin = A0;
int Spin = A2;
int Xval;
int Yval;
int Sval;

unsigned long prevTime = 0;
int waitJoy = 1000;
int printTime;

int posX = 3;
int posY = 3;
int p = 0;


void setup() {
  Serial.begin(9600);

  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  for(int i = 0; i< 3; i++){
    lc.shutdown(i, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(i);
  }

  setBlokje(1,3,3);

}

void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  //Positie JoyStick
  if (Xval >= 980 && posX < 7) {p = 1;}
    else if(Xval < 20 && posX > 0) {p = 2;}
    else if (Yval >= 980 && posY < 7) {p = 3;}
    else if(Yval < 20 && posY > 0) {p = 4;}
    else{p=0;}

if(p){
  unsigned long currentTime = millis();
  
  switch(p){
    case 1:
        printTime = currentTime;
    
        if(currentTime - prevTime > waitJoy){
          posX = posX+1;
          setBlokje(1,posX,posY);
          prevTime = currentTime;
        }
        break;

    case 2:
        printTime = currentTime;
    
        if(currentTime - prevTime > waitJoy){
          posX=posX-1; 
          setBlokje(1,posX,posY);
          prevTime = currentTime;
        }
        break;
  
      case 3:
        printTime = currentTime;
        
        if(currentTime - prevTime > waitJoy){
          posY = posY+1;
          setBlokje(1,posX,posY);
          prevTime = currentTime;
        }
        break;

      case 4:
        printTime = currentTime;
        if(currentTime - prevTime > waitJoy){
          posY=posY-1; 
          setBlokje(1,posX,posY);
          prevTime = currentTime;
        }
        break;
  }
}

  Serial.println(p);
  

}

void setBlokje(int addr, int posX, int posY) {
   for(int i=0; i<3;i++){
     lc.clearDisplay(i);
    }
  lc.setLed(addr, posX, posY, true);
  Serial.print("posX = ");
  Serial.println(posX);
  Serial.print("posY = ");
  Serial.println(posY);

}
