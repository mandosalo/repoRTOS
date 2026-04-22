/*
    ADQUISICION DE ADC1_C6, GPIO34, PIN 5
    Lee de:     124  mV    a  3145 mV
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "esp_log.h"
#include "driver/adc.h"
#include "esp_adc_cal.h"
static const char *TAG = "ADC EXAMPLE";
static esp_adc_cal_characteristics_t adc1_chars;

void app_main(void){
uint32_t voltage;
esp_adc_cal_characterize(ADC_UNIT_1, ADC_ATTEN_DB_11,
ADC_WIDTH_BIT_DEFAULT, 0, &adc1_chars);
ESP_ERROR_CHECK(adc1_config_width(ADC_WIDTH_BIT_DEFAULT));
ESP_ERROR_CHECK(adc1_config_channel_atten(ADC1_CHANNEL_6,ADC_ATTEN_DB_11));

  while (1) {
   voltage = esp_adc_cal_raw_to_voltage(adc1_get_raw(ADC1_CHANNEL_6),&adc1_chars);
   printf( "Salida de canal ADC1_6_GPIO34_PIN_5: %ld mV \n", voltage);
   sleep(1); } // while

} // main
