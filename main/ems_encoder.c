#include "ems_encoder.h"

Encoder ems_encoder_init(GPIO_TypeDef* GPIOx, uint16_t PIN_X, SPI_HandleTypeDef* hspix) {
    Encoder obj = {
        .last_angle = 0,
        .raw_reading = {0,0},
        .revolutions = 0,
        .GPIOx = GPIOx,
        .GPIO_PIN_X = PIN_X,
        .hspi = hspix
    };

    return obj;
}

void ems_encoder_read_angle(Encoder *obj) {

    HAL_GPIO_WritePin(obj->GPIOx, GPIO_PIN_4, RESET);
    HAL_SPI_Receive((obj->hspi), (uint8_t*)obj->raw_reading, 2, 100);
    HAL_GPIO_WritePin(obj->GPIOx, GPIO_PIN_4, SET);

    #if defined(LOG_DEBUG)
    volatile uint16_t temp = ((uint16_t)obj->raw_reading[1]) << 9U | ((uint16_t)obj->raw_reading[0]<<1u);
    uint16_t angle = (temp >> 6U);
    printf("%i\r\n", angle);
    #endif

}