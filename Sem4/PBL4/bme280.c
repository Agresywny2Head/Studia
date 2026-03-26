/*
 * bme280.c
 *
 *  Created on: Mar 26, 2026
 *      Author: tymon
 */


#include "bme280.h"


int BME280_Init(Sensor *self) {
    BME280_Handler *handler = (BME280_Handler *)self->instance;
    uint8_t chip_id = 0;
    uint8_t reg_id = 0xD0; // dupa


    if (HAL_I2C_Mem_Read(handler->hi2c, handler->dev_address, reg_id, 1, &chip_id, 1, 100) != HAL_OK) {
        return -1; // Błąd komunikacji I2C
    }

    // 3. Sprawdzamy, czy to na pewno BME280 (powinien zwrócić 0x60)
    if (chip_id != 0x58) {
        return -2; // To nie jest BME280!
    }

    // 4. Sukces!
    handler->is_initialized = 1;
    return 0; // Wszystko OK
}


int BME280_Read(Sensor *self, SensorData *data) {
    BME280_Handler *handler = (BME280_Handler *)self->instance;

    if (!handler->is_initialized) {
        return -1;
    }

    // Tu w przyszłości dojdzie odczyt temperatury i matematyka
    data->temperature = 25.0f; // Tymczasowa "sztywna" wartość do testów

    return 0;
}
