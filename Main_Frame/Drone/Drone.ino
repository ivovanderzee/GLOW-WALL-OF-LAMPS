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
#define SENSITIVITY 5

// LED Locations
int LEDLOCATION[LED_SIZE]{2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45};

// LED Status OFF/ON
int LEDSTATUS[(LED_SIZE)];
int RECEIVEDSTATUS[(LED_SIZE)];




// Define the IN/OUTPUT's
void Allocate() {
  // Define LED and LDR input/output
  int LED_COUNT = 0;

  while (LED_COUNT < (LED_SIZE)){
    pinMode(LEDLOCATION[LED_COUNT], OUTPUT);
    LED_COUNT++;
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

void Switch_Light(){
  for(int i = 0; i < 36; i++){
    if(LEDSTATUS[i] == 1){
      digitalWrite(LEDLOCATION[i], LOW);
    }
    else{
      digitalWrite(LEDLOCATION[i], HIGH);
    }
  }
}

int t[10];
int i = 0;

byte j, stat;
void receiveEvent(int bytes){
  //Serial.println('hallo');
  // TODO: add begin and end points.
    //RECEIVEDSTATUS[0] = Wire.read();
    //j = Wire.read();
//    i=0;
//    while (Wire.available()) { 
//    t[i] = Wire.read(); // every character that arrives it put in order in the empty array "t"
//    i=i+1;
//  }
    j = Wire.read();
    stat = Wire.read();
 //   byte stat = Wire.read();
    LEDSTATUS[j] = stat;
 //   Serial.println(LEDSTATUS[pos]);
  }
  
void Receive_Array(){
  Serial.println(LEDSTATUS[1]);
}



// Setup
void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
  Allocate();
  //Light_On();
  Light_Off();
  Serial.println("INITIAL VALUES FETCHED");
}

// Main loop
void loop() {
  Receive_Array();
  Switch_Light();
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
