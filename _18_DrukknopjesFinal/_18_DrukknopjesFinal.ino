
//#018 Drukknopjes
#define drukKnop1 22
#define drukKnop2 23
#define drukKnop3 24
#define drukKnop4 25
#define drukKnop5 26
#define drukKnop6 27
#define drukKnop7 28
#define drukKnop8 29

bool d;
bool e;
bool f;
bool g;
bool h;
bool i;
bool j;
bool k;
bool presstate1 = 0;
bool presstate2 = 0;
bool presstate3 = 0;
bool presstate4 = 0;
bool presstate5 = 0;
bool presstate6 = 0;
bool presstate7 = 0;
bool presstate8 = 0;

int zone = 1;

void setup() {
  Serial.begin(9600);
  //#018
  pinMode(drukKnop1, INPUT_PULLUP);
  pinMode(drukKnop2, INPUT_PULLUP);
  pinMode(drukKnop3, INPUT_PULLUP);
  pinMode(drukKnop4, INPUT_PULLUP);
  pinMode(drukKnop5, INPUT_PULLUP);
  pinMode(drukKnop6, INPUT_PULLUP);
  pinMode(drukKnop7, INPUT_PULLUP);
  pinMode(drukKnop8, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  d = digitalRead(drukKnop1);
  e = digitalRead(drukKnop2);
  f = digitalRead(drukKnop3);
  g = digitalRead(drukKnop4);
  
  h = digitalRead(drukKnop5);
  i = digitalRead(drukKnop6);
  j = digitalRead(drukKnop7);
  k = digitalRead(drukKnop8);

  if (d && !presstate1) {
    Serial.print("d ");
    Serial.print(zone);
    Serial.println("01");
    presstate1 = !presstate1;
  } else if (!d && presstate1) {
    Serial.print("d ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate1 = !presstate1;
  }

  if (e && !presstate2) {
    Serial.print("e ");
    Serial.print(zone);
    Serial.println("01");
    presstate2 = !presstate2;
  } else if (!e && presstate2) {
    Serial.print("e ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate2 = !presstate2;
  }

  if (!f && !presstate3) {
    Serial.print("f ");
    Serial.print(zone);
    Serial.println("01");
    presstate3 = !presstate3;
  } else if (f && presstate3) {
    Serial.print("f ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate3 = !presstate3;
  }
  if (!g && !presstate4) {
    Serial.print("g ");
    Serial.print(zone);
    Serial.println("01");
    presstate4 = !presstate4;
  } else if (g && presstate4) {
    Serial.print("g ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate4 = !presstate4;
  }

  if (h && !presstate5) {
    Serial.print("h ");
    Serial.print(zone);
    Serial.println("01");
    presstate5 = !presstate5;
  } else if (!h && presstate5) {
    Serial.print("h ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate5 = !presstate5;
  }

  if (i && !presstate6) {
    Serial.print("i ");
    Serial.print(zone);
    Serial.println("01");
    presstate6 = !presstate6;
  } else if (!i && presstate6) {
    Serial.print("i ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate6 = !presstate6;
  }


  if (j && !presstate7) {
    Serial.print("j ");
    Serial.print(zone);
    Serial.println("01");
    presstate7 = !presstate7;
  } else if (!j && presstate7) {
    Serial.print("j ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate7 = !presstate7;
  }
  if (!k && !presstate8) {
    Serial.print("k ");
    Serial.print(zone);
    Serial.println("01");
    presstate8 = !presstate8;
  } else if (k && presstate8) {
    Serial.print("k ");
    Serial.print(zone); // zone
    Serial.println("00"); // status
    presstate8 = !presstate8;
  }



}
