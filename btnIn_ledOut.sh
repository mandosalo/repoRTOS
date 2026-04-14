#!/bin/bash
# con la primer linea #!/bin/bash le indicamos al sistema operativo
# cual es el interprete de comandos
echo Verifica si se oprime el pushbutton en GPIO 22
number=5 # numero de ves a realizar el ciclo

#Apertura de GPIOS 2,3,22
sudo echo 2 > /sys/class/gpio/export
sudo echo 3 > /sys/class/gpio/export
sudo echo 22 > /sys/class/gpio/export
sleep 1
#configura los GPIOS como salida
echo out > /sys/class/gpio/gpio2/direction
echo out > /sys/class/gpio/gpio3/direction
echo in > /sys/class/gpio/gpio22/direction
#Verifica estado actual de los GPIOS leds
cat /sys/class/gpio/gpio2/value
cat /sys/class/gpio/gpio3/value
cat /sys/class/gpio/gpio22/value

leegpio22=$(cat /sys/class/gpio/gpio22/value)
while [ $leegpio22 = 1 ]; do
	echo "oprime push button"
	leegpio22=$( cat /sys/class/gpio/gpio22/value)
done
echo "se oprimio push button"
while [ $number -gt 1 ];do
#encendido de leds en forma secuencial
echo 1 > /sys/class/gpio/gpio2/value
sleep 1
echo 1 > /sys/class/gpio/gpio3/value
sleep 1

#Apagado de Leds en forma secuencial
echo 0 > /sys/class/gpio/gpio2/value
sleep 1
echo 0 > /sys/class/gpio/gpio3/value
sleep 1

number=$(($number-1))
done

#cierre de GPIOS
echo 2 > /sys/class/gpio/unexport
echo 3 > /sys/class/gpio/unexport
echo 22 > /sys/class/gpio/unexport
