// JAI SHREE RAM

#include<LiquidCrystal.h>
//#include<RF24.h>

const int ctPin1 = A0,ctPin2 = A1,led = 8;
double kwh1 = 0,kwh2=0;
int peakPower1 = 0,peakPower2=0;

LiquidCrystal lcd(12,11,7,6,5,4);

unsigned long lastMillis=0;
    unsigned long lastHourMillis=0;
    unsigned long lastReading1=0,lastReading2=0;
    unsigned long consumedReading1=0,consumedReading2=0;
    unsigned long currentMillis=millis();
/*    
    RF24 radio(2,3);
    byte address[]="home1";
    byte da[]="da";
*/
void setup()
{
  Serial.begin(9600);
    lcd.begin(16,2);
    pinMode(led,OUTPUT);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("JAI");
    lcd.setCursor(3,1);
    lcd.print("SHREE RAM");
    digitalWrite(led,HIGH);
    delay (3000);
    digitalWrite(led,LOW);
    delay(500);
    lcd.clear();
    lcd.setCursor(6,0);
    lcd.print("AIR");
    lcd.setCursor(0,1);
    lcd.print("REVOLUTIONARIES");
    digitalWrite(led,HIGH);
    delay (3000);
    digitalWrite(led,LOW);
}
void loop()
{
  //***********************************************ctPin1*******************
  
    int current1 = 0,current2 = 0;
    int maxCurrent1 = 0,maxCurrent2 = 0;
    int minCurrent1 = 0,minCurrent2 = 0;
    
    for (int i=0;i<=200;i++)
    {
        current1 = analogRead(ctPin1);
        
        if (current1>=maxCurrent1)
            maxCurrent1=current1;
            else if  (current1<=minCurrent1)
            minCurrent1=current1;
        }
        if (maxCurrent1<=517)
        {
            maxCurrent1 = 516;
        }
        double RMScurrent1 = ((maxCurrent1-516)*0.707)/11.8337;
        int RMSpower1=230*RMScurrent1;
        
        if(RMSpower1>peakPower1)
        {
            peakPower1 = RMSpower1;
        }
        kwh1=kwh1+(RMSpower1*(2.05/60/60/1000));
                delay(100);

        
     //*************************************************ctPin2*******************
     
    for (int i=0;i<=200;i++)
    {
        current2 = analogRead(ctPin2);
        
        if (current2>=maxCurrent2)
            maxCurrent2=current2;
            else if  (current2<=minCurrent2)
            minCurrent2=current2;
        }
        if (maxCurrent2<=517)
        {
            maxCurrent2 = 516;
        }
        double RMScurrent2 = ((maxCurrent2-516)*0.707)/11.8337;
        int RMSpower2=230*RMScurrent2;
        
        if(RMSpower2>peakPower2)
        {
            peakPower2 = RMSpower2;
        }
        kwh2=kwh2+(RMSpower2*(2.05/60/60/1000));
        delay(100);

        //********************************************Looking for any difference********************

        Serial.print("RMSpower1 = ");
        Serial.println(RMSpower1);
        Serial.print("RMSpower2 = ");
        Serial.println(RMSpower2);
        
        Serial.print("RMScurrent1 = ");
        Serial.println(RMScurrent1);
        Serial.print("RMScurrent2 = ");
        Serial.println(RMScurrent2);
        
        if (RMSpower2-RMSpower1>0)
        {
          Serial.println("*****************************-PROBLEM-******************************");
          Serial.println("**********************-PROBLEM-------FOUND-***********************");
          Serial.println("******************************-ALERT-***********************");
          digitalWrite(led,HIGH);
          delay(100);
          digitalWrite(led,LOW);
        }

     //************************************************displaying ctPin1 reading*********************
     
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(RMScurrent1);
        lcd.print("A");
        lcd.setCursor(10,0);
        lcd.print(RMSpower1);
        lcd.print("W");
        lcd.setCursor(0,1);
        lcd.print(kwh1);
        lcd.print("kwh");
        lcd.setCursor(10,1);
        lcd.print(peakPower1);
        lcd.print("W+"); 

    // continue loop from here...
    // To trans-receiving data with nRF24L01 module...
   
  /*  unsigned long currentMillis=millis();
    
    if (currentMillis-lastMillis>=1000)
    {
      Serial.print("currentMillis = ");
      Serial.println(currentMillis);
      Serial.print("lastMillis = ");
      Serial.println(lastMillis);
      Serial.print("diffMillis = ");
      Serial.println(currentMillis-lastMillis);
        lastMillis = currentMillis;
        if (currentMillis-lastMillis>=10000)
        {
            radio.openWritingPipe(da);
            radio.stopListening();
            radio.write(&kwh,sizeof(kwh));
            radio.startListening(); 
            // serial monitor display 
            Serial.print("kwh = ");
            Serial.println(kwh1);
        }
        if (currentMillis-lastHourMillis>=60000)
        {
            lastHourMillis=currentMillis;
            radio.openWritingPipe(da);
            radio.stopListening();
            
            radio.write(&consumedReading,sizeof(consumedReading));
            radio.startListening(); 
            lastReading1=consumedReading1;
            Serial.print("consumedReading1 = ");
            Serial.println(consumedReading1);
            Serial.print("consumedReading2 = ");
            Serial.println(consumedReading2);           
        }
    }*/
    
}
