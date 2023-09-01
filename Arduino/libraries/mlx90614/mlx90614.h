/*
  mlx90614.h - Library for grabbing the temperature from MLX90614
  I2C temperature sensors
*/
#ifndef mlx90614_h
#define mlx90614_h

#include "Arduino.h"

class mlx90614
{
  public:
  	mlx90614(byte Address);
    float ReadTemp(char unit);
  private:
    byte _Address;
    int _data_low;
    int _data_high;
    int _pec;
    float Temperature;
    char _unit;
};

#endif