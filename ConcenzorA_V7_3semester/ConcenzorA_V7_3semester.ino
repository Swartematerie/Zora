/*
   sketch ten behoeve van Experimenteer avond 2 in Podium Zuidheage te Assen.
   Patricia Swart & Jan Ruerd Oosterhaven.
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        3
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
bool presstateZone7 = 0;

//#002 paddenstoelen
int LDR1 = A2;
int LDR2 = A3;
int padDruk = 30;
int padLED = 31;

int paddenstoel1;
int paddenstoel2;
bool padKnopje;
bool padPresstate;

//018 Drukknopjes

#define drukKnop5 23
#define drukKnop6 25
#define drukKnop7 27
#define drukKnop8 29


bool x;
bool y;
bool z;
bool a;
bool b;
bool c;
bool h;
bool i;
bool j;
bool k;
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
  setBlokje2(4);

  //#002 paddenstoel
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(padDruk, INPUT_PULLUP);
  pinMode(padLED, OUTPUT);
  digitalWrite(padLED, LOW);

  //#018

  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(drukKnop7, INPUT_PULLUP);
  pinMode(drukKnop8, INPUT_PULLUP);


}

//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
void loop() {
  //#001 JoyStick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (Xval >= 980) {
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
      setBlokje2(in);
      break;

    case 2:
      in--;
      pixels.clear ();
      setBlokje2(in);
      break;
  }

  if (Sval == LOW) {
    pixels.clear();
    in = 5;
    setBlokje2(5);
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
    presstateZone7 = 0;
  }

  if (in >= 31 && in <= 50  && !presstateZone7) {
    zone = 7;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone6 = 0;
    presstateZone7 = 1;
  }


  padKnopje = digitalRead(padDruk);
  if (padKnopje == HIGH && padPresstate == 0 && zone < 7) {
    digitalWrite(padLED, LOW);
        Serial.println("x 1");
    zone++;
    
    if (zone == 1) {
      pixels.clear();
      setBlokje1(5);
    }
    if (zone == 2) {
      pixels.clear();
      setBlokje1(11);
      in = 11;
    }

    if (zone == 3) {
      pixels.clear();
      setBlokje1(14);
      in = 14;
    }

    if (zone == 4) {
      pixels.clear();
      setBlokje1(18);
      in = 18;
    }
    if (zone == 5) {
      pixels.clear();
      setBlokje1(23);
      in = 23;
    }
    if (zone == 6) {
      pixels.clear();
      setBlokje1(27);
      in = 27;
    }
    if (zone == 7) {
      pixels.clear();
      setBlokje1(31);
      in = 31;
    }
    Serial.print("zone ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == HIGH && padPresstate == 0 && zone == 7) {
    zone = 1;
    pixels.clear();
    setBlokje1(5);
    in = 5;
        Serial.println("x 1");
    Serial.print("zone ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == LOW && padPresstate == 1) {
    digitalWrite(padLED, HIGH);
       Serial.println("x 0");
    padPresstate = 0;
    delay(8);
  }

 drukknopjes();
  Paddenstoel();
}

//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------
void setBlokje1 (int in) {

  if (in > 0; in < 10) {
    for (int i = 4; i < 10; i++ ) {
      pixels.setPixelColor(i, pixels.Color(10, 4, 1));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  else if (in > 9; in < 14) {
    for (int i = 10; i < 14; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 10, 0));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 13; in < 18) {
    for (int i = 14; i < 18; i++) {
      pixels.setPixelColor(i, pixels.Color(15, 20, 0));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 17; in < 23) {
    for (int i = 18; i < 23; i++) {
      pixels.setPixelColor(i, pixels.Color(15, 10, 0));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 22; in < 27) {
    for (int i = 23; i < 27; i++) {
      pixels.setPixelColor(i, pixels.Color(10, 10, 18));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 26; in < 31) {
    for (int i = 27; i < 31; i++) {
      pixels.setPixelColor(i, pixels.Color(10, 0, 0));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 30; in < 50) {
    for (int i = 31; i < 50; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 10));
    }
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void setBlokje2 (int in) {

  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(10, 4, 1));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else if (in > 9; in < 14) {
    pixels.setPixelColor(in, pixels.Color(0, 10, 0));
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
    pixels.setPixelColor(in, pixels.Color(0, 0, 10));
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

}


void drukknopjes() {
  h = digitalRead(drukKnop5);
  i = digitalRead(drukKnop6);
  j = digitalRead(drukKnop7);
  k = digitalRead(drukKnop8);
  
 if (h && !presstate5) {
    Serial.print("h ");
    Serial.print(zone);
    Serial.println("01");
    presstate5 = !presstate5;
  } else if (!h && presstate5) {
    Serial.print("h ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate5 = !presstate5;
  }

  if (i && !presstate6) {
    Serial.print("i ");
    Serial.print(zone);
    Serial.println("01");
    presstate6 = !presstate6;
  } else if (!i && presstate6) {
    Serial.print("i ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate6 = !presstate6;
  }


  if (j && !presstate7) {
    Serial.print("j ");
    Serial.print(zone);
    Serial.println("01");
    presstate7 = !presstate7;
  } else if (!j && presstate7) {
    Serial.print("j ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate7 = !presstate7;
  }
  if (!k && !presstate8) {
    Serial.print("k ");
    Serial.print(zone);
    Serial.println("01");
    presstate8 = !presstate8;
  } else if (k && presstate8) {
    Serial.print("k ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate8 = !presstate8;
  }
}