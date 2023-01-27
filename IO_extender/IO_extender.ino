/*  *********************************** 
     IO extender
     
     This code expands the usage of IOs using I2C protocol 
     Supporting PCF8574 I2C module.
     Identifying the pins may be tricky - the yare not marked

By: Gal Arbel 2023

*/

#include <PCF8574.h>
PCF8574 PCF1(0x26); //writes
PCF8574 PCF2(0x27);//reads


void setup()
{
  Serial.begin(115200);

  if (!PCF1.begin() || !PCF2.begin())
  {
    Serial.println("could not initialize...");
  }
  if (!PCF1.isConnected() || !PCF2.isConnected())
  {
    Serial.println("=> not connected");
    while(1);
  }
}


void loop()
{
  PCF1.write(3, HIGH);
  PCF1.write(6, HIGH);
  PCF1.write(4, HIGH);
  Serial.println(PCF2.read(0));
  delay(1000);
  PCF1.write(3, LOW);
  PCF1.write(6, LOW);
  PCF1.write(4, LOW);
  Serial.println(PCF2.read(0));
  delay(1000);
  
}

