#include <Arduino.h>
#include "awsC.h"
#include "OneButton.h"
#include "TFT_eSPI.h"
#include "pin_config.h"
#include "display.h"


#define AWS_TEST 0
#define SPRITE_TEST 0
#define MAIN 1

#define BUTTON_1 14
#define BUTTON_2 0

OneButton sendButton(BUTTON_1);
OneButton navButton(BUTTON_2);
String display_str[] = {"Love You!", "Miss You!", "Duckies", "Motivation", "Kisses", "Poopies"};
String motivation_str[] = {"It's a ruff day not a ruff life!", "You're doing great today baby", "Keep on pushing!!"};
// String send_str[] =  {"I love you baby", "Missing you :((", "Duckies", "Motivation", "MUAHH", "Taking a phat poopies rn"};
int send_str[] =  {0, 1, 2, 3, 4, 5};


#define GFX_DEV_DEVICE LILYGO_T_DISPLAY_S3
#define GFX_EXTRA_PRE_INIT()              \
    {                                     \
        pinMode(15 /* PWD */, OUTPUT);    \
        digitalWrite(15 /* PWD */, HIGH); \
    }

// MQTTClient Jclient = MQTTClient(256);

#if AWS_TEST
void setup() {
  Serial.begin(115200);
  Serial.println("Beginning WIFI Connection");
  CconnectAWS();
}

void loop() {
  // Serial.println("Yo");

  CpublishMessage();
  Cloop();
  delay(1000);
}
#endif


#if SPRITE_TEST


TFT_eSPI tft = TFT_eSPI(); 
TFT_eSprite shippoSprite= TFT_eSprite(&tft);
TFT_eSprite background= TFT_eSprite(&tft);
TFT_eSprite txtSprite= TFT_eSprite(&tft);
TFT_eSprite selectorSprite = TFT_eSprite(&tft);

void setup() {
  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  

  background.createSprite(320,170);
  background.setSwapBytes(true);
  selectorSprite.createSprite(150, 18);
  selectorSprite.setSwapBytes(true);
  shippoSprite.createSprite(96,96);
  // shippoSprite.setSwapBytes(true);
  txtSprite.createSprite(320,170);
  txtSprite.setTextColor(TFT_WHITE,TFT_BLACK);

}

void loop() {
  background.fillSprite(TFT_BLACK);
  txtSprite.fillSprite(TFT_BLACK);
  selectorSprite.fillSprite(TFT_BLUE);
  txtSprite.drawString("Hello World",0,0,2);
  txtSprite.drawString("Another Test", 0, 15,2);

  shippoSprite.pushImage(0,0,100,100,poodle_heart);
  selectorSprite.pushToSprite(&background, 0, 29);

  shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
  txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
  
  background.pushSprite(0,0);
}

#endif

#if MAIN
void navClick();
void sendClick();

int ind = 0; // Index for selector

int sent_msgs = 0;

bool prev_disp = false;

void setup(){
  Serial.begin(115200);
  Serial.println("Beginning WIFI Connection");

  pinMode(BUTTON_1, INPUT_PULLUP);
  pinMode(BUTTON_2, INPUT_PULLUP);

  

  CconnectAWS();
  displayInit();
  updateDisplay(0);
  navButton.attachClick(navClick);
  sendButton.attachClick(sendClick);
}

void loop(){
  navButton.tick();
  sendButton.tick();
  Cloop();
  if(prev_disp != messageDisplayed()){
    prev_disp = messageDisplayed();
    // if(prev_disp == )
  }
  // updateDisplay(ind);
  // // delay(500);
  // ind = ind % 5;
}

void navClick(){
  if (messageDisplayed()){
    changeDisplay();
    updateDisplay(ind);
  }
  else{
    ind++;
    ind = ind % 6;
    updateDisplay(ind);
  }

}

void sendClick(){
  if (messageDisplayed()){
    changeDisplay();
    updateDisplay(ind);
  }
  else{
    sent_msgs++;
    updateCount();
    flashSelector(ind);
    CpublishMessage(send_str[ind]);
  } 
}
#endif