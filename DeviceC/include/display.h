#include "TFT_eSPI.h"

#ifndef DISPLAY_H
#define DISPLAY_H

// Setup for the display
void displayInit();

// void displayMsg(String str);
void displayMsg(int str);


void updateDisplay(int index);

void updateCount();
void resetCount();

bool messageDisplayed();
void changeDisplay();

void flashSelector(int ind);

#endif