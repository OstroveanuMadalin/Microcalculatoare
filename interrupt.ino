#include <LiquidCrystal.h>
#define buttonPin 2
#define ledPin 13 
#define buzzer 10

volatile boolean state=false;
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);
int lightSensorPin= A0;
int analogValue=0;
void setup() {
  
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), change, RISING);   
}

void loop() {

 if (state)
 {
    execute();
 }else
 {
    digitalWrite(ledPin, LOW);
    lcd.clear();
    noTone(buzzer);
 
 }
}

void execute()
{
  
  analogValue=analogRead(lightSensorPin);

  if (analogValue<=30)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
     digitalWrite(ledPin, LOW);    
     tone(buzzer, 170, 350);
     delay(100);
   }
     
  lcd.clear();
  lcd.print("Valoare senzor:");
  lcd.setCursor(8,1);
  lcd.print(analogValue);
  delay(2250);

}

void change()
{
  state= !state;
}

 
