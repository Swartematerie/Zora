int OD1g = 53;
int ODV1g;
int OD1b = 51;
int ODV1b;
bool oDetSw1 = 0;

int OD2g = 49;
int ODV2g;
int OD2b = 47;
int ODV2b;
bool oDetSw2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(OD1g, INPUT);
  pinMode(OD1b, INPUT);
}

void loop() {
  ODV1g = digitalRead(OD1g);
  ODV1b = digitalRead(OD1b);

  if (ODV1g == LOW && ODV1b == LOW) {
   if (oDetSw1 == 0) {
      Serial.println("Q1 1");
     oDetSw1 = 1;
    }
  }
  else if(oDetSw1 == 1) {
    oDetSw1 = 0;
    Serial.println("Q1 0");
  }


  ODV2g = digitalRead(OD2g);
  ODV2b = digitalRead(OD2b);

  if (ODV2g == LOW && ODV2b == LOW) {
   if (oDetSw2 == 0) {
      Serial.println("Q3 1");
     oDetSw2 = 1;
    }
  }
  else if (oDetSw2 == 1) {
    oDetSw2 = 0;
    Serial.println("Q3 0");
  }
}
