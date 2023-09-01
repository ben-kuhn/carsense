### CarSense

Please note: This project has not seen any active development since about 2013.  Various versions of the code were written from 2010-2013 to add various features or to experiment.  Commercial data loggers became widely availabe and popular by 2014 or 2015 and this was replaced with a commercial unit.  This project is on GitHub for archival purposes and in case anyone may find the code interesting or useful.  Some of the display libraries, or the library to access the thermal sensors may still be of interest.

This project was used to gather tire temperature data from I2C IR thermal sensors during test laps on a super late model cirlce-track race car.  This data was used to make adjustments to the suspension for optimal grip and cornering.

The hardware consisted of 3 sensors for each front tire to monitor the outer, middle, and inner third of the tire.  The rear tire had a single sensor monitoring the entire tire.  Nokia phone displays were used to watch the data real-time during a test lap, or were included in-frame of a dash cam for reference.  Data was also written to SD cards and converted in to RRD graphs.  There is also a Raspberry Pi (1) version in this repo used in conjunction with the RPi camera, complete with a patched kernel to work around some of the I2C limitations present on that hardware.