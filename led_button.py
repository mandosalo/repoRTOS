#!/usr/bin/python3
import wiringpi as wpi
from time import sleep

print("Starting the Python wiringPi example")
wpi.wiringPiSetupGpio()
wpi.pinMode(2,1)
wpi.pinMode(22,0)

while wpi.digitalRead(22)==0:
    wpi.digitalWrite(2,1)
    sleep(0.1)
    wpi.digitalWrite(2,0)
    sleep(0.1)

print("Button pressed: end of example")
