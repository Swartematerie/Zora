int zone = 0; //incomming byte from UNO
int zone2 = 0;
char mystr[1];
char mysts[1];

//#002 paddenstoel
int LDR1 = A2;
int LDR2 = A3;
int padDruk = 36;
int padLED = 37;

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

//#018 Drukknopjes
#define drukKnop1 22
#define drukKnop2 24
#define drukKnop3 26
#define drukKnop4 28
#define drukKnop5 23
#define drukKnop6 25
#define drukKnop7 27
#define drukKnop8 29

bool d;
bool e;
bool f;
bool g;
bool h;
bool i;
bool j;
bool k;
bool presstate1 = 0;
bool presstate2 = 0;
bool presstate3 = 0;
bool presstate4 = 0;
bool presstate5 = 0;
bool presstate6 = 0;
bool presstate7 = 0;
bool presstate8 = 0;



//-----------------------------------------
//----------------Setup--------------------
//-----------------------------------------
void setup() {
  Serial.begin(115200);
  pinMode(padDruk, INPUT_PULLUP);
  pinMode(padLED, OUTPUT);
  digitalWrite(padLED, HIGH);
  digitalWrite(padKnopje, HIGH);


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
  pinMode(drukKnop1, INPUT_PULLUP);
  pinMode(drukKnop2, INPUT_PULLUP);
  pinMode(drukKnop3, INPUT_PULLUP);
  pinMode(drukKnop4, INPUT_PULLUP);
  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(drukKnop7, INPUT_PULLUP);
  pinMode(drukKnop8, INPUT_PULLUP);
}

//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
void loop() {

  if (Serial.available() > 0) {
    zone = Serial.parseInt();
    Serial.print("zone ");
    Serial.println(zone);
    delay(200);
  }


  /*
    zone = Serial.readBytes(mystr, 2);
    Serial.println(zone);
    delay(200);
  */
 drukknopjes();
 cactus();
  //Serial.print("zone ");
  //Serial.println(zone);


}

//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------
void Paddenstoel () {

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
      Serial.print("C3 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C3 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau1 = au1;
  }

  au2 = digitalRead(cactus2);
  if (au2 != oldau2) {
    if (au2 == HIGH) {
      Serial.print("C4 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C4 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau2 = au2;
  }

  au3 = digitalRead(cactus3);
  if (au3 != oldau3) {
    if (au3 == HIGH) {
      Serial.print("C5 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C5 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau3 = au3;
  }

  au4 = digitalRead(cactus4);
  if (au4 != oldau4) {
    if (au4 == HIGH) {
      Serial.print("C1 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C1 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau4 = au4;
  }

  au5 = digitalRead(cactus5);
  if (au5 != oldau5) {
    if (au5 == HIGH) {
      Serial.print("C2 ");
      Serial.print(zone);
      Serial.println(" 1");
    }
    else {
      Serial.print("C2 ");
      Serial.print(zone);
      Serial.println(" 0");
    }
    oldau5 = au5;
  }
}

void drukknopjes(){
  d = digitalRead(drukKnop1);
  e = digitalRead(drukKnop2);
  f = digitalRead(drukKnop3);
  g = digitalRead(drukKnop4);
  
  h = digitalRead(drukKnop5);
  i = digitalRead(drukKnop6);
  j = digitalRead(drukKnop7);
  k = digitalRead(drukKnop8);

  if (d && !presstate1) {
    Serial.print("d ");
    Serial.print(zone);
    Serial.println("01");
    presstate1 = !presstate1;
  } else if (!d && presstate1) {
    Serial.print("d ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate1 = !presstate1;
  }

  if (e && !presstate2) {
    Serial.print("e ");
    Serial.print(zone);
    Serial.println("01");
    presstate2 = !presstate2;
  } else if (!e && presstate2) {
    Serial.print("e ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate2 = !presstate2;
  }

  if (!f && !presstate3) {
    Serial.print("f ");
    Serial.print(zone);
    Serial.println("01");
    presstate3 = !presstate3;
  } else if (f && presstate3) {
    Serial.print("f ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate3 = !presstate3;
  }
  if (!g && !presstate4) {
    Serial.print("g ");
    Serial.print(zone);
    Serial.println("01");
    presstate4 = !presstate4;
  } else if (g && presstate4) {
    Serial.print("g ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate4 = !presstate4;
  }

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
