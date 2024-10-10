int sensorPin = 2;
int ledPin = 4;
int value = 0;

void setup() {
  Serial.begin(57600);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  value = analogRead(sensorPin);
  Serial.println(value);
  

//  if (value > 400) {
//    digitalWrite(ledPin, HIGH);
//                      }
//  else {
//    digitalWrite(ledPin, LOW);
//         }
// 
  delay(100);

}
