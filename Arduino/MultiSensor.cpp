#include <i2cmaster.h>
#include <mlx90614.h>

// Pins: Standard: SDA:A4  SCL:A5
//       Mega:     SDA:D20 SCL:D21

//Instanciate sensors
//Left front
mlx90614 LFOutside(0x50<<1);
mlx90614 LFCenter(0x51<<1);
mlx90614 LFInside(0x52<<1);

//Right Front
mlx90614 RFOutside(0x55<<1);
mlx90614 RFCenter(0x56<<1);
mlx90614 RFInside(0x57<<1);
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
    Serial.println(LFOutside.ReadTemp('F'));  //Print Left Front Outside temp
    Serial.print("Left Front Center:  ");
    Serial.println(LFCenter.ReadTemp('F'));   //Print Left Front Center temp
    Serial.print("Left Front Inside:  ");
    Serial.println(LFInside.ReadTemp('F'));   //Print Left Front Inside temp
    Serial.println();
    Serial.print("Right Front Outside:  ");
    Serial.println(RFOutside.ReadTemp('F'));  //Print Right Front Outside temp
    Serial.print("Right Front Center:  ");
    Serial.println(RFCenter.ReadTemp('F'));   //Print Right Front Center temp
    Serial.print("Right Front Inside:  ");
    Serial.println(RFInside.ReadTemp('F'));   //Print Right Front Inside temp
    Serial.println();
    epoch += 1;
    delay(1000); // wait 1 second
}

