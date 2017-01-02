# HARDWARE ORGANISATION
Here are hardware's files for the windlogger project.

## BLOCK DIAGRAM
![windlogger project block diagram](/Hardware/diagram.png)

Green : it's working
Yellow : Work in progress
Red : Need to be implement

The differents signals from the sensors are adapted on the shield board to be accepted by the micro controller (between 0 and 5V).
All data are timestamped at each measure and can be save on the SD card or transmit on a serial interface.
Transmitter like the ESP-01 or ESP-12 wifi module can be use like a serial to wifi converter to send data on the web.
Transmitter like M590E or A gprs module, with a sim card, can be use like a serial to gprs converter.

###Enclosure
We have choose the UnioBox66 in 132*120mm format to receive our project, e.g. Enclosure folder.

Work is under development and lot's of function need to be implemented.