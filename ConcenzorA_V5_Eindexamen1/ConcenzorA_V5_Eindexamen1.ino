
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        6
#define NUMPIXELS 50
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 300 // Time (in milliseconds) to pause between pixels

//Declaration Joystick
int Xpin = A0;
int Ypin = A1;
int Spin = 7;
int Xval;
int Yval;
int Sval;
int in;
int p;

void setup() {
  pixels.begin();
  pixels.clear();
  Serial.begin(9600);
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

}

void loop() {
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (Xval >= 980 && in < 50) {
    p = 1;
  }
  else if (Xval < 20 && in > 0) {
    p = 2;
  }
  else if (Yval >= 980) {
    p = 3;
  }
  else if (Yval < 20) {
    p = 4;
  }
  else {
    p = 0;
  }

  switch (p) {
    case 1:
      in++;
      pixels.clear ();
      aanUit(in);
      break;

    case 2:
      in--;
      pixels.clear ();
      aanUit(in);
      break;

  }
  Serial.print("p = ");
  Serial.println(p);

}


void aanUit (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
    else if (in > 9; in < 25) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
   else if (in > 24; in < 50) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }

}
