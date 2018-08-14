#include <Sensirion.h>
#include <Wire.h>
#include "DS3231.h"


RTClib RTC;
DS3231 Clock;

const uint8_t dataPin  =  8;//2
const uint8_t clockPin =  9;//3

float temperature;
float humidity;
float dewpoint;

Sensirion tempSensor = Sensirion(dataPin, clockPin);


#include <EtherCard.h>

// ethernet interface mac address, must be unique on the LAN
static byte mymac[] = { 0x74,0x69,0x39,0x2D,0x30,0x31 };
static byte myip[] = { 192,168,1,50 };

byte Ethernet::buffer[500];
BufferFiller bfill;

void setup () {


  pinMode(A1, INPUT_PULLUP);        
  pinMode(A2, INPUT_PULLUP);        
  pinMode(A3, INPUT_PULLUP);        

  
      Wire.begin();
    Serial.begin(9600);
    Serial.println("Start");

  if (ether.begin(sizeof Ethernet::buffer, mymac) == 0)
    Serial.println(F("Failed to access Ethernet controller"));
  ether.staticSetup(myip);
}

static word homePage() {

   DateTime now = RTC.now();
  
   
  tempSensor.measure(&temperature, &humidity, &dewpoint);


  int a1=analogRead(A1);
  delay(20);
  int a2=analogRead(A2);
  delay(20);

  int yea =  now.year();
  int mon =  now.month();
  int day =  now.day();
  int h =now.hour();
  int m = now.minute();
  int s = now.second();
  int f = temperature;
  int g = humidity;
  int d = dewpoint;
  bfill = ether.tcpOffset();
  bfill.emit_p(PSTR(
    "HTTP/1.0 200 OK\r\n"
    "Content-Type: application/json\r\n"
    "Access-Control-Allow-Credentials: true\r\n"
    "Access-Control-Allow-Origin: *\r\n"
    "Pragma: no-cache\r\n"
    "\r\n"
    "{\"Temp\":\"$D\",\"Hum\":\"$D\",\"Dewpoint\":\"$D\",\"Time\":\"$D:$D:$D\",\"Date\":\"$D.$D.$D\",\"Analogs\":\"A1=$D, A2=$D\"}"),
      f,  g, d, h, m, s, day, mon, yea, a1, a2);
  return bfill.position();
}

void loop () {

  
  word len = ether.packetReceive();
  word pos = ether.packetLoop(len);
  
  if (pos){  // check if valid tcp data is received
    ether.httpServerReply(homePage()); // send web page data
  }
  else{
    delay(10);
  }
    
}
