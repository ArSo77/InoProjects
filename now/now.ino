// now.pde
// Prints a snapshot of the current date and time along with the UNIX time
// Modified by Andy Wickert from the JeeLabs / Ladyada RTC library examples
// 5/15/11

#include <Wire.h>
#include "DS3231.h"

RTClib RTC;
DS3231 Clock;


void setup () {
    Serial.begin(57600);
    Wire.begin();
}

void loop () {
  
    delay(1000);
  
    DateTime now = RTC.now();


//    Clock.setYear(18);
//    Clock.setMonth(7);
//    Clock.setDate(30);
//    Clock.setDoW(1);
//    Clock.setHour(22);
//    Clock.setMinute(24);
//    Clock.setSecond(30);

    
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(' ');
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
    
    Serial.print(" since midnight 1/1/1970 = ");
    Serial.print(now.unixtime());
    Serial.print("s = ");
    Serial.print(now.unixtime() / 86400L);
    Serial.println("d");
}

