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
int addr = 1;

void setup() {
  Serial.begin(9600);

  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  randomSeed(50000);
  
  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(0, 8);
    lc.clearDisplay(i);
  }
  
  int j = random(0,150);
  int i = 0;
    while(i <= j){
      int s = random(0,8);
      int q = random(0,8);
      int p = random(0,4);
      lc.setLed(p, s, q, true);
      i++;
    }
  delay(8000);
  setBlokje(addr, 3, 3);
  }

void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

 
  //Kaartlezen
  if (Sval = HIGH) {
    
  }
  //Positie JoyStick
  if (Xval >= 980 && posX < 7) {
    p = 1;
  }
  else if (Xval < 20 && posX > 0) {
    p = 2;
  }
  else if (Yval >= 980 && posY < 8) {
    p = 3;
  }
  else if (Yval < 20 && posY > -1) {
    p = 4;
  }
  else {
    p = 0;
  }

  if (p) {
    unsigned long currentTime = millis();

    switch (p) {
      case 1:
        printTime = currentTime;

        if (currentTime - prevTime > waitJoy) {
          posX = posX + 1;
          setBlokje(addr, posX, posY);
          prevTime = currentTime;
        }
        break;

      case 2:
        printTime = currentTime;

        if (currentTime - prevTime > waitJoy) {
          posX = posX - 1;
          setBlokje(addr, posX, posY);
          prevTime = currentTime;
        }
        break;

      case 3:
        printTime = currentTime;

        if (currentTime - prevTime > waitJoy) {
          posY = posY + 1;
          if (posY == 8) {
            addr--;
            posY = 0;
          }
          setBlokje(addr, posX, posY);
          prevTime = currentTime;
        }
        break;

      case 4:
        printTime = currentTime;
        if (currentTime - prevTime > waitJoy) {
          posY = posY - 1;
          if (posY == -1) {
            addr++;
            posY = 7;
          }
          setBlokje(addr, posX, posY);
          prevTime = currentTime;
        }
        break;
    }
  }




}

void setBlokje(int addr, int posX, int posY) {
  for (int i = 0; i < 3; i++) {
    lc.clearDisplay(i);
  }
  lc.setLed(addr, posX, posY, true);
  Serial.print("posX = ");
  Serial.println(posX);
  Serial.print("posY = ");
  Serial.println(posY);

}

void showMapOnMatrix (){
  
}
