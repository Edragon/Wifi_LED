#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiManager.h>
#include "ledController.h"

ESP8266WebServer Webserver(80);

void OFF_ALL_BTN_FRONTED();
void OFF_ALL_LED_HW();
void ON_EACH_LED_HW(uint8_t currentState);
void ON_EACH_BTN(uint8_t actualBtn);
void SET_LEDS(uint8_t currentPin);
void BUTTONS_HTML_PAGE();


int redvalue = LOW;
int greenvalue = LOW;
int bluevalue = LOW;
int yellowvalue = LOW;

int redvalue2 = LOW;
int greenvalue2 = LOW;
int bluevalue2 = LOW;
int yellowvalue2 = LOW;

String btnStatus[9];
String ledStatus[9];

String statusLed ="ledOFF";
String HTMLpage = "";

String btn1 = "";
String btn2 = "";
String btn3 = "";
String btn4 = "";
String btn5 = "";
String btn6 = "";
String btn7 = "";
String btn8 = "";
String btn9 = "";

String footer = "";
int ledState = LOW;

unsigned long lastTime = 0;
void setup(void){

  HTMLpage += "<!DOCTYPE html><html>";
  HTMLpage += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">";
  HTMLpage += "<link rel=\"icon\" href=\"data:,\">";
  HTMLpage += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}";
  HTMLpage += ".button { background-color: #DA1038; border: none; color: white; padding: 16px 40px; width: 260px;";
  HTMLpage += "text-decoration: none; font-size: 16px; margin: 2px; cursor: pointer;}";
  HTMLpage += ".button2 {background-color: #17AB48; width: 260px; font-size: 16px;}</style></head>";
  HTMLpage += "<body><h1>Cronolaps Safety Flags</h1>";

  OFF_ALL_LED_HW();
  OFF_ALL_BTN_FRONTED();//button off state firstly
  BUTTONS_HTML_PAGE();
  footer = "</body></html>";

  ledController.begin();//ESP8266 RGB LED CONTROLLER
  Serial.begin(115200);//START SERIAL BEGIN

  WiFiManager wifiManager;
  wifiManager.autoConnect("CronolapsSafetyFlags");

  Serial.println("");
  Serial.print("Connected!!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266", WiFi.localIP())) {
    Serial.println("MDNS responder started");
  }

  Webserver.on("/", [](){
    SET_LEDS(0);
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
  });

  Webserver.on("/ledON", [](){//RED LED ON
    ON_EACH_BTN(1);
    ON_EACH_LED_HW(1);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(1);
    delay(1000);
  });


  Webserver.on("/ledOFF", [](){//RED LED OFF
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(2);
    delay(1000);
  });

  Webserver.on("/ledON2", [](){///ENABLE BLINK RED LED
    ON_EACH_BTN(2);
    ON_EACH_LED_HW(2);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(3);
    delay(1000);
  });

  Webserver.on("/ledOFF2", [](){//DISABLE BLINK RED LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(4);
    delay(1000);
  });

  Webserver.on("/ledON3", [](){//ENABLE GREEN LED
    ON_EACH_BTN(3);
    ON_EACH_LED_HW(3);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(5);
    delay(1000);
  });

  Webserver.on("/ledOFF3", [](){//DISABLE GREEN LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(6);
    delay(1000);
  });

  Webserver.on("/ledON4", [](){//ENABLE BLINK GREEN LED
    ON_EACH_BTN(4);
    ON_EACH_LED_HW(4);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(7);
    delay(1000);
  });

  Webserver.on("/ledOFF4", [](){//DISABLE BLINK GREEN LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(8);
    delay(1000);
  });

  Webserver.on("/ledON5", [](){//ENABLE BLUE LED
    ON_EACH_BTN(5);
    ON_EACH_LED_HW(5);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(9);
    delay(1000);
  });

  Webserver.on("/ledOFF5", [](){//DISABLE BLUE LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(10);
    delay(1000);
  });

  Webserver.on("/ledON6", [](){//ENABLE BLINK BLUE LED
    ON_EACH_BTN(6);
    ON_EACH_LED_HW(6);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(11);
    delay(1000);
  });

  Webserver.on("/ledOFF6", [](){//DISABLE BLINK BLUE LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(12);
    delay(1000);
  });

  Webserver.on("/ledON7", [](){//ENABLE YELLOW  LED
    ON_EACH_BTN(7);
    ON_EACH_LED_HW(7);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(13);
    delay(1000);
  });

  Webserver.on("/ledOFF7", [](){//DISABLE BLINK YELLOW LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(14);
    delay(1000);
  });
  Webserver.on("/ledON8", [](){//ENABLE YELLOW  LED
    ON_EACH_BTN(8);
    ON_EACH_LED_HW(8);
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(15);
    delay(1000);
  });


  Webserver.on("/ledOFF8", [](){//DISABLE BLINK YELLOW LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(16);
    delay(1000);
  });

  Webserver.on("/offAll", [](){//DISABLE BLINK YELLOW LED
    OFF_ALL_LED_HW();
    OFF_ALL_BTN_FRONTED();
    BUTTONS_HTML_PAGE();
    Webserver.send(200, "text/html", HTMLpage + btn1 + btn2 +  btn3 + btn4 +  btn5 + btn6 + btn7 + btn8 + btn9 + footer);
    SET_LEDS(0);
    delay(1000);
  });


  Webserver.begin();
  Serial.println("HTTP Webserver started");
}

void loop(void){
  Webserver.handleClient();
  if (redvalue2 == HIGH)ledController.blinkLedR(50,10);
  if (greenvalue2 == HIGH)ledController.blinkLedG(50,10);
  if (bluevalue2 == HIGH)ledController.blinkLedB(50,10);
  if (yellowvalue2 == HIGH)ledController.blinkLedY(50,10);
}

void OFF_ALL_BTN_FRONTED()
{
  btnStatus[0] = "\"button button\"";//RED BUTTON STATUS
  btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS
  btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS
  btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS
  btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS
  btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS
  btnStatus[6] = "\"button button\"";//BLUE BUTTON STATUS
  btnStatus[7] = "\"button button\"";//BLUE BLINK BUTTON STATUS
  btnStatus[8] = "\"button button\"";// OFF ALL LEDS
}

void ON_EACH_BTN(uint8_t actualBtn)
{
  switch (actualBtn) {
    case 1:
    btnStatus[0] = "\"button button2\"";//RED BUTTON STATUS = ON
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 2:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button2\"";//RED BLINK BUTTON STATUS = ON
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 3:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button2\"";//GREEN BUTTON STATUS = ON
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 4:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button2\"";//GREEN BLINK BUTTON STATUS = ON
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 5:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button2\"";//BLUE BUTTON STATUS = ON
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 6:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button2\"";//BLUE BLINK BUTTON STATUS = 0N
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 7:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = ON
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = OFF
    btnStatus[6] = "\"button button2\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;
    case 8:
    btnStatus[0] = "\"button button\"";//RED BUTTON STATUS = OFF
    btnStatus[1] = "\"button button\"";//RED BLINK BUTTON STATUS = OFF
    btnStatus[2] = "\"button button\"";//GREEN BUTTON STATUS = OFF
    btnStatus[3] = "\"button button\"";//GREEN BLINK BUTTON STATUS = OFF
    btnStatus[4] = "\"button button\"";//BLUE BUTTON STATUS = OFF
    btnStatus[5] = "\"button button\"";//BLUE BLINK BUTTON STATUS = 0N
    btnStatus[6] = "\"button button\"";//YELLOW BUTTON STATUS = OFF
    btnStatus[7] = "\"button button2\"";//YELLOW BLINK BUTTON STATUS = OFF
    btnStatus[8] = "\"button button\"";// OFF ALL LEDS
    break;

  }
}

void ON_EACH_LED_HW(uint8_t currentState)
{
  switch (currentState) {
    case 1:
    ledStatus[0] = "\"ledOFF\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 2:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledOFF2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 3:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledOFF3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 4:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledOFF4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 5:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledOFF5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 6:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledOFF6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 7:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledOFF7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
    case 8:
    ledStatus[0] = "\"ledON\"";//RED LED STATUS
    ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
    ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
    ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
    ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
    ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
    ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
    ledStatus[7] = "\"ledOFF8\"";//YELLOW BLINK LED STATUS
    ledStatus[8] = "\"offAll\"";
    break;
  }
}

void OFF_ALL_LED_HW()
{
  ledStatus[0] = "\"ledON\"";//RED LED STATUS
  ledStatus[1] = "\"ledON2\"";//RED BLINK LED STATUS
  ledStatus[2] = "\"ledON3\"";//GREEN LED STATUS
  ledStatus[3] = "\"ledON4\"";//GREEN BLINK LED STATUS
  ledStatus[4] = "\"ledON5\"";//BLUE LED STATUS
  ledStatus[5] = "\"ledON6\"";//BLUE BLINK LED STATUS
  ledStatus[6] = "\"ledON7\"";//YELLOW LED STATUS
  ledStatus[7] = "\"ledON8\"";//YELLOW BLINK LED STATUS
  ledStatus[8] = "\"offAll\"";
}

void SET_LEDS(uint8_t currentPin)
{
  switch (currentPin) {
    case 0:
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 1://TURN ON RED LED
    //TURN OFF ANY BLINK LED
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = HIGH;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(1, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, true);
    break;
    case 2://TURN OFF RED LED
    //TURN OFF ANY BLINK LED
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue2 = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 3://TURN ON BLINK RED LED
    //TURN ON BLINK LED STATUS
    redvalue2 = HIGH;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(1, true);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, true);
    break;
    case 4://TURN OFF BLINK RED LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;

    case 5://TURN ON GREEN LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;


    redvalue = LOW;
    greenvalue = HIGH;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(1, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, true);
    break;
    case 6://TURN OFF GREEN LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 7://TURN ON GREEN BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = HIGH;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, true);
    ledController.setLedB(0, false);
    ledController.setLedY(0, true);
    break;

    case 8://TURN OFF GREEN BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 9://TURN ON BLUE LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = HIGH;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(1, false);
    ledController.setLedY(0, true);
    break;
    case 10://TURN OFF BLUE LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 11://TURN ON BLUE BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = HIGH;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, true);
    ledController.setLedY(0, true);
    break;

    case 12://TURN OFF BLUE BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 13://TURN ON YELLOW LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = HIGH;

    ledController.setLedR(0, true);
    ledController.setLedG(0, true);
    ledController.setLedB(0, false);
    ledController.setLedY(1, false);
    break;
    case 14://TURN OFF YELLOW LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
    case 15://TURN ON YELLOW BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = HIGH;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, true);
    ledController.setLedG(0, true);
    ledController.setLedB(0, false);
    ledController.setLedY(0, true);
    break;

    case 16://TURN OFF YELLOW BLINK LED
    //TURN ON BLINK LED STATUS
    redvalue2 = LOW;
    greenvalue2 = LOW;
    bluevalue2 = LOW;
    yellowvalue2 = LOW;

    redvalue = LOW;
    greenvalue = LOW;
    bluevalue = LOW;
    yellowvalue = LOW;

    ledController.setLedR(0, false);
    ledController.setLedG(0, false);
    ledController.setLedB(0, false);
    ledController.setLedY(0, false);
    break;
  }

}

void BUTTONS_HTML_PAGE()
{
  btn1 = "<p><a href="+ ledStatus[0] +"><button class =" +  btnStatus[0] + ">RED</button></a></p>";
  btn2 = "<p><a href="+ ledStatus[1] +"><button class =" +  btnStatus[1] + ">RED BLINK</button></a></p>";
  btn3 = "<p><a href="+ ledStatus[2] +"><button class =" +  btnStatus[2] + ">GREEN</button></a></p>";
  btn4 = "<p><a href="+ ledStatus[3] +"><button class =" +  btnStatus[3] + ">GREEN BLINK</button></a></p>";
  btn5 = "<p><a href="+ ledStatus[4] +"><button class =" +  btnStatus[4] + ">BLUE</button></a></p>";
  btn6 = "<p><a href="+ ledStatus[5] +"><button class =" +  btnStatus[5] + ">BLUE BLINK</button></a></p>";
  btn7 = "<p><a href="+ ledStatus[6] +"><button class =" +  btnStatus[6] + ">YELLOW</button></a></p>";
  btn8 = "<p><a href="+ ledStatus[7] +"><button class =" +  btnStatus[7] + ">YELLOW BLINK</button></a></p>";
  btn9 = "<p><a href="+ ledStatus[8] +"><button class =" +  btnStatus[8] + ">OFF</button></a></p>";
}
