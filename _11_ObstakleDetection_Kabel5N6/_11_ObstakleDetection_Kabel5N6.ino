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

int LED25b = 41;
int BTN25b = 43;
int BTNV25b;



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

  if (ODV25g == LOW) {
    if (oDetSw5 == 0) {
      Serial.println("GROEN");
      oDetSw5 = 1;
    }
  }
  else if (ODV25g == HIGH) {
    if (oDetSw5 == 1) {
      Serial.println("NO GROEN");
      oDetSw5 = 0;
    }
  }

  if (ODV25b == LOW) {
    if (oDetSw6 == 0) {
      Serial.println("Blauw");
      oDetSw6 = 1;
    }
  }
  else if (ODV25b == HIGH) {
    if (oDetSw6 == 1) {
      Serial.println("NO BLAUW");
      oDetSw6 = 0;
    }
  }


  if (ODV25g == LOW && ODV25b == LOW) {
   if (oDetSw25 == 0) {
      Serial.println("Q4 1");
     oDetSw25 = 1;
    }
  }
  else if(oDetSw25 == 1) {
    oDetSw25 = 0;
    Serial.println("Q4 0");
  }


}
