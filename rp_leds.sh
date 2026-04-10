#!/bin/bash


# Con !/bin/bash, le informamos al sistema operativo
# cual es el intérprete de comandos
# I@res 20-abril-2023

number=20  # numero de veces a realizar el ciclo

# Apertura de GPIOS: 2,3,4
sudo echo 2 > /sys/class/gpio/export
sudo echo 3 > /sys/class/gpio/export
sudo echo 4 > /sys/class/gpio/export

#define los gpios 2,3,4 como salida
echo out > /sys/class/gpio/gpio2/direction
echo out > /sys/class/gpio/gpio4/direction
echo out > /sys/class/gpio/gpio3/direction

# Verifica estado inial de GPIOS, leds
cat /sys/class/gpio/gpio2/value
cat /sys/class/gpio/gpio3/value
cat /sys/class/gpio/gpio4/value

while [ $number -gt 1 ]; do
    # Encendido de leds en forma secuencial
    echo 1 > /sys/class/gpio/gpio2/value
    sleep 1
    echo 1 > /sys/class/gpio/gpio3/value
    sleep 1
    echo 1 > /sys/class/gpio/gpio4/value
    sleep 2
    # Apagado de leds en forma secuencial
    echo 0 > /sys/class/gpio/gpio2/value
    sleep 1
    echo 0 > /sys/class/gpio/gpio3/value
    sleep 1
    echo 0 > /sys/class/gpio/gpio4/value
    sleep 2

    number=$(($number-1))
done

#
# Cierre de GPIOS 2,3,4
#
echo 2 > /sys/class/gpio/unexport
echo 3 > /sys/class/gpio/unexport
echo 4 > /sys/class/gpio/unexport
