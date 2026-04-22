


/* Control de  PWM  por Hardware 
  Sobre LED GPIO 16
  L@rry abril de 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "driver/ledc.h"
#include "esp_err.h"
#define LEDC_TIMER              LEDC_TIMER_0 //Timer 0
#define LEDC_MODE               LEDC_LOW_SPEED_MODE // Modo baja velocidad
#define LEDC_OUTPUT_IO          (16) // GPIO 16
#define LEDC_CHANNEL            LEDC_CHANNEL_0
#define LEDC_DUTY_RES           LEDC_TIMER_13_BIT // Resolución del ciclo de trabajo a 13 bits
#define LEDC_DUTY               (8190)//(4095) // Ciclo de trabajo al 50%. ((2 ** 13) - 1) * 50% = 4095
#define LEDC_FREQUENCY          (50) // Frecuencia en Hertz. Frecuencia a 50 Hz
#define DUTY_MAX                (8000) 
#define DELTA_DUTY              (25)
#define DELAY                   700000   // MILISEGUNGOS
static void example_ledc_init(void)
{
  // Configuración del Timer
    ledc_timer_config_t ledc_timer = {
        .speed_mode       = LEDC_MODE,   //configura a baja velocidad
        .timer_num        = LEDC_TIMER,  // Habilita el timer 0
        .duty_resolution  = LEDC_DUTY_RES,  // Establece la resolución a 13 bits
        .freq_hz          = LEDC_FREQUENCY, // Establece la frecuencia del timer
        .clk_cfg          = LEDC_AUTO_CLK // Elije la fuente de reloj automáticamente
    };
    ESP_ERROR_CHECK(ledc_timer_config(&ledc_timer));    
    ledc_channel_config_t ledc_channel = { // Configuración del canal LEDC
        .speed_mode     = LEDC_MODE, // configura a baja velocidad(igual al timer)
        .channel        = LEDC_CHANNEL,  // establece el canal 0 de LEDC
        .timer_sel      = LEDC_TIMER, // Selecciona el timer (el mismo que se configuró)
        .intr_type      = LEDC_INTR_DISABLE, // Deshabilita interrupciones
        .gpio_num       = LEDC_OUTPUT_IO, // Establece el GPIO de salida al 16
        .duty           = 0,	//Ciclo de trabajo inicial
        .hpoint         = 0
    };
    ESP_ERROR_CHECK(ledc_channel_config(&ledc_channel));
}
//------------------------------------------------
void app_main(void){
uint32_t ciclo_objetivo = 8000;
uint32_t crecimiento_ciclo = 100;
uint32_t ciclo_reg = 5;
    example_ledc_init();        // Configuración de LEDC    
    ledc_fade_func_install(0); // Función para poder cambiar por hardware el ciclo de trabajo
    //Función para configurar como aumenta o disminuye el PWM.
//    while(1) 
    ledc_set_fade_with_step(LEDC_MODE, LEDC_CHANNEL, ciclo_objetivo, crecimiento_ciclo, ciclo_reg);    while(1) {
    //Función que incia el cambio el ciclo de trabajo
    ledc_fade_start(LEDC_MODE, LEDC_CHANNEL, LEDC_FADE_WAIT_DONE);
    usleep(DELAY);
   }   
}
