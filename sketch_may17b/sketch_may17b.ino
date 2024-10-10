int firefLights = A3;
int LDR1;

int REEDpin1 = 12;
int REEDvalue1 = 0;
int oldREEDvalue1 = 0;

void setup() {
  Serial.begin(9600);
  pinMode(firefLights, INPUT);
  pinMode(REEDpin1, INPUT);

}

void loop() {
  LDR1 = analogRead(firefLights);
  Serial.print("LDR1 ");
  Serial.println(LDR1);
  
  REEDvalue1 = digitalRead(REEDpin1);
  if (REEDvalue1 != oldREEDvalue1) {
    if (digitalRead(REEDpin1) == LOW)
      Serial.println("REED1 1");
    else
      Serial.println("REED1 0");
    oldREEDvalue1 = REEDvalue1;
  }
  delay(100);

}
