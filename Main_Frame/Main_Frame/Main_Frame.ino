/* ________  ___  _______   _____ ______           ___  ________   ________                                 ________  ___       ________  ___       __      
|\   __  \|\  \|\  ___ \ |\   _ \  _   \        |\  \|\   ___  \|\   ____\                               |\   ____\|\  \     |\   __  \|\  \     |\  \    
\ \  \|\ /\ \  \ \   __/|\ \  \\\__\ \  \       \ \  \ \  \\ \  \ \  \___|             ____________      \ \  \___|\ \  \    \ \  \|\  \ \  \    \ \  \   
 \ \   __  \ \  \ \  \_|/_\ \  \\|__| \  \       \ \  \ \  \\ \  \ \  \               |\____________\     \ \  \  __\ \  \    \ \  \\\  \ \  \  __\ \  \  
  \ \  \|\  \ \  \ \  \_|\ \ \  \    \ \  \       \ \  \ \  \\ \  \ \  \____  ___     \|____________|      \ \  \|\  \ \  \____\ \  \\\  \ \  \|\__\_\  \ 
   \ \_______\ \__\ \_______\ \__\    \ \__\       \ \__\ \__\\ \__\ \_______\\__\                          \ \_______\ \_______\ \_______\ \____________\
    \|_______|\|__|\|_______|\|__|     \|__|        \|__|\|__| \|__|\|_______\|__|                           \|_______|\|_______|\|_______|\|____________|                                                                                                                                                      
*/                                                                                                                                                 
                                                                                                                                                          
// Allocate memory for the LED's and Sensors
#define LED_SIZE 35
#define LDR_SIZE 35

int LED[LED_SIZE];
int LDR[LDR_SIZE]; // We still have to discuss where to connect these...

int PopulateArray() {
  for (int i = 0; i <= ARRAYLENGHT; i++) {
    TheArray[i] = i;
  }
}

Allocate() {
  PopulateArray();
  // Define LED and LDR input/output
  int LED_COUNT = 0;
  int LDR_COUNT = 0;

  while (LED_COUNT <= LED_SIZE){
    pinMode(LED[LED_COUNT], OUTPUT);
    LED_COUNT++;
  }

  while (LDR_COUNT <= LDR_SIZE){
    pinMode(LDR[LDR_COUNT], INPUT);
    LDR_COUNT++;
  }
}

Light_On() {
  // Lights On (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= LED_SIZE){
      digitalWrite(LED[POWER_COUNT], HIGH);
      POWER_COUNT++;
    }
  }
  
Light_Off() {
  // Lights Off (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= LED_SIZE){
      digitalWrite(LED[POWER_COUNT], LOW);
      POWER_COUNT++;
    }
}

Start(){
  // Retrieve initial LDR values
}



void setup() {
  Allocate();
  Light_On();
  Start();
}

void loop() {
  New_Value();
  Receive_Array();
  Switch_Light();
  Algo();
  Old_Value();
  Send_Array();
}
