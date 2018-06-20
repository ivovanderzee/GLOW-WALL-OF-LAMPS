/* ________  ___  _______   _____ ______           ___  ________   ________                                 ________  ___       ________  ___       __      
|\   __  \|\  \|\  ___ \ |\   _ \  _   \        |\  \|\   ___  \|\   ____\                               |\   ____\|\  \     |\   __  \|\  \     |\  \    
\ \  \|\ /\ \  \ \   __/|\ \  \\\__\ \  \       \ \  \ \  \\ \  \ \  \___|             ____________      \ \  \___|\ \  \    \ \  \|\  \ \  \    \ \  \   
 \ \   __  \ \  \ \  \_|/_\ \  \\|__| \  \       \ \  \ \  \\ \  \ \  \               |\____________\     \ \  \  __\ \  \    \ \  \\\  \ \  \  __\ \  \  
  \ \  \|\  \ \  \ \  \_|\ \ \  \    \ \  \       \ \  \ \  \\ \  \ \  \____  ___     \|____________|      \ \  \|\  \ \  \____\ \  \\\  \ \  \|\__\_\  \ 
   \ \_______\ \__\ \_______\ \__\    \ \__\       \ \__\ \__\\ \__\ \_______\\__\                          \ \_______\ \_______\ \_______\ \____________\
    \|_______|\|__|\|_______|\|__|     \|__|        \|__|\|__| \|__|\|_______\|__|                           \|_______|\|_______|\|_______|\|____________|                                                                                                                                                      
*/                                                                                                                                                 

// External script for the communication between the Mega's
#include <Wire.h>
                                                                                                                                                          
// Allocate memory for the LED's and Sensors
#define LED_SIZE 36
#define LDR_SIZE 36   
#define SENSITIVITY 16

// Define the Multiplex pins
const int MultiPlexPins_One[4] = {46, 47, 48, 49};
const int MultiPlexPins_Two[4] = {50, 51, 52, 53};
const int MultiPlexOne = A0;
const int MultiPlexTwo = A5;

// LDR Locations
int LDRLOCATION[4]{A1, A2, A3, A4};

// LED Locations
int LEDLOCATION[LED_SIZE]{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};

// LED Status OFF/ON
int LEDSTATUS[(LED_SIZE)];
int RECEIVEDSTATUS[(LED_SIZE)];

// LDR Values
int LDRVALUES_OLD[LDR_SIZE];
int LDRVALUES_NEW[LDR_SIZE];


int Compare(){
  for(int i = 0; i < 36; i++){
    float difference = LDRVALUES_OLD[i] - LDRVALUES_NEW[i];
    float percentage = (difference / LDRVALUES_OLD[i] * 100);
    if(percentage > SENSITIVITY && LEDSTATUS[i] == 1){
      digitalWrite(LEDLOCATION[i], LOW);
      LEDSTATUS[i] = 0;
      delay(300);
    } else if(percentage > SENSITIVITY && LEDSTATUS[i] == 0){
      digitalWrite(LEDLOCATION[i], HIGH);
      LEDSTATUS[i] = 1;
      delay(300);
    }
  }
}

int Old_Value(){
  for (int i = 0; i < 36; i++){
    LDRVALUES_OLD[i] = LDRVALUES_NEW[i];
  }
}

int GetValues(){
  int a = 0;
  int b = 20;
  for (byte pin = 0; pin <= 15; pin++){
    SelectDefinedPin(pin);
    
    LDRVALUES_NEW[a] = analogRead(A0);
    LDRVALUES_NEW[b] = analogRead(A5);
    
    //Serial.print(String(LDRVALUES_NEW[a]) + "\t");
    //Serial.print(String(LDRVALUES_NEW[b]) + "\t");
    
    a++;
    b++;
  }
  LDRVALUES_NEW[16] = analogRead(A1);
  LDRVALUES_NEW[17] = analogRead(A2);
  LDRVALUES_NEW[18] = analogRead(A3);
  LDRVALUES_NEW[19] = analogRead(A4);
}


void SelectDefinedPin(byte pin) {
  for (int i = 0; i < 4; i++){
    if (pin & (1<<i)){
    digitalWrite(MultiPlexPins_One[i], HIGH);
    digitalWrite(MultiPlexPins_Two[i], HIGH);
    }
    else{
    digitalWrite(MultiPlexPins_One[i], LOW);
    digitalWrite(MultiPlexPins_Two[i], LOW);
    }
  }
}




int MultiPlex(){
  for (int i= 0; i < 0; i++)
  {
    pinMode(MultiPlexPins_One[i], OUTPUT);
    pinMode(MultiPlexPins_Two[i], OUTPUT);
    digitalWrite(MultiPlexPins_One[i], HIGH);
    digitalWrite(MultiPlexPins_Two[i], HIGH);
  }
  pinMode(MultiPlexOne, INPUT);
  pinMode(MultiPlexTwo, INPUT);
}

// Define the IN/OUTPUT's
void Allocate() {
  MultiPlex();
  // Define LED and LDR input/output
  int LED_COUNT = 0;
  int LDR_COUNT = 0;

  while (LED_COUNT < (LED_SIZE)){
    pinMode(LEDLOCATION[LED_COUNT], OUTPUT);
    LED_COUNT++;
  }

  while (LDR_COUNT < 4){
    pinMode(LDRLOCATION[LDR_COUNT], INPUT);
    LDR_COUNT++;
  }

  Serial.println("INPUT/OUTPUT SET");
 
}

// Light on by default
void Light_On() {
  // Lights On (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT < (LED_SIZE)){
      digitalWrite(LEDLOCATION[POWER_COUNT], HIGH);
      LEDSTATUS[POWER_COUNT] = 1;
      POWER_COUNT++;
    }
    Serial.println("LIGHTS ON");
  }

// Light off by default
void Light_Off() {
  // Lights Off (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= LED_SIZE){
      digitalWrite(LEDLOCATION[POWER_COUNT], LOW);
      POWER_COUNT++;
    }
    Serial.println("LIGHTS OFF");
}

void Send_Array(){
  for(int i = 0; i < LED_SIZE; i++){
    Wire.beginTransmission(8);
    byte myArray[2] = {i, LEDSTATUS[i]};
    Wire.write(myArray, 2);
    Wire.endTransmission();
  }
}



// Setup
void setup() {
  Wire.begin(8);
  Serial.begin(9600);
  for (int i=0; i<4; i++)
  {
    pinMode(MultiPlexPins_One[i], OUTPUT);
    pinMode(MultiPlexPins_Two[i], OUTPUT);
    digitalWrite(MultiPlexPins_One[i], HIGH);
    digitalWrite(MultiPlexPins_Two[i], HIGH);
  }
  
  Allocate();
  //Light_On();
  Light_Off();
  GetValues();
  Serial.println("INITIAL VALUES FETCHED");
}

// Main loop
void loop() {
  GetValues();
  //Receive_Array();
  //Switch_Light();
  Compare();
  Old_Value();
  Send_Array();
  //Serial.print(LDRVALUES_NEW[29]);
  //Serial.print("\n");
  delay(110);
  Serial.println(LDRVALUES_NEW[0]);

}
/*
 int x = 0;
  while (x < 36){
    //Serial.print(LEDSTATUS[x]) ;
    //Serial.print("\t");
    x++;
  }
  x = 0;
  Serial.print("\n");
  Serial.print(LDRVALUES_NEW[4]);
  Serial.print("\n");
 */
