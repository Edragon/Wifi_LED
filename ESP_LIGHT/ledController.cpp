#include "ledController.h"

void ledControllerClass::begin()
{
  //SET LEDS PIN AS OUTPUT
  // pinMode(outputR, OUTPUT);
  // pinMode(outputG, OUTPUT);
  // pinMode(outputB, OUTPUT);
  #ifdef LOGIC_INVERTED
  // Set  LEDS outputs to HIGH
  analogWrite(outputR, 255);
  analogWrite(outputG, 255);
  analogWrite(outputB, 255);
  #else
  // Set  LEDS outputs to LOW
  analogWrite(outputR, 0);
  analogWrite(outputG, 0);
  analogWrite(outputB, 0);
  #endif
}

void ledControllerClass::setLedR(uint8_t status, bool blinkStatus )
{
  if (!blinkStatus)
  {
    #ifdef LOGIC_INVERTED
    status = !status;
    #endif
    // digitalWrite(outputR, status);
    int light = 0;
    if (status == 1)
    {
      light = 255;
    }else{
      light = 0;
    }
    analogWrite(outputR, light);
  }
}

void ledControllerClass::setLedG(uint8_t status, bool blinkStatus)
{
  if (!blinkStatus)
  {
    #ifdef LOGIC_INVERTED
    status = !status;
    #endif
    // digitalWrite(outputG, status);
    int light = 0;
    if (status == 1)
    {
      light = 255;
    }else{
      light = 0;
    }
    analogWrite(outputG, light);
  }
}

void ledControllerClass::setLedB(uint8_t status, bool blinkStatus)
{
  if (!blinkStatus)
  {
    #ifdef LOGIC_INVERTED
    status = !status;
    #endif
    // digitalWrite(outputB, status);
    int light = 0;
    if (status == 1)
    {
      light = 255;
    }else{
      light = 0;
    }
    analogWrite(outputB, light);
  }
}

void ledControllerClass::setLedY(uint8_t status, bool blinkStatus)
{
  if (!blinkStatus)
  {
    #ifdef LOGIC_INVERTED
    status = !status;
    #endif
    int light = 0;
    if (status == 1)
    {
      light = 255;
    }else{
      light = 0;
    }
    analogWrite(outputR, light);
    analogWrite(outputG, light);
    // digitalWrite(outputR, status);
    // digitalWrite(outputG, status);
  }
}



void ledControllerClass::blinkLedR(unsigned long interval, uint16_t repetitions)
{
  unsigned long now = millis();
  if (now - lastTime[0] >= interval)
  {
    lastTime[0] = now;
    if (ledState[0] == LOW) {
      ledState[0] = 255;
    } else {
      ledState[0] = 0;
    }
    analogWrite(outputR, ledState[0]);
  }
}

void ledControllerClass::blinkLedG(unsigned long interval, uint16_t repetitions)
{
  unsigned long now = millis();
  if (now - lastTime[1] >= interval)
  {
    lastTime[1] = now;
    if (ledState[1] == LOW) {
      ledState[1] = 255;
    } else {
      ledState[1] = 0;
    }
    analogWrite(outputG, ledState[1]);
  }
}

void ledControllerClass::blinkLedB(unsigned long interval, uint16_t repetitions)
{
  unsigned long now = millis();
  if (now - lastTime[2] >= interval)
  {
    lastTime[2] = now;
    if (ledState[2] == LOW) {
      ledState[2] = 255;
    } else {
      ledState[2] = 0;
    }
    analogWrite(outputB, ledState[2]);
  }
}

void ledControllerClass::blinkLedY(unsigned long interval, uint16_t repetitions)
{
  unsigned long now = millis();
  if (now - lastTime[3] >= interval)
  {
    lastTime[3] = now;
    if (ledState[3] == LOW) {
      ledState[3] = HIGH;
      analogWrite(outputR, 210);
      analogWrite(outputG, 250);
      analogWrite(outputB, 0.01);
    } else {
      ledState[3] = LOW;
      analogWrite(outputR, 0);
      analogWrite(outputG, 0);
      analogWrite(outputB, 0);
    }
    // digitalWrite(outputR, ledState[3]);
    // digitalWrite(outputG, ledState[3]);
  }
}

ledControllerClass ledController;
