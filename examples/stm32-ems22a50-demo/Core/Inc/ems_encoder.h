#ifndef _EMS_ENCODER_H_
#define _EMS_ENCODER_H_

#include "stdint.h"
#include "stm32f1xx_hal.h"

typedef struct Encoder {
    
    uint8_t raw_reading[2];
    uint32_t revolutions;
    uint32_t last_angle;

    GPIO_TypeDef* GPIOx;
    uint16_t GPIO_PIN_X;
    SPI_HandleTypeDef* hspi;
    
} Encoder;

Encoder ems_encoder_init(GPIO_TypeDef* GPIOx, uint16_t GPIO_PIN_X, SPI_HandleTypeDef* hspix);

void ems_encoder_read_angle(Encoder *obj);

#endif