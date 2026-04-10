#!/bin/bash

# Verifica si se oprime el push boton en GPIO22
# Secuencia los GPIOS: 2,3,
number=5

# Apertura de GPIOS: 2,3, 22
sudo echo 2 > /sys/class/gpio/export
sudo echo 3 > /sys/class/gpio/export
sudo echo 22 > /sys/class/gpio/export

#define los gpios 2,3, 22 como salida
echo out > /sys/class/gpio/gpio2/direction
echo out > /sys/class/gpio/gpio3/direction
echo "in" > /sys/class/gpio/gpio22/direction

# Verifica estado inial de GPIOS, leds
cat /sys/class/gpio/gpio2/value
cat /sys/class/gpio/gpio3/value
cat /sys/class/gpio/gpio4/value
leegpio22=$(cat /sys/class/gpio/gpio22/value)

while [ $leegpio22 = 1 ]; do
    echo "Oprime push-botton"
    leegpio22=$(cat /sys/class/gpio/gpio22/value)
done

echo "Se oprimió el push-botton"

while [ $number -gt 1 ]; do
    # Encendido de leds en forma secuencial
    echo 1 > /sys/class/gpio/gpio2/value
    sleep 0.5
    echo 1 > /sys/class/gpio/gpio3/value
    sleep 1

    # Apagado de leds en forma secuencial
    echo 0 > /sys/class/gpio/gpio2/value
    sleep 0.5
    echo 0 > /sys/class/gpio/gpio3/value
    sleep 1

    number=$(($number-1))
done

# Cierre de GPIOS 2,3, 22
echo 2 > /sys/class/gpio/unexport
echo 3 > /sys/class/gpio/unexport
echo 22 > /sys/class/gpio/unexport