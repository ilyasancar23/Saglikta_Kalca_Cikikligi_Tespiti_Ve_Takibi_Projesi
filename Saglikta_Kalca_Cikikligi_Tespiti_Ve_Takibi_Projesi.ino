#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int gecenSure = 1000;//2 adım arası geçen süre 1000 ms = 1 sn
int bekleme = 1000;//ledin yanma süresi 1000 ms = 1 sn

bool kontrol = false;
int led = 6, button1 = 9, buzzer = 7;
int ilkZaman = 0, sonZaman = 0, b1_deger = LOW, b2_deger = LOW;
void setup(){
pinMode(led, OUTPUT);
pinMode(button1, INPUT);
pinMode(buzzer, OUTPUT);
lcd.begin(16,2);
Serial.begin(9600);
}

void loop (){

  lcd.clear();
  
  b1_deger = digitalRead(button1);
  
  if(b1_deger == HIGH){
      kontrol = true;
      ilkZaman = millis();
  }
  if(kontrol)
  {
      sonZaman = millis();
      if((sonZaman-ilkZaman) > gecenSure)
      {
           lcd.clear();
           digitalWrite(led, HIGH);
           digitalWrite(buzzer, HIGH);
           lcd.print("Ayagi yere");
           lcd.setCursor(2, 1);
           lcd.print("degmedi");
           
           delay (bekleme);
           
           digitalWrite(led, LOW);
           digitalWrite(buzzer, LOW);
           kontrol = false;
           ilkZaman = 0;
           sonZaman = 0;
      }
      else
      {
           lcd.clear();
           lcd.print("23");
      }
     
  }
}