/*
ConcenzorA project voor 18 november 2021 (c) Patricia Swart en Jan Ruerd Oosterhaven
last update: 28 okt 2021

*/

#include "LedControl.h"
#include <TM1637display.h>
#include <arduino.h>

#define CLK 48 
#define DIO 49 

//DIN 6, CLK 7, CS 5
LedControl lc = LedControl(6, 7, 5, 3);
TM1637Display teller(CLK, DIO);

//Declaration Joystick
int Xpin = A1;
int Ypin = A0;
int Spin = 2;
int Xval;
int Yval;
int Sval;

//switch case bewegen over de kaart
//unsigned long delaytime = 100;
unsigned long prevTime = 0;
int waitJoy = 1000;
//sint printTime;
int klok = 9;

//functie set Blokje
int posX = 3;
int posY = 3;
int p = 0;
int addr = 1;

//uiterlijk kaart
const uint64_t IMAGES[] = {
  0xfebf3efff6e2feff,  //woestijn
  0xfe7ffe7fff7eff7e,
  0x7578fd7e7ff3737f
};
const int IMAGES_LEN = sizeof(IMAGES)/8;


//#5 stip aan de horizon kanon.
int laserRichter = 13;
int schietdoel1 = A4;
int schietdoel2 = A5;
int lont = 12;
int laden1;
int laden2;
int LOS;




void setup() {
  Serial.begin(9600);

  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);
  teller.setBrightness(0x0f);

  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i,2);
    lc.clearDisplay(i);
  }

  setBlokje(addr, posX, posY);

  //#5
  pinMode (laserRichter, INPUT);
  pinMode (schietdoel1, INPUT);
  pinMode (schietdoel2, INPUT);
  pinMode (lont, INPUT);
  digitalWrite(lont, HIGH);

}





//LOOP!!!
void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (addr = 0){
    kanonAfvuren ();
    //En nog een aantal woestijn functies
  }
 
  if (addr = 1){
    kanonAfvuren ();
  }

 if (addr = 2){
    kanonAfvuren ();
    //En nog een aantal bos functies
  }
 
  //Kaartlezen
  if (Sval == LOW) {
    displayMap(0,IMAGES[0]);
    displayMap(1,IMAGES[1]);
    displayMap(2,IMAGES[2]);
  }
  if(Sval == HIGH){
    setBlokje(addr, posX, posY);
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
    teller.showNumberDec(klok, false);
        
        if (currentTime - prevTime > waitJoy) {
          klok --;
          prevTime = currentTime;
        }
    
    if(klok == 0){ 
      klok = 9; 
    switch (p) {
      case 1:
          posX = posX + 1;
          setBlokje(addr, posX, posY);
        break;

      case 2:
          posX = posX - 1;
          setBlokje(addr, posX, posY);
        break;

      case 3:
          posY = posY - 1;
          if (posY == -1) {
            addr++;
            posY = 7;
          }
          setBlokje(addr, posX, posY);
        break;

      case 4:
          posY = posY + 1;
          if (posY == 8) {
            addr--;
            posY = 0;
          }
          setBlokje(addr, posX, posY);
        break;
    }
    }
  }

}









//FUNCTIONS
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


void displayMap(int addr, uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      lc.setLed(addr, i, j, bitRead(row, j));
    }
  }
}



void kanonAfvuren (){
  digitalWrite (laserRichter, HIGH);
  laden1 = analogRead(schietdoel1);
  laden2 = analogRead(schietdoel2);
  LOS = digitalRead(lont);

  if(laden1>750 && LOS == HIGH){
    Serial.print("kanon 1");
  }
  if(laden2>750 && LOS == HIGH){
    Serial.print("kanon 2");
  }
}
 
