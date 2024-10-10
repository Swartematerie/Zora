int LDR6 = A6;
int LDRwaarde6;

int LLButton1 = 51;
int LLButtonwaarde1;

int laser21 = 50;
int LLLED21 = 49;
+
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(LDR6, INPUT);
pinMode(LLButton1, INPUT_PULLUP);
pinMode(laser21, OUTPUT);
pinMode(LLLED21, OUTPUT);
digitalWrite(laser21, HIGH);
digitalWrite(LLLED21, HIGH);

}

void loop() {
  LDRwaarde6 = analogRead(LDR6);
Serial.println(LDRwaarde6);
  LLButtonwaarde1 = digitalRead(LLButton1);
if (LLButtonwaarde1 == LOW){
  Serial.println("LED ON");
  digitalWrite(LLLED21, LOW);
}
else if (LLButtonwaarde1 == HIGH){
  Serial.println("LED OFF");
  digitalWrite(LLLED21, HIGH);
}

if (LDRwaarde6 < 800) {
  Serial.println("Ja6");
}

delay (700);
}
