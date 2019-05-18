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
  Random = random(1, 7);
  RandomSpeciali = random(0, 5);

}

void loop() {
  

}

void PiGreco()
{
  while(digitalRead(PulsanteAccensione) == LOW) {} 
    lcd.setCursor(0, 0);
    lcd.println( "VITE:" + String(Vite) + "PARTITE:" + String(Partite));
    while(Vite > 0)
    {
      if(Random == 1)
      {
        lcd.setCursor(0, 1);
        lcd.println("π");
        while(digitalRead(PulsanteA) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 2)
      {
        lcd.setCursor(0, 2);
        lcd.println("π");
        while(digitalRead(PulsanteB) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 3)
      {
        lcd.setCursor(0, 3);
        lcd.println("π");
        while(digitalRead(PulsanteC) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteE) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 4)
      {
        lcd.setCursor(0, 4);
        lcd.println("π");
        while(digitalRead(PulsanteD) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteA) == HIGH || digitalRead(PulsanteE) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 5)
      {
        lcd.setCursor(0, 5);
        lcd.println("π");
        while(digitalRead(PulsanteE) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteA) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 6)
      {
        lcd.setCursor(RandomSpeciali, 0);
        lcd.println("J");
        if(RandomSpeciali == 0)
        {
          
        }
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteA) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
        }
      }
      else if(Random == 7)
      {
        lcd.setCursor(0, random(0, 5));
        lcd.println("P");
        while(digitalRead(PulsanteE) == LOW) {}
        Record++;
        CalcolaPartite(Partite);
        if(digitalRead(PulsanteB) == HIGH || digitalRead(PulsanteC) == HIGH || digitalRead(PulsanteD) == HIGH || digitalRead(PulsanteA) == HIGH)
        {
          Vite--;
          CalcolaPartite(Partite);
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
