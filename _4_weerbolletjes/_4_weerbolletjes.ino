#define windTrig 42
#define windEcho 43
#define waterTrig 44
#define waterEcho 45
#define birdsTrig 46
#define birdsEcho 47


long windDuration;
int windDistance;
long waterDuration;
int waterDistance;
long birdsDuration;
int birdsDistance;

unsigned long prevTimeWB1;
unsigned long prevTimeWB2;
int waitWB1 = 2;
int waitWB2 = 10;


void setup(){
  pinMode(windTrig, OUTPUT);
  pinMode(windEcho, INPUT);
  pinMode(waterTrig, OUTPUT);
  pinMode(waterEcho, INPUT);
  pinMode(birdsTrig, OUTPUT);
  pinMode(birdsEcho, INPUT);
  Serial.begin(9600);
  

}

void loop() {

weerBolletjes();
  
}


void weerBolletjes () {
  digitalWrite(windTrig, LOW);
    delay (2);
  digitalWrite(windTrig, HIGH);
    delay (10);
  digitalWrite(windTrig, LOW);
  
  windDuration = pulseIn(windEcho, HIGH);
  windDistance = windDuration *0.034 /2;

  digitalWrite(waterTrig, LOW);
    delay (2);
  digitalWrite(waterTrig, HIGH);
    delay (10);
  digitalWrite(waterTrig, LOW);

  
  waterDuration = pulseIn(waterEcho, HIGH);
  waterDistance = waterDuration *0.034 /2;

  digitalWrite(birdsTrig, LOW);
    delay (2);
  digitalWrite(birdsTrig, HIGH);
    delay (10);
  digitalWrite(birdsTrig, LOW);



  
  birdsDuration = pulseIn(birdsEcho, HIGH);
  birdsDistance = birdsDuration *0.034 /2;

  

 
  Serial.print("windDisstance ");
  Serial.println(windDistance);
  Serial.print("waterDisstance ");
  Serial.println(waterDistance);
  Serial.print("birdsDisstance ");
  Serial.println(birdsDistance);
}
