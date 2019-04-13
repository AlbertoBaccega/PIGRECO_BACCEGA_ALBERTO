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
  

}

void PiGreco()
{
  lcd.setCursor(0, 0);
  lcd.println( "VITE:" + String() + "PARTITE:" + Partite);
  while(digitalRead(PulsanteAccensione) == HIGH)
  {
    lcd.setCursor(0, 1);
    
  }
  
}

void CalcolaVite(int Vite+
)
{
  
}

void CalcolaRecord(int Record)
{
  while(digitalRead(PulsanteAccensione) == LOW) {}
  while(Cliccato == false)
  {
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
