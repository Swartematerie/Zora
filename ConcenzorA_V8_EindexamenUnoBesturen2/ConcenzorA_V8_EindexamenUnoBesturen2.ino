/*
   sketch ten behoeve van Experimenteer avond 2 in Podium Zuidheage te Assen.
   Patricia Swart & Jan Ruerd Oosterhaven.
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        2
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

int in = 4;
int p;
int zone;

bool presstateZone1 = 0;
bool presstateZone2 = 0;
bool presstateZone3 = 0;
bool presstateZone4 = 0;
bool presstateZone5 = 0;
bool presstateZone6 = 0;
bool presstateZone7 = 0;

bool event1 = 0;
bool event2 = 0;
bool event3 = 0;
bool event4 = 0;
bool event5 = 0;
bool event6 = 0;

bool eventStop1 = 0;
bool eventStop2 = 0;
bool eventStop3 = 0;
bool eventStop4 = 0;
bool eventStop5 = 0;
bool eventStop6 = 0;

int prevBlinkTime1 = 0;
int blinkSwitch1 = 0;
int prevBlinkTime2 = 0;
int blinkSwitch2 = 0;
int prevBlinkTime3 = 0;
int blinkSwitch3 = 0;
int prevBlinkTime4 = 0;
int blinkSwitch4 = 0;
int prevBlinkTime5 = 0;
int blinkSwitch5 = 0;
int prevBlinkTime6 = 0;
int blinkSwitch6 = 0;


//-----------------------------------------
//----------------Setup--------------------
//-----------------------------------------
void setup() {
  Serial.begin(9600);

  //#000 joyStick + LEDstrip
  pixels.begin();
  pixels.clear();
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  Serial.print("Zone: ");
  Serial.println(zone);
  setBlokje(4);


}

//-----------------------------------------
//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
//-----------------------------------------
void loop() {
  //#001 JoyStick
  Xval = analogRead(Xpin);
  Yval = analogRead(Ypin);
  Sval = digitalRead(Spin);

  if (Xval >= 980) {
    p = 1;
  }
  else if (Xval < 100 && in > 5) {
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
      if (in == 18) {in = 46;}
      if (in == 51) {in = 18;}
      pixels.clear ();
      setBlokje(in);
      break;

    case 2:
      in--;
      if (in == 45) {in = 17;}
      pixels.clear ();
      setBlokje(in);
      break;
  }

  if (Sval == LOW) {
    pixels.clear();
    in = 5;
    setBlokje(5);
  }


  zonePrint();
  eventCounter();


}


//-----------------------------------------
//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------
//-----------------------------------------

void setBlokje (int in) {

  if (in > 0; in < 10) {
    pixels.setPixelColor(in, pixels.Color(10, 4, 1));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else if (in > 9; in < 14) {
    pixels.setPixelColor(in, pixels.Color(0, 10, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 13; in < 18) {
    pixels.setPixelColor(in, pixels.Color(15, 20, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 17; in < 23) {
    pixels.setPixelColor(in, pixels.Color(15, 10, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 22; in < 27) {
    pixels.setPixelColor(in, pixels.Color(10, 10, 18));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 26; in < 31) {
    pixels.setPixelColor(in, pixels.Color(10, 0, 0));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in > 30; in < 50) {
    pixels.setPixelColor(in, pixels.Color(0, 0, 10));
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}


void zonePrint() {
  if (in >= 5 && in <= 9 && !presstateZone1) {
    zone = 1;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone1 = 1;
    presstateZone2 = 0;
  }
  if (in >= 10 && in <= 13  && !presstateZone2) {
    zone = 2;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone1 = 0;
    presstateZone2 = 1;
    presstateZone3 = 0;
  }

  if (in >= 14 && in <= 17  && !presstateZone3) {
    zone = 3;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone2 = 0;
    presstateZone3 = 1;
    presstateZone4 = 0;
    presstateZone7 = 0;
  }
  if (in >= 18 && in <= 22  && !presstateZone4) {
    zone = 4;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone3 = 0;
    presstateZone4 = 1;
    presstateZone5 = 0;
  }
  if (in >= 23 && in <= 26  && !presstateZone5) {
    zone = 5;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone4 = 0;
    presstateZone5 = 1;
    presstateZone6 = 0;
  }

  if (in >= 27 && in <= 30  && !presstateZone6) {
    zone = 6;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone5 = 0;
    presstateZone6 = 1;
    presstateZone7 = 0;
  }

  if (in >= 31 && in <= 51  && !presstateZone7) {
    zone = 7;
    Serial.print("zone ");
    Serial.println(zone);
    presstateZone3 = 0;
    presstateZone6 = 0;
    presstateZone7 = 1;
  }
}







//-----------------------------------------
//----------------EventCounter-------------
//-----------------------------------------
void eventCounter() {
  unsigned long currentTime = millis();

//----------------Event1----------------------
  if (currentTime > 600000 && eventStop1 == 0) {
    if (event1 == 0) {
      Serial.println("Event1");
      event1 = 1;
    }
    int currentBlinkTime1 = millis();

    if ((currentBlinkTime1 - prevBlinkTime1) > 1000 && blinkSwitch1 == 0) {
      pixels.setPixelColor(12, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch1 = 1;
      prevBlinkTime1 = currentBlinkTime1;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime1 - prevBlinkTime1) > 1000 && blinkSwitch1 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch1 = 0;
      prevBlinkTime1 = currentBlinkTime1;
      Serial.println("LED OFF");
    }

    if (in == 12) {
      Serial.println("Event1 Stop");
      eventStop1 = 1;
    }
  }



//----------------Event2----------------------
  if (currentTime > 1200000 && eventStop2 == 0) {
    if (event2 == 0) {
      Serial.println("Event2");
      event2 = 1;
    }
    unsigned long currentBlinkTime2 = millis();

    if ((currentBlinkTime2 - prevBlinkTime2) > 1000 && blinkSwitch2 == 0) {
      pixels.setPixelColor(16, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch2 = 1;
      prevBlinkTime2 = currentBlinkTime2;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime2 - prevBlinkTime2) > 1000 && blinkSwitch2 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch2 = 0;
      prevBlinkTime2 = currentBlinkTime2;
      Serial.println("LED OFF");
    }
    if (in == 16) {
      Serial.println("Event2 Stop");
      eventStop2 = 1;
    }
  }







//----------------Event 3----------------------
  if (currentTime > 1800000 && eventStop3 == 0) {
    if (event3 == 0) {
      Serial.println("Event3");
      event3 = 1;
    }
    unsigned long currentBlinkTime3 = millis();
    if ((currentBlinkTime3 - prevBlinkTime3) > 1000 && blinkSwitch3 == 0) {
      pixels.setPixelColor(20, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch3 = 1;
      prevBlinkTime3 = currentBlinkTime3;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime3 - prevBlinkTime3) > 1000 && blinkSwitch3 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch3 = 0;
      prevBlinkTime3 = currentBlinkTime3;
      Serial.println("LED OFF");
    }
    if (in == 20) {
      Serial.println("Event3 Stop");
      eventStop3 = 1;
    }
  }





//----------------Event 4----------------------
  if (currentTime > 2400000 && eventStop4 == 0) {
    if (event4 == 0) {
      Serial.println("Event4");
      event4 = 1;
    }
    unsigned long currentBlinkTime4 = millis();

    if ((currentBlinkTime4 - prevBlinkTime4) > 1000 && blinkSwitch4 == 0) {
      pixels.setPixelColor(30, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch4 = 1;
      prevBlinkTime4 = currentBlinkTime4;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime4 - prevBlinkTime4) > 1000 && blinkSwitch4 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch4 = 0;
      prevBlinkTime4 = currentBlinkTime4;
      Serial.println("LED OFF");
    }
    if (in == 30) {
      Serial.println("Event4 Stop");
      eventStop4 = 1;
    }
  }




//----------------Event 5----------------------
  if (currentTime > 3000000 && eventStop5 == 0) {
    if (event5 == 0) {
      Serial.println("Event5");
      event5 = 1;
    }
    unsigned long currentBlinkTime5 = millis();

    if ((currentBlinkTime5 - prevBlinkTime5) > 1000 && blinkSwitch5 == 0) {
      pixels.setPixelColor(33, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch5 = 1;
      prevBlinkTime5 = currentBlinkTime5;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime5 - prevBlinkTime5) > 1000 && blinkSwitch5 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch5 = 0;
      prevBlinkTime5 = currentBlinkTime5;
      Serial.println("LED OFF");
    }
    if (in == 30) {
      Serial.println("Event5 Stop");
      eventStop5 = 1;
    }
  }






//----------------Event 6----------------------
  if (currentTime > 3600000 && eventStop6 == 0) {
    if (event6 == 0) {
      Serial.println("Event6");
      event6 = 1;
    }
    unsigned long currentBlinkTime6 = millis();

    if ((currentBlinkTime6 - prevBlinkTime6) > 1000 && blinkSwitch6 == 0) {
      pixels.setPixelColor(40, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch6 = 1;
      prevBlinkTime6 = currentBlinkTime6;
      Serial.println("LED ON");
    }
    if ((currentBlinkTime6 - prevBlinkTime6) > 1000 && blinkSwitch6 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch6 = 0;
      prevBlinkTime6 = currentBlinkTime6;
      Serial.println("LED OFF");
    }
    if (in == 40) {
      Serial.println("Event6 Stop");
      eventStop6 = 1;
    }
  }

}
