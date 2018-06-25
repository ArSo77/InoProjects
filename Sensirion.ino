#include <Sensirion.h>

const uint8_t dataPin  =  10;//2
const uint8_t clockPin =  11;//3

float temperature;
float humidity;
float dewpoint;

Sensirion tempSensor = Sensirion(dataPin, clockPin);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  tempSensor.measure(&temperature, &humidity, &dewpoint);



  Serial.print("{\"Temp\":");
  Serial.print(temperature);
  Serial.print(",\"Hum\":");
  Serial.print(humidity);
  Serial.print(",\"Dew\":");
  Serial.print(dewpoint);
  Serial.print("}");




  
  
  delay(900);  
}
