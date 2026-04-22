#include <stdio.h>
#include <unistd.h>
#include "driver/gpio.h"

#define LED_PIN 2
#define GPIO16 16

void app_main(void)
{
 gpio_set_direction(LED_PIN, GPIO_MODE_OUTPUT);
 gpio_set_direction(GPIO16, GPIO_MODE_OUTPUT);

 int ON = 0;
while(true){
 printf("Cambia estado de LED cada dos segundos \n");
ON = !ON;
gpio_set_level(LED_PIN, ON);
gpio_set_level(GPIO16, !ON);
 sleep(2);

 }

}

