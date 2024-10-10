int zone = 6;

//#011 Themaplankjes
int OD1b = 53; //obstakel detectie 1m afstend blauwwitte draad
int OD1g = 51; //obstacle detection 1m afstand groenewitte internet draad

int OD15b = 52;
int LED15b = 46;
int BTN15b = 48;

int OD15g = 50; // obstake detectie 1,5m afstand groenwitte
int LED15g = 42;
int BTN15g = 44;

int OD2b = 49;
int OD2g = 47;

int OD25b = 41;
int LED25b = 43;
int BTN25b = 45;

int OD25g = 39;
int LED25g = 35;
int BTN25g = 37;

//#011 Themaplankjes varabelen declaratie.
int ODV1g; //Obstacle detection 1m afstand groene kant
int ODV1b;

int ODV15g;
int ODV15b;
int BTNV15g; //button value 1,5m groene kant
int BTNV15b; //button value 1.5m blauwe kant
bool BTN15gpresstate = 0;
bool BTN15bpresstate = 0;

int ODV2g;
int ODV2b;

int ODV25g;
int ODV25b;
int BTNV25g;
int BTNV25b;
bool BTN25gpresstate = 0;
bool BTN25bpresstate = 0;

bool oDetSw1 = 0;
bool oDetSw15 = 0;
bool oDetSw2 = 0;
bool oDetSw25 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //#011 themaplankjes
  pinMode(OD1g, INPUT);
  pinMode(OD1b, INPUT);

  pinMode(OD15g, INPUT);
  pinMode(OD15b, INPUT); 
  pinMode(LED15g, OUTPUT);
  pinMode(LED15b, OUTPUT);
  pinMode(BTN15g, INPUT_PULLUP);
  pinMode(BTN15b, INPUT_PULLUP);
  digitalWrite(LED15g, HIGH);
  digitalWrite(LED15b, HIGH);

  pinMode(OD2g, INPUT);
  pinMode(OD2b, INPUT);

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

  ODV1g = digitalRead(OD1g);
  ODV1b = digitalRead(OD1b);

  if (ODV1g == LOW && ODV1b == LOW) {
    if (oDetSw1 == 0) {
      Serial.print("Q1 ");
      Serial.print(zone);
      Serial.println(" 1");
      oDetSw1 = 1;
    }
  }
  else if (oDetSw1 == 1) {
    oDetSw1 = 0;
      Serial.print("Q1 ");
      Serial.print(zone);
      Serial.println(" 0");
  }

  ODV15g = digitalRead(OD15g);
  ODV15b = digitalRead(OD15b);


  if (ODV15g == LOW && ODV15b == LOW) {
    if (oDetSw15 == 0) {
      Serial.print("Q2 ");
      Serial.print(zone);
      Serial.println(" 1");
      oDetSw15 = 1;
    }

    BTNV15g = digitalRead(BTN15g);
    BTNV15b = digitalRead(BTN15b);

    if (BTNV15g == LOW && BTN15gpresstate == 0) {
      digitalWrite(LED15g, LOW);
      Serial.print("B1 ");
      Serial.print(zone);
      Serial.println(" 1");
      BTN15gpresstate = 1;
    }
    else if (BTNV15g == HIGH && BTN15gpresstate == 1) {
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
    else if (BTNV15b == HIGH && BTN15bpresstate == 1) {
      digitalWrite(LED15b, HIGH);
      Serial.print("B2 ");
      Serial.print(zone);
      Serial.println(" 0");
      BTN15bpresstate = 0;
    }
    delay(2);
  }

  else if (oDetSw15 == 1) {
    oDetSw15 = 0;
      Serial.print("Q2 ");
      Serial.print(zone);
      Serial.println(" 0");
  }

  ODV2g = digitalRead(OD2g);
  ODV2b = digitalRead(OD2b);

  if (ODV2g == LOW && ODV2b == LOW) {
    if (oDetSw2 == 0) {
      Serial.print("Q3 ");
      Serial.print(zone);
      Serial.println(" 1");
      oDetSw2 = 1;
    }
  }
  else if (oDetSw2 == 1) {
    oDetSw2 = 0;
      Serial.print("Q3 ");
      Serial.print(zone);
      Serial.println(" 0");
  }

  ODV25g = digitalRead(OD25g);
  ODV25b = digitalRead(OD25b);


  if (ODV25g == LOW && ODV25b == LOW) {
    if (oDetSw25 == 0) {
      Serial.print("Q4 ");
      Serial.print(zone);
      Serial.println(" 1");
      oDetSw25 = 1;
    }


    BTNV25g = digitalRead(BTN25g);
    BTNV25b = digitalRead(BTN25b);

    if (BTNV25g == LOW && BTN25gpresstate == 0) {
      digitalWrite(LED25g, LOW);
      Serial.print("B3 ");
      Serial.print(zone);
      Serial.println(" 1");
      BTN25gpresstate = 1;
    }
    else if (BTNV25g == HIGH && BTN25gpresstate == 1) {
      digitalWrite(LED25g, HIGH);
      Serial.print("B3 ");
      Serial.print(zone);
      Serial.println(" 0");
      BTN25gpresstate = 0;
    }
    if (BTNV25b == LOW && BTN25bpresstate == 0) {
      digitalWrite(LED25b, LOW);
      Serial.print("B4 ");
      Serial.print(zone);
      Serial.println(" 1");
      BTN25bpresstate = 1;
    }
    else if (BTNV25b == HIGH && BTN25bpresstate == 1) {
      digitalWrite(LED25b, HIGH);
      Serial.print("B4 ");
      Serial.print(zone);
      Serial.println(" 0");
      BTN25bpresstate = 0;
    }
    delay(2);
  }

  else if (oDetSw25 == 1) {
    oDetSw25 = 0;
      Serial.print("Q4 ");
      Serial.print(zone);
      Serial.println(" 0");
  }


}
