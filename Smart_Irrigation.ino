
#include <LiquidCrystal.h>

#define NOTE_C4 262 
#define NOTE_D4 294 
#define NOTE_E4 330 
#define NOTE_F4 349 
#define NOTE_G4 392 
#define NOTE_A4 440 
#define NOTE_B4 494 
#define NOTE_C5 523 

int temp;
int T_Sensor = A3;
int M_Sensor = A0;
int W_led = 7;
int P_led = 13;
int Speaker = 9;
int val;
int cel;  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup()
 {
    lcd.begin(16, 2);
    lcd.clear(); 
    pinMode(13,OUTPUT);
    pinMode(7,INPUT);
    pinMode(9,OUTPUT);
    
    val = analogRead(T_Sensor); //Read Temperature sensor value 
    int mv = ( val/1023.0)*5000; 
    cel = mv/10;
    
  
    
    lcd.setCursor(0,0);
    lcd.print("MINI PROJECT");
    delay(500);
   
}

void loop()
{
  
  lcd.clear();
  int Moisture = analogRead(M_Sensor); //Read Moisture Sensor Value 

  lcd.setCursor(0,0);
  lcd.print("TEMP:");
  lcd.setCursor(5,0);
  lcd.print(cel);
  lcd.setCursor(7,0);
  lcd.print("*C");
 
 if (Moisture> 700)   // for dry soil
  { 
        lcd.setCursor(11,0);
        lcd.print("DRY");
        lcd.setCursor(11,1);
        lcd.print("SOIL");
        digitalWrite(13, HIGH);
         lcd.setCursor(0,1);
         lcd.print("PUMP:ON");
           
           tone(Speaker, NOTE_C4, 100); 
           delay(100); 
           tone(Speaker, NOTE_D4, 100);
           delay(100); 
           tone(Speaker, NOTE_E4, 100); 
           delay(100); 
           tone(Speaker, NOTE_F4, 100); 
           delay(100); 
           tone(Speaker, NOTE_G4, 100); 
           delay(100);
      
    }
 
     if (Moisture>= 300 && Moisture<=700) //for Moist Soil
    { 
      lcd.setCursor(11,0);
     lcd.print("MOIST");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");    
  }
 
  if (Moisture < 300)  // For Soggy soil
  { 
    lcd.setCursor(11,0);
     lcd.print("WET");
     lcd.setCursor(11,1);
     lcd.print("SOIL");
     digitalWrite(13,LOW);
     lcd.setCursor(0,1);
     lcd.print("PUMP:OFF");
  }
 delay(500);    
}  
