#include "main.h"
void SystemClock_Config(void);

volatile uint8_t spi_buffer[4];
volatile uint16_t angle;

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();

  while (1)
  {

    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, RESET);

    HAL_SPI_Receive(&hspi1, (uint8_t*)spi_buffer, 3, 100);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, SET);

    /* 

        fb | d9 | d8 | d7 | d6 | d5 | d4 | d3
        d2 | d1 | d0 | s1 | s2 | s3 | s4 | s5 
        
        p1

        d9 | d8 | d7 | d6 | d5 | d4 | d3 | d2 | d1 | d0 | s1 | s2 | s3 | s4 | s5  | 0

     */

    volatile uint16_t temp = ((uint16_t)spi_buffer[1]) << 9U | ((uint16_t)spi_buffer[0]<<1u);
    angle = (temp >> 6U);
    printf("%i\r\n", angle);
        
  }
}
