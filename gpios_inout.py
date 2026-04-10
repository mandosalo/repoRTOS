# Encienden y apagan los LEDs de los GPIOs 2,3,4,17,27
# en modo BCM, hasta que se oprima el push-button en GPIO22

import RPi.GPIO as g
import time as t

g.setwarnings(False)   # deshabilita warnings
g.setmode(g.BCM)       # Configura tarjeta en BCM

g.setup(2,g.OUT)       # Configura GPIOs de salida
g.setup(3,g.OUT)
g.setup(4,g.OUT)
g.setup(17,g.OUT)
g.setup(27,g.OUT)

# GPIO22 entrada del push-button
g.setup(22,g.IN)

n = 1
N = 5

val = g.input(22)

while val == 1:
    # Espera que se oprima
    print("Oprimir Push_button")
    val = g.input(22)     # Lee valor de Push button

print("Se oprimió Push_button")

while True:   # Si ciclo finito while n <= N:
    g.output(2,True)
    print("ON")
    t.sleep(1)

    g.output(2,False)
    print("OFF")
    t.sleep(1)

    # n = n + 1, aumenta n para ciclo finito