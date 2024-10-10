/*
  ConcenzorA project voor 18 november 2021 (c) Patricia Swart en Jan Ruerd Oosterhaven
  last update: 28 okt 2021

*/

#include "LedControl.h";
#include "TM1637Display.h";
//#include <TM1637.h>!!!!!!!!!???
#include "arduino.h";

#define CLK 38;
#define DIO 39;

//#000 Joystick
//DIN 50, CLK 52, CS 51
LedControl lc = LedControl(50, 52, 51, 3);
TM1637Display teller(CLK, DIO);
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
  0x5fbf7fffffe7e7ff,  //woestijn
  0xffffffffffffffff,
  0xfafdfeffffe7e7ff
};
const int IMAGES_LEN = sizeof(IMAGES) / 8;

//#2 paddenstoelen
int padd1 = A2;
int LDR1;

//#4 weerBolletjes


//#5 stip aan de horizon kanon.
int laserRichter = 23;
int schietdoel1 = A7;
int schietdoel2 = A8;
int schietdoel3 = A9;
int schietdoel4 = A10;
int lontDK = 2;
int laden1;
int laden2;
int laden3;
int laden4;
int LOS;

//#8 rumBottles
int rum1 = 3;
int rum2 = 4;
int rum3 = 5;
int rum4 = 6;

//#9 dePutOase
const int numReadings9 = 10;
int readings9[numReadings9];      // the readings from the analog input
int readIndex9 = 0;              // the index of the current reading
int total9 = 0;                  // the running total
int average9 = 0;                // the average
int putPin = A7;
int putValue = 0;

//#10 cactus
int cactus1 = 8;
int cactus2 = 9;
int cactus3 = 10;
int cactus4 = 11;
int cactus5 = 12;
int au1;
int au2;
int au3;
int au4;
int au5;

//#11 themaPlankjes

//#12 firefLights
int firefLights = A3;
int LDR2;

//#13 casesOfContrast
int desertCase = A4;
int oceanCase = A5;
int forestCase = A6;
int LDR3;
int LDR4;
int LDR5;

//-----------------------------------------
//------------Setup------------------------
//-----------------------------------------
void setup() {
  Serial.begin(9600);
  //#000 Joystick
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);
  teller.setBrightness(0x0f);

  for (int i = 0; i < 3; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 2);
    lc.clearDisplay(i);
  }

  setBlokje(addr, posX, posY);

  //#2 paddenstoelen
  pinMode(padd1, INPUT);
  //#4 weerbollen

  //#5 kanon
  pinMode (laserRichter, OUTPUT);
  pinMode (schietdoel1, INPUT);
  pinMode (schietdoel2, INPUT);
  pinMode (schietdoel3, INPUT);
  pinMode (schietdoel4, INPUT);
  pinMode (lontDK, INPUT_PULLUP);
  digitalWrite(laserRichter, HIGH);

  //#8 rumbottles
  pinMode (rum1, INPUT_PULLUP);
  pinMode (rum2, INPUT_PULLUP);
  pinMode (rum3, INPUT_PULLUP);
  pinMode (rum4, INPUT_PULLUP);

  //#9 put/oase
  pinMode (putPin, INPUT);
  for (int thisReading9 = 0; thisReading9 < numReadings9; thisReading9++) {
    readings9[thisReading9] = 0;
  }

  //#10 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
  pinMode (cactus3, INPUT_PULLUP);
  pinMode (cactus4, INPUT_PULLUP);
  pinMode (cactus5, INPUT_PULLUP);

  //#11 themaplankjes

  //#12 fireflights
  pinMode(firefLighrs, INPUT);

  //#13 cases of contrast
  pinMode(desertCase, INPUT);
  pinMode(oceanCase, INPUT);
  pinMode(forestCase, INPUT);
}


//-----------------------------------------
//-----------LOOP--------------------------
//-----------------------------------------
void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

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
    teller.showNumberDec(klok, false);

    if (currentTime - prevTime > waitJoy) {
      klok --;
      prevTime = currentTime;
    }

    if (klok == 0) {
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
  if (addr == 0) {
    weerBolletjes ();
    desertRumBottles ();
    themaPlankjes ();
    desertFirefLights ();
    desertCase ();

    cactus ();
    //-------------------------------------woestijn functies
  }

  if (addr == 1) {
    oceanWeerBolletjes ();
    oceanRumBottles ()
    oceanThemaPlankjes ();
    oceanFirefLights ();
    oceanCase ();

    kanonAfvuren ();
    //-------------------------------------oceaan functies
  }

  if (addr == 2) {
    weerBolletjes ();
    forestRumBottles ();
    themaPlankjes ();
    forestFirefLights ();
    forestCase ();

    paddenstoelen ();

    //-----------------------------------------bos functies
  }

  //#9 Oase
  if (addr == 0 && (posX == 2 || posX == 1) && (posY == 3 || posY == 4) ) {
    Serial.println("OaseHallucinatie");
    putOase ();
  }
  //# 15 Sensuele Tempel
  if (addr == 0 && (posX == 5 && posY == 7) || (posX == 6 && posY == 6) || (posX == 7 && posY == 5) ) {
    Serial.println("Sex");
  }
  //#9 put
  if (addr == 2 && (posX == 2 || posX == 1) && (posY == 3 || posY == 4) ) {
    Serial.println("PutHallucinatie");
    putOase ();
  }

  //#7 Boomwackerboom
  if (addr == 2 && (posX == 5 && posY == 0) || (posX == 6 && posY == 1) || (posX == 7 && posY == 2) ) {
    Serial.println("Yewtree");
  }


}



}



//-----------------------------------------
//------------FUNCTIONS--------------------
//-----------------------------------------
void setBlokje(int addr, int posX, int posY) {
  for (int i = 0; i < 3; i++) {
    lc.clearDisplay(i);
  }
  lc.setLed(addr, posX, posY, true);
  Serial.print("posX = ");
  Serial.println(posX);
  Serial.print("posY = ");
  Serial.println(posY);
  Serial.print("addr = ");
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
  Serial.print("Paddenstoel: ");
  Serial.println(LDR1);
}

void weerBolletjes () {

}

void kanonAfvuren () {
  digitalWrite (laserRichter, HIGH);
  laden1 = analogRead(schietdoel1);
  laden2 = analogRead(schietdoel2);
  laden3 = analogRead(schietdoel3);
  laden4 = analogRead(schietdoel4);
  LOS = digitalRead(lont);

  if (laden1 > 100 && LOS == LOW) {
    Serial.println("kanon 1");
  }
  if (laden2 > 100 && LOS == LOW) {
    Serial.println("kanon 2");
  }
  if (laden3 > 100 && LOS == LOW) {
    Serial.println("kanon 3");
  }
  if (laden4 > 100 && LOS == LOW) {
    Serial.println("kanon 4");
  }
}

void desertRumBottles () {
  bottomUp1 = digitalRead(rum1);
  if(bottomUp1 == HIGH){
    Serial.println("desertRumBottles 1");
  }
    bottomUp2 = digitalRead(rum2);
  if(bottomUp2 == HIGH){
    Serial.println("desertRumBottles 2");
  }  
  bottomUp3 = digitalRead(rum3);
  if(bottomUp3 == HIGH){
    Serial.println("desertRumBottles 3");
  }  
  bottomUp4 = digitalRead(rum4);
  if(bottomUp4 == HIGH){
    Serial.println("desertRumBottles 4");
  }
}
void oceanRumBottles () {
  bottomUp1 = digitalRead(rum1);
  if(bottomUp1 == HIGH){
    Serial.println("oceanRumBottles 1");
  }
    bottomUp2 = digitalRead(rum2);
  if(bottomUp2 == HIGH){
    Serial.println("oceanRumBottles 2");
  }  
  bottomUp3 = digitalRead(rum3);
  if(bottomUp3 == HIGH){
    Serial.println("oceanRumBottles 3");
  }  
  bottomUp4 = digitalRead(rum4);
  if(bottomUp4 == HIGH){
    Serial.println("oceanRumBottles 4");
  }
}

void forestRumBottles () {
  bottomUp1 = digitalRead(rum1);
  if(bottomUp1 == HIGH){
    Serial.println("forestRumBottles 1");
  }
    bottomUp2 = digitalRead(rum2);
  if(bottomUp2 == HIGH){
    Serial.println("forestRumBottles 2");
  }  
  bottomUp3 = digitalRead(rum3);
  if(bottomUp3 == HIGH){
    Serial.println("forestRumBottles 3");
  }  
  bottomUp4 = digitalRead(rum4);
  if(bottomUp4 == HIGH){
    Serial.println("forestRumBottles 4");
  }
}

void putOase () {
  total9 = total9 - readings9[readIndex9];
  readings9[readIndex9] = analogRead(putPin);
  total9 = total9 + readings9[readIndex9];
  readIndex9 = readIndex9 + 1;


  if (readIndex9 >= numReadings9) {
    // ...wrap around to the beginning:
    readIndex9 = 0;
  }

  average9 = total9 / numReadings9;

  putValue = analogRead(putPin);
  if (putValue > (average9 = average9 + 20)) {
    Serial.println("overgangPut 1");
  }
}

void cactus() {
  au1 = digitalRead(cactus1);
  if (au1 == HIGH) {
    Serial.println("au1");
  }

  au2 = digitalRead(cactus2);
  if (au2 == HIGH) {
    Serial.println("au2");
  }
  au3 = digitalRead(cactus3);
  if (au3 == HIGH) {
    Serial.println("au3");
  }
  au4 = digitalRead(cactus4);
  if (au4 == HIGH) {
    Serial.println("au4");
  }
  au5 = digitalRead(cactus5);
  if (au5 == HIGH) {
    Serial.println("au5");
  }
}

void themaPlankjes () {

}

void desertFirefLights () {
  LDR2 = analogRead(firefLights);
  Serial.print("desertFireflights ");
  Serial.println(LDR2);
}
void oceanFirefLights () {
  LDR2 = analogRead(firefLights);
  Serial.print("oceanFireflights ");
  Serial.println(LDR2);
}
void forestFirefLights () {
  LDR2 = analogRead(firefLights);
  Serial.print("forestFireflights ");
  Serial.println(LDR2);
}

//--------
void desertCase () {
  LDR3 = analogRead(desertCase);
  Serial.print("desertCase ");
  Serial.println(LDR3);

}

void oceanCase () {

  LDR4 = analogRead(oceanCase);
  Serial.print("oceanCase ");
  Serial.println(LDR4);

}

void forestCase () {

  LDR5 = analogRead(forestCase);
  Serial.print("forestCase ");
  Serial.println(LDR5);
}
