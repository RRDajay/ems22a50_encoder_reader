#include "main.h"
void SystemClock_Config(void);

volatile Encoder obj;
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

  /* Initialize Encoder */
  obj = ems_encoder_init(GPIOA, GPIO_PIN_4, &hspi1);

  while (1)
  {

    ems_encoder_read_angle((Encoder*)&obj);

    HAL_Delay(10);


    /* 

        fb | d9 | d8 | d7 | d6 | d5 | d4 | d3
        d2 | d1 | d0 | s1 | s2 | s3 | s4 | s5 
        
        p1

        d9 | d8 | d7 | d6 | d5 | d4 | d3 | d2 | d1 | d0 | s1 | s2 | s3 | s4 | s5  | 0

     */
        
  }
}
