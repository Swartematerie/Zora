

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        2
#define NUMPIXELS 50
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 100 // Time (in milliseconds) to pause between pixels
int ledPin = 13;   // a single '=' means ASSIGN THHIS VALUE to the variable
int buttonPin = 7;
bool buttonVal;
int in;
int p;

//Declaration Joystick
int Xpin = A0;
int Ypin = A1;
int Spin = 7;
int Xval;
int Yval;
int Sval;

void setup() {
  // put your setup code here, to run once:
  pixels.begin();
  pixels.clear();
  Serial.begin (9600);  // starts the communication with the computer via USB
  pinMode (ledPin, OUTPUT);
  pinMode (buttonPin, INPUT_PULLUP);


  //Joystick
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);


  setBlokje(1);
  setBlokje2(1);
  setBlokje3(1);
  setBlokje4(1);
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
        setBlokje(in);
        break;

      case 2:
        in--;
        pixels.clear ();
        setBlokje(in);
        break;
    }
  

  if (Serial.available( )) {
    int ch = Serial.read( );
    Serial.print("Just received ");
    Serial.println(ch);
   
    switch (ch) {
      case 1:
        pixels.clear ();
        setBlokje(in);
        break;

      case 2:
        pixels.clear ();
        setBlokje2(in);
        break;
    
          case 3:
        pixels.clear ();
        setBlokje3(in);
        break;
    
          case 4:
        pixels.clear ();
        setBlokje4(in);
        break;
    }
   }

  buttonVal = digitalRead(buttonPin);

  //  Serial.print("button ");
  //  Serial.println(buttonVal);

  if (Xval >= 980 && in < 50) {

    Serial.print("X ");
    Serial.println(1);
  }




}



void setBlokje (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  if (in > 9; in < 20) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  if (in > 19; in < 30) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  if (in > 29; in < 40) {
    pixels.setPixelColor(in, pixels.Color(30, 25, 85));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  if (in > 39; in < 50) {
    pixels.setPixelColor(in, pixels.Color(85, 30, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}


void setBlokje2 (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  else if (in > 9; in < 20) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 19; in < 30) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 29; in < 40) {
    pixels.setPixelColor(in, pixels.Color(30, 25, 85));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 39; in < 50) {
    pixels.setPixelColor(in, pixels.Color(85, 30, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}
void setBlokje3 (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  else if (in > 9; in < 20) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 19; in < 30) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 29; in < 40) {
    pixels.setPixelColor(in, pixels.Color(30, 25, 85));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 39; in < 50) {
    pixels.setPixelColor(in, pixels.Color(85, 30, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}

void setBlokje4 (int in) {
  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(25, 75, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop

  }
  else if (in > 9; in < 20) {
    pixels.setPixelColor(in, pixels.Color(0, 25, 75));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 19; in < 30) {
    pixels.setPixelColor(in, pixels.Color(75, 0, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 29; in < 40) {
    pixels.setPixelColor(in, pixels.Color(30, 25, 85));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 39; in < 50) {
    pixels.setPixelColor(in, pixels.Color(85, 30, 25));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}
