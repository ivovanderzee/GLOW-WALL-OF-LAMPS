#include <Wire.h>

int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;

int ldr1 = A0;
int ldr2 = A1;
int ldr3 = A2;
int ldr4 = A3;
int ldr5 = A4;
int ldr6 = A5;
int ldr7 = A6;
int ldr8 = A7;
int ldr9 = A8;

int a = 1;
int b = 2;
int c = 3;
int d = 4;
int e = 5;
int f = 6;
int g = 7;
int h = 8;
int i = 9;

int z = 10;
int k = 11;
int l = 12;
int m = 13;
int n = 14;
int o = 15;
int p = 16;
int q = 17;
int r = 18;


bool light1 = true;
bool light2 = true;
bool light3 = true;
bool light4 = true;
bool light5 = true;
bool light6 = true;
bool light7 = true;
bool light8 = true;
bool light9 = true;

bool Reset = true;



int j;



void receiveEvent(int bytes){
    j = Wire.read();
  }



int storedValue;

void setup() {
  Wire.begin(8); // join i2c bus (address optional for master)

   Serial.begin(9600);
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


   digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);

  
  delay(1000);
}


void loop() {
  /*
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  digitalWrite(led4, HIGH);
  digitalWrite(led5, HIGH);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);
  digitalWrite(led8, HIGH);
  digitalWrite(led9, HIGH);
  */
  

  
  int ldrStat1 = analogRead(ldr1);
  int ldrStat2 = analogRead(ldr2);
  int ldrStat3 = analogRead(ldr3);
  int ldrStat4 = analogRead(ldr4);
  int ldrStat5 = analogRead(ldr5);
  int ldrStat6 = analogRead(ldr6);
  int ldrStat7 = analogRead(ldr7);
  int ldrStat8 = analogRead(ldr8);
  int ldrStat9 = analogRead(ldr9);

  
  if(Reset == false)
  {
    ldrStat1 = 0;
    ldrStat2 = 0;
    ldrStat3 = 0;
    ldrStat4 = 0;
    ldrStat5 = 0;
    ldrStat6 = 0;
    ldrStat7 = 0;
    ldrStat8 = 0;
    ldrStat9 = 0;
    Reset = false;
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

  

  Serial.println("ldr7");
  Serial.println(ldrStat7); //> 14
  
  /*
   storedValue = ldrStat7;
   if(ldrStat7 > (storedValue + 2) || ldrStat7 < (storedValue - 2) )
   {
    Serial.println(ldrStat7);
   }


   */

  if (ldrStat7 > 590)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(a);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light1 = false;
  }

  if (ldrStat8 > 600)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(b);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light2 = false;
  }

  if (ldrStat9 > 265)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(c);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light3 = false;
  }

  if (ldrStat4 > 350)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(d);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light4 = false;
  }

  if (ldrStat5 > 590)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(e);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light5 = false;
  }

  if (ldrStat6 > 440)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(f);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light6 = false;
  }

  if (ldrStat1 > 500)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(g);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light7 = false;
  }

  if (ldrStat2 > 420)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(h);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light8 = false;
  }

  if (ldrStat3 > 490)
  {
    Wire.beginTransmission(8); // transmit to device #8
    Wire.write(i);              // sends one byte
    Wire.endTransmission();    // stop transmitting
    light9 = false;
  }



  if(light1 == false)
  {
    digitalWrite(led1, LOW);
  } else {
    digitalWrite(led1, HIGH);
  }

  if(light2 == false)
  {
    digitalWrite(led2, LOW);
  } else {
    digitalWrite(led2, HIGH);
  }

  if(light3 == false)
  {
    digitalWrite(led3, LOW);
  } else {
    digitalWrite(led3, HIGH);
  }

  if(light4 == false)
  {
    digitalWrite(led4, LOW);
  } else {
    digitalWrite(led4, HIGH);
  }

  if(light5 == false)
  {
    digitalWrite(led5, LOW);
  } else {
    digitalWrite(led5, HIGH);
  }

  if(light6 == false)
  {
    digitalWrite(led6, LOW);
  } else {
    digitalWrite(led6, HIGH);
  }

  if(light7 == false)
  {
    digitalWrite(led7, LOW);
  } else {
    digitalWrite(led7, HIGH);
  }

  if(light8 == false)
  {
    digitalWrite(led8, LOW);
  } else {
    digitalWrite(led8, HIGH);
  }

  if(light9 == false)
  {
    digitalWrite(led9, LOW);
  } else {
    digitalWrite(led9, HIGH);
  }


  Wire.onReceive(receiveEvent);
  
  if(j== 1)
  {
    light1 = true;
    j = 0;
  }

  if(j== 2)
  {
    light2 = true;
    j = 0;
  }

  if(j== 3)
  {
    light3 = true;
    j = 0;
  }

  if(j== 4)
  {
    light4 = true;
    j = 0;
  }

  if(j== 5)
  {
    light5 = true;
    j = 0;
  }

  if(j== 6)
  {
    light6 = true;
    j = 0;
  }

  if(j== 7)
  {
    light7 = true;
    j = 0;
  }

  if(j== 8)
  {
    light8 = true;
    j = 0;
  }

  if(j== 9)
  {
    light9 = true;
    j = 0;
  }

  if(j== 10)
  {
    light1 = false;
    j = 0;
  }

  if(j== 11)
  {
    light9 = false;
    j = 0;
  }

    
  delay(50);
}
