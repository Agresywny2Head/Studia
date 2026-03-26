/*
 * sensor_interface.h
 *
 *  Created on: Mar 26, 2026
 *      Author: tymon
 */

#ifndef INC_SENSOR_INTERFACE_H_
#define INC_SENSOR_INTERFACE_H_

#include <stdint.h>
//structure containing data collected by sensors
typedef struct {
    float temperature;
    float humidity;
    float pressure;
    uint32_t timestamp;   // optional
} SensorData;




struct Sensor;


typedef struct Sensor {
    void *instance;  // wskaźnik to specific sensor structure

    /**
     * @brief Funkcja inicjalizująca czujnik.
     * @return 0 przy sukcesie, wartość ujemna przy błędzie.
     */
    int (*init)(struct Sensor *self);

    /**
     * @brief Funkcja odczytująca dane z czujnika.
     * @param data Wskaźnik na strukturę, do której zostaną zapisane wyniki.
     * @return 0 przy sukcesie, wartość ujemna przy błędzie.
     */
    int (*read)(struct Sensor *self, SensorData *data);

} Sensor;

#endif /* INC_SENSOR_INTERFACE_H_ */
