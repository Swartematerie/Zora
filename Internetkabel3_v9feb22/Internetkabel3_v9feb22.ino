int LDR1 = A3; 
int LDR2 = A4; 
int LDR3 = A5; 
int LDR4 = A6; 
int LDR5 = A7; 

int case1;
int case2;
int case3;
int doel2;
int paddenstoel1;
int paddenstoel2;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(LDR3, INPUT);
  pinMode(LDR4, INPUT);
  pinMode(LDR5, INPUT);
}

void loop() {
  paddenstoel1 = analogRead(LDR1);
  Serial.print("P1 ");
  Serial.println(paddenstoel1);

  paddenstoel2 = analogRead(LDR2);
  Serial.print("P2 ");
  Serial.println(paddenstoel2);

  case1 = analogRead(LDR3);
  Serial.print("C1 ");
  Serial.println(case1);
  
  case2 = analogRead(LDR4);
  Serial.print("C2 ");
  Serial.println(case2);

  case3 = analogRead(LDR5);
  Serial.print("C3 ");
  Serial.println(case3);

  delay(600);

}
