int led = 2;
int ldr = A0;
int ldrStat;

bool LightOn = true;

int SetLight(){
  if(LightOn == true){
    digitalWrite(led, HIGH);
  } else{
    digitalWrite(led, LOW);
  }
}

int CheckLight() {
  if(ldrStat < 50){
    LightOn = true;
  } else{
    LightOn = false;
  }
}

int OldValue;
int NewValue;

void setup() {
  Serial.begin(9600);

  pinMode(ldr, INPUT);
  pinMode(led, OUTPUT);

  digitalWrite(led, HIGH);

  delay(500);
}

void loop() {

  ldrStat = analogRead(ldr);
  OldValue = analogRead(ldr);

  CheckLight();
  SetLight();

  Serial.println(ldrStat);
  delay(500);
}
