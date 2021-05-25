<p align="center">
	<img src="http://content.arduino.cc/brand/arduino-color.svg" width="50%" />
</p>

Arduino is an open-source physical computing platform based on a simple I/O
board and a development environment that implements the Processing/Wiring
language. Arduino can be used to develop stand-alone interactive objects or
can be connected to software on your computer (e.g. Flash, Processing and MaxMSP).
The boards can be assembled by hand or purchased preassembled; the open-source
IDE can be downloaded for free at [https://arduino.cc](https://www.arduino.cc/en/Main/Software)


# Parking sensor arduino project


- [Tinkercad link](https://www.tinkercad.com/embed/dj0SsiJUyb4?editbtn=1)


## Circuit 

![circuit](https://i.postimg.cc/wTLS3NQK/circuit.png)

## How it works

- The HC-SR04 Ultrasonic (US) sensor is a 4 pin module, that measures the distance (between itself and an obstacle) by multiplying the time an ultrasonic wave, sent by the transmitter, takes to reach the reciever.

**Distance = Speed x Time**

- Based on the measured distance, one of the light-emitting diodes (LED) will light up, visually representing the distance (BLUE meaning far, YELLOW meaning close, ORANGE meaning closer and you can guess what RED does).

- Following the LED representation, the distance is also printed to the user on a LCD display, which is connected to another arduino microcontroller, which is connected to the main arduino board via analog A4 and A5 pins.

- The buzzer will also play a tone at 500hz for 100ms, but will be delayed (thus creating a parking-sensor-like sound) according to the distance 'zone' it measured from the obstacle.







