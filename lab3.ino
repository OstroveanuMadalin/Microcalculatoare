#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 6, 5, 4, 3);

#define buttonPin 2
#define buzzer 8
int RED_LED=11;
int YELLOW_LED=10;
int GREEN_LED=9;
bool ramura=true;
bool state = 1;

void setup() {
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), change, RISING); 
  
 }

int time_count=0;
int time_count1=0;
int led_red_state=1;
int led_yellow_state=0;
int led_green_state=0;
void loop() {

 if (state)
 {  
  execute();
    
 }else
 {
 
  lcd.clear();
  digitalWrite(RED_LED, 0);
  digitalWrite(YELLOW_LED,0);
  digitalWrite(GREEN_LED, 0);
  time_count=0;
  time_count1=0;
  led_red_state=1;
  led_green_state=0;
  led_yellow_state=0;
  ramura=true;
  noTone(buzzer);

}
}

void execute()
{
  lcd.clear();
  // put your main code here, to run repeatedly:
  digitalWrite(RED_LED, led_red_state);
  digitalWrite(YELLOW_LED, led_yellow_state);
  digitalWrite(GREEN_LED, led_green_state);

  if (led_red_state){
    lcd.setCursor(0,0);
    lcd.print("rosu");
   
  }
    if (led_green_state){
    lcd.setCursor(0,0);
    lcd.print("verde");
  }
  
  delay(50);
  if(ramura){
    time_count+=50;
  }else{
  time_count1+=50;
  }
  if (time_count >2000 and time_count<3000)
  {
    lcd.setCursor(0,1);
    lcd.print("galben");
    led_yellow_state=!led_yellow_state;
    
      if(led_yellow_state)
  
      {
       tone(buzzer,2400);
    
      } 
      else
      {
        noTone(buzzer);
      }
   
    
  }
  if (time_count1 >4000 and time_count1<5000)
  {
    led_yellow_state=!led_yellow_state;
    lcd.setCursor(0,1);
    lcd.print("galben");
  if(led_yellow_state)
  
    {
      tone(buzzer,2400);
    
    }else{
      noTone(buzzer);
    }
   
  }
  
  if (time_count>3000 and ramura==true){
    noTone(buzzer);
    led_yellow_state=0;
    led_red_state=0;
    led_green_state=1;
    time_count=0;
    ramura=false;
    
       
  } 
  if (time_count1>5000 and ramura==false){
    noTone(buzzer);
    led_yellow_state=0;
    led_red_state=1;
    led_green_state=0;
    time_count1=0;
    ramura=true;
     lcd.setCursor(0,0);
    lcd.print("rosu");
       
  }
}
void change()
{
  state= !state;
}
