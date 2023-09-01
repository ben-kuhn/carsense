/*
This Code has extra features 
including a XY positioning function on Display
and a Line Draw function on Nokia 3310 LCD 
It is modded from the original 
http://www.arduino.cc/playground/Code/PCD8544
*/
// Mods by Jim Park 
// jim(^dOt^)buzz(^aT^)gmail(^dOt^)com
// hope it works for you
#include <nokia5110.h>

#define PIN_SCE   7  // LCD CS  .... Pin 3
#define PIN_RESET 6  // LCD RST .... Pin 1
#define PIN_DC    5  // LCD Dat/Com. Pin 5
#define PIN_SDIN  4  // LCD SPIDat . Pin 6
#define PIN_SCLK  3  // LCD SPIClk . Pin 4
                     // LCD Gnd .... Pin 2
                     // LCD Vcc .... Pin 8
                     // LCD Vlcd ... Pin 7

#define PIN2_SCE   12  // LCD CS  .... Pin 3
#define PIN2_RESET 11  // LCD RST .... Pin 1
#define PIN2_DC    10  // LCD Dat/Com. Pin 5
#define PIN2_SDIN  9  // LCD SPIDat . Pin 6
#define PIN2_SCLK  8  // LCD SPIClk . Pin 4
                     // LCD Gnd .... Pin 2
                     // LCD Vcc .... Pin 8
                     // LCD Vlcd ... Pin 7

nokia5110 LeftDisplay(PIN_SCE, PIN_RESET, PIN_DC, PIN_SDIN, PIN_SCLK);
nokia5110 RightDisplay(PIN2_SCE, PIN2_RESET, PIN2_DC, PIN2_SDIN, PIN2_SCLK);

void setup(void)
{
  LeftDisplay.LcdInitialise();
  LeftDisplay.LcdClear();
  RightDisplay.LcdInitialise();
  RightDisplay.LcdClear();
}

void loop(void)
{
  // Display some simple character animation
  //
  int a,b;
  char Str[15];
  // Draw a Box
  for(b=1000; b>0; b--){
  LeftDisplay.drawLine();
  RightDisplay.drawLine();
  for(a=0; a<=5 ; a++){
  LeftDisplay.gotoXY(2,1);
  RightDisplay.gotoXY(2,1);
  // Put text in Box
  LeftDisplay.LcdString ("Left Front");
  LeftDisplay.gotoXY(24,3);
  LeftDisplay.LcdCharacter('H');
  LeftDisplay.LcdCharacter('E');
  LeftDisplay.LcdCharacter('L');
  LeftDisplay.LcdCharacter('L');
  LeftDisplay.LcdCharacter('O');
  LeftDisplay.LcdCharacter(' ');
  LeftDisplay.LcdCharacter('=');
  RightDisplay.LcdString ("Right Front");
  RightDisplay.gotoXY(24,3);
  RightDisplay.LcdCharacter('H');
  RightDisplay.LcdCharacter('E');
  RightDisplay.LcdCharacter('L');
  RightDisplay.LcdCharacter('L');
  RightDisplay.LcdCharacter('O');
  RightDisplay.LcdCharacter(' ');
  RightDisplay.LcdCharacter('=');
  // Draw + at this position
  LeftDisplay.gotoXY(10,3);
  LeftDisplay.LcdCharacter('=');
  RightDisplay.gotoXY(10,3);
  RightDisplay.LcdCharacter('=');
  delay(250);
  
  LeftDisplay.gotoXY(24,3);
  LeftDisplay.LcdCharacter('h');
  LeftDisplay.LcdCharacter('e');
  LeftDisplay.LcdCharacter('l');
  LeftDisplay.LcdCharacter('l');
  LeftDisplay.LcdCharacter('o');
  LeftDisplay.LcdCharacter(' ');
  LeftDisplay.LcdCharacter('-');
  RightDisplay.gotoXY(24,3);
  RightDisplay.LcdCharacter('h');
  RightDisplay.LcdCharacter('e');
  RightDisplay.LcdCharacter('l');
  RightDisplay.LcdCharacter('l');
  RightDisplay.LcdCharacter('o');
  RightDisplay.LcdCharacter(' ');
  RightDisplay.LcdCharacter('-');
  // Draw - at this position
  LeftDisplay.gotoXY(10,3);
  LeftDisplay.LcdCharacter('-');
  RightDisplay.gotoXY(10,3);
  RightDisplay.LcdCharacter('-');
  delay(250);
  }
  }
}