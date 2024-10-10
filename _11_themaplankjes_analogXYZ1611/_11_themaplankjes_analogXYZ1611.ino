int thema1 = A0;
int Xas;

void setup() {
  Serial.begin(9600);
  pinMode(thema1, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
Xas = analogRead(thema1);
Serial.print("Xwaarde ");
Serial.println(Xas);
delay(1000);
}
