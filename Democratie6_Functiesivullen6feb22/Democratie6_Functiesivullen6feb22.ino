/*
   ConcenzorA v5.58
   3 February 2022

   (c) Patricia Swart, SwarteMaterie.
    supervised by J.R.Oosterhaven

*/
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

bool z;
bool a;
bool b;
bool c;
bool d;
bool e;
bool f;
bool g;
bool presstate3 = 0;
bool presstate4 = 0;
bool presstate5 = 0;
bool presstate6 = 0;
bool presstate7 = 0;
bool presstate8 = 0;
bool presstate9 = 0;
bool presstate10 = 0;

int zone = 1;
int tijdzone = 0;
int currentTime = 0;
int timeUnits = 0;
// 21 23 22
int kiezen = 8;
int maxZoneTime = 10;
int wisselZone = 9;
bool wisselen = 0;
bool noodknop = 0;
int teller = 0;

// variables will change:
int buttonStateRed = 0;         // variable for reading the pushbutton status
int count_red = 2;
int prestateRed = 0;
int buttonStateGreen = 0;         // variable for reading the pushbutton status
int count_green = 1;
int prestateGreen = 0;

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
int cactus1 = 37;
int cactus2 = 39;
int cactus3 = 47;
int cactus4 = 43;
int cactus5 = 45;
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

void setup() {
  // initialize the LED pin as an output:

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

  //#013 & #002
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

  digitalWrite(controlLed, LOW);
  //  pinMode(LDR1, INPUT);
  //  pinMode(LDR2, INPUT);
  Serial.begin(9600);
  Serial.println("Start");
}


void loop() {

  if (noodknop) {
    teller++;
  }

  if (!noodknop) {

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

    if (buttonStateRed || buttonStateGreen || z || !a || b || c || !d || !e || !f || !g) {
      digitalWrite(controlLed, HIGH);
    }
    else {
      digitalWrite(controlLed, LOW);
    }

    buttonStateRed = digitalRead(roodKnopje);

    if (buttonStateRed == HIGH && prestateRed == 0 && !wisselen) {
      count_red++;
      prestateRed = 1;
    }  else if (buttonStateRed == LOW) {
      prestateRed = 0;
    }

    buttonStateGreen = digitalRead(groenKnopje);

    if (buttonStateGreen == HIGH && prestateGreen == 0 && !wisselen) {
      count_green++;
      prestateGreen = 1;

    } else if (buttonStateGreen == LOW) {
      prestateGreen = 0;
    }
      if (zone == 2) {int kiezen = 6; int maxZoneTime = 8; int wisselZone = 7;}
      if (zone == 3) {int kiezen = 4; int maxZoneTime = 15; int wisselZone = 14;}
      if (zone == 4) {int kiezen = 12; int maxZoneTime = 15; int wisselZone = 14;}
      if (zone == 5) {int kiezen = 10; int maxZoneTime = 15; int wisselZone = 14;}
      if (zone == 6) {int wisselZone = 1;}
      if (zone == 7) {int wisselZone = 10;}
      
    if (timeUnits == kiezen && currentTime == 0) {
      Serial.println("kies 7");
    }

    if (timeUnits == maxZoneTime) {
      tijdzone ++;
      timeUnits = 0;
      count_red = 0;
      count_green = 0;
      wisselen = 0;
      Serial.print("zone ");
      Serial.println(zone);
    }



      if (tijdzone == 3) {Serial.println ("kies 8");} 



    if (timeUnits == wisselZone && currentTime == 0) {
      Serial.println("wis");
    }

    if (timeUnits >= wisselZone) {
      //  Serial.println("wis");
      wisselen = 1;
    }

    switch (tijdzone) {
      case 0:
        if (wisselen) {
          if (count_red > count_green) {
            zone = 2;
          }
          if (count_green > count_red) {
            zone = 3;
          }
          if (count_red == count_green) {
            zone = 2;
          }
        }
        break;

      case 1:
        if (wisselen) {
          if (zone == 2) {
            if (count_red > count_green) {
              zone = 4;
            }
            if (count_green > count_red) {
              zone = 5;
            }
            if (count_green == count_red) {
              zone = 7;
            }
          }

          if (zone == 3) {
            if (count_red > count_green) {
              zone = 6;
            }
            if (count_green > count_red) {
              zone = 7;
            }
            if (count_green == count_red) {
              zone = 7;
            }
          }
          break;

        case 2:
          if (wisselen) {
            if (zone == 4) {
              if (count_red > count_green) {
                zone = 8;
              }
              if (count_green > count_red) {
                zone = 9;
              }
            }

            if (zone == 5) {
              if (count_red > count_green) {
                zone = 10;
              }
              if (count_green > count_red) {
                zone = 11;
              }
            }
          }
          break;

        }


    }

    currentTime++;
    delay(5);
    if (currentTime == 1500) {
      currentTime = 0;
      timeUnits++;
      Serial.print("unit ");
      Serial.println(timeUnits);

    }
    
    if (zone == 1) {
     Paddenstoel1();
     Paddenstoel2();
    }
    
    if (zone == 2) {
    Paddenstoel1();
    Paddenstoel2();
    }
    if (zone == 3){
      cactus();
      cases2();
    }

    if (zone == 4){
    cases3 ();
    }
    if (zone == 5){
 
    }
    if (zone == 6){
    cases2 ();
    cactus ();  
    }
    if (zone == 7){
      
    }

  }
}

//-----------------------------------------
//------------FUNCTIONS--------------------
//-----------------------------------------

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
