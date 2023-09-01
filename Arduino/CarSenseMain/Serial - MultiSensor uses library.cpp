#include <i2cmaster.h>
#include <mlx90614.h>
// Pins: Standard: SDA:A4  SCL:A5
//       Mega:     SDA:D20 SCL:D21

byte LFOutside = 0x50<<1;           // Left Front Outside Tire sensor address
byte LFCenter = 0x51<<1;            // Left Front Center Tire sensor addresss
byte LFInside = 0x52<<1;            // Left Inside Center Tire sensor address
int epoch = 0;                       // Set the epoch to zero

MLX sensorbar;

void setup(){
  Serial.begin(9600);
  Serial.println("Setup...");
  delay(5000);                    // Wait to allow serial connection
}

void loop(){
    Serial.print("Time:  ");
    Serial.println(epoch);
    Serial.print("Left Front Outside:  ");
    Serial.println(sensorbar.ReadTemp(LFOutside));  //Print Left Front Outside temp
    Serial.print("Left Front Center:  ");
    Serial.println(sensorbar.ReadTemp(LFCenter));   //Print Left Front Center temp
    Serial.print("Left Front Inside:  ");
    Serial.println(sensorbar.ReadTemp(LFInside));   //Print Left Front Inside temp
    Serial.println();
    epoch += 1;
    delay(1000); // wait 1 second
}