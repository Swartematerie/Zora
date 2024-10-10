#include "LedControl.h"

LedControl lc = LedControl(6, 7, 5, 1);

unsigned long delaytime = 100;

//Declaration Joystick
int Xpin = A1;
int Ypin = A0;
int Spin = A2;
int Xval;
int Yval;
int Sval;
int counter1 = 0;
int counter2 = 0;
int posX = 3;
int posY = 3;

bool pointUp = false;

unsigned long prevTime = 0;

void setup() {
  Serial.begin(9600);

  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);

}

void loop() {

  if (Xval >= 1020 && Yval > 500 && Yval < 540) {
    pointUp = true;
  }
  else {
    pointUp = false;
  }

  if (millis() > prevTime + 999) {
    prevTime = millis();
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);

    if (pointUp == true){
      counter1++;
      if (counter1 == 10){
        setBlokje(posX, posY);
        counter1 = 0;
      }
    }
    
  }
}

void setBlokje(int posX, int posY) {
  lc.clearDisplay(0);
  lc.setLed(0, posX, posY, true);

  //lc.setLed(0,(posX+1),posY,true);
  //lc.setLed(0,posX,(posY+1),true);
  //lc.setLed(0,(posX+1),(posY+1),true);
}
