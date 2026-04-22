//  Preuba de todos los puertos TOUCH
// Oct_25
#include <stdio.h>
#include <inttypes.h>
// #include "driver/touch_sensor.h"
#include "driver/touch_sensor_legacy.h"

// #include "driver/touch_pad.h"    //  Librería obsoleta
#include "esp_log.h"                // Mensajes a color de Espresiff
#include <unistd.h>


#define TOUCH_PAD_NO_CHANGE   (-1)
#define TOUCH_THRESH_USE   (20000)
// #define TOUCH_THRESH_NO_USE   (0)
#define TOUCH_FILTER_MODE_EN  (1)
#define TOUCHPAD_FILTER_TOUCH_PERIOD (10)

/* ----- Lee todos los valores de Puertos Touch y los imprime */
void tp_example_read() {
    uint16_t touch_value;
    uint16_t touch_filter_value;
#if TOUCH_FILTER_MODE_EN
    printf("Touch en modo filter de lectura, Formato : \nTouchpad  num:[raw data, filtered data]\n\n");
#else
    printf("Touch modo normal de lectura, formato de salid : \n Touchpad num:[raw data] \n\n");
#endif
    while (1) {
        for (int i = 0; i < TOUCH_PAD_MAX; i++) { //Lee valores de Puertos_TOUCH  i :0 --> 9  
#if TOUCH_FILTER_MODE_EN
            // If open the filter mode, please use this API to get the touch pad count.
            touch_pad_read_raw_data(i, &touch_value);
            touch_pad_read_filtered(i, &touch_filter_value);
            printf("T%d:[%4"PRIu16",%4"PRIu16"] ", i, touch_value, touch_filter_value);
#else
            touch_pad_read(i, &touch_value);
            printf("T%d:[%4"PRIu16"] ", i, touch_value);
#endif
        }
        printf("\n");
        sleep(1);
    }
}
//--------------------- Inicializa puertos touch
static void tp_example_touch_pad_init(void){
    for (int i = 0;i< TOUCH_PAD_MAX;i++) {
        touch_pad_config(i, TOUCH_THRESH_USE);
    }
}

void app_main(void)
{
    // Inicializa puertos  touch, por default están en modo fsm disparo posr sofware.
    ESP_ERROR_CHECK(touch_pad_init());
    // Fija voltajes de referencia carga descarga. Voltaje alto 2.7V - 1V = 1.7V
    // Voltaje bajo be 0.5
    touch_pad_set_voltage(TOUCH_HVOLT_2V7, TOUCH_LVOLT_0V5, TOUCH_HVOLT_ATTEN_1V);
    tp_example_touch_pad_init();
#if TOUCH_FILTER_MODE_EN
    touch_pad_filter_start(TOUCHPAD_FILTER_TOUCH_PERIOD);
#endif
    // Lectura de los sensores Touch
    tp_example_read( );
}
