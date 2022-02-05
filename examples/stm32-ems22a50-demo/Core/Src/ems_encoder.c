#include "ems_encoder.h"

Encoder ems_encoder_init(GPIO_TypeDef* GPIOx, uint16_t PIN_X, SPI_HandleTypeDef* hspix) {
    Encoder enc = {
        .last_angle = 0,
        .raw_reading = {0,0},
        .f_angle = 0,
        .GPIOx = GPIOx,
        .GPIO_PIN_X = PIN_X,
        .hspi = hspix
    };

    return enc;
}

void ems_encoder_read_angle(Encoder *enc) {

    HAL_GPIO_WritePin(enc->GPIOx, GPIO_PIN_4, RESET);
    HAL_SPI_Receive((enc->hspi), (uint8_t*)enc->raw_reading, 2, 100);
    HAL_GPIO_WritePin(enc->GPIOx, GPIO_PIN_4, SET);

    volatile uint16_t temp = ((uint16_t)enc->raw_reading[1]) << 9U | ((uint16_t)enc->raw_reading[0]<<1u);
    uint16_t angle = (temp >> 6U);
    enc->f_angle = angle * (360.0f/1023);

    #if !defined(LOG_DEBUG)
    printf("reading (raw): %i prev: %li\r\n", angle, enc->last_angle);
    #endif

    enc->last_angle = angle;


}