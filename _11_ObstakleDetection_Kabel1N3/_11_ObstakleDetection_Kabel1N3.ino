int OD1g = 47;
int ODV1g;
bool oDetSw1g;

int OD1b = 50;
int ODV1b;
bool oDetSw1b;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(OD1g, INPUT);
  pinMode(OD1b, INPUT);
}

void loop() {
  ODV1g = digitalRead(OD1g);
  ODV1b = digitalRead(OD1b);

  if (ODV1g == LOW) {
    if (oDetSw1g == 0) {
      Serial.println("GROEN");
      oDetSw1g = 1;
    }
  }
  else if (ODV1g == HIGH) {
    if (oDetSw1g == 1) {
      Serial.println("NO GROEN");
      oDetSw1g = 0;
    }
  }

  if (ODV1b == LOW) {
    if (oDetSw1b == 0) {
      Serial.println("Blauw");
      oDetSw1b = 1;
    }
  }
  else if (ODV1b == HIGH) {
    if (oDetSw1b == 1) {
      Serial.println("NO BLAUW");
      oDetSw1b = 0;
    }
  }

    if(ODV1g == LOW && ODV1b == LOW) {
      Serial.println("HOERA");
    }
  
}
