/* WORKING OF DA...
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  it is calculating kwh output through the DA source of individual Meter.                                          //
//  now just receive the input of the individual Meter and compare them.                                             //
//  now compare them separatly and if there is any abnormal diff... is found,                                        //
//  then note the address and send it to the MT Meter,                                                               //
//  else send the sum of all output to MT Meter.                                                                     //
//       After 60 min... send the received messages from Meters as it is. Which is basically the total consummed kwh.//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
#include<RF24>

   int ctPin1=A1;
   int ctPin2=A2;
   int ctPin2=A2;

       double kwh1=0,kwh2=0,kwh3=0;

void setup() 
{
  Serial.begin(9600);
}

void loop()
{
     for (int i=0 ; i<=200 ; i++)  //Monitors and logs the current input for 200 cycles to determine max and min current
 {
  //********************************************************************************* HOME-1st OUTPUT (KWH)
  int current1 = 0;
  int maxCurrent1 = 0;
  int minCurrent1 = 1000;
  int peakPower1=0;
 
    current1 = analogRead(ctPin1);    //Reads current input
    if(current1 >= maxCurrent1)
    {
      maxCurrent1 = current1;
    } else if(current1 <= minCurrent1)
    {
      minCurrent1 = current1;
    }
  if (maxCurrent1 <= 517)
  {
    maxCurrent1 = 516;
  }
  double RMSCurrent1 = ((maxCurrent1 - 516)*0.707)/11.8337;    //Calculates RMS current based on maximum value
  int RMSpower1 = 220*RMSCurrent1;    //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
  if (RMSpower1 > peakPower1)
  {
    peakPower1 = RMSpower1;
  }
  kwh1 = kwh1 + (RMSpower1 * (2.05/60/60/1000));    //Calculate kilowatt hours used

  //********************************************************************************* HOME-2nd OUTPUT (KWH)
  int current2 = 0;
  int maxCurrent2 = 0;
  int minCurrent2 = 1000;
  int peakPower2=0;
 
    current2 = analogRead(ctPin2);    //Reads current input
    if(current2 >= maxCurrent2)
    {
      maxCurrent2 = current2;
    } else if(current2 <= minCurrent2)
    {
      minCurrent2 = current2;
    }
  if (maxCurrent2 <= 517)
  {
    maxCurrent2 = 516;
  }
  double RMSCurrent2 = ((maxCurrent2 - 516)*0.707)/11.8337;    //Calculates RMS current based on maximum value
  int RMSpower2 = 220*RMSCurrent2;    //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
  if (RMSpower2 > peakPower2)
  {
    peakPower2 = RMSpower2;
  }
  kwh2 = kwh2 + (RMSpower2 * (2.05/60/60/1000));    //Calculate kilowatt hours used
      
  //********************************************************************************* HOME-3rd OUTPUT (KWH)
  int current3 = 0;
  int maxCurrent3 = 0;
  int minCurrent3 = 1000;
  int peakPower3=0;
 
    current3 = analogRead(ctPin3);    //Reads current input
    if(current3 >= maxCurrent3)
    {
      maxCurrent3 = current3;
    } else if(current3 <= minCurrent3) 
    {
      minCurrent3 = current3;
    }
  if (maxCurrent3 <= 517)
  {
    maxCurrent3 = 516;
  }
  double RMSCurrent3 = ((maxCurrent3 - 516)*0.707)/11.8337;    //Calculates RMS current based on maximum value
  int RMSpower3 = 220*RMSCurrent3;    //Calculates RMS Power Assuming Voltage 220VAC, change to 110VAC accordingly
  if (RMSpower3 > peakPower3)
  {
    peakPower3 = RMSpower3;
  }
  kwh3 = kwh3 + (RMSpower3 * (2.05/60/60/1000));    //Calculate kilowatt hours used
      sPrint();
  }
}
void sPrint()
{
  Serial.print("kwh1 = ");
  Serial.print(kwh1);
  Serial.println("kwh2 = ");
  Serial.print(kwh2);
  Serial.println("kwh3 = ");
  Serial.print(kwh3);
}