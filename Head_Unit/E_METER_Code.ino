// Jai Shree Ram
#include <LiquidCrystal.h>

int currentPin = A0;              //Assign CT input
double kilos = 0;
int peakPower = 0;
LiquidCrystal lcd(12, 11,7 , 6, 5, 4);  //Assign LCD screen pins

void setup() 
{ 
  lcd.begin(16,2);
  Serial.begin(9600); // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear();
  lcd.setCursor(0,0);           // set cursor to column 0, row 0 (the first row)
  lcd.print("Jai Shree Ram");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("Revolutionaries");
  lcd.setCursor(7,0);
  lcd.print("AIR");
  delay(1);
  delay(3000);
}

void loop() 
{ 
  int current = 0;
  int maxCurrent = 0;
  int minCurrent = 1000;
  for (int i=0 ; i<=200 ; i++)  //Monitors and logs the current input for 200 cycles to determine max and min current
  {
    current = analogRead(currentPin);    //Reads current input
    if(current >= maxCurrent)
      maxCurrent = current;
    else if(current <= minCurrent)
      minCurrent = current;
  }
  if (maxCurrent <= 517)
  {
    maxCurrent = 516;
  }
  double RMSCurrent = ((maxCurrent - 516)*0.707)/11.8337;    //Calculates RMS current based on maximum value
  int RMSPower = 230*RMSCurrent;    //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
  if (RMSPower > peakPower)
  {
    peakPower = RMSPower;
  }
  kilos = kilos + (RMSPower * (2.05/60/60/1000));    //Calculate kilowatt hours used
  Serial.println();
  Serial.println();
  Serial.println(current);
  delay (2000);
  lcd.clear();
  lcd.setCursor(0,0);           // Displays all current data
  lcd.print(RMSCurrent);
  lcd.print("A");
  lcd.setCursor(10,0);
  lcd.print(RMSPower);
  lcd.print("W");
  lcd.setCursor(0,1);
  lcd.print(kilos);
  lcd.print("kWh");
  lcd.setCursor(10,1);
  lcd.print(peakPower);
  lcd.print("pW");

           // Displays all current data
           Serial.println();
           Serial.println();
  Serial.print(RMSCurrent);
  Serial.print(" A");
  Serial.println(RMSPower);
  Serial.print(" W");
  Serial.println(kilos);
  Serial.print(" kWh");
  Serial.println(peakPower);
  Serial.print(" pW");
}
