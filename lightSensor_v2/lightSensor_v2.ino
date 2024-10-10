int sensorPin = 0;
int value = 0;


void setup() {
  Serial.begin(57600);
  pinMode(sensorPin, INPUT);

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
