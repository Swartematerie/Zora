int zone = 2;
//#011 Arcade drukknop
int LED15b = 49;
int BTN15b = 51;
int LED15g = 46;
int BTN15g = 48;

int ODV15g;
int ODV15b;
int BTNV15g; //button value 1,5m groene kant
int BTNV15b; //button value 1.5m blauwe kant
bool BTN15gpresstate = 0;
bool BTN15bpresstate = 0;



void setup() {
  Serial.begin(9600);
  pinMode(LED15g, OUTPUT);
  pinMode(LED15b, OUTPUT);
  pinMode(BTN15g, INPUT_PULLUP);
  pinMode(BTN15b, INPUT_PULLUP);
  digitalWrite(LED15g, HIGH);
  digitalWrite(LED15b, HIGH);
}

void loop() {
  BTNV15g = digitalRead(BTN15g);
  BTNV15b = digitalRead(BTN15b);

  if (BTNV15g == LOW && BTN15gpresstate == 0) {
    digitalWrite(LED15g, LOW);
    Serial.print("B1 ");
    Serial.print(zone);
    Serial.println(" 1");
    BTN15gpresstate = 1;
  }
  if (BTNV15g == HIGH && BTN15gpresstate == 1) {
    digitalWrite(LED15g, HIGH);
    Serial.print("B1 ");
    Serial.print(zone);
    Serial.println(" 0");
    BTN15gpresstate = 0;
  }
  if (BTNV15b == LOW && BTN15bpresstate == 0) {
    digitalWrite(LED15b, LOW);
    Serial.print("B2 ");
    Serial.print(zone);
    Serial.println(" 1");
    BTN15bpresstate = 1;
  }
  if (BTNV15b == HIGH && BTN15bpresstate == 1) {
    digitalWrite(LED15b, HIGH);
    Serial.print("B2 ");
    Serial.print(zone);
    Serial.println(" 0");
    BTN15bpresstate = 0;
  }
  delay(2);
}
