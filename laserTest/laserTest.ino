
//#011 alle lasers aan
int laser1 = 53;
int laser2 = 52;
int laser3 = 50;
int laser4 = 47;
int laser5 = 45;
int laser6 = 44;
int laser7 = 42;
int laser8 = 39;



void setup() {
  Serial.begin(9600);
  pinMode(laser1, OUTPUT);
  pinMode(laser2, OUTPUT);
  pinMode(laser3, OUTPUT);
  pinMode(laser4, OUTPUT);
  pinMode(laser5, OUTPUT);
  pinMode(laser6, OUTPUT);
  pinMode(laser7, OUTPUT);
  pinMode(laser8, OUTPUT);
  digitalWrite(laser1, HIGH);
  digitalWrite(laser2, HIGH);
  digitalWrite(laser3, HIGH);
  digitalWrite(laser4, HIGH);
  digitalWrite(laser5, HIGH);
  digitalWrite(laser6, HIGH);
  digitalWrite(laser7, HIGH); 
  digitalWrite(laser8, HIGH); 
}

void loop() {

}
