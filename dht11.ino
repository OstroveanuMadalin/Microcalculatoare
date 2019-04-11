#include <dht.h>
#include <LiquidCrystal.h>
#define DHT11_PIN 1
LiquidCrystal lcd(13, 12, 6, 5, 4, 3);

dht DHT;
int buzzer=8;
int redLED=11, greenLED=9;
int buttonPin=2;

float tempK=0.0;
float tempC=0.0;
bool state=1;

  void setup(){
  lcd.begin(16, 2);
  pinMode(9, OUTPUT);
  pinMode(11,OUTPUT);
  attachInterrupt(digitalPinToInterrupt(buttonPin), change, RISING); 
  }
  
void loop() {

 if (state)
 {  
  execute();
    
 }else
 {
 
  lcd.clear();
  digitalWrite(redLED, 0);
  
  digitalWrite(greenLED, 0);
 
  noTone(buzzer);

}
}
void execute()
{  
  int chk = DHT.read11(DHT11_PIN);
  tempC=DHT.temperature;
  tempK=271.15+DHT.temperature;
  
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Temp: ");
  
  lcd.print(tempK);
  lcd.print((char)223);
 
  lcd.print("K");
   digitalWrite(greenLED, tempC<=19?HIGH:LOW);
    digitalWrite(redLED, tempK>=20?HIGH:LOW);
    if(tempC > 19 && tempC <20  ){
      tone(buzzer,100);
    }else{
      noTone(buzzer);
    }
  delay(100);
}
void change()
{
  state= !state;
}
