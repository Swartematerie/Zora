int LDR1 = A0;
int paddenstoelA;

//#10 cactus
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
  // put your setup code here, to run once:
//#10 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
  pinMode (cactus3, INPUT_PULLUP);
  pinMode (cactus4, INPUT_PULLUP);
  pinMode (cactus5, INPUT_PULLUP);
  pinMode (LDR1, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 cactus();
}

void cactus() {

paddenstoelA = analogRead(LDR1);
  au1 = digitalRead(cactus1);
  if (au1 != oldau1) {
    if (au1 == HIGH) {
      Serial.print("cactus A 1 ");      
    }
    else {
      Serial.println("cactus A 0");
    }
    oldau1 = au1;
  }

  au2 = digitalRead(cactus2);
  if (au2 != oldau2) {
    if (au2 == HIGH) {
      Serial.println("cactus B 1");
    }
    else {
      Serial.println("cactus B 0");
    }
    oldau2 = au2;
  }

  au3 = digitalRead(cactus3);
  if (au3 != oldau3) {
    if (au3 == HIGH) {
      Serial.println("cactus C 1");
    }
    else {
      Serial.println("cactus C 0");
    }
    oldau3 = au3;
  }

  au4 = digitalRead(cactus4);
  if (au4 != oldau4) {
    if (au4 == HIGH) {
      Serial.println("cactus 4, 1");
    }
    else {
      Serial.println("cactus 4, 0");
    }
    oldau4 = au4;
  }

  au5 = digitalRead(cactus5);
  if (au5 != oldau5) {
    if (au5 == HIGH) {
      Serial.println("cactus5 1");
    }
    else {
      Serial.println("cactus5 0");
    }
    oldau5 = au5;
  }
}
