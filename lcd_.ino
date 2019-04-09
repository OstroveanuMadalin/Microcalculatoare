#include <LiquidCrystal.h>


LiquidCrystal lcd(13, 12, 6, 5, 4, 3);
int count1=0, length1, length2, lungime, lungime1=0, i=1,count=0;
String text1, text2, subtext11, subtext1,subtext2,subtext22;
void setup(){
  lcd.begin(16,2);
  lcd.clear();
  lcd.setCursor(0,0);
  text1="Hello";
  text2="World";
  length1=text1.length();
  length2=text2.length();
  lungime=text1.length();
  lungime1=length2;
  
  
  
}

void loop(){
  lcd.clear();
  
  if(count1 >15-length1){
    
    subtext1=text1.substring(lungime);
    subtext11=text1.substring(0, 16-count1);
    lcd.setCursor(0,0);
    lcd.print(subtext1);
    lcd.setCursor(count1,0);
    lcd.print(subtext11);
    lungime--;
   
  }
  else {
    lcd.setCursor(count1, 0);
    lcd.print(text1);
  }
  if(count>16-length2){
    subtext2=text2.substring(0,i);
    subtext22=text2.substring(i,length2);
    lcd.setCursor(16-i,1);
    lcd.print(subtext2);
    lcd.setCursor(0,1);
    lcd.print(subtext22);
    i++;
  } else

  {
  lcd.setCursor(16-lungime1,1);
  lcd.print(text2);
  lungime1++;
  }

  if (i==length2){
    count=0;
    i=1;
    lungime1=text2.length();
  }
  if(count1 >=16){
    count1=0;
    lungime=text1.length();
  }
  delay(500);
  count1++;
  count++;
}
