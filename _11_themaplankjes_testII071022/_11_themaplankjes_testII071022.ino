int zone = 1;

int laser1 = 53;
int laser2 = 52;
int laser3 = 50;
int laser4 = 47;
int laser5 = 45;
int laser6 = 44;
int laser7 = 42;
int laser8 = 39;

int LDR4 = A4;
int LDR5 = A5;
int LDR6 = A6;
int LDR7 = A7;
int LDR8 = A8;
int LDR9 = A9;
int LDR10 = A10;
int LDR11 = A11;

int aButton15a = 51;
int aLED15a = 49;
int aButton15b = 48;
int aLED15b = 46;
int aButton25a = 43;
int aLED25a = 41;
int aButton25b = 39;
int aLED25b = 38;

int LDRwaarde4;
int LDRwaarde5;
int LDRwaarde6;
int LDRwaarde7;
int LDRwaarde8;
int LDRwaarde9;
int LDRwaarde10;
int LDRwaarde11;

bool LL1a = 0;
bool LL1b = 0;
bool LL1c = 1;
bool LL1d = 0;
bool LL15a = 0;
bool LL15b = 0;
bool LL15c = 1;
bool LL15d = 0;
bool LL2a = 0;
bool LL2b = 0;
bool LL2c = 1;
bool LL2d = 0;
bool LL25a = 0;
bool LL25b = 0;
bool LL25c = 0;
bool LL25d = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR4, INPUT);
  pinMode(LDR5, INPUT);
  pinMode(LDR6, INPUT);
  pinMode(LDR7, INPUT);
  pinMode(LDR8, INPUT);
  pinMode(LDR9, INPUT);
  pinMode(LDR10, INPUT);
  pinMode(LDR11, INPUT);

  pinMode(aButton15a, INPUT_PULLUP);
  pinMode(aButton15b, INPUT_PULLUP);
  pinMode(aButton25a, INPUT_PULLUP);
  pinMode(aButton25b, INPUT_PULLUP);

  pinMode(aLED15a, INPUT_PULLUP);  
  pinMode(aLED15b, INPUT_PULLUP);
  pinMode(aLED25a, INPUT_PULLUP);
  pinMode(aLED25b, INPUT_PULLUP);  

  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);

  digitalWrite(aLED15a, LOW);
  digitalWrite(aLED15b, LOW);
  digitalWrite(aLED25a, HIGH);
  digitalWrite(aLED25b, HIGH);
}

void loop() {

  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);
  digitalWrite(laser4, HIGH);
  digitalWrite(laser5, HIGH);
  digitalWrite(laser6, HIGH);
  digitalWrite(laser7, HIGH);
  digitalWrite(laser8, HIGH);


  LDRwaarde4 = analogRead(LDR4);
  LDRwaarde5 = analogRead(LDR5);
  LDRwaarde6 = analogRead(LDR6);
  LDRwaarde7 = analogRead(LDR7);
  LDRwaarde8 = analogRead(LDR8);
  LDRwaarde9 = analogRead(LDR9);
  LDRwaarde10 = analogRead(LDR10);
  LDRwaarde11 = analogRead(LDR11);

  if (LDRwaarde4 < 800) {
    LL1a = 1;
  }
  else {
    LL1a = 0;
  }

  if (LDRwaarde5 < 800) {
    LL1b = 1;
  }
  else {
    LL1b = 0;
  }

  if (LDRwaarde6 < 800) {
    LL15a = 1;
  }
  else {
    LL15a = 0;
  }

  if (LDRwaarde7 < 800) {
    LL15b = 1;
  }
  else {
    LL15b = 0;
  }

  if (LL1a && LL1b && LL1c == 1) {
    Serial.print("L1 ");
    Serial.print(zone);
    Serial.println(" 1");
    LL1c = 0;
    LL1d = 1;
  }
  else if (LL1a == 0 || LL1b == 0 && LL1d == 1) {
    Serial.print("L1 ");
    Serial.print(zone);
    Serial.println(" 0");
    LL1c = 1;
    LL1d =0;
  }

  if (LL15a && LL15b && LL15c == 1) {
    Serial.print("L15 ");
    Serial.print(zone);
    Serial.println(" 1");
    LL15c = 0;
    LL15d = 1;
  }
  else if (LL15a == 0 || LL15b == 0 && LL15d == 1) {
    Serial.print("L15 ");
    Serial.print(zone);
    Serial.println(" 0");
    LL15c = 1;
    LL15d = 0;
  }

  if (LL1a && LL1b && aButton15a == HIGH) {
    digitalWrite(aLED15a, LOW);
    Serial.print("L15a ");
    Serial.print(zone);
    Serial.println(" 1");
  }
  else if (LL1a && LL1b && aButton15a == LOW) {
    digitalWrite(aLED15a, HIGH);
    Serial.print("L1 ");
    Serial.print(zone);
    Serial.println(" 0");
  }

  if (LL1a && LL1b && aButton15b == HIGH) {
    digitalWrite(aLED15a, LOW);
    Serial.print("L15b ");
    Serial.print(zone);
    Serial.println(" 1");
  }
  else if (LL1a && LL1b && aButton15b == LOW) {
    digitalWrite(aLED15b, HIGH);
    Serial.print("L15b ");
    Serial.print(zone);
    Serial.println(" 0");
  }


  delay (500);
}
