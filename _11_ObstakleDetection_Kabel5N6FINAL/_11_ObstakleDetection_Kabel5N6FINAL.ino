//#011
int OD25g = 39;
int ODV25g;
bool oDetSw5 = 0;
int OD25b = 42;
int ODV25b;
bool oDetSw6 = 0;
bool oDetSw25 = 0;

int LED25g = 38;
int BTN25g = 40;
int BTNV25g;
bool BTN25gpresstate = 0;

int LED25b = 41;
int BTN25b = 43;
int BTNV25b;
bool BTN25bpresstate = 0;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(OD25g, INPUT);
  pinMode(OD25b, INPUT);
  pinMode(LED25g, OUTPUT);
  pinMode(LED25b, OUTPUT);
  pinMode(BTN25g, INPUT_PULLUP);
  pinMode(BTN25b, INPUT_PULLUP);
  digitalWrite(LED25g, HIGH);
  digitalWrite(LED25b, HIGH);
}

void loop() {


  ODV25g = digitalRead(OD25g);
  ODV25b = digitalRead(OD25b);


  if (ODV25g == LOW && ODV25b == LOW) {
    if (oDetSw25 == 0) {
      Serial.println("Q4 1");
      oDetSw25 = 1;
    }


    BTNV25g = digitalRead(BTN25g);
    BTNV25b = digitalRead(BTN25b);

    if (BTNV25g == LOW && BTN25gpresstate == 0) {
      digitalWrite(LED25g, LOW);
      Serial.println("B3 1");
      BTN25gpresstate = 1;
    }
    else if (BTNV25g == HIGH && BTN25gpresstate == 1) {
      digitalWrite(LED25g, HIGH);
      Serial.println("B3 0");
      BTN25gpresstate = 0;
    }
    if (BTNV25b == LOW && BTN25bpresstate == 0) {
      digitalWrite(LED25b, LOW);
      Serial.println("B4 1");
      BTN25bpresstate = 1;
    }
    else if (BTNV25b == HIGH && BTN25bpresstate == 1) {
      digitalWrite(LED25b, HIGH);
      Serial.println("B4 0");
      BTN25bpresstate = 0;
    }
    delay(2);
  }

  else if (oDetSw25 == 1) {
    oDetSw25 = 0;
    Serial.println("Q4 0");
  }


}
