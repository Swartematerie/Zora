//#10 cactus
int cactus1 = 8;
int cactus2 = 9;
int cactus3 = 10;
int cactus4 = 11;
int cactus5 = 12;
int au1;
int au2;
int au3;
int au4;
int au5;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //#10 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
  pinMode (cactus3, INPUT_PULLUP);
  pinMode (cactus4, INPUT_PULLUP);
  pinMode (cactus5, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  au1 = digitalRead(cactus1);
  if (au1 == HIGH) {
    Serial.println("au1");
  }

  au2 = digitalRead(cactus2);
  if (au2 == HIGH) {
    Serial.println("au2");
  }
  au3 = digitalRead(cactus3);
  if (au3 == HIGH) {
    Serial.println("au3");
  }
  au4 = digitalRead(cactus4);
  if (au4 == HIGH) {
    Serial.println("au4");
  }
  au5 = digitalRead(cactus5);
  if (au5 == HIGH) {
    Serial.println("au5");
  }

}
