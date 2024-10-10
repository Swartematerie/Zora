/*
 * sketch ten behoeve van Experimenteer avond 2 in Podium Zuidheage te Assen. 
 * Patricia Swart & Jan Ruerd Oosterhaven.
 */


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        2
#define NUMPIXELS 50
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 300 // Time (in milliseconds) to pause between pixels

//Declaration Joystick
int Xpin = A0;
int Ypin = A1;
int Spin = 7;
int Xval;
int Yval;
int Sval;

int in = 4;
int p;
int zone;
bool presstateZone1 = 0;
bool presstateZone2 = 0;
bool presstateZone3 = 0;
bool presstateZone4 = 0;
bool presstateZone5 = 0;
bool presstateZone6 = 0;

//#002 paddenstoelen
int LDR1 = A2;
int LDR2 = A3;
int padDruk = 38;
int padLED = 39;

int paddenstoel1;
int paddenstoel2;
bool padKnopje;
bool padPresstate;

//#010 Cactus
int cacLED = 13;
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
int oldau1;
int oldau2;
int oldau3;
int oldau4;
int oldau5;

//018 Drukknopjes
#define controlLED 25
#define roodKnopje 22
#define groenKnopje 23
#define drukKnop3 24
#define drukKnop4 26
#define drukKnop5 30
#define drukKnop6 28
#define drukKnop7 27
#define drukKnop8 29
#define drukKnop9 31
#define drukKnop10 32

bool x;
bool y;
bool z;
bool a;
bool b;
bool c;
bool d;
bool e;
bool f;
bool g;
bool presstate = 0;
bool presstate2 = 0;
bool presstate3 = 0;
bool presstate4 = 0;
bool presstate5 = 0;
bool presstate6 = 0;
bool presstate7 = 0;
bool presstate8 = 0;
bool presstate9 = 0;
bool presstate10 = 0;




//-----------------------------------------
//----------------Setup--------------------
//-----------------------------------------
void setup() {
  Serial.begin(9600);
 
  //#000 joyStick + LEDstrip
  pixels.begin();
  pixels.clear();
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  Serial.print("Zone: ");
  Serial.println(zone);
  setBlokje1(4);

  //#002 paddenstoel
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(padDruk, INPUT_PULLUP);
  pinMode(padLED, OUTPUT);
  digitalWrite(padLED, LOW);

  //#010 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
  pinMode (cactus3, INPUT_PULLUP);
  pinMode (cactus4, INPUT_PULLUP);
  pinMode (cactus5, INPUT_PULLUP);
  pinMode (cacLED, OUTPUT);
  digitalWrite(cacLED, LOW);

  //#018
  pinMode(roodKnopje, INPUT_PULLUP);
  pinMode(groenKnopje, INPUT_PULLUP);
  pinMode(drukKnop3, INPUT_PULLUP);
  pinMode(drukKnop4, INPUT_PULLUP);
  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(drukKnop7, INPUT_PULLUP);
  pinMode(drukKnop8, INPUT_PULLUP);
  pinMode(drukKnop9, INPUT_PULLUP);
  pinMode(drukKnop10, INPUT_PULLUP);
  pinMode(controlLED, OUTPUT);
  digitalWrite(controlLED, LOW);

}

//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
void loop() {
  //#001 JoyStick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (Xval >= 980 && in < 30) {
    p = 1;
  }
  else if (Xval < 100 && in > 5) {
    p = 2;
  }
  else if (Yval >= 980) {
    p = 3;
  }
  else if (Yval < 20) {
    p = 4;
  }
  else {
    p = 0;
  }

  switch (p) {
    case 1:
      in++;
      pixels.clear ();
      setBlokje1(in);
      break;

    case 2:
      in--;
      pixels.clear ();
      setBlokje1(in);
      break;
  }

  if (Sval == LOW) {
    pixels.clear();
    in = 5;
    setBlokje1(5);
  }

  //#018 Drukknopjes
  y = digitalRead(groenKnopje);
  if (y == HIGH && presstate2 == 0) {
    digitalWrite(controlLED, HIGH);
    Serial.println("y 1");
    presstate2 = 1;
  }
  else if (y == LOW && presstate2 == 1) {
    digitalWrite(controlLED, LOW);
    Serial.println("y 0");
    presstate2 = 0;
  }

  z = digitalRead(drukKnop3);
  a = digitalRead(drukKnop4);
  b = digitalRead(drukKnop5);
  c = digitalRead(drukKnop6);

  d = digitalRead(drukKnop7);
  e = digitalRead(drukKnop8);
  f = digitalRead(drukKnop9);
  g = digitalRead(drukKnop10);


  if (z && !presstate3) {
    Serial.print("z ");
    Serial.print(zone);
    Serial.println("01");
    presstate3 = !presstate3;
  } else if (!z && presstate3) {
    Serial.print("z ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate3 = !presstate3;
  }
  if (!a && !presstate4) {
    Serial.print("a ");
    Serial.print(zone);
    Serial.println("01");
    presstate4 = !presstate4;
  } else if (a && presstate4) {
    Serial.print("a ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate4 = !presstate4;
  }

  if (b && !presstate5) {
    Serial.print("b ");
    Serial.print(zone);
    Serial.println("01");
    presstate5 = !presstate5;
  } else if (!b && presstate5) {
    Serial.print("b ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate5 = !presstate5;
  }

  if (c && !presstate6) {
    Serial.print("c ");
    Serial.print(zone);
    Serial.println("01");
    presstate6 = !presstate6;
  } else if (!c && presstate6) {
    Serial.print("c ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate6 = !presstate6;
  }


  if (!d && !presstate7) {
    Serial.print("d ");
    Serial.print(zone);
    Serial.println("01");
    presstate7 = !presstate7;
  } else if (d && presstate7) {
    Serial.print("d ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate7 = !presstate7;
  }
  if (!e && !presstate8) {
    Serial.print("e ");
    Serial.print(zone);
    Serial.println("01");
    presstate8 = !presstate8;
  } else if (e && presstate8) {
    Serial.print("e ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate8 = !presstate8;
  }

  if (!f && !presstate9) {
    Serial.print("f ");
    Serial.print(zone);
    Serial.println("01");
    presstate9 = !presstate9;
  } else if (f && presstate9) {
    Serial.print("f ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate9 = !presstate9;
  }

  if (!g && !presstate10) {
    Serial.print("g ");
    Serial.print(zone);
    Serial.println("01");
    presstate10 = !presstate10;
  } else if (g && presstate10) {
    Serial.print("g ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate10 = !presstate10;
  }
  if (x || y || z || !a || b || c || !d || !e || !f || !g) {
    digitalWrite(controlLED, HIGH);
  }
  else {
    digitalWrite(controlLED, LOW);
  }



  if (in >= 5 && in <= 9 && !presstateZone1) {
    zone = 1;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone1 = 1;
    presstateZone2 = 0;
  }
  if (in >= 10 && in <= 13  && !presstateZone2) {
    zone = 2;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone1 = 0;
    presstateZone2 = 1;
    presstateZone3 = 0;
  }

  if (in >= 14 && in <= 17  && !presstateZone3) {
    zone = 3;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone2 = 0;
    presstateZone3 = 1;
    presstateZone4 = 0;
  }
  if (in >= 18 && in <= 22  && !presstateZone4) {
    zone = 4;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone3 = 0;
    presstateZone4 = 1;
    presstateZone5 = 0;
  }
  if (in >= 23 && in <= 26  && !presstateZone5) {
    zone = 5;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone4 = 0;
    presstateZone5 = 1;
    presstateZone6 = 0;
  }

  if (in >= 27 && in <= 30  && !presstateZone6) {
    zone = 6;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone5 = 0;
    presstateZone6 = 1;
  }


  if (zone == 1) {
 Paddenstoel();

  }
  if (zone == 2) {
    Paddenstoel();
  }

  if (zone == 3) {
    digitalWrite(cacLED, LOW);
    Paddenstoel();
  }

  if (zone == 4) {
    digitalWrite(padLED, HIGH);
    cactus();
  }
  if (zone == 5) {
    cactus();
  }
  if (zone == 6) {
    cactus ();
  }


}

//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------
void setBlokje1 (int in) {

  if (in > 0; in < 10) {   
    for(int i = 4; i < 10; i++ ){
     pixels.setPixelColor(i, pixels.Color(10, 4, 1));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop   

  }
  else if (in > 9; in < 14) {
   for (int i = 10; i < 14; i++){
    pixels.setPixelColor(i, pixels.Color(0, 10, 0));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 13; in < 18) {
   for(int i = 14; i < 18; i++){
    pixels.setPixelColor(i, pixels.Color(15, 20, 0));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 17; in < 23) {
       for(int i = 18; i < 23; i++){
    pixels.setPixelColor(i, pixels.Color(15, 10, 0));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 22; in < 27) {
       for(int i = 23; i < 27; i++){
    pixels.setPixelColor(i, pixels.Color(10, 10, 18));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 26; in < 31) {
     for(int i = 27; i < 31; i++){
    pixels.setPixelColor(i, pixels.Color(10, 0, 0));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 30; in < 50) {
       for(int i = 31; i < 50; i++){
    pixels.setPixelColor(i, pixels.Color(0, 0, 10));
   }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void setBlokje2 (int in) {

  if (in > 0; in < 10) {   
    for(int i = 4; i < 10; i++ ){
     pixels.setPixelColor(i, pixels.Color(10, 4, 1));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop   


  }
  else if (in > 9; in < 14) {
    pixels.setPixelColor(10, pixels.Color(0, 10, 0));
    pixels.setPixelColor(11, pixels.Color(0, 10, 0));
    pixels.setPixelColor(12, pixels.Color(0, 10, 0));
    pixels.setPixelColor(13, pixels.Color(0, 10, 0));    
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 13; in < 18) {
    pixels.setPixelColor(in, pixels.Color(15, 20, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 17; in < 23) {
    pixels.setPixelColor(in, pixels.Color(15, 10, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 22; in < 27) {
    pixels.setPixelColor(in, pixels.Color(10, 10, 18));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 26; in < 31) {
    pixels.setPixelColor(in, pixels.Color(10, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 30; in < 50) {
    pixels.setPixelColor(in, pixels.Color(238, 55, 10));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void Paddenstoel () {
 // digitalWrite(padLED, LOW);

  paddenstoel1 = analogRead(LDR1);
  Serial.print("P1 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(paddenstoel1);

  paddenstoel2 = analogRead(LDR2);
  Serial.print("P2 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(paddenstoel2);


  padKnopje = digitalRead(padDruk);
  if (padKnopje == HIGH && padPresstate == 0) {
    digitalWrite(padLED, HIGH);
    Serial.print("x ");
    Serial.print(zone);
    Serial.println("01");
    padPresstate = 1;
  }
  else if (padKnopje == LOW && padPresstate == 1) {
    digitalWrite(padLED, LOW);
    Serial.print("x ");
    Serial.print(zone);
    Serial.println("00"); 
    padPresstate = 0;
  }
}


void cactus() {
  digitalWrite (cacLED, HIGH);
  au1 = digitalRead(cactus1);
  if (au1 != oldau1) {
    if (au1 == HIGH) {
      Serial.print("C4 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C4 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau1 = au1;
  }

  au2 = digitalRead(cactus2);
  if (au2 != oldau2) {
    if (au2 == HIGH) {
      Serial.print("C5 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C5 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau2 = au2;
  }

  au3 = digitalRead(cactus3);
  if (au3 != oldau3) {
    if (au3 == HIGH) {
      Serial.print("C6 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C6 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau3 = au3;
  }

  au4 = digitalRead(cactus4);
  if (au4 != oldau4) {
    if (au4 == HIGH) {
      Serial.print("C7 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C7 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau4 = au4;
  }

  au5 = digitalRead(cactus5);
  if (au5 != oldau5) {
    if (au5 == HIGH) {
      Serial.print("C8 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C8 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau5 = au5;
  }
}
