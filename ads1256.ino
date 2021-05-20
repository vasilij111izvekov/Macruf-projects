
/* Sensor reading:
  sensor1 = differential input connected on AIN0 - AIN1
  sensor2 = differential input connected on AIN2 - AIN3
  sensor3 = differential input connected on AIN4 - AIN5
  sensor4 = differential input connected on AIN6 - AIN7
*/


#include <ADS1256.h>
#include <SPI.h>

float clockMHZ = 7.68; // crystal frequency used on ADS1256
float vRef = 2.5; // voltage reference
ADS1256 adc(clockMHZ,vRef,false); 
float sensor1, sensor2;


void setup()
{
  Serial.begin(9600);
  
  Serial.println("Starting ADC");


  adc.begin(ADS1256_DRATE_10SPS,ADS1256_GAIN_1,false); 

  Serial.println("ADC Started");

}

void loop()
{ 


  
  adc.waitDRDY(); 
  adc.setChannel(1);  
  sensor1 = adc.readCurrentChannel(); 
  adc.waitDRDY();
  adc.setChannel(0);
  sensor2 = adc.readCurrentChannel(); 

  //print the result.
  Serial.print("С потенциометра ");
  Serial.print(sensor1,3);
  Serial.print(" | ");
   Serial.print("С фотодатчика ");
  Serial.print(sensor2,3);
  Serial.print("\n");
  
}
