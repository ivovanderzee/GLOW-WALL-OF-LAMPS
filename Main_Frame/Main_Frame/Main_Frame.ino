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

int LED[LED_SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34};
int LDR[LDR_SIZE] = {}; // We still have to discuss where to connect these...


Allocate() {
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
  
  }
  
Light_Off() {
  // Lights Off (Default)
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
