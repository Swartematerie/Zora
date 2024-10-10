//#11 Thema plankjes
int vib1 = 8;
bool toggle = false;
int LED = LED_BUILTIN;

void setup() {
  pinMode (vib1, INPUT);
  pinMode (LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
 int val;
 val = digitalRead(vib1);
 Serial.println(val);
 
 if (val == HIGH){
    Serial.println("aan");
    digitalWrite(LED, HIGH);
 }
  else {
    Serial.println("uit");
    digitalWrite(LED, LOW);
  }

delay (500);
}
