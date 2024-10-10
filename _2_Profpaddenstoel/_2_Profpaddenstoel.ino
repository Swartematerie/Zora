
//#002 paddenstoelen
int LDR1 = A2;
int LDR2 = A3;
int padDruk = 36;
int padLED = 37;

int paddenstoel1;
int paddenstoel2;
bool padKnopje;
bool padPresstate;
bool padPresstate7;

int zone = 0;



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


  padKnopje = digitalRead(padDruk);
  if (zone == 7) {
    padPresstate7 = 1;
  }
  if (padKnopje == HIGH && padPresstate == 0 && zone < 7) {
    digitalWrite(padLED, HIGH);
//    Serial.println("x 1");
    zone++;
    Serial.print("zone: ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == HIGH && padPresstate == 0 && zone == 7) {
    zone = 0;    
    Serial.print("zone: ");
    Serial.println(zone);
    padPresstate = 1;
    delay(8);
  }
  else if (padKnopje == LOW && padPresstate == 1) {
    digitalWrite(padLED, LOW);
 //   Serial.println("x 0");
    padPresstate = 0;
    delay(8);
  }

  delay(500);

}
