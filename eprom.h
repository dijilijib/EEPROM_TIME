#ifndef EPROM_H
#define EPROM_H

#include <Arduino.h>

class eprom 
{
  public:
  eprom(uint8_t address);
  void setup();
  int Saat1();
  int Dakika1();
  int Saat2();
  int Dakika2();
  void time1(uint8_t hours, uint8_t minutes);
  void time2(uint8_t hours, uint8_t minutes);
  private:
  uint16_t _address;
};

// KULLANIM
///////////
/* : SETUP

    eprom zaman(3);
    zaman.setup();

////////////
/* : LOOP

    zaman.time1(11, 26);
    zaman.time2(23, 44);

    saat1 = zaman.Saat1();
    dakika1 = zaman.Dakika1();
    saat2 = zaman.Saat2();
    dakika2 = zaman.Dakika2();
    test = zaman.Test();

    delay(2000);
    Serial.println(saat1);
    Serial.println(dakika1);
    Serial.println(saat2);
    Serial.println(dakika2);
    //Serial.println(test);
    delay(2000);
*/
#endif 
