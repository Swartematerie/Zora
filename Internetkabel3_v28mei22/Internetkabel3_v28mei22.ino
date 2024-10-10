int LDR1 = A0; 
int LDR2 = A1; 
int drukPad = 22;
int ledPad = 31;

int paddenstoel1;
int paddenstoel2;
int presstate = 0;
int pad; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(drukPad, INPUT_PULLUP);
  pinMode(ledPad, OUTPUT);
  digitalWrite(ledPad, HIGH);

}

void loop() {

  paddenstoel1 = analogRead(LDR1);
  Serial.print("P1 ");
  Serial.println(paddenstoel1);

 paddenstoel2 = analogRead(LDR2);
  Serial.print("P2 ");
  Serial.println(paddenstoel2);

  pad = digitalRead(drukPad);
  if (pad == HIGH && presstate == 0) {
    digitalWrite(ledPad, HIGH);
    Serial.println("pad 1");
    presstate = 1;
  }
else if (pad == LOW && presstate == 1) {
    digitalWrite(ledPad, LOW);
    Serial.println("pad 0");
    presstate = 0;
  }
  
  delay(50);

}
