
//#002 paddenstoelen
int LDR1 = A2;
int LDR2 = A3;
int padDruk = 38;
int padLED = 39;

int paddenstoel1;
int paddenstoel2;
bool padKnopje;
bool padPresstate;

bool zonePresstate;
int zone = 0;
int rondje;
bool einde = 0;



void setup() {
  Serial.begin(9600);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(padDruk, INPUT_PULLUP);
  pinMode(padLED, OUTPUT);
  digitalWrite(padLED, HIGH);
  digitalWrite(padKnopje, HIGH);
}

void loop() {
  
  if(einde == 0){
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

//    digitalWrite(padLED, LOW);
  }

  padKnopje = digitalRead(padDruk);
  if (padKnopje == HIGH && padPresstate == 0 && zone < 5) {
      digitalWrite(padLED, LOW);
//    Serial.println("x 1");
    zone++;
    Serial.print("zone ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == HIGH && padPresstate == 0 && zone == 5) {
    zone = 1;
//    Serial.println("x 1");
    Serial.print("zone ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == LOW && padPresstate == 1) {
    digitalWrite(padLED, HIGH);
 //   Serial.println("x 0");
    padPresstate = 0;
    delay(8);
  }

  if (zone == 1 && zonePresstate == 0 && einde == 0){
    rondje++;
    zonePresstate = 1;
    Serial.println(rondje);
  }
  if(zone >= 2){
    zonePresstate = 0;
  }
 /*
  if (rondje == 15 && zonePresstate == 1){
    zone = 100;
    Serial.println ("einde");
    zonePresstate = 1;
    einde = 1; 
  }
*/
}
