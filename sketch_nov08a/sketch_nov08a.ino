int drukKnop = 22;
int drukKnop2 = 23;
int drukKnop3 = 24;
int drukKnop4 = 26;
int drukKnop5 = 28;
int drukKnop6 = 30;

int ledPin = 25;
int x;
int y;
int z;
int a;
int b;
int c;
int presstate = 0;
int presstate2 = 0;
int presstate3 = 0;
int presstate4 = 0;
int presstate5 = 0;
int presstate6 = 0;

int LDR1 = A0;
int paddenstoelA;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(drukKnop, INPUT_PULLUP);
  pinMode(drukKnop2, INPUT_PULLUP);
  pinMode(drukKnop3, INPUT_PULLUP);
  pinMode(drukKnop4, INPUT_PULLUP);
  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

}

void loop() {
  x = digitalRead(drukKnop);
  if (x == HIGH && presstate == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("x 1");
    presstate = 1;
  }
  else if (x == LOW && presstate == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("x 0");
    presstate = 0;
  }

  y = digitalRead(drukKnop2);
  if (y == HIGH && presstate2 == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("y 1");
    presstate2 = 1;
  }
  else if (y == LOW && presstate2 == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("y 0");
    presstate2 = 0;
  }

  z = digitalRead(drukKnop3);
  if (z == HIGH && presstate3 == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("z 1");
    presstate3 = 1;
  }
  else if (z == LOW && presstate3 == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("z 0");
    presstate3 = 0;
  }
  
    a = digitalRead(drukKnop4);
  if (a == HIGH && presstate4 == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("a 1");
    presstate4 = 1;
  }
  else if (a == LOW && presstate4 == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("a 0");
    presstate4 = 0;
  }

    b = digitalRead(drukKnop5);
  if (b == HIGH && presstate5 == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("b 1");
    presstate5 = 1;
  }
  else if (b == LOW && presstate5 == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("b 0");
    presstate5 = 0;
  }

    c = digitalRead(drukKnop6);
  if (c == HIGH && presstate6 == 0) {
    digitalWrite(ledPin, HIGH);
    Serial.println("c 1");
    presstate6 = 1;
  }
  else if (c == LOW && presstate6 == 1) {
    digitalWrite(ledPin, LOW);
    Serial.println("c 0");
    presstate6 = 0;
  }
  /*
    paddenstoelA = analogRead(LDR1);
    Serial.print("LDR1 ");
    Serial.println(paddenstoelA);
  */

}