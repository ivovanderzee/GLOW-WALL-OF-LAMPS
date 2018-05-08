int led = 2;
int ldr = A0;
int ldrStat;
int OldValue;
int NewValue;

bool LightOn = true;

int SetLight(){
  if(LightOn == true){
    digitalWrite(led, HIGH);
  } else{
    digitalWrite(led, LOW);
  }
}

/*
int CheckLight() {
  if(NewValue < (OldValue - 30) || NewValue > (OldValue + 30)){
    LightOn = true;
  } else {
    
  }
}
*/

int CheckLight() {
  while(LightOn == false && NewValue < (OldValue - 30)){
    LightOn = true;
  }

  while(LightOn == true && NewValue > (OldValue + 30)){
    LightOn = false;
  }
}

void setup() {
  Serial.begin(19200);

  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);


  delay(500);
}

void loop() {

  ldrStat = analogRead(ldr);
  NewValue = analogRead(ldr);
  CheckLight();
  SetLight();
  
  Serial.println(ldrStat);
  OldValue = analogRead(ldr);

  delay(500);
}
