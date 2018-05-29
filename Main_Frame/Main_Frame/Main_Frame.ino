/* ________  ___  _______   _____ ______           ___  ________   ________                                 ________  ___       ________  ___       __      
|\   __  \|\  \|\  ___ \ |\   _ \  _   \        |\  \|\   ___  \|\   ____\                               |\   ____\|\  \     |\   __  \|\  \     |\  \    
\ \  \|\ /\ \  \ \   __/|\ \  \\\__\ \  \       \ \  \ \  \\ \  \ \  \___|             ____________      \ \  \___|\ \  \    \ \  \|\  \ \  \    \ \  \   
 \ \   __  \ \  \ \  \_|/_\ \  \\|__| \  \       \ \  \ \  \\ \  \ \  \               |\____________\     \ \  \  __\ \  \    \ \  \\\  \ \  \  __\ \  \  
  \ \  \|\  \ \  \ \  \_|\ \ \  \    \ \  \       \ \  \ \  \\ \  \ \  \____  ___     \|____________|      \ \  \|\  \ \  \____\ \  \\\  \ \  \|\__\_\  \ 
   \ \_______\ \__\ \_______\ \__\    \ \__\       \ \__\ \__\\ \__\ \_______\\__\                          \ \_______\ \_______\ \_______\ \____________\
    \|_______|\|__|\|_______|\|__|     \|__|        \|__|\|__| \|__|\|_______\|__|                           \|_______|\|_______|\|_______|\|____________|                                                                                                                                                      
*/                                                                                                                                                 


                                                                                                                                                          
// Allocate memory for the LED's and Sensors
#define LED_SIZE 3
#define LDR_SIZE 5

int LED[(LED_SIZE - 1)];
int LEDSTATUS[(LED_SIZE - 1)];
int LDR[LDR_SIZE]; // We still have to discuss where to connect these...
int LDR_VALUES[LDR_SIZE];

int PopulateArray() {
  int y = 2;
  for (int i = 0; i <= LED_SIZE; i++) {
    LED[i] = y;
    y++;
  }
  Serial.println("ARRAY POPULATED");
}

void Allocate() {
  PopulateArray();
  // Define LED and LDR input/output
  int LED_COUNT = 0;
  int LDR_COUNT = 0;

  while (LED_COUNT <= (LED_SIZE - 1)){
    pinMode(LED[LED_COUNT], OUTPUT);
    LED_COUNT++;
  }

/*
  while (LDR_COUNT <= LDR_SIZE){
    pinMode(LDR[LDR_COUNT], INPUT);
    LDR_COUNT++;

  }

*/

  Serial.println("INPUT/OUTPUT SET");
 
}

void Light_On() {
  // Lights On (Default)
  int POWER_COUNT = 0;
    while (POWER_COUNT <= (LED_SIZE - 1)){
      digitalWrite(LED[POWER_COUNT], HIGH);
      POWER_COUNT++;
    }
    Serial.println("LIGHTS ON");
  }
  
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
  // Retrieve initial LDR values
  Serial.println("INITIAL VALUES FETCHED");
}




// Fix these methods later on...


/*
ReceiveArray(){


  
}
*/



// Setup and Main Loop

void setup() {
  Serial.begin(9600);
  Allocate();
  Light_On();
  // Light_Off();
  Start();
}

void loop() {
  /*
  New_Value();
  Receive_Array();
  Switch_Light();
  Algo();
  Old_Value();
  Send_Array();
  */
}
