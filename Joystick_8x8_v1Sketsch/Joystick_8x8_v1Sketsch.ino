//Declaration Joystick
int Xpin = A0;
int Ypin = A1;
int Spin = 2;
int Xval;
int Yval;
int Sval;  


//Declaration 8x8 led + shiftregister
int XasArray[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int YasArray[8] = {9, 10, 11, 12, 13, A3, A4, A5};
int x = 4;
int y = 12;


void setup() {
  Serial.begin(9600);
  // Joystick
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  //8x8 LED
  pinMode (XasArray[8], OUTPUT);
  pinMode (YasArray[8], OUTPUT);
}

void loop() {
  // Joystick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  while (Xval >= 1020, Ypin >= 505 && Ypin <= 520);
  {
    int i; i<10; i++;
    delay(1000);
    if (i = 10) 
    {
      digitalWrite(XasArray[x+1], HIGH);
    }
  }

  while (Xval <= 20, Ypin >= 505 && Ypin <= 520);

  while (Xpin >= 505 && Xpin <= 520, Ypin >= 1020);

  while (Xpin >= 505 && Xpin <= 520, Ypin <= 20);
}
