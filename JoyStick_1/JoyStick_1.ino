int JSX=A0;
int JSY=A1;
int JSS=2;
int Xval;
int Yval;
int Sval;
int dt = 1000;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(JSX, INPUT);
pinMode(JSY, INPUT);
pinMode(JSS, INPUT);
digitalWrite(JSS, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
Xval=analogRead(JSX);
Yval=analogRead(JSY);
Sval=digitalRead(JSS);
delay(dt);
Serial.print("X=  ");
Serial.println(Xval);
Serial.print("Y=  ");
Serial.println(Yval);
Serial.print("Switch = ");
Serial.println(Sval);


}
