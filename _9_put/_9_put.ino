//#9 de put
const int numReadings9 = 10;
int readings9[numReadings9];      // the readings from the analog input
int readIndex9 = 0;              // the index of the current reading
int total9 = 0;                  // the running total
int average9 = 0;                // the average
int putPin = A11;
int putValue = 0;


void setup() {
  Serial.begin(9600);
  //#9
  for (int thisReading9 = 0; thisReading9 < numReadings9; thisReading9++) {
    readings9[thisReading9] = 0;
  }
}

void loop() {

  total9 = total9 - readings9[readIndex9];
  readings9[readIndex9] = analogRead(putPin);
  Serial.println(putPin);
  total9 = total9 + readings9[readIndex9];
  readIndex9 = readIndex9 + 1;

 
  if (readIndex9 >= numReadings9) {
    // ...wrap around to the beginning:
    readIndex9 = 0;
  }

  average9 = total9 / numReadings9;
 
  putValue = analogRead(putPin);
  if (putValue > (average9 = average9 + 20)) {
    Serial.println("bang");

  }
}
