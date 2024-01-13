/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
//#include "pca9685.h"
#include "smartwind.h"
#include "stdio.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */



extern USRAT_RX usart1_rx;
#define rBuf usart1_rx.rx_buff

/* USER CODE BEGIN PV */



/* USER CODE END PV */
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */


/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */



/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */



/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void Clear_Usart(USRAT_RX *usart_rx)		
{
	memset((uint8_t*)usart_rx,0,sizeof(USRAT_RX)); 
}
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_TIM1_Init();
  MX_TIM2_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_TIM5_Init();
  MX_TIM8_Init();
  MX_TIM9_Init();
  MX_TIM13_Init();
  MX_I2C1_Init();
  MX_I2C2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
	Pwm_Init_9();
	PWM_SET_9();
	
	
	fan_handle myfan;
	

 //
	Clear_Usart(&usart1_rx); 
  __HAL_UART_ENABLE_IT(&huart1,UART_IT_IDLE);	//
  HAL_UART_Receive_DMA(&huart1,usart1_rx.rx_buff,RX_BUF_MAX_LEN);	


	//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	fan_init(&myfan,&hi2c2,&hi2c1,100.0f);
	char flag = 'i'; 
	int even_count =0;
	memset((void *)rBuf, 0x00, RX_BUF_MAX_LEN);
	//pca9685_set_pwm_frequency(&pca_handle, 100.0f);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
		

// Set the channel on and off times.
// The channel must be >= 0 and < 16.
// The on and off times must be >= 0 and < 4096.
// In this example, the duty cycle is (off time - on time) / 4096 = (2048 - 0) / 4096 = 50%
	//pca9685_set_channel_pwm_times(&pca_handle, 0, 0, 2048);
		
		//printf("good");
		
		if(rBuf[0]==0x00){
			
			
			
			
		continue;
		};
		
		switch(rBuf[0]) 
		{
			//test mode
			case 't':
			{
				fan_device_detect(&myfan);
			break;
			}
			//stop mode
			case 'p' :
			{
				fan_stop(&myfan);
			printf("r$p$\n");
			break;
			}
			//even mode
			case 'e' :
			{
				uint16_t pwm_up=0;
				sscanf(rBuf,"e$%i$",&pwm_up);
			even_count++;
			
				printf("r$e$\n");
				fan_set_all(&myfan,0,pwm_up);		
			rBuf[0]=0u;
			//memset((void *)rBuf, 0x00, RX_BUF_MAX_LEN)	
				break;
			}
			case 'c' :
				fan_callibration(&myfan);
			
			//echo test
			case 'q' :
				
				printf("%s",rBuf);
			
			//gust mode
			case 'g' :
			{
				
				uint32_t pwm_down,pwm_up,period;
				sscanf(rBuf,"g$%i,%i,%i$",&period,&pwm_down,&pwm_up);
				
				fan_gust_initialize(&myfan,period,pwm_up,pwm_down);
				
				fan_gust_update(&myfan);
				printf("r$g$\n");
				break;
			
			}
			
			//sheer mode
			case 's' :
			{
				int direction;
				int row,pwm_up;
				sscanf(rBuf,"s$%i,%i,%i$",&direction,&row,&pwm_up);
				if(direction == 0){
					fan_set_row(&myfan,row,0,pwm_up);
					
				}
				
				if(direction == 1){
					fan_set_col(&myfan,row,0,pwm_up);
					
				}
				
				printf("r$s$\n");
				rBuf[0]=0u;
				break;
	
			}
			
			//wave mode
			case 'w' :
			{
				int direction;
				int spatial_period,time_period,pwm;
				sscanf(rBuf,"w$%d,%d,%d,%d$",&direction,&spatial_period,&time_period,&pwm);
				fan_wave_initialize(&myfan,spatial_period,pwm,direction);
			fan_wave_update(&myfan);
			
			
			}
			
break;				
		}
		
		

      
		 
	
	 
		
		
		
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 100;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */








/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

