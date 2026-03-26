/*
 * bme280.h
 *
 *  Created on: Mar 26, 2026
 *      Author: tymon
 */

#ifndef INC_BME280_DRIVER_H_
#define INC_BME280_DRIVER_H_

#include "stm32wlxx_hal.h"
#include "sensor_interface.h"


typedef struct {
	//Temperature
    uint16_t dig_T1;
    int16_t  dig_T2;
    int16_t  dig_T3;

    // Preasure
    uint16_t dig_P1;
    int16_t  dig_P2;
    int16_t  dig_P3;
    int16_t  dig_P4;
    int16_t  dig_P5;
    int16_t  dig_P6;
    int16_t  dig_P7;
    int16_t  dig_P8;
    int16_t  dig_P9;

    // Humidity
    uint8_t  dig_H1;
    int16_t  dig_H2;
    uint8_t  dig_H3;
    int16_t  dig_H4;
    int16_t  dig_H5;
    int8_t   dig_H6;
} BME280_Calib_Data;


typedef struct BME280_Handler{
    // CONFIG
    I2C_HandleTypeDef *hi2c;    // Wskaźnik for I2C handler
    uint16_t dev_address;
    int8_t (*init)(struct BME280_Handler *dev);

    // dATA
    float temp;
    float press;
    float hum;
    uint8_t is_initialized;     // Status

    // SYSTEM
    BME280_Calib_Data calib;

} BME280_Handler;

int BME280_Init(Sensor *self);
int BME280_Read(Sensor *self, SensorData *data);

#endif /* INC_BME280_DRIVER_H_ */
