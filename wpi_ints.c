// INTERRUPCIONES DE GPIO WiringPi, L@r 2024, en C

#include <wiringPi.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#define LED_GPIO    17   // GPIO17, Pin 11
#define BUTTON_GPIO 22   // GPIO27, Pin 15

void lightLED(void) {        // Rutina ISR, LED ON OFF
    digitalWrite(LED_GPIO, HIGH);
    printf("LED en ON");
    delay(1000);

    digitalWrite(LED_GPIO, LOW);
    printf("LED en OF");
    delay(1000);
}

int main() {
    wiringPiSetupGpio();    // Configura GPIOs como BCM

    pinMode(LED_GPIO, OUTPUT);     // GPIO17 como salida LED
    pinMode(BUTTON_GPIO, INPUT);   // GPIO22 como entrada Push-button

    digitalWrite(LED_GPIO, LOW);   // Señal de inicio

    // Conecta ISR lightLED() con flanco de subida (rising edge)
    wiringPiISR(BUTTON_GPIO, INT_EDGE_RISING, &lightLED);

    printf(" Oprimir push-button y soltar \n");

    while(1) {
        sleep(1);   // Retardo de un segundo
    }

    return 0;
}