#ifndef _SYSCALLS_H_
#define _SYSCALLS_H_

#include "stm32f1xx_hal.h"
extern UART_HandleTypeDef huart1;
int _read(int file, char *ptr, int len);
int _write(int file, char *ptr, int len);

#endif // _SYSCALLS_H_