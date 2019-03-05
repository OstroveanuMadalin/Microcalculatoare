int RED_LED=13;
int YELLOW_LED=12;
int GREEN_LED=11;
bool ramura=true;
void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

int time_count=0;
int time_count1=0;
int led_red_state=1;
int led_yellow_state=0;
int led_green_state=0;
void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, led_red_state);
  digitalWrite(YELLOW_LED, led_yellow_state);
  digitalWrite(GREEN_LED, led_green_state);

  delay(50);
  if(ramura){
    time_count+=50;
  }else{
  time_count1+=50;
  }
  if (time_count >2000 and time_count<3000){

    led_yellow_state=!led_yellow_state;
  }
  if (time_count1 >4000 and time_count1<5000)
  {
    led_yellow_state=!led_yellow_state;
  }
  
  if (time_count>3000 and ramura==true){

    led_yellow_state=0;
    int aux=RED_LED;
    RED_LED=GREEN_LED;
    GREEN_LED=aux;
    time_count=0;
    ramura=false;
       
  } 
  if (time_count1>5000 and ramura==false){
    led_yellow_state=0;
    int aux=GREEN_LED;
    GREEN_LED=RED_LED;
    RED_LED=aux;
    time_count1=0;
    ramura=true;
  }
}
