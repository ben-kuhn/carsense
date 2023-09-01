/*
This library contains the function needed to grab the temperature
from an MLX90614 I2C Temperature Sensor.
*/
#include <i2cmaster.h>
#include "Arduino.h"
#include "mlx90614.h"

mlx90614::mlx90614(byte Address)
{
  i2c_init();                              //Initialise the i2c bus
  //PORTC = (1 << PORTC4) | (1 << PORTC5);   //enable pullups
  _Address = Address;
}

float mlx90614::ReadTemp(char unit) // Grab data from the sensors
{
  _data_low = 0;
  _data_high = 0;
  _pec = 0;

  i2c_start_wait(_Address + I2C_WRITE);
  i2c_write(0x07);                  // Address of temp bytes
  
  // read
  i2c_rep_start(_Address + I2C_READ);
  _data_low = i2c_readAck();         //Read 1 byte and then send ack
  _data_high = i2c_readAck();        //Read 1 byte and then send ack
  _pec = i2c_readNak();
  i2c_stop();
  
  //This converts high and low bytes together and processes temperature, MSB is a error bit and is ignored for temps
  Temperature = 0x0000;       // zero out the data
  
  // This masks off the error bit of the high byte, then moves it left 8 bits and adds the low byte.
  Temperature = (float)(((_data_high & 0x007F) << 8) + _data_low);

  if (unit == 'F')
    return (((Temperature * 0.02) -273.16) * 1.8) + 32; //Farenheight
  else if (unit == 'C')
    return (Temperature * 0.02) - 273.16; //Celcius
  else 
    return (Temperature * 0.02); //Kelvin (sensor default)

}