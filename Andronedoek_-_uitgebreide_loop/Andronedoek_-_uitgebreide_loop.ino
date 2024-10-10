#include <Adafruit_NeoPixel.h>
#define PIN 6
#define NUM_LEDS 50 //aantal pixels in totale project
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);

int ledsUit[] = {1,3,5,7,9,11,13,17,19,21,23,25,27,29,31,33,35,37,39,41,43,45,47,49,51,53,55,57,59,61,62,64,66,68,70,72,74,76,78,80,82,84,86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,122,124,126,128,130,132,134,136,138,140,142,144,146,148,150,152,154,156,158,160,162,164,166,168,170,172,174,175,177,179,181,183,185,187,189,191,193,195,196,198,199,200,202,204,206,207,209,210,211,213,215,217,219,221,223,225,227,229,231,233,235,237,239,241,243,245,248};
int ledsSter[] = {0,2,4,6,8,10,12,14,15,16,18,20,22,24,26,28,30,32,34,36,38,40,42,44,46,48,50,52,54,56,58,60,65,67,75,77,79,85,87,89,93,95,97,99,101,103,105,107,109,111,113,115,117,119,121,123,125,127,129,131,133,135,137,139,141,143,145,147,149,151,153,155,157,159,161,163,165,167,169,171,173,178,182,184,186,188,190,192,203,205,216,218,220,222,224,226,232,234,236,238,240,242,244,249};
int ledsLogo[] = {176,201,180,208,197,194,91,212,83,81,73,214,71,228,230,246,247,69,63};

void setup() {
  pixels.begin();
  for(int i = 0; i < 104; i++ ) {
    pixels.setPixelColor(ledsSter[i], pixels.Color(13,0,35)); // zet alle sterrenlampjes op paars
  }
  for(int i = 0; i < 19; i++ ) {
      pixels.setPixelColor(ledsLogo[i], pixels.Color(255,255,255)); // zet alle logolampjes op wit
    }
  pixels.show(); // Zet pixels op standaardkleur
}


void loop() { 
   // Androneda functie variabelen: Color (red, green, blue)
   Androneda(0x13, 0x0, 0x35);  
}


void Androneda(byte red, byte green, byte blue) {   

    float r, g, b;


  // Fade willekeurige gewone ster in en uit
    for(int i = 0; i < 9; i++ ) {    
      int Pixel = ledsSter[random(0,104)];  
      int SparkleDelay = random(500,1500);
      float r, g, b;
        for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*red;
        g = (k/256.0)*green;
        b = (k/256.0)*blue;
        pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
        pixels.show();
        }
        delay(500);      
        for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*red;
          g = (k/256.0)*green;
          b = (k/256.0)*blue;
          pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
          pixels.show();
        }
      delay(SparkleDelay);     
    }

    
    // loopje alle logosterren een voor een uit, dan een voor een aan
    for(int i = 0; i < 19; i++ ) {
      pixels.setPixelColor(ledsLogo[i], pixels.Color(0,0,0)); //Zet alle logolampjes op zwart
      delay(50);
      pixels.show(); // This sends the updated pixel color to the hardware.
    }    
    for(int i = 0; i < 19; i++ ) {
      pixels.setPixelColor(ledsLogo[i], pixels.Color(255,255,255)); // zet alle logolampjes op wit
      delay(50);
      pixels.show(); // This sends the updated pixel color to the hardware.
    }

// Fade willekeurige gewone ster in en uit
    for(int i = 0; i < 9; i++ ) {    
      int Pixel = ledsSter[random(0,104)];  
      int SparkleDelay = random(500,1500);
      float r, g, b;
        for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*red;
        g = (k/256.0)*green;
        b = (k/256.0)*blue;
        pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
        pixels.show();
        }
        delay(500);      
        for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*red;
          g = (k/256.0)*green;
          b = (k/256.0)*blue;
          pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
          pixels.show();
        }
      delay(SparkleDelay);     
    }


    // loopje alle logosterren langzaam uit en in faden
    for(int j = 0; j < 4; j++ ) {
      for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*0xff;
        g = (k/256.0)*0xff;
        b = (k/256.0)*0xff;
        pixels.setPixelColor(176, pixels.Color(r,g,b));
        pixels.setPixelColor(201, pixels.Color(r,g,b));
        pixels.setPixelColor(180, pixels.Color(r,g,b));
        pixels.setPixelColor(208, pixels.Color(r,g,b)); 
        pixels.setPixelColor(197, pixels.Color(r,g,b)); 
        pixels.setPixelColor(194, pixels.Color(r,g,b)); 
        pixels.setPixelColor(91, pixels.Color(r,g,b)); 
        pixels.setPixelColor(212, pixels.Color(r,g,b)); 
        pixels.setPixelColor(83, pixels.Color(r,g,b)); 
        pixels.setPixelColor(81, pixels.Color(r,g,b)); 
        pixels.setPixelColor(73, pixels.Color(r,g,b)); 
        pixels.setPixelColor(214, pixels.Color(r,g,b)); 
        pixels.setPixelColor(71, pixels.Color(r,g,b)); 
        pixels.setPixelColor(228, pixels.Color(r,g,b)); 
        pixels.setPixelColor(230, pixels.Color(r,g,b)); 
        pixels.setPixelColor(246, pixels.Color(r,g,b)); 
        pixels.setPixelColor(247, pixels.Color(r,g,b)); 
        pixels.setPixelColor(69, pixels.Color(r,g,b)); 
        pixels.setPixelColor(63, pixels.Color(r,g,b)); 
        pixels.show();
        }
        delay(100);
      for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*0xff;
          g = (k/256.0)*0xff;
          b = (k/256.0)*0xff;
          pixels.setPixelColor(176, pixels.Color(r,g,b));
          pixels.setPixelColor(201, pixels.Color(r,g,b));
          pixels.setPixelColor(180, pixels.Color(r,g,b));
          pixels.setPixelColor(208, pixels.Color(r,g,b)); 
          pixels.setPixelColor(197, pixels.Color(r,g,b)); 
          pixels.setPixelColor(194, pixels.Color(r,g,b)); 
          pixels.setPixelColor(91, pixels.Color(r,g,b)); 
          pixels.setPixelColor(212, pixels.Color(r,g,b)); 
          pixels.setPixelColor(83, pixels.Color(r,g,b)); 
          pixels.setPixelColor(81, pixels.Color(r,g,b)); 
          pixels.setPixelColor(73, pixels.Color(r,g,b)); 
          pixels.setPixelColor(214, pixels.Color(r,g,b)); 
          pixels.setPixelColor(71, pixels.Color(r,g,b)); 
          pixels.setPixelColor(228, pixels.Color(r,g,b)); 
          pixels.setPixelColor(230, pixels.Color(r,g,b)); 
          pixels.setPixelColor(246, pixels.Color(r,g,b)); 
          pixels.setPixelColor(247, pixels.Color(r,g,b)); 
          pixels.setPixelColor(69, pixels.Color(r,g,b)); 
          pixels.setPixelColor(63, pixels.Color(r,g,b));
          pixels.show();
        }  
    }
    
    
    // Fade willekeurige gewone ster in en uit
    for(int i = 0; i < 9; i++ ) {    
      int Pixel = ledsSter[random(0,104)];  
      int SparkleDelay = random(500,1500);
      float r, g, b;
        for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*red;
        g = (k/256.0)*green;
        b = (k/256.0)*blue;
        pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
        pixels.show();
        }
        delay(500);      
        for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*red;
          g = (k/256.0)*green;
          b = (k/256.0)*blue;
          pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
          pixels.show();
        }
      delay(SparkleDelay);     
    }

    // loopje logosterren schijnbaar willekeurig afwisselend aan en uit
      pixels.setPixelColor(176, pixels.Color(0,0,0));
      pixels.setPixelColor(201, pixels.Color(0,0,0));
      pixels.setPixelColor(180, pixels.Color(0,0,0));
      pixels.setPixelColor(208, pixels.Color(0,0,0));
      pixels.setPixelColor(197, pixels.Color(0,0,0));
      pixels.setPixelColor(194, pixels.Color(0,0,0));
      pixels.setPixelColor(91, pixels.Color(0,0,0)); 
      pixels.setPixelColor(212, pixels.Color(0,0,0));
      pixels.setPixelColor(83, pixels.Color(0,0,0)); 
      pixels.setPixelColor(81, pixels.Color(0,0,0)); 
      pixels.setPixelColor(73, pixels.Color(0,0,0)); 
      pixels.setPixelColor(214, pixels.Color(0,0,0)); 
      pixels.setPixelColor(71, pixels.Color(0,0,0)); 
      pixels.setPixelColor(228, pixels.Color(0,0,0)); 
      pixels.setPixelColor(230, pixels.Color(0,0,0)); 
      pixels.setPixelColor(246, pixels.Color(0,0,0)); 
      pixels.setPixelColor(247, pixels.Color(0,0,0)); 
      pixels.setPixelColor(69, pixels.Color(0,0,0)); 
      pixels.setPixelColor(63, pixels.Color(0,0,0)); 
      pixels.show(); 
      delay(300);
      pixels.setPixelColor(228, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(228, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(83, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(83, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(194, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(194, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(63, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(63, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(176, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(176, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(214, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(214, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(201, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(201, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(197, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(197, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(246, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(246, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(73, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(73, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(247, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(247, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(180, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(180, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(91, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(91, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(208, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(208, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(69, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(69, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(230, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(230, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(212, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(212, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(81, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(81, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(71, pixels.Color(255,255,255)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(71, pixels.Color(0,0,0)); 
      pixels.show();
      delay(50);
      pixels.setPixelColor(176, pixels.Color(255,255,255)); 
      pixels.setPixelColor(201, pixels.Color(255,255,255)); 
      pixels.setPixelColor(180, pixels.Color(255,255,255));
      pixels.setPixelColor(208, pixels.Color(255,255,255)); 
      pixels.setPixelColor(197, pixels.Color(255,255,255)); 
      pixels.setPixelColor(194, pixels.Color(255,255,255)); 
      pixels.setPixelColor(91, pixels.Color(255,255,255)); 
      pixels.setPixelColor(212, pixels.Color(255,255,255));
      pixels.setPixelColor(83, pixels.Color(255,255,255)); 
      pixels.setPixelColor(81, pixels.Color(255,255,255)); 
      pixels.setPixelColor(73, pixels.Color(255,255,255));
      pixels.setPixelColor(214, pixels.Color(255,255,255));
      pixels.setPixelColor(71, pixels.Color(255,255,255)); 
      pixels.setPixelColor(228, pixels.Color(255,255,255)); 
      pixels.setPixelColor(230, pixels.Color(255,255,255)); 
      pixels.setPixelColor(246, pixels.Color(255,255,255)); 
      pixels.setPixelColor(247, pixels.Color(255,255,255)); 
      pixels.setPixelColor(69, pixels.Color(255,255,255)); 
      pixels.setPixelColor(63, pixels.Color(255,255,255)); 
      pixels.show(); 

 
      // Fade willekeurige gewone ster in en uit
    for(int i = 0; i < 9; i++ ) {    
      int Pixel = ledsSter[random(0,104)];  
      int SparkleDelay = random(500,1500);
      float r, g, b;
        for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*red;
        g = (k/256.0)*green;
        b = (k/256.0)*blue;
        pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
        pixels.show();
        }
        delay(500);      
        for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*red;
          g = (k/256.0)*green;
          b = (k/256.0)*blue;
          pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
          pixels.show();
        }
      delay(SparkleDelay);     
    }
    

    // loopje alle logosterren een voor een knipperen
    for(int i = 0; i < 19; i++ ) {   
             pixels.setPixelColor(ledsLogo[i], pixels.Color(0,0,0)); 
             pixels.show(); 
             delay(200);
             pixels.setPixelColor(ledsLogo[i], pixels.Color(255,255,255)); 
             pixels.show(); 
        }    

         
   // Fade willekeurige gewone ster in en uit
    for(int i = 0; i < 9; i++ ) {    
      int Pixel = ledsSter[random(0,104)];  
      int SparkleDelay = random(500,1500);
      float r, g, b;
        for(int k = 255; k >= 0; k=k-2) {
        r = (k/256.0)*red;
        g = (k/256.0)*green;
        b = (k/256.0)*blue;
        pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
        pixels.show();
        }
        delay(500);      
        for(int k = 0; k < 256; k=k+2) {
          r = (k/256.0)*red;
          g = (k/256.0)*green;
          b = (k/256.0)*blue;
          pixels.setPixelColor(Pixel, pixels.Color(r,g,b));
          pixels.show();
        }
      delay(SparkleDelay);     
    }

    // loopje alle logosterren tegelijk knipperen
    for(int j = 0; j < 5; j++ ) {
      pixels.setPixelColor(176, pixels.Color(0,0,0));
      pixels.setPixelColor(201, pixels.Color(0,0,0));
      pixels.setPixelColor(180, pixels.Color(0,0,0));
      pixels.setPixelColor(208, pixels.Color(0,0,0));
      pixels.setPixelColor(197, pixels.Color(0,0,0));
      pixels.setPixelColor(194, pixels.Color(0,0,0));
      pixels.setPixelColor(91, pixels.Color(0,0,0)); 
      pixels.setPixelColor(212, pixels.Color(0,0,0));
      pixels.setPixelColor(83, pixels.Color(0,0,0)); 
      pixels.setPixelColor(81, pixels.Color(0,0,0)); 
      pixels.setPixelColor(73, pixels.Color(0,0,0)); 
      pixels.setPixelColor(214, pixels.Color(0,0,0)); 
      pixels.setPixelColor(71, pixels.Color(0,0,0)); 
      pixels.setPixelColor(228, pixels.Color(0,0,0)); 
      pixels.setPixelColor(230, pixels.Color(0,0,0)); 
      pixels.setPixelColor(246, pixels.Color(0,0,0)); 
      pixels.setPixelColor(247, pixels.Color(0,0,0)); 
      pixels.setPixelColor(69, pixels.Color(0,0,0)); 
      pixels.setPixelColor(63, pixels.Color(0,0,0)); 
      pixels.show(); 
      delay(300);
      pixels.setPixelColor(176, pixels.Color(255,255,255)); 
      pixels.setPixelColor(201, pixels.Color(255,255,255)); 
      pixels.setPixelColor(180, pixels.Color(255,255,255));
      pixels.setPixelColor(208, pixels.Color(255,255,255)); 
      pixels.setPixelColor(197, pixels.Color(255,255,255)); 
      pixels.setPixelColor(194, pixels.Color(255,255,255)); 
      pixels.setPixelColor(91, pixels.Color(255,255,255)); 
      pixels.setPixelColor(212, pixels.Color(255,255,255));
      pixels.setPixelColor(83, pixels.Color(255,255,255)); 
      pixels.setPixelColor(81, pixels.Color(255,255,255)); 
      pixels.setPixelColor(73, pixels.Color(255,255,255));
      pixels.setPixelColor(214, pixels.Color(255,255,255));
      pixels.setPixelColor(71, pixels.Color(255,255,255)); 
      pixels.setPixelColor(228, pixels.Color(255,255,255)); 
      pixels.setPixelColor(230, pixels.Color(255,255,255)); 
      pixels.setPixelColor(246, pixels.Color(255,255,255)); 
      pixels.setPixelColor(247, pixels.Color(255,255,255)); 
      pixels.setPixelColor(69, pixels.Color(255,255,255)); 
      pixels.setPixelColor(63, pixels.Color(255,255,255)); 
      pixels.show(); 
    }



}
