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
NokiaLCD LeftDisplay(PIN_SCE, PIN_RESET, PIN_DC, PIN_SDIN, PIN_SCLK);

void setup(void)
{

}

void loop(void)
{
  // Display some simple character animation
  //
  int a,b;
  char Str[15];
  // Draw a Box
  for(b=1000; b>0; b--){
  LeftDisplay.drawBorderBox();
  for(a=0; a<=5 ; a++){
  LeftDisplay.gotoXY(2,1);
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
  // Draw + at this position
  LeftDisplay.gotoXY(10,3);
  LeftDisplay.LcdCharacter('=');
  delay(250);
  LeftDisplay.gotoXY(24,3);
  LeftDisplay.LcdCharacter('h');
  LeftDisplay.LcdCharacter('e');
  LeftDisplay.LcdCharacter('l');
  LeftDisplay.LcdCharacter('l');
  LeftDisplay.LcdCharacter('o');
  LeftDisplay.LcdCharacter(' ');
  LeftDisplay.LcdCharacter('-');
  // Draw - at this position
  LeftDisplay.gotoXY(10,3);
  LeftDisplay.LcdCharacter('-');
  delay(250);
  }
  }
}