/*
DisplayTemps.cpp
Attempts to display the output from 3 sensors
to the Nokia diplay attached to pins 3-7
Hopefully we have enough power on the 3.3v
output pin ;)
*/

#include <i2cmaster.h> //Modified I2C Library for sensors
#include <nokia5110.h> //Library for writing to the displays
#include <mlx90614.h>  //Library for the sensors

//LCD setup code follows:

#define LEFT_PIN_SCE   7   // LCD CS  .... Pin 3
#define LEFT_PIN_RESET 6   // LCD RST .... Pin 1
#define LEFT_PIN_DC    5   // LCD Dat/Com. Pin 5
#define LEFT_PIN_SDIN  4   // LCD SPIDat . Pin 6
#define LEFT_PIN_SCLK  3   // LCD SPIClk . Pin 4

#define RIGHT_PIN_SCE   12  // LCD CS  .... Pin 3
#define RIGHT_PIN_RESET 11  // LCD RST .... Pin 1
#define RIGHT_PIN_DC    10  // LCD Dat/Com. Pin 5
#define RIGHT_PIN_SDIN  9   // LCD SPIDat . Pin 6
#define RIGHT_PIN_SCLK  8   // LCD SPIClk . Pin 4

char tempBuffer[16]; // Char array used as a buffer to convert float to string

//Sensor setup code follows

byte LFOutside = 0x50<<1;           // Left Front Outside Tire sensor address
byte LFCenter = 0x51<<1;            // Left Front Center Tire sensor addresss
byte LFInside = 0x52<<1;            // Left Inside Center Tire sensor address
int epoch = 0;                      // Set the epoch to zero

void setup(void)
{

 // Left LCD Initilization

 LcdInitialise(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK); // Set up LCD
 LcdClear(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK);	  // Clear LCD

// Sensor Initialization

i2c_init();                              //Initialise the i2c bus
PORTC = (1 << PORTC4) | (1 << PORTC5);   //enable pullups
delay(250);								 //Let the I2C bus settle

}

void loop(void)  // And the fun begins...
{
  int a,b;
  char Str[15];
  // Draw a Border
  drawBorderBox(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK);
  logLeftFront();
  logRightFront();
  epoch += 1; //increment the seconds counter
  delay(1000);  //wait for next cycle

}

void logLeftFront(void)
{
  // Print the header
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, "Left Front");
  //Left Outside
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 5,2);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, "O: ");
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 20,2);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, dtostrf(ReadTemp(LFOutside), 6, 2, tempBuffer));
  //Left Center
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 5,3);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, "C:  ");
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 20,3);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, dtostrf(ReadTemp(LFCenter), 6, 2, tempBuffer));
  //Left Inside
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 5,4);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, "I:  ");
  gotoXY(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, 20,4);
  LcdString(LEFT_PIN_SCE, LEFT_PIN_RESET, LEFT_PIN_DC, LEFT_PIN_SDIN, LEFT_PIN_SCLK, dtostrf(ReadTemp(LFInside), 6, 2, tempBuffer));
}

void logRightFront(void)
{
  // Print the header
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK, "Right Front");
  //Left Outside
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,5,2);
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,"O: ");
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,20,2);
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK, dtostrf(ReadTemp(LFInside), 6, 2, tempBuffer));
  //Left Center
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,5,3);
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,"C:  ");
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,20,3);
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK, dtostrf(ReadTemp(LFCenter), 6, 2, tempBuffer));
  //Left Inside
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,5,4);
  LcdString(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,"I:  ");
  gotoXY(RIGHT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK,20,4);
  LcdString(LEFT_PIN_SCE, RIGHT_PIN_RESET, RIGHT_PIN_DC, RIGHT_PIN_SDIN, RIGHT_PIN_SCLK, dtostrf(ReadTemp(LFOutside), 6, 2, tempBuffer));

}