#define controlLed 24

int roodKnopje = 23;
int groenKnopje = 22;
int ledPin = 9;
int ledPin2 = 10;

int zone = 1; 
int tijdzone = 0;
int currentTime = 0;
int maxZoneTime = 2000;
int wisselZone = 1700;
bool wisselen = 0;
bool noodknop = 0; 
int teller = 0;


// variables will change:
int buttonStateRed = 0;         // variable for reading the pushbutton status
int count_red = 1;
int prestateRed = 0;
int buttonStateGreen = 0;         // variable for reading the pushbutton status
int count_green = 2;
int prestateGreen = 0;



int paddenstoelA;
int paddenstoelB;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(roodKnopje, INPUT_PULLUP);
  pinMode(groenKnopje, INPUT_PULLUP);
  pinMode(controlLed, OUTPUT);

  digitalWrite(controlLed, LOW);
//  pinMode(LDR1, INPUT);
//  pinMode(LDR2, INPUT);
  Serial.begin(9600);
}


void loop() {

if(noodknop){ teller++;}

if(!noodknop){

    if (buttonStateRed == HIGH ||  buttonStateGreen == HIGH){digitalWrite(controlLed, HIGH);}
    else {digitalWrite(controlLed, LOW);}
  
  buttonStateRed = digitalRead(roodKnopje);

  if (buttonStateRed == HIGH && prestateRed == 0 && !wisselen) {
   	count_red++;
   		 Serial.println(count_red);
    	digitalWrite(ledPin, HIGH);
    		delay(100);
    	digitalWrite(ledPin, LOW);

    prestateRed = 1;

  } else if (buttonStateRed == LOW) {
    prestateRed = 0;
  }

  buttonStateGreen = digitalRead(groenKnopje);

  if (buttonStateGreen == HIGH && prestateGreen == 0 && !wisselen) {
    	count_green++;
    		Serial.println(count_green);
    	digitalWrite(ledPin2, HIGH);
    		delay(100);
   	digitalWrite(ledPin2, LOW);

    prestateGreen = 1;

  } else if (buttonStateGreen == LOW) {
    prestateGreen = 0;
  }

  if (currentTime == maxZoneTime) {
	tijdzone ++;
	currentTime = 0; }
  if (currentTime >= wisselZone) {
	wisselen = 1;
	//Serial.println("vogel"); 
	}

      switch(tijdzone){
		case 0:      
			if (wisselen) {
				if (count_red > count_green) {zone = 2;}
				if (count_green > count_red) {zone = 3;}
				count_red=0;
				count_green=0;
				Serial.print("Zonewissel ");
				Serial.println(zone);
				!wisselen;
			}
			break;
	
		case 1:	
			if (wisselen) {
				if (zone == 2){
					if (count_red > count_green) {zone = 4;}
					if (count_green > count_red) {zone = 5;}
				}	
				
				if (zone == 3){
					if (count_red > count_green) {zone = 6;}
					if (count_green > count_red) {zone = 7;}
				}	
				count_red=0;
				count_green=0;
        !wisselen;

			}
			break;
		
		case 2:	
			if (wisselen) {
				if (zone == 4){
					if (count_red > count_green) {zone = 8;}
					if (count_green > count_red) {zone = 9;}
				}	
				
				if (zone == 5){
					if (count_red > count_green) {zone = 10;}
					if (count_green > count_red) {zone = 11;}
				}	
				count_red=0;
				count_green=0; 
				!wisselen;

			}
			break;

      }
	currentTime++;
  Serial.print("Red
  Serial.println(currentTime);
  Serial.println(count_red);
  Serial.println(count_green);
	}

}



 
	
