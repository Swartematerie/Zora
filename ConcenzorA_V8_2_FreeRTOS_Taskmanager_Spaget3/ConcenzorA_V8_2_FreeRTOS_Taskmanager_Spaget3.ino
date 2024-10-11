/*
   sketch ten behoeve nieuwe versie Zora van Ludwig Maes en Patricia Swart.
*/

#include <Arduino_FreeRTOS.h>

#include <semphr.h>

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif
#define LEDstripPIN 2
#define NUMPIXELS 100
Adafruit_NeoPixel pixels(NUMPIXELS, 2, NEO_GRB + NEO_KHZ800);
#define DELAYVAL 200  // Time (in milliseconds) to pause between pixels
#define DelayValTicks (DELAYVAL / portTICK_PERIOD_MS)

TaskHandle_t NavigationHandle;
TaskHandle_t PaddenstoelHandle;
TaskHandle_t CactusHandle;
TaskHandle_t ThemaplankjesHandle;
TaskHandle_t DrukknopjesHandle;
TaskHandle_t EventHandle;
//TaskHandle_t ;

int in = 0;
int p;
int zone;
int zoneBef;
int SvalCounter = 1;


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
bool poortSwitch = 1;

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

//Serialpoort berichtjes sleutel.
SemaphoreHandle_t mutex;





//-----------------------------------------
//----------------Setup--------------------
//-----------------------------------------
void setup() {

  xTaskCreate(NavigationTask,      // function name
              "Navigation",        // human readable name
              128,                 // stack depth
              NULL,                // no parameters are being passed
              2,                   //priority hoger cijfer is hogere prioiteit!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
              &NavigationHandle);  // task handle

  xTaskCreate(PaddenstoelTask,      // function name
              "Paddenstoel",        // human readable name
              128,                  // stack depth
              NULL,                 // no parameters are being passed
              2,                    //priority
              &PaddenstoelHandle);  // task handle

  xTaskCreate(CactusTask,      // function name
              "Cactus",        // human readable name
              128,             // stack depth
              NULL,            // no parameters are being passed
              2,               //priority
              &CactusHandle);  // task handle

  xTaskCreate(ThemaplankjesTask,      // function name
              "Themaplankjes",        // human readable name
              128,                    // stack depth
              NULL,                   // no parameters are being passed
              2,                      //priority
              &ThemaplankjesHandle);  // task handle
                                      //Taak nog niet opgeruimd.

  xTaskCreate(DrukknopjesTask,      // function name
              "Drukknopjes",        // human readable name
              128,                  // stack depth
              NULL,                 // no parameters are being passed
              2,                    //priority
              &DrukknopjesHandle);  // task handle

  /*xTaskCreate(EventTask,      // function name
              "Event",        // human readable name
              128,            // stack depth
              NULL,           // no parameters are being passed
              2,              //priority
              &EventHandle);  // task handle
*/
  /*  xTaskCreate(Task,   // function name
              "",     // human readable name
              128,          // stack depth
              NULL,         // no parameters are being passed
              2,            //priority
              Handle);        // task handle

*/

  Serial.begin(115200);
}

//-----------------------------------------
//----------------LOOP---------------------
//-----------------------------------------
void loop() {
  eventCounter();

  delay(5);
}

//-----------------------------------------
//----------------Functies-----------------
//-----------------------------------------

void MyPrint(const String &s) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(s);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(const char str[]) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(str);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(char c) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(c);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(unsigned char c, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(c, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(int n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(unsigned int n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(long n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(unsigned long n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrint(double n, int precision = 2) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.print(n, precision);
    xSemaphoreGive(mutex);
  }
}
//println.
void MyPrintln(const String &s) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(s);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(const char str[]) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(str);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(char c) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(c);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(unsigned char c, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(c, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(int n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(unsigned int n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(long n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(unsigned long n, int base = DEC) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(n, base);
    xSemaphoreGive(mutex);
  }
}
void MyPrintln(double n, int precision = 2) {
  if (xSemaphoreTake(mutex, portMAX_DELAY) == pdTRUE) {
    Serial.println(n, precision);
    xSemaphoreGive(mutex);
  }
}

void setBlokje(int in) {

  // Serial.print("in = ");
  // Serial.println(in);

  if (in >= 1; in <= 5) {
    pixels.setPixelColor(in, pixels.Color(10, 4, 1));  //trein
    pixels.show();                                     // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                         // Pause before next pass through loop
  } else if (in >= 6; in <= 15) {
    pixels.setPixelColor(in, pixels.Color(10, 10, 18));  //kristalland
    pixels.show();                                       // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                           // Pause before next pass through loop
  } else if (in >= 16; in <= 24) {
    pixels.setPixelColor(in, pixels.Color(0, 0, 15));  //oceaan
    pixels.show();                                     // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                         // Pause before next pass through loop
  } else if (in >= 25; in <= 32) {
    pixels.setPixelColor(in, pixels.Color(15, 15, 0));  //Laagland
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                          // Pause before next pass through loop
  } else if (in >= 33; in <= 45) {
    pixels.setPixelColor(in, pixels.Color(0, 10, 0));  // bos
    pixels.show();                                     // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                         // Pause before next pass through loop
  } else if (in >= 46; in <= 55) {
    pixels.setPixelColor(in, pixels.Color(9, 0, 9));  //Lavandro
    pixels.show();                                    // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                        // Pause before next pass through loop
  } else if (in >= 56; in <= 64) {
    pixels.setPixelColor(in, pixels.Color(15, 10, 0));  //Woestijn
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                          // Pause before next pass through loop
  } else if (in >= 65; in <= 68) {
    pixels.setPixelColor(in, pixels.Color(5, 4, 5));  //Tunnel
    pixels.show();                                    // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                        // Pause before next pass through loop
  } else if (in >= 69; in <= 79) {
    pixels.setPixelColor(in, pixels.Color(15, 20, 0));  //Laagland
    pixels.show();                                      // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                          // Pause before next pass through loop
  } else if (in >= 80; in <= 88) {
    pixels.setPixelColor(in, pixels.Color(10, 10, 10));  //Metal Mountain
    pixels.show();                                       // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                           // Pause before next pass through loop
  } else if (in >= 89; in <= 100) {
    pixels.setPixelColor(in, pixels.Color(10, 0, 0));  //ConcenzorA
    pixels.show();                                     // Send the updated pixel colors to the hardware.
    vTaskDelay(DelayValTicks);                         // Pause before next pass through loop
  }
}


void zonePrint() {

  if (in >= 1 && in <= 5) zone = 1;    //trein
  if (in >= 6 && in <= 15) zone = 2;   //kristalland
  if (in >= 16 && in <= 24) zone = 3;  //oceaan
  if (in >= 25 && in <= 32) zone = 4;  //laagland
  if (in >= 33 && in <= 45) zone = 5;  //bos
  if (in >= 46 && in <= 55) zone = 6;  //Lavandro
  if (in >= 56 && in <= 64) zone = 7;  //woestijn
  if (in >= 65 && in <= 68) zone = 8;  //Tunnel
  if (in >= 69 && in <= 79) zone = 4;  //Laagland

  if (zone != zoneBef) {
    //*
    Serial.print("zone ");
    Serial.println(zone);
    /*/
    MyPrint("zone ");
    MyPrintln(zone);
    */
  }

  zoneBef = zone;
}



void NavigationTask(void *pvParameters) {
  (void)pvParameters;
  //Declaration Navigation
  int Xpin = A0;
  int Ypin = A1;
  int Spin = 7;
  int Xval;
  int Yval;
  int Sval;

  pinMode(Xpin, INPUT);
  pinMode(Ypin, INPUT);
  pinMode(Spin, INPUT);
  digitalWrite(Spin, HIGH);

  pixels.begin();
  //pixels.show();
  pixels.clear();


  Serial.print("Zone: ");
  Serial.println(zone);
  setBlokje(0);

  for (;;) {
    Xval = analogRead(Xpin);
    Yval = analogRead(Ypin);
    Sval = digitalRead(Spin);

    if (Xval >= 980 && in < 77) {
      p = 1;
    } else if (Xval >= 980 && poortSwitch == 1 && in < 94) {
      p = 1;
    } else if (Xval < 100 && in > 0) {
      p = 3;
    } else {
      p = 0;
    }

    switch (p) {
      case 1:
        in++;
        //      if (in == 18) {in = 46;}
        //      if (in == 51) {in = 18;}
        pixels.clear();
        setBlokje(in);
        //Serial.print("setBlokje: ");
        //Serial.println(in);
        break;

      case 3:
        in--;
        //      if (in == 45) {in = 17;}
        pixels.clear();
        setBlokje(in);
        //Serial.print("setBlokje: ");
        //Serial.println(in);
        break;
    }

    if (Sval == LOW) {
      if (SvalCounter == 1) {
        pixels.clear();
        in = 1;
        setBlokje(in);
        SvalCounter = 2;
      } else if (SvalCounter == 2) {
        pixels.clear();
        in = 6;
        setBlokje(in);
        SvalCounter = 3;
      } else if (SvalCounter == 3) {
        pixels.clear();
        in = 16;
        setBlokje(in);
        SvalCounter = 4;
      } else if (SvalCounter == 4) {
        pixels.clear();
        in = 25;
        setBlokje(in);
        SvalCounter = 5;
      } else if (SvalCounter == 5) {
        pixels.clear();
        in = 33;
        setBlokje(in);
        SvalCounter = 6;
      } else if (SvalCounter == 6) {
        pixels.clear();
        in = 46;
        setBlokje(in);
        SvalCounter = 7;
      } else if (SvalCounter == 7) {
        pixels.clear();
        in = 56;
        setBlokje(in);
        SvalCounter = 1;
      }
    }

    zonePrint();
  }
}


//
void PaddenstoelTask(void *pvParameters) {
  (void)pvParameters;
  int LDR1 = A2;
  int LDR2 = A3;
  int padDruk = 36;
  int padLED = 37;

  int paddenstoel1;
  int paddenstoel2;
  bool padKnopje;
  bool padPresstate;

  //#002 paddenstoel
  pinMode(LDR1, INPUT);
  pinMode(LDR2, INPUT);
  pinMode(padDruk, INPUT_PULLUP);
  pinMode(padLED, OUTPUT);
  digitalWrite(padLED, HIGH);

  for (;;) {
    if (zone == 1 || zone == 5 || zone == 6) {
      //*
      paddenstoel1 = analogRead(LDR1);
      Serial.print("P1 ");
      Serial.print(zone);
      Serial.print(" ");
      Serial.println(paddenstoel1);

      paddenstoel2 = analogRead(LDR2);
      Serial.print("P2 ");
      Serial.print(zone);
      Serial.print(" ");
      Serial.println(paddenstoel2);

/*/
      paddenstoel1 = analogRead(LDR1);
      MyPrint("P1 ");
      MyPrint(zone);
      MyPrint(" ");
      MyPrintln(paddenstoel1);

      paddenstoel2 = analogRead(LDR2);
      MyPrint("P2 ");
      MyPrint(zone);
      MyPrint(" ");
      MyPrintln(paddenstoel2);
      //*/
      padKnopje = digitalRead(padDruk);
      // indien knopje niet bevestigd, inverteren
      padKnopje = !padKnopje;
      //*
      if (padKnopje == HIGH && padPresstate == 0) {
        digitalWrite(padLED, LOW);
        Serial.print("x ");
        Serial.print(zone);
        Serial.println("01");
        padPresstate = 1;
      } else if (padKnopje == LOW && padPresstate == 1) {
        digitalWrite(padLED, HIGH);
        Serial.print("x ");
        Serial.print(zone);
        Serial.println("00");
        padPresstate = 0;
      }
      //*/
    }
    vTaskDelay( 1 / portTICK_PERIOD_MS );
  }
}


//
void CactusTask(void *pvParameters) {
  (void)pvParameters;
  //#010 Cactus
  int cactus1 = 8;
  int cactus2 = 9;
  int cactus3 = 10;
  int cactus4 = 11;
  int cactus5 = 12;

  int au1;
  int au2;
  int au3;
  int au4;
  int au5;
  int oldau1;
  int oldau2;
  int oldau3;
  int oldau4;
  int oldau5;

  //#010 Cactus
  pinMode(cactus1, INPUT_PULLUP);
  pinMode(cactus2, INPUT_PULLUP);
  pinMode(cactus3, INPUT_PULLUP);
  pinMode(cactus4, INPUT_PULLUP);
  pinMode(cactus5, INPUT_PULLUP);

  for (;;) {
    if (zone == 3 || zone == 6 || zone == 7) {

      au1 = digitalRead(cactus1);
      if (au1 != oldau1) {
        Serial.print("C1 ");
        Serial.print(zone);
        Serial.println(au1 ? " 1" : " 0");
        oldau1 = au1;
      }

      au2 = digitalRead(cactus2);
      if (au2 != oldau2) {
        Serial.print("C2 ");
        Serial.print(zone);
        Serial.println(au2 ? " 1" : " 0");
      }
      oldau2 = au2;


      au3 = digitalRead(cactus3);
      if (au3 != oldau3) {
        Serial.print("C3 ");
        Serial.print(zone);
        Serial.println(au3 ? " 1" : " 0");
      }
      oldau3 = au3;


      au4 = digitalRead(cactus4);
      if (au4 != oldau4) {
        Serial.print("C4 ");
        Serial.print(zone);
        Serial.println(au4 ? " 1" : " 0");
      }
      oldau4 = au4;


      au5 = digitalRead(cactus5);
      if (au5 != oldau5) {
        Serial.print("C5 ");
        Serial.print(zone);
        Serial.println(au5 ? " 1" : " 0");
      }
      oldau5 = au5;
    }
    //vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}

//
void ThemaplankjesTask(void *pvParameters) {
  (void)pvParameters;
  //#011 Themaplankjes
  int OD1b = 53;  //obstakel detectie 1m afstend blauwwitte draad
  int OD1g = 51;  //obstacle detection 1m afstand groenewitte internet draad

  int OD15b = 52;
  int LED15b = 46;
  int BTN15b = 48;

  int OD15g = 50;  // obstake detectie 1,5m afstand groenwitte
  int LED15g = 42;
  int BTN15g = 44;

  int OD2b = 49;
  int OD2g = 47;

  int OD25b = 41;
  int LED25b = 43;
  int BTN25b = 45;

  int OD25g = 39;
  int LED25g = 35;
  int BTN25g = 37;
  //#011 Themaplankjes varabelen declaratie.
  int ODV1g;  //Obstacle detection 1m afstand groene kant
  int ODV1b;

  int ODV15g;
  int ODV15b;
  int BTNV15g;  //button value 1,5m groene kant
  int BTNV15b;  //button value 1.5m blauwe kant
  bool BTN15gpresstate = 0;
  bool BTN15bpresstate = 0;

  int ODV2g;
  int ODV2b;

  int ODV25g;
  int ODV25b;
  int BTNV25g;
  int BTNV25b;
  bool BTN25gpresstate = 0;
  bool BTN25bpresstate = 0;

  bool oDetSw1 = 0;
  bool oDetSw15 = 0;
  bool oDetSw2 = 0;
  bool oDetSw25 = 0;

  int themaSw = 0;

  //#011 themaplankjes
  pinMode(OD1g, INPUT);
  pinMode(OD1b, INPUT);

  pinMode(OD15g, INPUT);
  pinMode(OD15b, INPUT);
  pinMode(LED15g, OUTPUT);
  pinMode(LED15b, OUTPUT);
  pinMode(BTN15g, INPUT_PULLUP);
  pinMode(BTN15b, INPUT_PULLUP);
  digitalWrite(LED15g, HIGH);
  digitalWrite(LED15b, HIGH);

  pinMode(OD2g, INPUT);
  pinMode(OD2b, INPUT);

  pinMode(OD25g, INPUT);
  pinMode(OD25b, INPUT);
  pinMode(LED25g, OUTPUT);
  pinMode(LED25b, OUTPUT);
  pinMode(BTN25g, INPUT_PULLUP);
  pinMode(BTN25b, INPUT_PULLUP);
  digitalWrite(LED25g, HIGH);
  digitalWrite(LED25b, HIGH);

  for (;;) {
    if (zone == 4 || zone == 6 || zone == 7) {
      if (themaSw == 0) {
        digitalWrite(LED15g, HIGH);
        digitalWrite(LED15b, HIGH);
        digitalWrite(LED25g, HIGH);
        digitalWrite(LED25b, HIGH);
        themaSw = 1;

        ODV1g = digitalRead(OD1g);
        ODV1b = digitalRead(OD1b);

        if (ODV1g == LOW && ODV1b == LOW) {
          if (oDetSw1 == 0) {
            Serial.print("Q1 ");
            Serial.print(zone);
            Serial.println(" 1");
            oDetSw1 = 1;
          }
        } else if (oDetSw1 == 1) {
          oDetSw1 = 0;
          Serial.print("Q1 ");
          Serial.print(zone);
          Serial.println(" 0");
        }

        ODV15g = digitalRead(OD15g);
        ODV15b = digitalRead(OD15b);


        if (ODV15g == LOW && ODV15b == LOW) {
          if (oDetSw15 == 0) {
            Serial.print("Q2 ");
            Serial.print(zone);
            Serial.println(" 1");
            oDetSw15 = 1;
          }

          BTNV15g = digitalRead(BTN15g);
          BTNV15b = digitalRead(BTN15b);

          if (BTNV15g == LOW && BTN15gpresstate == 0) {
            digitalWrite(LED15g, LOW);
            Serial.print("B1 ");
            Serial.print(zone);
            Serial.println(" 1");
            BTN15gpresstate = 1;
          } else if (BTNV15g == HIGH && BTN15gpresstate == 1) {
            digitalWrite(LED15g, HIGH);
            Serial.print("B1 ");
            Serial.print(zone);
            Serial.println(" 0");
            BTN15gpresstate = 0;
          }
          if (BTNV15b == LOW && BTN15bpresstate == 0) {
            digitalWrite(LED15b, LOW);
            Serial.print("B2 ");
            Serial.print(zone);
            Serial.println(" 1");
            BTN15bpresstate = 1;
          } else if (BTNV15b == HIGH && BTN15bpresstate == 1) {
            digitalWrite(LED15b, HIGH);
            Serial.print("B2 ");
            Serial.print(zone);
            Serial.println(" 0");
            BTN15bpresstate = 0;
          }
          delay(2);
        }

        else if (oDetSw15 == 1) {
          oDetSw15 = 0;
          Serial.print("Q2 ");
          Serial.print(zone);
          Serial.println(" 0");
        }

        ODV2g = digitalRead(OD2g);
        ODV2b = digitalRead(OD2b);

        if (ODV2g == LOW && ODV2b == LOW) {
          if (oDetSw2 == 0) {
            Serial.print("Q3 ");
            Serial.print(zone);
            Serial.println(" 1");
            oDetSw2 = 1;
          }
        } else if (oDetSw2 == 1) {
          oDetSw2 = 0;
          Serial.print("Q3 ");
          Serial.print(zone);
          Serial.println(" 0");
        }

        ODV25g = digitalRead(OD25g);
        ODV25b = digitalRead(OD25b);


        if (ODV25g == LOW && ODV25b == LOW) {
          if (oDetSw25 == 0) {
            Serial.print("Q4 ");
            Serial.print(zone);
            Serial.println(" 1");
            oDetSw25 = 1;
          }


          BTNV25g = digitalRead(BTN25g);
          BTNV25b = digitalRead(BTN25b);

          if (BTNV25g == LOW && BTN25gpresstate == 0) {
            digitalWrite(LED25g, LOW);
            Serial.print("B3 ");
            Serial.print(zone);
            Serial.println(" 1");
            BTN25gpresstate = 1;
          } else if (BTNV25g == HIGH && BTN25gpresstate == 1) {
            digitalWrite(LED25g, HIGH);
            Serial.print("B3 ");
            Serial.print(zone);
            Serial.println(" 0");
            BTN25gpresstate = 0;
          }
          if (BTNV25b == LOW && BTN25bpresstate == 0) {
            digitalWrite(LED25b, LOW);
            Serial.print("B4 ");
            Serial.print(zone);
            Serial.println(" 1");
            BTN25bpresstate = 1;
          } else if (BTNV25b == HIGH && BTN25bpresstate == 1) {
            digitalWrite(LED25b, HIGH);
            Serial.print("B4 ");
            Serial.print(zone);
            Serial.println(" 0");
            BTN25bpresstate = 0;
          }
          delay(2);
        }

        else if (oDetSw25 == 1) {
          oDetSw25 = 0;
          Serial.print("Q4 ");
          Serial.print(zone);
          Serial.println(" 0");
        }
      }
      //themaplankjes();
    }

    if (!(zone == 4 || zone == 6 || zone == 7)) {
      if (themaSw == 1) {
        digitalWrite(LED15g, LOW);
        digitalWrite(LED15b, LOW);
        digitalWrite(LED25g, LOW);
        digitalWrite(LED25b, LOW);
        themaSw = 0;
      }
    }
    //vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}


//
void DrukknopjesTask(void *pvParameters) {
  (void)pvParameters;
  //#018 Drukknopjes
  /*
#define drukKnop1 22
#define drukKnop2 24
#define drukKnop3 26
#define drukKnop4 28
#define drukKnop5 23
#define drukKnop6 25
#define drukKnop7 27
#define drukKnop8 29
*/

#define aantalDrukknoppen 8
  const int drukKnopPins[] = { 22, 24, 26, 28, 23, 25, 27, 29 };
  const bool drukknopInvert[] = { 0, 0, 1, 1, 0, 0, 1, 0 };
  bool drukKnop[aantalDrukknoppen];
  bool drukknopBef[aantalDrukknoppen];




  for (int i = 0; i < aantalDrukknoppen; i++) {
    pinMode(drukKnopPins[i], INPUT_PULLUP);
  }
  for (int i = 0; i < aantalDrukknoppen; i++)
    drukknopBef[i] = digitalRead(drukKnopPins[i]);


  for (;;) {
    char karakter = 'd';
    for (int i = 0; i < aantalDrukknoppen; i++) {
      drukKnop[i] = digitalRead(drukKnopPins[i]);
      if (drukknopBef[i] != drukKnop[i]) {
        Serial.print(karakter);
        Serial.print(" ");
        Serial.print(zone);
        Serial.println((drukKnop[i] ^ drukknopInvert[i]) ? "01" : "00");  // drukknopjes f,g,j waren geinverteerd (normally closed vs open)
      }
      karakter++;
      drukknopBef[i] = drukKnop[i];
    }

    // ? ms
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}


//
void EventTask(void *pvParameters) {
  (void)pvParameters;

  for (;;) {
    //vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}

/*
// 
void Task(void *pvParameters)
{
  (void) pvParameters;

  for (;;)
  {
    //vTaskDelay( 250 / portTICK_PERIOD_MS );
  }
}
*/




//-----------------------------------------
//----------------EventCounter-------------
//-----------------------------------------
void eventCounter() {
  unsigned long currentTime = millis();

  //----------------Event1-Forest---------------------
  if (currentTime > 600000 && eventStop1 == 0) {  // 10 min 600.000
    if (event1 == 0) {
      zone = 10;  // event jingle.
      Serial.print("zone ");
      Serial.println(zone);
      // mogelijks moeten alle andere threads gepauzeerd worden
      delay(10000);
      setBlokje(in);
      event1 = 1;
    }
    int currentBlinkTime1 = millis();

    if ((currentBlinkTime1 - prevBlinkTime1) > 1000 && blinkSwitch1 == 0) {
      pixels.setPixelColor(36, pixels.Color(4, 4, 4));
      pixels.show();  // Send the updated pixel colors to the hardware.
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
      zone = 11;  //bos event.
      Serial.print("zone ");
      Serial.println(zone);
      delay(15000);
      setBlokje(in);
      eventStop1 = 1;
    }
  }


  //----------------Event2-KijkenLuisteren---------------------
  if (currentTime > 1200000 && eventStop2 == 0) {  //20 min 1200 000
    if (event2 == 0) {
      zone = 10;  // event jingle.
      Serial.print("zone ");
      Serial.println(zone);
      delay(10000);
      setBlokje(in);
      event2 = 1;
    }
    unsigned long currentBlinkTime2 = millis();

    if ((currentBlinkTime2 - prevBlinkTime2) > 1000 && blinkSwitch2 == 0) {
      pixels.setPixelColor(27, pixels.Color(4, 4, 4));
      pixels.show();  // Send the updated pixel colors to the hardware.
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
    if (in == 27) {
      zone = 12;  //bos event.
      Serial.print("zone ");
      Serial.println(zone);
      delay(15000);
      setBlokje(in);
      eventStop2 = 1;
    }
  }


  //----------------Event 3-LeidenVolgen---------------------
  if (currentTime > 1800000 && eventStop3 == 0) {  //30 min 1800 000
    if (event3 == 0) {
      zone = 10;  // event jingle.
      Serial.print("zone ");
      Serial.println(zone);
      delay(10000);
      setBlokje(in);
      event3 = 1;
    }
    unsigned long currentBlinkTime3 = millis();
    if ((currentBlinkTime3 - prevBlinkTime3) > 1000 && blinkSwitch3 == 0) {
      pixels.setPixelColor(49, pixels.Color(4, 4, 4));
      pixels.show();  // Send the updated pixel colors to the hardware.
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
      zone = 13;  //leiden volgen event.
      Serial.print("zone ");
      Serial.println(zone);
      delay(15000);
      setBlokje(in);
      eventStop3 = 1;
    }
  }





  //----------------Event 4-Woestijn---------------------
  if (currentTime > 2400000 && eventStop4 == 0) {  //40 min 2400 000
    if (event4 == 0) {
      zone = 10;  // event jingle.
      Serial.print("zone ");
      Serial.println(zone);
      delay(10000);
      setBlokje(in);
      event4 = 1;
    }
    unsigned long currentBlinkTime4 = millis();

    if ((currentBlinkTime4 - prevBlinkTime4) > 1000 && blinkSwitch4 == 0) {
      pixels.setPixelColor(59, pixels.Color(4, 4, 4));
      pixels.show();  // Send the updated pixel colors to the hardware.
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
      zone = 14;  //bos event.
      Serial.print("zone ");
      Serial.println(zone);
      delay(15000);
      setBlokje(in);
      eventStop4 = 1;
    }
  }




  //----------------Event 5-Open de Poort---------------------
  if (currentTime > 2700000 && eventStop5 == 0) {  //2700000 45 minuten
    if (event5 == 0) {
      zone = 15;  // event jingle.
      Serial.print("zone ");
      Serial.println(zone);
      delay(5000);
      setBlokje(in);
      event5 = 1;
      poortSwitch = 1;
    }
    unsigned long currentBlinkTime5 = millis();

    if ((currentBlinkTime5 - prevBlinkTime5) > 1000 && blinkSwitch5 == 0) {
      pixels.setPixelColor(80, pixels.Color(4, 4, 4));
      pixels.show();  // Send the updated pixel colors to the hardware.
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
    if (in == 80) {
      zone = 16;  //bos event.
      Serial.print("zone ");
      Serial.println(zone);
      delay(5000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(60000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(60000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(30000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(30000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(30000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(30000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(1000);
      in++;
      pixels.clear();
      setBlokje(in);
      delay(1000);
      pixels.clear();
      for (in = 89; in < 95; in++) {
        setBlokje(in);
      }
      delay(600000);
    }
  }

  //-----------------------------------------
  //----------------Installations!-------------
  //-----------------------------------------
}
