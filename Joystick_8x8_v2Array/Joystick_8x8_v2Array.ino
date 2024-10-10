//Declaration Joystick
int JoystickArray[] = (A0, A1, A2);
int Xval;
int Yval;
int Sval; 


//Declaration 8x8 led + shift register


void setup() {
  Serial.begin(9600);
  // Joystick
  for(int i; i<2; i++)
  {
    pinMode(JoystickArray[i], INPUT);
  }
  digitalWrite(Spin, HIGH);

  //8x8 LED
  
}

void loop() {
  // Joystick
  Xval = analogRead(JoystickArray[0]);
  Yval = analogRead(JoystickArray[1]);
  Sval = digitalRead(JoystickArray[2]);
}
