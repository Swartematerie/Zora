 
//#5 stip aan de horizon kanon.
int laserRichter = 23;
int schietdoel1 = A8;
int schietdoel2 = A9;
int lontDK = 22;
int laden1;
int laden2;
int LOS;

//#9 Cactus
int cactus1 = 9;
int cactus2 = 10;
int au1; 
int au2;

//-----------------------------------------
//------------Setup------------------------
//-----------------------------------------
void setup() {
  Serial.begin(9600);
  //#5 Stip aan de horizon kanon
  pinMode (laserRichter, OUTPUT);
  pinMode (schietdoel1, INPUT);
  pinMode (schietdoel2, INPUT);
  pinMode (lontDK, INPUT_PULLUP);
  digitalWrite(laserRichter, HIGH);

  //#9 Cactus
  pinMode (cactus1, INPUT_PULLUP);
  pinMode (cactus2, INPUT_PULLUP);
}

//-----------------------------------------
//-----------LOOP--------------------------
//-----------------------------------------
void loop (){
  kanonAfvuren();
  cactus();
}

//-----------------------------------------
//------------FUNCTIONS--------------------
//-----------------------------------------
void cactus(){
  au1 = digitalRead(cactus1);
  if (au1 == HIGH){
    Serial.println("au1");
  }

  au2 = digitalRead(cactus2);
  if (au2 == HIGH){
    Serial.println("au2");
  }
}

void kanonAfvuren (){
  digitalWrite (laserRichter, HIGH);
  laden1 = analogRead(schietdoel1);
  laden2 = analogRead(schietdoel2);
  LOS = digitalRead(lontDK);

  //Serial.println(laden1);

  if (LOS == LOW){
     Serial.println("los");
     }
 

  if(laden1>100 && LOS == LOW){
    Serial.println("kanon 1");
  }
  if(laden2>500 && LOS == LOW){
    Serial.println("kanon 2");
  }

delay(500);
}


 
