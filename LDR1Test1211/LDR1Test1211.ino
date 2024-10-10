int LDR1 = A8;
int LDRwaarde;
int laser = 8;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LDR1, INPUT);
pinMode(laser, OUTPUT);
digitalWrite(laser, HIGH);
}

void loop() {
  LDRwaarde = analogRead(LDR1);
Serial.println(LDRwaarde);
}
