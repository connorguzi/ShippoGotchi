#include "display.h"
#include "duckies.h"
#include "poodle_cry.h"
#include "poodle_heart.h"
#include "poodle_sad.h"
#include "poodle_happy.h"

int last_motive = 0;
const unsigned short *poodles[] = {poodle_cry, poodle_sad, poodle_happy, poodle_heart};

static int sent_msgs = 0;

bool displayedMsg = false;

TFT_eSPI tft = TFT_eSPI(); 
TFT_eSprite shippoSprite= TFT_eSprite(&tft);
TFT_eSprite background= TFT_eSprite(&tft);
TFT_eSprite txtSprite= TFT_eSprite(&tft);
TFT_eSprite selectorSprite = TFT_eSprite(&tft);

TFT_eSprite msgSprite = TFT_eSprite(&tft);

String display_strings[] = {"Love You!", "Miss You!", "Duckies", "Motivation", "Kisses", "Poopies"};
String motivation_strings[] = {"It's a ruff day not a ruff life!", "You're doing great today baby", "Keep on pushing!!"};
String rec_strings[] =  {"I love you baby", "Missing you :((", "Duckies", "Motivation", "MUAHH", "Taking a phat poopies rn"};

static int shippoSelector();

void displayInit() {
    tft.init();
    tft.setRotation(1);
    tft.setSwapBytes(true);
    
    background.createSprite(320,170);
    background.setSwapBytes(true);
    selectorSprite.createSprite(170, 20);
    selectorSprite.setSwapBytes(true);
    msgSprite.createSprite(320, 170);
    msgSprite.setTextColor(TFT_WHITE, TFT_DARKGREEN);
    msgSprite.setSwapBytes(true);
    shippoSprite.createSprite(96,96);
    // shippoSprite.setSwapBytes(true);
    txtSprite.createSprite(320,170);
    txtSprite.setTextColor(TFT_WHITE,TFT_BLACK);

}


void updateDisplay(int ind){
    background.fillSprite(TFT_BLACK);
    txtSprite.fillSprite(TFT_BLACK);
    selectorSprite.fillSprite(TFT_BLUE);
    for(int i = 0; i < 6; i++){
        txtSprite.drawString(display_strings[i],0,i * 20,2);
    }

    shippoSprite.pushImage(0,0,100,100,poodles[shippoSelector()]);
    selectorSprite.pushToSprite(&background, 0, 30 + ind * 20  );

    shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
    txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
    
    background.pushSprite(0,0);


}

void updateCount(){
    sent_msgs++;
}

void resetCount(){
    sent_msgs = 0;
}

bool messageDisplayed(){
    return displayedMsg;
}

void changeDisplay(){
    displayedMsg = false;
}

// void displayMsg(String str){
//     displayedMsg = true;
//     background.fillSprite(TFT_DARKGREEN);
//     msgSprite.fillSprite(TFT_DARKGREEN);

//     if(str.compareTo("Duckies") == 0){
//         msgSprite.pushImage(0, 0, 130, 130, duckies);
//         msgSprite.pushToSprite(&background, 95, 20);
//     }
//     else{
//         msgSprite.drawString(str, 0, 0, 2);
//         msgSprite.pushToSprite(&background, 100, 85);

//     }
//     background.pushSprite(0,0);
    
// }

void displayMsg(int str){
    displayedMsg = true;
    msgSprite.fillSprite(TFT_DARKGREEN);
    background.fillSprite(TFT_DARKGREEN);
    // msgSprite.unloadFo;
    if(str == 2){
        msgSprite.pushImage(0, 0, 130, 130, duckies);
        msgSprite.pushToSprite(&background, 95, 20);
    }
    else if (str == 3){
        msgSprite.drawString(motivation_strings[last_motive], 0, 0, 2);
        msgSprite.pushToSprite(&background, 100, 85);
        last_motive = (last_motive + 1) % 3;
    }
    else{
        msgSprite.drawString(rec_strings[str], 0, 0, 2);
        msgSprite.pushToSprite(&background, 100, 85);

    }
    background.pushSprite(0,0);
}

void flashSelector(int ind){

    background.fillSprite(TFT_BLACK);
    txtSprite.fillSprite(TFT_BLACK);
    selectorSprite.fillSprite(0x047de0);
    for(int i = 0; i < 6; i++){
        txtSprite.drawString(display_strings[i],0,i * 20,2);
    }

    shippoSprite.pushImage(0,0,100,100,poodles[shippoSelector()]);
    selectorSprite.pushToSprite(&background, 0, 30 + ind * 20  );

    shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
    txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
    
    background.pushSprite(0,0);
    delay(250);
    background.fillSprite(TFT_BLACK);
    txtSprite.fillSprite(TFT_BLACK);
    selectorSprite.fillSprite(TFT_BLUE);
    for(int i = 0; i < 6; i++){
        txtSprite.drawString(display_strings[i],0,i * 20,2);
    }

    shippoSprite.pushImage(0,0,100,100,poodles[shippoSelector()]);
    selectorSprite.pushToSprite(&background, 0, 30 + ind * 20  );

    shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
    txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
    
    background.pushSprite(0,0);
    delay(250);
    background.fillSprite(TFT_BLACK);
    txtSprite.fillSprite(TFT_BLACK);
    selectorSprite.fillSprite(0x047de0);
    for(int i = 0; i < 6; i++){
        txtSprite.drawString(display_strings[i],0,i * 20,2);
    }

    shippoSprite.pushImage(0,0,100,100,poodles[shippoSelector()]);
    selectorSprite.pushToSprite(&background, 0, 30 + ind * 20  );

    shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
    txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
    
    background.pushSprite(0,0);
    delay(250);
    background.fillSprite(TFT_BLACK);
    txtSprite.fillSprite(TFT_BLACK);
    selectorSprite.fillSprite(TFT_BLUE);
    for(int i = 0; i < 6; i++){
        txtSprite.drawString(display_strings[i],0,i * 20,2);
    }

    shippoSprite.pushImage(0,0,100,100,poodles[shippoSelector()]);
    selectorSprite.pushToSprite(&background, 0, 30 + ind * 20  );

    shippoSprite.pushToSprite(&background,200,20,TFT_BLACK); 
    txtSprite.pushToSprite(&background,5,30,TFT_BLACK); 
    
    background.pushSprite(0,0);
}


static int shippoSelector(){
    if(sent_msgs < 2){
        return 0;
    }
    else if(sent_msgs < 4){
        return 1;
    }
    else if (sent_msgs < 6){
        return 2;
    }
    else{
        return 3;
    }
}
