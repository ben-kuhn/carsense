/*
nokia5110.h
This file contains the functions and data required
to drive several Nokia 5110 LCD displays.
*/


#ifndef nokia5110_h
#define nokia5110_h

#include "Arduino.h"

class nokia5110
{
  public:
    nokia5110(int SCE, int RESET, int DC, int SDIN, int SCLK);
    void drawLine();
    void gotoXY(int x, int y);
    void LcdWrite(byte dc, byte data);
    void LcdClear();
    void LcdString(char *charachters);
    void LcdCharacter(char charachter);
    void LcdInitialise();
    
  private:
    int _SCE;
    int _RESET;
    int _DC;
    int _SDIN;
    int _SCLK;
};
  
#endif