int roodKnopje = 2;
int groenKnopje = 3;
int ledPin = 9;
int ledPin2 = 10;
int LDR1 = A0;
int LDR2 = A1;


// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int count_red = 1;
int prestate = 0;
int buttonState2 = 0;         // variable for reading the pushbutton status
int count_green = 2;
int prestate2 = 0;
int count1 = 1;

int paddenstoelA;
int paddenstoelB;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(roodKnopje, INPUT_PULLUP);
  pinMode(groenKnopje, INPUT_PULLUP);
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  Serial.begin(9600);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(roodKnopje);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState == HIGH && prestate == 0) {
    count_red++;
    Serial.println(count_red);
    // turn LED on
    digitalWrite(ledPin, HIGH);
    delay(100);
    // turn LED off
    digitalWrite(ledPin, LOW);

    prestate = 1;
  } else if (buttonState == LOW) {
    prestate = 0;
  }

  buttonState2 = digitalRead(groenKnopje);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState2 == HIGH && prestate2 == 0) {
    count_green++;
    Serial.println(count_green);
    // turn LED on
    digitalWrite(ledPin2, HIGH);
    delay(100);
    // turn LED off
    digitalWrite(ledPin2, LOW);

    prestate2 = 1;
  } else if (buttonState2 == LOW) {
    prestate2 = 0;
  }

//deciding where to go red or green
  unsigned long currentTime = millis();
  if (currentTime > 10000) {
    if (count1 == 1) {
      if (count_red > count_green) {
        Serial.print("Rood ");
        count_red = 0;
        count_green = 0;
        count1 = 2;
      }
      if (count_red < count_green) {
        Serial.print("Groen ");
        count_red = 0;
        count_green = 0;
        count1 = 3;
      }
    }
  }

if (count1 == 2){
 paddenstoelA = analogRead(LDR1);
 Serial.print("paddenstoel A ");
 Serial.println(paddenstoelA);
 count_green = 2;
}

if (count1 == 3){
 paddenstoelB = analogRead(LDR2);
 Serial.print("paddenstoel C ");
 Serial.println(paddenstoelB);
 count_red = 2;
}

//deciding where to go from red to yellow or purple
  if (currentTime > 20000) {
    if (count1 == 2){
      if (count_red > count_green){
        Serial.println("Geel ");
        count_red = 0;
        count_green = 0;
        count1 = 4;
      }
     if (count_green > count_red){
       Serial.println("Paars ");
       count_red = 0;
       count_green = 0;
       count1 = 5;
     }
    }
  }

  if (count1 == 5){
    paddenstoelB = analogRead(LDR2);
    Serial.print("paddenstoel B ");
    Serial.println(paddenstoelB);
  }

//deciding where to go from green to blue or black
    if (currentTime > 20000) {
    if (count1 == 3){
      if (count_red > count_green){
        Serial.println("Blauw ");
        count_red = 0;
        count_green = 0;
        count1 = 6;
      }
     if (count_green > count_red){
       Serial.println("Zwart ");
       count_red = 0;
       count_green = 0;
       count1 = 7;
     }
    }
  }

  if (count1 == 6){
 paddenstoelA = analogRead(LDR1);
 Serial.print("paddenstoel D ");
 Serial.println(paddenstoelA);
}

}
