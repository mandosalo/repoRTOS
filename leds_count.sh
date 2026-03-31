#!/bin/bash
# con la primer linea #!/bin/bash le indicamos al sistema operativo
# cual es el interprete de comandos
echo Este script hace parpadear un led en el pin indicado N veces
number = 20 # numero de ves a realizar el ciclo
while
	#Apertura de GPIOS 2,3,4
	sudo echo 2 >/sys/class/gpio/export
	sudo echo 3 >/sys/class/gpio/export
	sudo echo 4 >/sys/class/gpio/export
	sleep 1
	#configura los GPIOS como salida
	echo out /sys/class/gpio/gpio2/direction
	echo out /sys/class/gpio/gpio3/direction
	echo out /sys/class/gpio/gpio4/direction
	#Verifica estado actual de los GPIOS leds
	cat /sys/class/gpio/gpio2/value
	sleep 1
	cat /sys/class/gpio/gpio3/value
	sleep 1
	cat /sys/class/gpio/gpio4/value
	sleep 1

	#Apagado de Leds en forma secuencial
	echo 0 > /sys/class/gpios/gpio2/value
	sleep 1
	echo 0 > /sys/class/gpios/gpio3/value
	sleep 1
	echo 0 > /sys/class/gpios/gpio4/value
	sleep 1
	number=$(($number-1))
done

#cierre de GPIOS
echo 2 > /sys/class/gpio/unexport
echo 3 > /sys/class/gpio/unexport
echo 4 > /sys/class/gpio/unexport
