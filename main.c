#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define LED 2
#define LED1 4

void piscar_ambos(int vezes, int delay_ms) {
    for (int i = 0; i < vezes; i++) {
        gpio_set_level(LED, 1);
        gpio_set_level(LED1, 1);

        vTaskDelay(pdMS_TO_TICKS(delay_ms));

        gpio_set_level(LED, 0);
        gpio_set_level(LED1, 0);

        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}

void piscar(int vezes, int delay_ms) {
    for (int i = 0; i < vezes; i++) {
        gpio_set_level(LED, 1);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
        gpio_set_level(LED, 0);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }
}

void piscar_alternado(int vezes, int delay_ms) {
    for (int i = 0; i < vezes; i++) {
        gpio_set_level(LED, 1);
        gpio_set_level(LED1, 0);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
        gpio_set_level(LED, 0);
        gpio_set_level(LED1, 1);
        vTaskDelay(pdMS_TO_TICKS(delay_ms));
    }

    gpio_set_level(LED, 0);
    gpio_set_level(LED1, 0);
}

void app_main() {
  gpio_set_direction(LED, GPIO_MODE_OUTPUT);
  gpio_set_direction(LED1, GPIO_MODE_OUTPUT);

  int C = 0;

  while (true) {
    C++;

    if( C % 5 == 0 && C % 3 == 0){
      printf("Número mútiplo de 3 e 5!\n");
    }

      else if(C % 3 == 0){
        printf("Número múltiplo de 3!\n");
        piscar_ambos(3, 200);
      }

        else if(C % 5 == 0){
          printf("Número múltiplo de 5!\n");
          piscar_alternado(2, 200);
        }

          else{
            printf("Número: %d\n", C);
            piscar(2, 400);
          }

            if( C == 16){
              C = 0;
            }

      printf("-----------------------------------------\n");
      vTaskDelay(1500 / portTICK_PERIOD_MS);
  }
}