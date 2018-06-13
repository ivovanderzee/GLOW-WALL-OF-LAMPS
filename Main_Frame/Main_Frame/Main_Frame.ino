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

// LDR Values
int LDRVALUES_OLD[LDR_SIZE];
int LDRVALUES_NEW[LDR_SIZE];


int GetValues(){
  for (byte pin = 0; pin <= 15; pin++){
    SelectDefinedPin(pin);
    int inputtest = analogRead(A0);
    
    //int inputtest_two = analogRead(A5);
    Serial.print(String(inputtest) + "\t");
    //Serial.print(String(inputtest_two) + "\t");
  }
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

int j;

void receiveEvent(int bytes){
    j = Wire.read();
  }
  
void Receive_Array(){
  Wire.onReceive(receiveEvent);
  Serial.println(j);
}

void Send_Array(){
  Wire.beginTransmission(8);
  Wire.write(LDR_SIZE);
  Wire.endTransmission();
}



// Setup
void setup() {
  Wire.begin(8);
  Serial.begin(9600);
  Allocate();
  Light_On();
  // Light_Off();
  GetValues();
  Serial.println("\nINITIAL VALUES FETCHED");
  
  
  int x = 0;
  while (x < 25){
    Serial.print(LDRVALUES_NEW[x]) ;
    Serial.print("\t");
    x++;
  }

}

// Main loop
void loop() {
  //New_Value();
  // getValues( oldArray);
  //Receive_Array();
  //Switch_Light();
  //Algo();
  //Old_Value();
  // getValues( newArray);
  //Send_Array();
}
