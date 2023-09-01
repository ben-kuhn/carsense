#include <i2cmaster.h>
// Pins: Standard: SDA:A4  SCL:A5
//       Mega:     SDA:D20 SCL:D21

byte LFOutside = 0x50<<1;           // Left Front Outside Tire sensor address
byte LFCenter = 0x51<<1;            // Left Front Center Tire sensor addresss
byte LFInside = 0x52<<1;            // Left Inside Center Tire sensor address
int epoch = 0;                       // Set the epoch to zero


void setup(){
  Serial.begin(9600);
  Serial.println("Setup...");
  
  i2c_init();                              //Initialise the i2c bus
  PORTC = (1 << PORTC4) | (1 << PORTC5);   //enable pullups
  
  delay(5000);                    // Wait to allow serial connection
}

void loop(){
    Serial.print("Time:  ");
    Serial.println(epoch);
    Serial.print("Left Front Outside:  ");
    Serial.println(ReadTemp(LFOutside));  //Print Left Front Outside temp
    Serial.print("Left Front Center:  ");
    Serial.println(ReadTemp(LFCenter));   //Print Left Front Center temp
    Serial.print("Left Front Inside:  ");
    Serial.println(ReadTemp(LFInside));   //Print Left Front Inside temp
    Serial.println();
    epoch += 1;
    delay(1000); // wait 1 second
}

float ReadTemp(byte Address) {
  int data_low = 0;
  int data_high = 0;
  int pec = 0;

  i2c_start_wait(Address + I2C_WRITE);
  i2c_write(0x07);                  // Address of temp bytes
  
  // read
  i2c_rep_start(Address + I2C_READ);
  data_low = i2c_readAck();         //Read 1 byte and then send ack
  data_high = i2c_readAck();        //Read 1 byte and then send ack
  pec = i2c_readNak();
  i2c_stop();
  
  //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
  float Temperature = 0x0000;       // zero out the data
  
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  Temperature = (float)(((data_high & 0x007F) << 8) + data_low);
  Temperature = (Temperature * 0.02) - 273.16;

  //This converts the temperature to something we Americans can understand.
  Temperature = (Temperature * 1.8) + 32;
  
//  Serial.print(Temperature);
//  Serial.println(" C");
  return Temperature;
}