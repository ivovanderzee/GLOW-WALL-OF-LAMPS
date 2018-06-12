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
#define LED_SIZE 45
#define LDR_SIZE 36

// Define the Multiplex pins
const int MultiPlexPins[4] = {46, 47, 48, 49};
const int MultiPlexOne = A0;

// LED Locations
int LED[(LED_SIZE - 1)];

// LED Status OFF/ON
int LEDSTATUS[(LED_SIZE - 1)];

// LDR Values
int LDR_VALUES[LDR_SIZE];







int MultiPlex(){
  for (int i= 0; i < 0; i++)
  {
    pinMode(MultiPlexPins[i], OUTPUT);
    digitalWrite(MultiPlexPins[i], HIGH);
  }
  pinMode(MultiPlexOne, INPUT);
}

int PinChannel(){
  for (byte pin = 0; pin <= 15; pin++){
    SelectDefinedPin(pin);
    int inputtest = analogRead(A0);
    Serial.print(String(inputtest) + "\t");
  }
}

void SelectDefinedPin(byte pin) {
  for (int i = 0; i < 4; i++){
    if (pin & (1<<i))
    digitalWrite(MultiPlexPins[i], HIGH);
    else
    digitalWrite(MultiPlexPins[i], LOW);
  }
}



// Populate the array
int PopulateArray() {
  int y = 2;
  for (int i = 0; i <= LED_SIZE; i++) {
    LED[i] = y;
    y++;
  }
  Serial.println("ARRAY POPULATED");
}

// Define the IN/OUTPUT's
void Allocate() {
  MultiPlex();
  PopulateArray();
  // Define LED and LDR input/output
  int LED_COUNT = 0;
  int LDR_COUNT = 0;

  while (LED_COUNT <= (LED_SIZE - 1)){
    pinMode(LED[LED_COUNT], OUTPUT);
    LED_COUNT++;
  }

  Serial.println("INPUT/OUTPUT SET");
 
}

// Light on by default
void Light_On() {
  // Lights On (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= (LED_SIZE - 1)){
      digitalWrite(LED[POWER_COUNT], HIGH);
      POWER_COUNT++;
    }
    Serial.println("LIGHTS ON");
  }

// Light off by default
void Light_Off() {
  // Lights Off (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= LED_SIZE){
      digitalWrite(LED[POWER_COUNT], LOW);
      POWER_COUNT++;
    }
    Serial.println("LIGHTS OFF");
}


void Start(){
  PinChannel();
  // Retrieve initial LDR values
  Serial.println("\nINITIAL VALUES FETCHED");
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
  Start();
}

// Main loop
void loop() {
  //New_Value();
  //Receive_Array();
  //Switch_Light();
  //Algo();
  //Old_Value();
  //Send_Array();
}
