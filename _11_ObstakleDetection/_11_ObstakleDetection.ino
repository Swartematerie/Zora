int oDet = 43;
int oDetvalue;
bool oDetSw;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(oDet, INPUT);
}

void loop() {
  oDetvalue = digitalRead(oDet);

  if (oDetvalue == LOW) {
    if (oDetSw == 0) {
      Serial.println("YES");
      oDetSw = 1;
    }
  }
  else if (oDetvalue == HIGH) {
    if (oDetSw == 1) {
      Serial.println("NO");
      oDetSw = 0;
    }
  }
}
