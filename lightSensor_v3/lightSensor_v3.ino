int sensorPin = 0;
int value = 0;
int sensorPin2 = 1;
int value2 = 0;

/*int ledPin = 4;

int value2 = 0;
int mv = 0;
*/

void setup() {
  Serial.begin(57600);
 // pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
  pinMode(sensorPin2, INPUT);
  

}

void loop() {
  value = analogRead(sensorPin);
  value2 = analogRead(sensorPin2);

  Serial.print("LDR ");
  Serial.println(value);
  Serial.print("IR ");
  Serial.println(value2);

 /* if (value2 > 0) {
    digitalWrite(ledPin, HIGH);
                      }
  else {
    digitalWrite(ledPin, LOW);
         }
 */
  delay(100);

}
