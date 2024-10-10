/*
   sketch ten behoeve van Eindexamen in Podium Zuidheage te Assen.
   Patricia Swart
*/


#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif
#define PIN        2
#define NUMPIXELS 100
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 200 // Time (in milliseconds) to pause between pixels

//Declaration Joystick
int Xpin = A0;
int Ypin = A1;
int Spin = 7;
int Xval;
int Yval;
int Sval;

int in = 0;
int p;
int zone;
char mystr[1] = "1";
char mysts[1] = "2";

bool presstateZone1 = 0;
bool presstateZone2 = 0;
bool presstateZone3 = 0;
bool presstateZone4 = 0;
bool presstateZone5 = 0;
bool presstateZone6 = 0;
bool presstateZone7 = 0;
bool presstateZone8 = 0;

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
bool poortSwitch = 0;

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
  Serial.begin(115200);

  //#000 joyStick + LEDstrip
  pixels.begin();
  pixels.clear();
  pinMode (Xpin, INPUT);
  pinMode (Ypin, INPUT);
  pinMode (Spin, INPUT);
  digitalWrite(Spin, HIGH);

  Serial.print("Zone: ");
  Serial.println(zone);
  setBlokje(0);


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

  if (Xval >= 980 && in < 77) {
    p = 1;
  }
  else if (Xval >= 980 && poortSwitch == 1) {
    p = 1;
  }
  else if (Xval < 100 && in > 0) {
    p = 3;
  }
  else {
    p = 0;
  }

  switch (p) {
    case 1:
      in++;
      //      if (in == 18) {in = 46;}
      //      if (in == 51) {in = 18;}
      pixels.clear ();
      setBlokje(in);
//      Serial.print("setBlokje: ");
//      Serial.println(in);
      break;

    case 3:
      in--;
      //      if (in == 45) {in = 17;}
      pixels.clear ();
      setBlokje(in);
 //     Serial.print("setBlokje: ");
 //     Serial.println(in);
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

  if (in >= 1; in <= 5) {
    pixels.setPixelColor(in, pixels.Color(10, 4, 1));//trein
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else if (in >= 6; in <= 15) {
    pixels.setPixelColor(in, pixels.Color(10, 10, 18));//kristalland
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in >= 16 ; in <= 24) {
    pixels.setPixelColor(in, pixels.Color(0, 0, 15));//oceaan
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in >= 25; in <= 32) {
    pixels.setPixelColor(in, pixels.Color(15, 15, 0));//Laagland 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in >= 33; in <= 45) {
    pixels.setPixelColor(in, pixels.Color(0, 10, 0));// bos 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in >= 46; in <= 55) {
    pixels.setPixelColor(in, pixels.Color(9, 0, 9));//Lavandro
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
  else  if (in >= 56; in <= 64) {
    pixels.setPixelColor(in, pixels.Color(15, 10, 0)); //Woestijn
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
    else  if (in >= 65; in <= 68) {
    pixels.setPixelColor(in, pixels.Color(5, 4, 5)); //Tunnel
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
    else  if (in >= 69; in <= 75) {
    pixels.setPixelColor(in, pixels.Color(15, 20, 0));//Laagland 
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
      else  if (in >= 76 ; in <= 81) {
    pixels.setPixelColor(in, pixels.Color(10,10, 10)); //Metal Mountain
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
      else  if (in >= 82; in <= 9) {
    pixels.setPixelColor(in, pixels.Color(0, 0, 10)); //ConcenzorA
    pixels.show();   // Send the updated pixel colors to the hardware.
    delay(DELAYVAL); // Pause before next pass through loop
  }
}


void zonePrint() {
  if (in >= 1 && in <= 5 && !presstateZone1) {
    zone = 1; //trein
    Serial.print(zone);
    presstateZone1 = 1;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }
  if (in >= 6 && in <= 15  && !presstateZone2) {
    zone = 2; //kristalland
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 1;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }

  if (in >= 16 && in <= 24  && !presstateZone3) {
    zone = 3; //oceaan
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 1;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }
  if (in >= 25 && in <= 32  && !presstateZone4) {
    zone = 4; //laagland
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 1;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }
  if (in >= 33 && in <= 45  && !presstateZone5) {
    zone = 5; //bos
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 1;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }

  if (in >= 46 && in <= 55  && !presstateZone6) {
    zone = 6; //Lavandro
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 1;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }

  if (in >= 56 && in <= 64  && !presstateZone7) {
    zone = 7; //woestijn
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 1;
    presstateZone8 = 0;
  }
    if (in >= 65 && in <= 68  && !presstateZone8) {
    zone = 8; //Tunnel
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 0;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 1;
  }
      if (in >= 69 && in <= 75  && !presstateZone3) {
    zone = 3; //Laagland
    Serial.print(zone);
    presstateZone1 = 0;
    presstateZone2 = 0;
    presstateZone3 = 1;
    presstateZone4 = 0;
    presstateZone5 = 0;
    presstateZone6 = 0;
    presstateZone7 = 0;
    presstateZone8 = 0;
  }
}







//-----------------------------------------
//----------------EventCounter-------------
//-----------------------------------------
void eventCounter() {
  unsigned long currentTime = millis();

  //----------------Event1-Forest---------------------
  if (currentTime > 600000 && eventStop1 == 0) {
    if (event1 == 0) {
      zone = 10; // event jingle.
      Serial.println(zone);
      delay(5000);
      setBlokje(in);
      event1 = 1;
    }
    int currentBlinkTime1 = millis();

    if ((currentBlinkTime1 - prevBlinkTime1) > 1000 && blinkSwitch1 == 0) {
      pixels.setPixelColor(12, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch1 = 1;
      prevBlinkTime1 = currentBlinkTime1;
//      Serial.println("LED ON");
    }
    if ((currentBlinkTime1 - prevBlinkTime1) > 1000 && blinkSwitch1 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch1 = 0;
      prevBlinkTime1 = currentBlinkTime1;
//      Serial.println("LED OFF");
    }

    if (in == 36) {
      zone = 11; //bos event.
      Serial.println(zone);
      delay(15000);
      eventStop1 = 1;
    }
  }



  //----------------Event2-KijkenLuisteren---------------------
  if (currentTime > 1200000 && eventStop2 == 0) {
    if (event2 == 0) {
      zone = 10; // event jingle.
      Serial.println(zone);
      delay(2000);
      setBlokje(in);
      event2 = 1;
    }
    unsigned long currentBlinkTime2 = millis();

    if ((currentBlinkTime2 - prevBlinkTime2) > 1000 && blinkSwitch2 == 0) {
      pixels.setPixelColor(28, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch2 = 1;
      prevBlinkTime2 = currentBlinkTime2;
 //     Serial.println("LED ON");
    }
    if ((currentBlinkTime2 - prevBlinkTime2) > 1000 && blinkSwitch2 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch2 = 0;
      prevBlinkTime2 = currentBlinkTime2;
 //     Serial.println("LED OFF");
    }
    if (in == 28) {
      zone = 12; //bos event.
      Serial.println(zone);
      delay(15000);
      eventStop2 = 1;
    }
  }







  //----------------Event 3-LeidenVolgen---------------------
  if (currentTime > 1800000 && eventStop3 == 0) {
    if (event3 == 0) {
      zone = 10; // event jingle.
      Serial.println(zone);
      delay(2000);
      setBlokje(in);
      event3 = 1;
    }
    unsigned long currentBlinkTime3 = millis();
    if ((currentBlinkTime3 - prevBlinkTime3) > 1000 && blinkSwitch3 == 0) {
      pixels.setPixelColor(49, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch3 = 1;
      prevBlinkTime3 = currentBlinkTime3;
//      Serial.println("LED ON");
    }
    if ((currentBlinkTime3 - prevBlinkTime3) > 1000 && blinkSwitch3 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch3 = 0;
      prevBlinkTime3 = currentBlinkTime3;
//      Serial.println("LED OFF");
    }
    if (in == 49) {
      zone = 13; //bos event.
      Serial.println(zone);
      delay(15000);
      eventStop3 = 1;
    }
  }





  //----------------Event 4-Woestijn---------------------
  if (currentTime > 2400000 && eventStop4 == 0) {
    if (event4 == 0) {
      zone = 10; // event jingle.
      Serial.println(zone);
      delay(2000);
      setBlokje(in);
      event4 = 1;
    }
    unsigned long currentBlinkTime4 = millis();

    if ((currentBlinkTime4 - prevBlinkTime4) > 1000 && blinkSwitch4 == 0) {
      pixels.setPixelColor(59, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch4 = 1;
      prevBlinkTime4 = currentBlinkTime4;
//      Serial.println("LED ON");
    }
    if ((currentBlinkTime4 - prevBlinkTime4) > 1000 && blinkSwitch4 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch4 = 0;
      prevBlinkTime4 = currentBlinkTime4;
//      Serial.println("LED OFF");
    }
    if (in == 59) {
      zone = 14; //bos event.
      Serial.println(zone);
      delay(15000);
      eventStop4 = 1;
    }
  }




  //----------------Event 5-Open de Poort---------------------
  if (currentTime > 3000000 && eventStop5 == 0) {
    if (event5 == 0) {
      zone = 15; // event jingle.
      Serial.println(zone);
      delay(2000);
      setBlokje(in);
      event5 = 1;
      poortSwitch = 1;
    }
    unsigned long currentBlinkTime5 = millis();

    if ((currentBlinkTime5 - prevBlinkTime5) > 1000 && blinkSwitch5 == 0) {
      pixels.setPixelColor(77, pixels.Color(4, 4, 4));
      pixels.show();   // Send the updated pixel colors to the hardware.
      setBlokje(in);
      blinkSwitch5 = 1;
      prevBlinkTime5 = currentBlinkTime5;
//      Serial.println("LED ON");
    }
    if ((currentBlinkTime5 - prevBlinkTime5) > 1000 && blinkSwitch5 == 1) {
      pixels.clear();
      setBlokje(in);
      blinkSwitch5 = 0;
      prevBlinkTime5 = currentBlinkTime5;
//      Serial.println("LED OFF");
    }
    if (in == 77) {
      zone = 16; //bos event.
      Serial.println(zone);
      delay(600000);
    }
  }

}
