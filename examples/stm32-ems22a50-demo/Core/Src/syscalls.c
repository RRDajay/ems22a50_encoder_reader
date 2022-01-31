#include "syscalls.h"

int _read(int file, char *ptr, int len) {
    HAL_StatusTypeDef hstatus;
    hstatus = HAL_UART_Receive(&huart1, (uint8_t*) ptr, 1, HAL_MAX_DELAY);
    if (hstatus == HAL_OK)
        return 1;
    else
        return 0;
}

int _write(int file, char *ptr, int len) {
    HAL_StatusTypeDef hstatus;
    hstatus = HAL_UART_Transmit(&huart1, (uint8_t*) ptr, len, 100);
    if (hstatus == HAL_OK)
        return len;
    else
        return 0;
}