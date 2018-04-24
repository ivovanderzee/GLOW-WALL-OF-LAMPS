#include <Wire.h>
int x = 0;
bool reset = true;


int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int h = 8;
int i = 9;

int j = 10;
int k = 11;
int l = 12;
int m = 13;
int n = 14;
int o = 15;
int p = 16;
int q = 17;
int r = 18;

bool light1 = false;
bool light2 = false;
bool light3 = false;
bool light4 = false;
bool light5 = false;
bool light6 = false;
bool light7 = false;
bool light8 = false;
bool light9 = false;



int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int ldr5 = A4;
int ldr6 = A5;
int ldr7 = A6;
int ldr8 = A7;
int ldr9 = A8;


int led1 = 13;
int led2 = 12;
int led3 = 11;
int led4 = 10;
int led5 = 9;
int led6 = 8;
int led7 = 7;
int led8 = 6;
int led9 = 5;


void setup() {
 Serial.begin(9600);
 Wire.begin(8);                // join i2c bus with address #8
 
 
 pinMode(ldr1, INPUT);
 pinMode(ldr2, INPUT);
 pinMode(ldr3, INPUT);
 pinMode(ldr4, INPUT);
 pinMode(ldr5, INPUT);
 pinMode(ldr6, INPUT);
 pinMode(ldr7, INPUT);
 pinMode(ldr8, INPUT);
 pinMode(ldr9, INPUT);


 pinMode(led1, OUTPUT);
 pinMode(led2, OUTPUT);
 pinMode(led3, OUTPUT);
 pinMode(led4, OUTPUT);
 pinMode(led5, OUTPUT);
 pinMode(led6, OUTPUT);
 pinMode(led7, OUTPUT);
 pinMode(led8, OUTPUT);
 pinMode(led9, OUTPUT);


  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
  digitalWrite(led5, LOW);
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);
  digitalWrite(led8, LOW);
  digitalWrite(led9, LOW);

  Wire.onReceive(receiveEvent);
  
 
  

 
 
}



void receiveEvent(int bytes) {
  
  x = Wire.read();    // receive byte as an integer
  Serial.print(x);         // print the integer
  
}




void loop() {

delay(50);


  int ldrStat1 = analogRead(ldr1);
  int ldrStat2 = analogRead(ldr2);
  int ldrStat3 = analogRead(ldr3);
  int ldrStat4 = analogRead(ldr4);
  int ldrStat5 = analogRead(ldr5);
  int ldrStat6 = analogRead(ldr6);
  int ldrStat7 = analogRead(ldr7);
  int ldrStat8 = analogRead(ldr8);
  int ldrStat9 = analogRead(ldr9);


if (reset == true){

  ldrStat1 = 0;
  ldrStat2 = 0;
  ldrStat3 = 0;
  ldrStat4 = 0;
  ldrStat5 = 0;
  ldrStat6 = 0;
  ldrStat7 = 0;
  ldrStat8 = 0;
  ldrStat9 = 0;

  reset = false;
}


 

 
  Serial.println("ldr1");
  Serial.println(ldrStat1); //> 14

  
  Serial.println("ldr2");
  Serial.println(ldrStat2); //> 16

  
  Serial.println("ldr3");
  Serial.println(ldrStat3); //>25

  
  Serial.println("ldr4");
  Serial.println(ldrStat4); //>66

  
  Serial.println("ldr5");
  Serial.println(ldrStat5); //>45

  
  Serial.println("ldr6");
  Serial.println(ldrStat6); //>44
  
  
  Serial.println("ldr7");
  Serial.println(ldrStat7); //>44


  
  Serial.println("ldr8");
  Serial.println(ldrStat8); //>51

  
  Serial.println("ldr9");
  Serial.println(ldrStat9);// >44
  



if (ldrStat7 > 420){

  Serial.println(a);
  Wire.beginTransmission(8);
  Wire.write(a);
  Wire.endTransmission();
  
  light1 = false;
  
}

/*
if (ldrStat7 > 0 && ldrStat7 < 10){

  Serial.println(j);
  Wire.beginTransmission(8);
  Wire.write(j);
  Wire.endTransmission();
  
  light1 = true;
  
}

*/






if (ldrStat8 > 500){

  Serial.println(b);
  Wire.beginTransmission(8);
  Wire.write(b);
  Wire.endTransmission();
  
  light2 = false;
  
}


/*
if (ldrStat8 > 0 && ldrStat8 < 10){

  Serial.println(k);
  Wire.beginTransmission(8);
  Wire.write(k);
  Wire.endTransmission();
  
  light2 = true;
  
}

*/

if (ldrStat9 > 400){

  Serial.println(c);
  Wire.beginTransmission(8);
  Wire.write(c);
  Wire.endTransmission();
  
  light3 = false;
  
}

if (ldrStat4 > 440){

  Serial.println(d);
  Wire.beginTransmission(8);
  Wire.write(d);
  Wire.endTransmission();
  
  light4 = false;
  
}

if (ldrStat5 > 500){

  Serial.println(e);
  Wire.beginTransmission(8);
  Wire.write(e);
  Wire.endTransmission();
  
  light5 = false;
  
}

if (ldrStat6 > 440){

  Serial.println(f);
  Wire.beginTransmission(8);
  Wire.write(f);
  Wire.endTransmission();
  
  light6 = false;
  
}

if (ldrStat1 > 275){

  Serial.println(g);
  Wire.beginTransmission(8);
  Wire.write(g);
  Wire.endTransmission();
  
  light7 = false;
  
}

if (ldrStat2 > 310){

  Serial.println(h);
  Wire.beginTransmission(8);
  Wire.write(h);
  Wire.endTransmission();
  
  light8 = false;
  
}

if (ldrStat3 > 440){

  Serial.println(i);
  Wire.beginTransmission(8);
  Wire.write(i);
  Wire.endTransmission();
  
  light9 = false;
  
}


/*
if (ldrStat3 > 0 && ldrStat3 < 100){

  Serial.println(k);
  Wire.beginTransmission(8);
  Wire.write(k);
  Wire.endTransmission();
  
  light9 = true;
  
}
*/

  
if(light1 == false){
  digitalWrite(led7, LOW);  
}
else{
  digitalWrite(led7, HIGH);
}
if(light2 == false){
  digitalWrite(led8, LOW);  
}
else{
  digitalWrite(led8, HIGH);
}
if(light3 == false){
  digitalWrite(led9, LOW);  
}
else{
  digitalWrite(led9, HIGH);
}
if(light4 == false){
  digitalWrite(led4, LOW);  
}
else{
  digitalWrite(led4, HIGH);
}
if(light5 == false){
  digitalWrite(led5, LOW);  
}
else{
  digitalWrite(led5, HIGH);
}
if(light6 == false){
  digitalWrite(led6, LOW);  
}
else{
  digitalWrite(led6, HIGH);
}
if(light7 == false){
  digitalWrite(led1, LOW);  
}
else{
  digitalWrite(led1, HIGH);
}
if(light8 == false){
  digitalWrite(led2, LOW);  
}
else{
  digitalWrite(led2, HIGH);
}
if(light9 == false){
  digitalWrite(led3, LOW);  
}
else{
  digitalWrite(led3, HIGH);
}

 
  if(x == 1){

    light1 = true;
    x = 0;
    
  }

   if(x == 2){

    light2 = true;
    x = 0;
    
  }

   if(x == 3){

    light3 = true;
    x = 0;
    
  }

   if(x == 4){

    light4 = true;
    x = 0;
    
  }

   if(x == 5){

    light5 = true;
    x = 0;
    
  }

   if(x == 6){

    light6 = true;
    x = 0;
    
  }

   if(x == 7){

    light7 = true;
    x = 0;
    
  }

   if(x == 8){

    light8 = true;
    x = 0;
    
  }

   if(x == 9){

    light9 = true;
    x = 0;
    
  }
  
  


  

}






