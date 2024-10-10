
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

int in;
int p;
int zone;
bool uitZone = 0;

//#002 paddenstoelen
int LDR3 = A2;
int LDR5 = A4;
int paddenstoel1;
int paddenstoel2;

//#013 Cases
int LDR1 = A0;
int LDR2 = A1;
int LDR4 = A3;
int case1;
int case2;
int case3;
int oldcase1;
int oldcase2;
int oldcase3;

//#010 Cactus
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
#define controlLed 25
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
bool presstateZone = 0;
bool presstateZone2 = 0;

//-----------------------------------------
//----------------Setup--------------------
//-----------------------------------------
void setup() {
  pixels.begin();
  pixels.clear();
  Serial.begin(9600);
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  setBlokje(1);

  //#013 & #002 koffers en paddenstoel
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  pinMode(LDR5, INPUT);

  //#010 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
  pinMode (cactus3, INPUT_PULLUP);
  pinMode (cactus4, INPUT_PULLUP);
  pinMode (cactus5, INPUT_PULLUP);

  //#018
  pinMode(roodKnopje, INPUT_PULLUP);
  pinMode(groenKnopje, INPUT_PULLUP);
  pinMode(controlLed, OUTPUT);
  pinMode(drukKnop3, INPUT_PULLUP);
  pinMode(drukKnop4, INPUT_PULLUP);
  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(drukKnop7, INPUT_PULLUP);
  pinMode(drukKnop8, INPUT_PULLUP);
  pinMode(drukKnop9, INPUT_PULLUP);
  pinMode(drukKnop10, INPUT_PULLUP);

  digitalWrite(controlLed, LOW);

}

//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
void loop() {
  //#001 JoyStick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (Xval >= 980 && in < 50) {
    p = 1;
  }
  else if (Xval < 20 && in > 0) {
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
      setBlokje(in);
      break;

    case 2:
      in--;
      pixels.clear ();
      setBlokje(in);
      break;
  }

  //#018 Drukknopjes
  x = digitalRead(roodKnopje);
  if (x == HIGH && presstate == 0) {
    digitalWrite(controlLed, HIGH);
    Serial.println("x 1");
    presstate = 1;
  }
  else if (x == LOW && presstate == 1) {
    digitalWrite(controlLed, LOW);
    Serial.println("x 0");
    presstate = 0;
  }

  y = digitalRead(groenKnopje);
  if (y == HIGH && presstate2 == 0) {
    digitalWrite(controlLed, HIGH);
    Serial.println("y 1");
    presstate2 = 1;
  }
  else if (y == LOW && presstate2 == 1) {
    digitalWrite(controlLed, LOW);
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
    digitalWrite(controlLed, HIGH);
  }
  else {
    digitalWrite(controlLed, LOW);
  }



  if (x == 1 && !presstateZone) {
    zone++;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone = 1;
  }
  else if (x == 0 && presstateZone) {
    presstateZone = 0;
  }

  if (y == 1 && !presstateZone2) {
    zone--;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone2 = 1;
  }
  else if (y == 0 && presstateZone2) {
    presstateZone2 = 0;
  }


  if (zone == 1) {
    Paddenstoel1();
    Paddenstoel2();
  }

  if (zone == 2) {
    Paddenstoel1();
    Paddenstoel2();
  }
  if (zone == 3) {
    cactus();
//    cases2();
  }

  if (zone == 4) {
    cases3 ();
  }
  if (zone == 5) {
    cases1 ();
    cases2 (); 
  }
  if (zone == 6) {
    cases2 ();
    cactus ();
  }
  if (zone == 7) {
Serial.print("X ");
Serial.println(Xval);
Serial.print("Y ");
Serial.println(Yval);
  }



  //  Serial.print("zone ");
  //  Serial.println(zone);
  //Serial.print("p ");
  //Serial.println(p);

}

//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------
void setBlokje (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  else if (in > 9; in < 20) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 19; in < 30) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 29; in < 40) {
    pixels.setPixelColor(in, pixels.Color(30, 25, 85));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 39; in < 50) {
    pixels.setPixelColor(in, pixels.Color(85, 30, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void Paddenstoel1 () {
  paddenstoel1 = analogRead(LDR5);
  Serial.print("P1 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(paddenstoel1);
}

void Paddenstoel2 () {
  paddenstoel2 = analogRead(LDR3);
  Serial.print("P2 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(paddenstoel2);
}

void cases1 () {

  case1 = analogRead(LDR4);
  Serial.print("C1 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(LDR4);
}

void cases2 () {
  case2 = analogRead(LDR2);
  Serial.print("C2 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(LDR2);
}

void cases3 () {
  case3 = analogRead(LDR1);
  Serial.print("C3 ");
  Serial.print(zone);
  Serial.print(" ");
  Serial.println(LDR4);
}

void cactus() {
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
