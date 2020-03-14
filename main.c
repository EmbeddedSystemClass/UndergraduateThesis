/*
 * main.c
 *
 *  Created on: Mar 13, 2020
 *      Author: Bojan Aleksovski
 */

#include <stdio.h>
#include "bme280.h"

void delay_sec(int time)
{
    vTaskDelay(time * 1000 / portTICK_PERIOD_MS);
}

void app_main()
{
    bme280_config_t my_bme280 = {
            .sda_pin = GPIO_NUM_19,
            .scl_pin = GPIO_NUM_18,
            .i2c_interface = I2C_NUM_1
    };
   if(bme280_init(&my_bme280) == 0)
	   printf("Error, no connection to sensor");

    for (;;)
    {
        bme280_measurement_t my_measurement;
        my_measurement = bme280_make_measurement(&my_bme280);
        bme280_print_measurement(&my_measurement);

        delay_sec(10);
    }
}
