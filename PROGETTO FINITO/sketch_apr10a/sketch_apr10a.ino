#include <LiquidCrystal.h>

#define PulsanteAccensione  1
#define PulsanteA  2
#define PulsanteB  3
#define PulsanteC  4
#define PulsanteD  5
#define PulsanteE  6

int Partite;
int Vite;
int Record;
int Jolly;
int Penalty;
int Random;
int RandomSpeciali;
int Tempo1;
int Tempo2;

bool Cliccato = false;

LiquidCrystal lcd(12, 11, 6, 5, 4, 3);

void setup() {

  pinMode(PulsanteAccensione, INPUT);
  pinMode(PulsanteA, INPUT);
  pinMode(PulsanteB, INPUT);
  pinMode(PulsanteC, INPUT);
  pinMode(PulsanteD, INPUT);
  pinMode(PulsanteE, INPUT);

  lcd.begin(16, 2);
  
  Partite = 0;
  Record = 0;
  Vite = 3;

}

void loop() {
  
  while(digitalRead(PulsanteAccensione) == LOW) {} 
    lcd.setCursor(0, 0);
    lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite));  
      
    while(Vite > 0)
    {    
      Random = random(1, 7);
      RandomSpeciali = random(0, 5);
      
      if(Random == 1)
      {
        Tempo1 = millis();
        lcd.setCursor(0, 1);
        lcd.println("π");
        Tempo2 = millis();
        while(digitalRead(PulsanteA) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
        }
        Record++;
        CalcolaPartite(Partite);
        lcd.setCursor(0, 0);
        lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite));   
       }
      else if(Random == 2)
      {
        Tempo1 = millis();
        lcd.setCursor(0, 2);
        lcd.println("π");
        Tempo2 = millis();
        while(digitalRead(PulsanteB) == LOW) {        
          if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
        }
        Record++;
        CalcolaPartite(Partite);
        lcd.setCursor(0, 0);
        lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
      }
      else if(Random == 3)
      {
        Tempo1 = millis();
        lcd.setCursor(0, 3);
        lcd.println("π");
        Tempo2 = millis();
        while(digitalRead(PulsanteC) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
         }
        Record++;
        CalcolaPartite(Partite);
        lcd.setCursor(0, 0);
        lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
      }
      else if(Random == 4)
      {
        Tempo1 = millis();
        lcd.setCursor(0, 4);
        lcd.println("π");
        Tempo2 = millis();
        while(digitalRead(PulsanteD) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
        }
        Record++;
        CalcolaPartite(Partite);
        lcd.setCursor(0, 0);
        lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
      }
      else if(Random == 5)
      {
        Tempo1 = millis();
        lcd.setCursor(0, 5);
        lcd.println("π");
        Tempo2 = millis();
        while(digitalRead(PulsanteE) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteA) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
        }
        Record++;
        CalcolaPartite(Partite);
        lcd.setCursor(0, 0);
        lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 

      }
      else if(Random == 6)
      {
        Tempo1 = millis();
        lcd.setCursor(RandomSpeciali, 0);
        lcd.println("J");
        Tempo2 = millis();
        if(RandomSpeciali == 0)
        {
          while(digitalRead(PulsanteA) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          }
          Vite++;
          CalcolaPartite(Partite);
          lcd.setCursor(0, 0);
          lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
        }
        else if(RandomSpeciali == 1)
        {
          while(digitalRead(PulsanteB) == LOW) {        
          if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          }
          Vite++;
          CalcolaPartite(Partite);
          lcd.setCursor(0, 0);
          lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
        }
        else if(RandomSpeciali == 2)
        {
          while(digitalRead(PulsanteC) == LOW) {        
          if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          }
          Vite++;
          CalcolaPartite(Partite);
          lcd.setCursor(0, 0);
          lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
        }
        else if(RandomSpeciali == 3)
        {
          while(digitalRead(PulsanteC) == LOW) {        
          if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          }
          Vite++;
          CalcolaPartite(Partite);
          lcd.setCursor(0, 0);
          lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          else if(RandomSpeciali == 4)
          {
            while(digitalRead(PulsanteD) == LOW) {        
            if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
            {
              CalcolaPartite(Partite);
              lcd.setCursor(0, 0);
              lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
            }
            }
            Vite++;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
      }
      else if(Random == 7)
      {
        Tempo1 = millis();
        lcd.setCursor(RandomSpeciali, 0);
        lcd.println("P");
        Tempo2 = millis();
        if(RandomSpeciali == 0)
        {
          while(digitalRead(PulsanteA) == LOW) {        
          if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
          {
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          }
          Vite--;
          CalcolaPartite(Partite);
          lcd.setCursor(0, 0);
          lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          else if(RandomSpeciali == 1)
          {
            while(digitalRead(PulsanteB) == LOW) {        
            if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
            {
              CalcolaPartite(Partite);
              lcd.setCursor(0, 0);
              lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
            }
            }
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
          }
          else if(RandomSpeciali == 2)
          {
            while(digitalRead(PulsanteC) == LOW) {        
            if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
            {
              CalcolaPartite(Partite);
              lcd.setCursor(0, 0);
              lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
            }
            }
            Vite--;
            CalcolaPartite(Partite);
            lcd.setCursor(0, 0);
            lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
            }
            else if(RandomSpeciali == 3)
            {
              while(digitalRead(PulsanteC) == LOW) {        
              if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
              {
                CalcolaPartite(Partite);
                lcd.setCursor(0, 0);
                lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
              }
              }
              Vite--;
              CalcolaPartite(Partite);
              lcd.setCursor(0, 0);
              lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
              }
              else if(RandomSpeciali == 4)
              {
                while(digitalRead(PulsanteD) == LOW) {        
                if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteE) == HIGH || (Tempo2 - Tempo1) > 2000)
                {
                  CalcolaPartite(Partite);
                  lcd.setCursor(0, 0);
                  lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
                }
                }
                Vite--;
                CalcolaPartite(Partite);
                lcd.setCursor(0, 0);
                lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite)); 
              }
      }
    }
}

void CalcolaPartite(int Partite)
{
  while(digitalRead(PulsanteAccensione) == LOW) {}
  while(Cliccato == false)
  {
    if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH)
    {
      Cliccato = true;
      if(Vite > 0)
      {
        Partite++;
      }
    }
  }
  Cliccato = false;
}
