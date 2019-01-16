#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H
#include <Arduino.h>
// Assign output variables to GPIO pins

//#define LOGIC_INVERTED

const int outputR = 15;
const int outputG = 13;
const int outputB = 12;

class ledControllerClass {
private:
  int ledState[4] = {LOW, LOW, LOW, LOW};
  unsigned long lastTime[4];
  uint16_t counter[4] = {0,0,0,0};
public:
  void begin();
  void setLedR(uint8_t status, bool blinkStatus);
  void setLedG(uint8_t status, bool blinkStatus);
  void setLedB(uint8_t status, bool blinkStatus);
  void setLedY(uint8_t status, bool blinkStatus);

  void blinkLedR(unsigned long interval, uint16_t repetitions);
  void blinkLedG(unsigned long interval, uint16_t repetitions);
  void blinkLedB(unsigned long interval, uint16_t repetitions);
  void blinkLedY(unsigned long interval, uint16_t repetitions);
};
extern ledControllerClass ledController;
#endif
