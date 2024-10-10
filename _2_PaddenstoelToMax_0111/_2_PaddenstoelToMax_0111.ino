#include "LedControl.h"

//DIN 6, CLK 7, CS 5
LedControl lc = LedControl(7, 5, 6, 3);

//Declaration Joystick
int Xpin = A1;
int Ypin = A0;
int Spin = 2;
int Xval;
int Yval;
int Sval;

//switch case bewegen over de kaart
unsigned long delaytime = 100;
unsigned long prevTime = 0;
int waitJoy = 1000;
int printTime;

//functie set Blokje
int posX = 3;
int posY = 3;
int p = 0;
int addr = 1;

//uiterlijk kaart
const uint64_t IMAGES[] = {
  0x5fbf7fffffe7e7ff,  //woestijn
  0xffffffffffffffff,
  0xfafdfeffffe7e7ff
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;


//#2 Paddenstoel
int padd1 = A2;
int LDR1;




void setup() {
  Serial.begin(9600);

  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 2);
    lc.clearDisplay(i);
  }

//  setBlokje(addr, posX, posY);

  //#2 paddenstoelen
  pinMode(padd1, INPUT);
}





//LOOP!!!
void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);
  
    if (addr == 1){
    paddenstoelen ();
    //En nog een aantal oceaan functies
    }
  
  //Kaartlezen
  if (Sval == LOW) {
    displayMap(0, IMAGES[0]);
    displayMap(1, IMAGES[1]);
    displayMap(2, IMAGES[2]);
  }
  if (Sval == HIGH) {
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
          posY = posY - 1;
          if (posY == -1) {
            addr++;
            posY = 7;
          }
          setBlokje(addr, posX, posY);
          prevTime = currentTime;
        }
        break;

      case 4:
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
        
    }
  }

  //#9 put
  if (addr == 2 && (posX == 2 || posX == 1) && (posY == 3 || posY == 4) ) {
    Serial.println("Put 1");
   
  }
  //#9 Boomwackerboom
  if (addr == 2 && (posX == 5 && posY == 0) || (posX == 6 && posY == 1) || (posX == 7 && posY == 2) ) {
    Serial.println("Yewtree 1");
  }
  
  //#7Boomwackerboom
  if (addr == 0 && (posX == 2 || posX == 1) && (posY == 3 || posY == 4) ){
    Serial.println("OASE 1");
  }
  //# 15 Sensuele Tempel
  if (addr == 0 && (posX == 5 && posY == 7) || (posX == 6 && posY == 6) || (posX == 7 && posY == 5) ){
    Serial.println("Sex 1");
  }
  
}









//FUNCTIONS
void setBlokje(int addr, int posX, int posY) {
  for (int i = 0; i < 3; i++) {
    lc.clearDisplay(i);
  }
  lc.setLed(addr, posX, posY, true);
  Serial.print("addr ");
  Serial.println(addr);
}


void displayMap(int addr, uint64_t image) {
  for (int i = 0; i < 8; i++) {
    byte row = (image >> i * 8) & 0xFF;
    for (int j = 0; j < 8; j++) {
      lc.setLed(addr, i, j, bitRead(row, j));
    }
  }
}

void paddenstoelen () {
 LDR1 = analogRead(padd1);
  Serial.print("LDR1 ");
  Serial.println(LDR1);
}
