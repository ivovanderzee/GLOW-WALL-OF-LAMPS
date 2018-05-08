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

int CheckLight() {
  if(NewValue < (OldValue - 20) || NewValue > (OldValue + 20)){
    LightOn = true;
  } else {
    
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);


  delay(500);
}

void loop() {

  ldrStat = analogRead(ldr);
  NewValue = analogRead(ldr);
  CheckLight();
  SetLight();
  
  delay(500);
  Serial.println(ldrStat);
  OldValue = analogRead(ldr);
  delay(500);
}
