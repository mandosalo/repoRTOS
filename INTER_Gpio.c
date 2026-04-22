/*  INTERRUPCIONES DE GPIO 5 CON Push_button

 */
 #include <stdio.h>
  #include "freertos/freeRTOS.h"
  #include "freertos/task.h"
  #include "driver/gpio.h"
  #include "esp_log.h  "
  
  #define LED2    2
  #define LED16  16
//  #define LED17  17   // button de entrada
   #define LED17  5   // 
  #define LED18  18
  
  const char *tag = "Main";
  
  // prototipos de funciones
  
  esp_err_t init_led(void);
  esp_err_t init_isr(void);
  void  isr_handler(void *args);
  
  // Principal
  void app_main(void)
  {
  int ON = 1;
   init_led();
   init_isr();
  }
  
 // funciones
 
  esp_err_t init_led(void){
   gpio_reset_pin(LED2);
   gpio_set_direcion(LED2,GPIO_MODE_OUTPUT);
   gpio_reset_pin(LED16);
   gpio_set_direcion(LED6,GPIO_MODE_OUTPUT);
   gpio_reset_pin(LED17);
   gpio_set_direcion(LED17,GPIO_MODE_INPUT);  // MICRO_SWITCH
      gpio_set_level(LED16,ON);    // prende el LED16
      gpio_set_level(LED2,!ON);      // apaga LED2
   
   return  ESP_OK;
 }
 
 esp_err_t init_isr(void){
   gpio_config_t pGPIOConfig;
   pGPIOConfig.pin_bit_mask = 0x020  ;  // N0. GPIO 17 (0x02000)
                                             // = (1ULL << Num_GPIO);
   pGPIOConfig.mode         = GPIO_MODE_DEF_INPUT;
   pGPIOConfig.pull_up_enx  = GPIO_PULLUP_DISABLE;
   pGPIOConfig.pull_down_en = GPIO_PULLDOWN_DISABLE;
   pGPIOConfig.intr_type    = GPIO_INTR_NEGEDGE;
   
   gpio_config(&pGPIOConfig);
   gpio_install_isr_servide(0);  // habilita globalmente interrups.
   gpio_isr_handler_add(LED17,isr_handler,NULL);
 
   return  ESP_OK;
 }
 
 void isr_handle(void ){
   ON = !ON;
 gpio_set_level(LED16,ON);    // prende el LED16
 gpio_set_level(LED2,!ON);
 
 }
