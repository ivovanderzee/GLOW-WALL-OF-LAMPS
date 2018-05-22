Allocate() {
  //toewijzen ldr's en led's
}

Light_On() {
  //Digital_Write(HIGH), lampen gaan aan
  }
  
Light_Off() {
  //Digital_Write(LOW), lampen gaan uit
}

Start(){
  //uitlezen
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
