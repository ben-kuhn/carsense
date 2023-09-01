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
#include <i2cmaster.h>
#include <mlx90614.h>

#define LEFT_SCE   7  // LCD CS  .... Pin 3
#define LEFT_RESET 6  // LCD RST .... Pin 1
#define LEFT_DC    5  // LCD Dat/Com. Pin 5
#define LEFT_SDIN  4  // LCD SPIDat . Pin 6
#define LEFT_SCLK  3  // LCD SPIClk . Pin 4
#define LEFT_PWM   32 // LCD Power .. Pin 32


#define RIGHT_SCE   12  // LCD CS  .... Pin 3
#define RIGHT_RESET 11  // LCD RST .... Pin 1
#define RIGHT_DC    10  // LCD Dat/Com. Pin 5
#define RIGHT_SDIN  9  // LCD SPIDat . Pin 6
#define RIGHT_SCLK  8  // LCD SPIClk . Pin 4
#define RIGHT_PWM   33 // LCD Power -- Pin 33

// Instanciate displays
nokia5110 LeftDisplay(LEFT_SCE, LEFT_RESET, LEFT_DC, LEFT_SDIN, LEFT_SCLK);
nokia5110 RightDisplay(RIGHT_SCE, RIGHT_RESET, RIGHT_DC, RIGHT_SDIN, RIGHT_SCLK);

//Instanciate sensors
//Left front
mlx90614 LFOutside(0x50<<1);
mlx90614 LFCenter(0x51<<1);
mlx90614 LFInside(0x52<<1);

//Right Front
mlx90614 RFOutside(0x55<<1);
mlx90614 RFCenter(0x56<<1);
mlx90614 RFInside(0x57<<1);

char tempBuffer[16]; //Buffer needed for float to String conversion

void setup(void)
{
  pinMode(LEFT_PWM, OUTPUT);
//  pinMode(RIGHT_PWM, OUTPUT);
  digitalWrite(LEFT_PWM, HIGH);
 // digitalWrite(RIGHT_PWM, HIGH);
  // Set up displays
  LeftDisplay.LcdInitialise();
  LeftDisplay.LcdClear();
  RightDisplay.LcdInitialise();
  RightDisplay.LcdClear();
}

void loop(void)
{
  // Draw borders
  LeftDisplay.drawLine();
  RightDisplay.drawLine();
//  RightDisplay.drawLine();

  // Left Display
  LeftDisplay.gotoXY(2,1);
  LeftDisplay.LcdString("Left Front"); //Title
  
  // Left Sensor data
  LeftDisplay.gotoXY(5,2);
  LeftDisplay.LcdString("O:  ");
  LeftDisplay.gotoXY(15,2);
  LeftDisplay.LcdString(dtostrf(LFOutside.ReadTemp('F'), 6, 2, tempBuffer));
  LeftDisplay.gotoXY(5,3);
  LeftDisplay.LcdString("C:  ");
  LeftDisplay.gotoXY(15,3);
  LeftDisplay.LcdString(dtostrf(LFCenter.ReadTemp('F'), 6, 2, tempBuffer));
  LeftDisplay.gotoXY(5,4);
  LeftDisplay.LcdString("I:  ");
  LeftDisplay.gotoXY(15,4);
  LeftDisplay.LcdString(dtostrf(LFInside.ReadTemp('F'), 6, 2, tempBuffer));

  //Right Display
  RightDisplay.gotoXY(2,1);
  RightDisplay.LcdString("Right Front"); //Title
  
  // Left Sensor data
  RightDisplay.gotoXY(5,2);
  RightDisplay.LcdString("O:  ");
  RightDisplay.gotoXY(15,2);
  RightDisplay.LcdString(dtostrf(RFInside.ReadTemp('F'), 6, 2, tempBuffer));
  RightDisplay.gotoXY(5,3);
  RightDisplay.LcdString("C:  ");
  RightDisplay.gotoXY(15,3);
  RightDisplay.LcdString(dtostrf(RFCenter.ReadTemp('F'), 6, 2, tempBuffer));
  RightDisplay.gotoXY(5,4);
  RightDisplay.LcdString("I:  ");
  RightDisplay.gotoXY(15,4);
  RightDisplay.LcdString(dtostrf(RFOutside.ReadTemp('F'), 6, 2, tempBuffer));
  
  delay(1000);
 }