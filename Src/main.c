/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "i2c-lcd.h"
#include "stm32f1xx_hal_flash.h"

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;

TIM_HandleTypeDef htim1;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_TIM1_Init(void);
/* USER CODE BEGIN PFP */
#include "lcd.h"

uint32_t Flash_Read(uint32_t Flash_Address);
void Flash_Write(uint32_t Flash_Address, uint32_t Flash_Data);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
uint32_t ticksNextBlink = 0;
uint32_t ticksForBlink = 1000;

int8_t enter(){ return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10); }
int8_t up(){ return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11); }
int8_t down(){ return HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_12); }

uint32_t adc2 = 0;
uint32_t adc3 = 0;
char adc2deger[16] = "  ";
char adc3char1[16] = "  ";
char adc3char2[16] = "  ";
char adc3char3[16] = "  ";
char adc3char4[16] = "  ";
char sondeger[16] = "  ";
uint32_t ledim = 0;
uint32_t stabilledim = 0;
uint16_t bekleme[3];
uint16_t deger = 0;

uint32_t flashoku;
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t a = 1;
	uint8_t b = 0;
	uint8_t adc3deger1;
	uint8_t adc3deger2;
	uint8_t adc3deger3;
	uint8_t adc3deger4;
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
  MX_ADC1_Init();
  MX_TIM1_Init();
  /* USER CODE BEGIN 2 */

  //Flash_Write(0x08003400, deger);
  HAL_TIM_Base_Start_IT(&htim1);

  lcd_init();

  HAL_ADC_Start(&hadc1);
  HAL_Delay(50);

  lcd_printf(1,1, " ALVEMSIS A.S. ");
  HAL_Delay(500);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  //flashoku = Flash_Read(0x08003400);

	  /*if (HAL_GetTick() > ticksNextBlink)
	  	  {
	  	      ticksNextBlink = HAL_GetTick() + ticksForBlink;
	  	  	  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, !HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13));
	  	  }*/

	  HAL_Delay(2);

	      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15) != 0)  //down
	      {
	      	a++;

	      	if(a == 7)//ana menü alt
	      	{
	      		a = 6;
	      	}
	      	if(a == 23)//led ayar alt
	      	{
	      		a = 22;
	      	}
	      	if(a == 52)//led ayar üst
	      	{
	      		a = 51;
	      	}
	      	if(a == 86)//led el ayar üst
	      	{
	      		a = 85;
	      	}
	      }

	      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))  //up
	      {
	      	a--;

	      	if(a == 0)//ana menü üst
	      	{
	      		a = 1;
	      	}
	      	if(a == 19)//led ayar üst
	      	{
	      		a = 20;
	      	}
	      	if(a == 49)//led ayar üst
	      	{
	      		a = 50;
	      	}
	      	if(a == 79)//led el ayar üst
	      	{
	      		a = 80;
	      	}

	      }

      	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))  //enter
      	  {
      		  if(a == 1)
      		  {
      			  a = 20;  //1.alt menü
      		  }
      		  if(a == 2)
      		  {
      			  a = 50;  //2.alt menü
      		  }
      		  if(a == 3)
      		  {
      			  a = 80;  //3.alt menü
      		  }
      		  if(a == 4)
      		  {
      			  //a = 110; //4.alt menü
      		  }
      		  if(a == 5)
      		  {
      			  //a = 140; //5.alt menü
      		  }
      		  if(a == 6)
      		  {
      			  //a = 170; //6.alt menü
      		  }

      	  }

/*---------------------------ana menü---------------------------*/

	      	  if(a == 0)//ana menü üst
	      	  {
	      		  a = 1;
	      	  }

	      	  if(a == 1)
			  {
				  lcd_printf(1,1, ">1.Led Ayari    ");
				  lcd_printf(2,1, " 2.ADC izle     ");
			  }

			  if(a == 2)
			  {
				  lcd_printf(1,1, " 1.Led Ayari    ");
				  lcd_printf(2,1, ">2.ADC izle     ");
			  }

			  if(a == 3)
			  {
				  lcd_printf(1,1, ">3.El ile ADC   ");
				  lcd_printf(2,1, " 4.Wifi         ");
			  }

			  if(a == 4)
			  {
				  lcd_printf(1,1, " 3.El ile ADC   ");
				  lcd_printf(2,1, ">4.Wifi         ");
			  }

			  if(a == 5)
			  {
				  lcd_printf(1,1, ">5.Genel Ayarlar");
				  lcd_printf(2,1, " 6.İsimler      ");
			  }

			  if(a == 6)
			  {
				  lcd_printf(1,1, " 5.Genel Ayarlar");
				  lcd_printf(2,1, ">6.İsimler      ");
			  }
/*---------------------------ana menü---------------------------*/
/*---------------------------led ayar---------------------------*/
			  if(a == 20)
			  {
				  lcd_printf(1,1,">AC              ");
				  lcd_printf(2,1," KAPAT           ");

				  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
				  {
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
				  }
			  }

			  if(a == 21)
			  {
				  lcd_printf(1,1," AC              ");
				  lcd_printf(2,1,">KAPAT           ");

				  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
				  {
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
					  b = 0;
				  }
			  }

			  if(a == 22)
			  {
				  lcd_printf(1,1,">GERI              ");
				  lcd_printf(2,1,"                   ");

				  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
				  {
					  a = 0;
				  }
			  }

			  if(b == 2) //led yanma süresi stabil kalsın diye
			  {
				  if (HAL_GetTick() > ledim)
				  	  {
				  	      ledim = HAL_GetTick() + adc2;
				  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, !HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
				  	  }
			  }

			  if(b == 3) //led el ile yanma süresi stabil kalsın diye
			  {
				  if (HAL_GetTick() > ledim)
				  	  {
				  	      ledim = HAL_GetTick() + deger;
				  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, !HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
				  	  }
			  }
/*---------------------------led ayar---------------------------*/
/*---------------------------ADC izle---------------------------*/

			  if(a == 50)
			  {
				  adc2 = HAL_ADC_GetValue(&hadc1);

				  sprintf(adc2deger, "%u    ", adc2);

				  lcd_printf(1,1,">ADC Deger:     ");
				  lcd_printf(1,12, adc2deger);
				  lcd_printf(2,1," GERI           ");

					  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
					  {
						  b = 1;

						  if (HAL_GetTick() > ledim)
						  	  {
						  	      ledim = HAL_GetTick() + adc2;
						  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, !HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
						  	  }
					  }
				  b = 2; //led yanma süresi stabil kalsın diye
			  }

			  if(a == 51)
			  {
				  sprintf(adc2deger, "%u    ", adc2);

				  lcd_printf(1,1," ADC Deger:     ");
				  lcd_printf(1,12, adc2deger);
				  lcd_printf(2,1,">GERI           ");

				  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
				  {
					  a = 0;
				  }
			  }
/*---------------------------ADC izle---------------------------*/
/*------------------------ADC el ile Ayar-----------------------*/
			  if(a == 80)
			  {
				  adc2 = HAL_ADC_GetValue(&hadc1);

				  sprintf(adc2deger, "%u    ", adc2);
			  	  lcd_printf(1,1,"ADC Deger Ayar  ");
			  	  lcd_printf(2,11, sondeger);
			  	  lcd_printf(2,1,"OK ");
			  }
			  	  //1. basamak
			  	  if(a == 81)
				  {
					  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
					  b = 0;
			  		  while(1)
			  		  {
					  adc2 = HAL_ADC_GetValue(&hadc1);

				  	  if(adc2 < 400 && adc2 > 0)
				  	  {
					  	  adc3deger1 = 0;
				  	  }
				  	  if(adc3 > 400 && adc2 < 800)
				  	  {
					  	  adc3deger1 = 1;
				  	  }
				  	  if(adc2 > 800 && adc2 < 1200)
				  	  {
					  	  adc3deger1 = 2;
				  	  }
				  	  if(adc2 > 1200 && adc2 < 1600)
				  	  {
					  	  adc3deger1 = 3;
				  	  }
				  	  if(adc2 > 1600 && adc2 < 2000)
				  	  {
					  	  adc3deger1 = 4;
				  	  }
				  	  if(adc2 > 2000 && adc2 < 2400)
				  	  {
					  	  adc3deger1 = 5;
				  	  }
				  	  if(adc2 > 2400 && adc2 < 2800)
				  	  {
					  	  adc3deger1 = 6;
				  	  }
				  	  if(adc2 > 2800 && adc2 < 3200)
				  	  {
					  	  adc3deger1 = 7;
				  	  }
				  	  if(adc2 > 3200 && adc2 < 3600)
				  	  {
					  	  adc3deger1 = 8;
				  	  }
				  	  if(adc2 > 3600 && adc2 < 4200)
				  	  {
					  	  adc3deger1 = 9;
				  	  }

				  	  sprintf(adc3char1, "%u", adc3deger1);

				  	  bekleme[3] = adc3deger1 * 1000;

				  	  lcd_printf(1,1,"ADC Deger Ayar  ");
				  	  lcd_printf(2,11, adc3char1);
				  	  lcd_printf(2,1,"OK -->  ");
				  	  //lcd_printf(2,12, adc3char1);
				  	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
				  	  {
				  		  break;
				  	  }
				      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))
				  	  {
				  		  break;
				  	  }
			  		  }
				  }

				  //2. basamak
			  	  if(a == 82)
				  {
			  		  while(1)
			  		  {
					  adc2 = HAL_ADC_GetValue(&hadc1);

				  	  if(adc2 < 400 && adc2 > 0)
				  	  {
					  	  adc3deger2 = 0;
				  	  }
				  	  if(adc2 > 400 && adc2 < 800)
				  	  {
					  	  adc3deger2 = 1;
				  	  }
				  	  if(adc2 > 800 && adc2 < 1200)
				  	  {
					  	  adc3deger2 = 2;
				  	  }
				  	  if(adc2 > 1200 && adc2 < 1600)
				  	  {
					  	  adc3deger2 = 3;
				  	  }
				  	  if(adc2 > 1600 && adc2 < 2000)
				  	  {
					  	  adc3deger2 = 4;
				  	  }
				  	  if(adc2 > 2000 && adc2 < 2400)
				  	  {
					  	  adc3deger2 = 5;
				  	  }
				  	  if(adc2 > 2400 && adc2 < 2800)
				  	  {
					  	  adc3deger2 = 6;
				  	  }
				  	  if(adc2 > 2800 && adc2 < 3200)
				  	  {
					  	  adc3deger2 = 7;
				  	  }
				  	  if(adc2 > 3200 && adc2 < 3600)
				  	  {
					  	  adc3deger2 = 8;
				  	  }
				  	  if(adc2 > 3600 && adc2 < 4200)
				  	  {
					  	  adc3deger2 = 9;
				  	  }

				  	  sprintf(adc3char2, "%u", adc3deger2);

				  	  bekleme[2] = adc3deger2 * 100;
				  	  lcd_printf(2,11, adc3char1);
				  	  lcd_printf(1,1,"ADC Deger Ayar  ");
				  	  lcd_printf(2,12, adc3char2);
				  	  lcd_printf(2,1,"OK -->  ");

				  	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
				  	  {
				  		  break;
				  	  }
				      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))
				  	  {
				  		  break;
				  	  }
			  		  }
				  }

				  //3. basamak
			  	  if(a == 83)
				  {
			  		  while(1)
			  		  {
					  adc2 = HAL_ADC_GetValue(&hadc1);

				  	  if(adc2 < 400 && adc2 > 0)
				  	  {
					  	  adc3deger3 = 0;
				  	  }
				  	  if(adc2 > 400 && adc2 < 800)
				  	  {
					  	  adc3deger3 = 1;
				  	  }
				  	  if(adc2 > 800 && adc2 < 1200)
				  	  {
					  	  adc3deger3 = 2;
				  	  }
				  	  if(adc2 > 1200 && adc2 < 1600)
				  	  {
					  	  adc3deger3 = 3;
				  	  }
				  	  if(adc2 > 1600 && adc2 < 2000)
				  	  {
					  	  adc3deger3 = 4;
				  	  }
				  	  if(adc2 > 2000 && adc2 < 2400)
				  	  {
					  	  adc3deger3 = 5;
				  	  }
				  	  if(adc2 > 2400 && adc2 < 2800)
				  	  {
					  	  adc3deger3 = 6;
				  	  }
				  	  if(adc2 > 2800 && adc2 < 3200)
				  	  {
					  	  adc3deger3 = 7;
				  	  }
				  	  if(adc2 > 3200 && adc2 < 3600)
				  	  {
					  	  adc3deger3 = 8;
				  	  }
				  	  if(adc2 > 3600 && adc2 < 4200)
				  	  {
					  	  adc3deger3 = 9;
				  	  }

				  	  sprintf(adc3char3, "%u", adc3deger3);

				  	  bekleme[1] = adc3deger3 * 10;
				  	  lcd_printf(2,11, adc3char1);
				  	  lcd_printf(2,12, adc3char2);
				  	  lcd_printf(1,1,"ADC Deger Ayar  ");
				  	  lcd_printf(2,13, adc3char3);
				  	  lcd_printf(2,1,"OK --> ");

				  	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
				  	  {
				  		  break;
				  	  }
				      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))
				  	  {
				  		  break;
				  	  }
			  		  }
				  }

				  //4. basamak
			  	  if(a == 84)
				  {
			  		  while(1)
			  		  {
					  //a = 93;
					  adc2 = HAL_ADC_GetValue(&hadc1);

				  	  if(adc2 < 400 && adc2 > 0)
				  	  {
					  	  adc3deger4 = 0;
				  	  }
				  	  if(adc2 > 400 && adc2 < 800)
				  	  {
					  	  adc3deger4 = 1;
				  	  }
				  	  if(adc2 > 800 && adc2 < 1200)
				  	  {
					  	  adc3deger4 = 2;
				  	  }
				  	  if(adc2 > 1200 && adc2 < 1600)
				  	  {
					  	  adc3deger4 = 3;
				  	  }
				  	  if(adc2 > 1600 && adc2 < 2000)
				  	  {
					  	  adc3deger4 = 4;
				  	  }
				  	  if(adc2 > 2000 && adc2 < 2400)
				  	  {
					  	  adc3deger4 = 5;
				  	  }
				  	  if(adc2 > 2400 && adc2 < 2800)
				  	  {
					  	  adc3deger4 = 6;
				  	  }
				  	  if(adc2 > 2800 && adc2 < 3200)
				  	  {
					  	  adc3deger4 = 7;
				  	  }
				  	  if(adc2 > 3200 && adc2 < 3600)
				  	  {
					  	  adc3deger4 = 8;
				  	  }
				  	  if(adc2 > 3600 && adc2 < 4200)
				  	  {
					  	  adc3deger4 = 9;
				  	  }

				  	  sprintf(adc3char4, "%u", adc3deger4);

				  	  bekleme[0] = adc3deger4;
				  	  lcd_printf(2,11, adc3char1);
				  	  lcd_printf(2,12, adc3char2);
				  	  lcd_printf(2,13, adc3char3);
				  	  lcd_printf(1,1,"ADC Deger Ayar  ");
				  	  lcd_printf(2,14, adc3char4);
				  	  lcd_printf(2,1,"OK --> ");

				  	  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_15))
				  	  {
				  		  break;
				  	  }
				      if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_11))
				  	  {
				  		  break;
				  	  }
			  		  }
				  }
			  	  /*adc3deger1 = 0;
			  	  adc3deger2 = 0;
			  	  adc3deger3 = 0;
			  	  adc3deger4 = 0;*/


				  if(a == 85)
				  {
					  deger = bekleme[0] + bekleme[1] + bekleme[2] + bekleme[3];

				  	  sprintf(sondeger, "%u", deger);

					  lcd_printf(1,1,">GERI           ");
					  lcd_printf(2,1,"                ");
				  	  lcd_printf(2,12, sondeger);

					  b = 3;

					  if (HAL_GetTick() > ledim)
					  	  {
					  	      ledim = HAL_GetTick() + deger;
					  	  	  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9, !HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_9));
					  	  }

					  if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_10))
					  {
						  a = 0;
					  }
				  }

				  }
/*------------------------ADC el ile Ayar-----------------------*/
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */


  /* USER CODE END 3 */
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if(TIM1 == htim -> Instance)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_9);
	}
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */

  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Common config 
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ScanConvMode = ADC_SCAN_DISABLE;
  hadc1.Init.ContinuousConvMode = ENABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConv = ADC_SOFTWARE_START;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Regular Channel 
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = ADC_REGULAR_RANK_1;
  sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */

  /* USER CODE END ADC1_Init 2 */

}

/**
  * @brief TIM1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM1_Init(void)
{

  /* USER CODE BEGIN TIM1_Init 0 */

  /* USER CODE END TIM1_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM1_Init 1 */

  /* USER CODE END TIM1_Init 1 */
  htim1.Instance = TIM1;
  htim1.Init.Prescaler = 10799;//3599;
  htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim1.Init.Period = 9999;
  htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim1.Init.RepetitionCounter = 0;
  htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM1_Init 2 */

  /* USER CODE END TIM1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LCD_EN_Pin|LCD_RS_Pin|LCD_D4_Pin|LCD_D5_Pin 
                          |LCD_D6_Pin|LCD_D7_Pin|led1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : PC13 */
  GPIO_InitStruct.Pin = GPIO_PIN_13;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : LCD_EN_Pin LCD_RS_Pin LCD_D4_Pin LCD_D5_Pin 
                           LCD_D6_Pin LCD_D7_Pin led1_Pin */
  GPIO_InitStruct.Pin = LCD_EN_Pin|LCD_RS_Pin|LCD_D4_Pin|LCD_D5_Pin 
                          |LCD_D6_Pin|LCD_D7_Pin|led1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : enter_Pin up_Pin down_Pin */
  GPIO_InitStruct.Pin = enter_Pin|up_Pin|down_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void Flash_Write(uint32_t Flash_Address, uint32_t Flash_Data)
{
	HAL_FLASH_Unlock();
	FLASH_PageErase(Flash_Address);
	//FLASH_Erase_Sector(FLASH_SECTOR_11, VOLTAGE_RANGE_3);
	HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD, Flash_Address, Flash_Data);
	HAL_FLASH_Lock();
}

uint32_t Flash_Read(uint32_t Flash_Address)
{
	uint32_t Flash_Data;
	Flash_Data = *(uint32_t*) Flash_Address;
	return Flash_Data;
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
