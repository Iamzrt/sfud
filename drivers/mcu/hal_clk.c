/**
  ******************************************************************************
  * @file      
  * @author    
  * @version   
  * @date      
  * @brief     
  ******************************************************************************  
  * 
  * 
  ******************************************************************************
  */
/*-- includes ----------------------------------------------------------------*/
#include "../../includes/_platform_conf.h"   
#include "./hal_mcu.h" 


/*-- defined -----------------------------------------------------------------*/


/*-- private variables -------------------------------------------------------*/


/*-- functions ---------------------------------------------------------------*/


/**
* @brief  System Clock Configuration
*         The system Clock is configured as follow : 
*            System Clock source            = PLL (HSE)
*            SYSCLK(Hz)                     = 72000000
*            HCLK(Hz)                       = 72000000
*            AHB Prescaler                  = 1
*            APB1 Prescaler                 = 2
*            APB2 Prescaler                 = 1
*            HSE Frequency(Hz)              = 8000000
*            HSE PREDIV1                    = 1
*            PLLMUL                         = 9
*            Flash Latency(WS)              = 0
* @param  None
* @return None
*/
void  hal_clk_init(u32_t freq)
{
  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
	RCC_PeriphCLKInitTypeDef PeriphClkInit;

	HAL_Init();
	
#if 0  /* HSE 72MHZ */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;  
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;  
  if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    while(1)
		{
			;
		}
  }

  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;      
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;              
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;               
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;            
  if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    while(1)
		{
			;
		}
  }
#else  /* HSI 8MHZ */

//	/**Initializes the CPU, AHB and APB busses clocks 
//	*/
//	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
//  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
//  RCC_OscInitStruct.HSICalibrationValue = 16;
//  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
//  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
//  {
//    while(1);
//  }

//    /**Initializes the CPU, AHB and APB busses clocks 
//    */
//  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
//                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
//  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
//  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
//  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
//  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;



//  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
//  {
//    while(1);
//  }

	if(freq == 8000000)
	{
		/* HSE 8MHZ */
		RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI;//RCC_OSCILLATORTYPE_LSE; // 
		RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		//RCC_OscInitStruct.LSEState = RCC_LSE_ON;
		RCC_OscInitStruct.LSIState = RCC_LSI_ON;
		RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2; 
		if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
		{
			while(1)
			{
				hal_mcu_reset();
			}
		}

		RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
																|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSE;//RCC_SYSCLKSOURCE_PLLCLK;      
		RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;              
		RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;               
		RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;            
		if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
		{
			while(1)
			{
				hal_mcu_reset();
			}
		}
	}
	else  if(freq == 16000000)
	{
		/* HSE 16MHZ */
		RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE | RCC_OSCILLATORTYPE_LSI;// RCC_OSCILLATORTYPE_LSE; //
		RCC_OscInitStruct.HSEState = RCC_HSE_ON;
		//RCC_OscInitStruct.LSEState = RCC_LSE_ON;
		RCC_OscInitStruct.LSIState = RCC_LSI_ON;
		RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
		RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
		RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
		RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL2; 
		if(HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
		{
			while(1)
			{
				hal_mcu_reset();
			}
		}

		RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
																|RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
		RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;      
		RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;              
		RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;               
		RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;            
		if(HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
		{
			while(1)
			{
				hal_mcu_reset();
			}
		}
	}

#endif
	
	//PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC | RCC_PERIPHCLK_RTC;
	PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_RTC;
  //PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV8;
	PeriphClkInit.RTCClockSelection = RCC_RTCCLKSOURCE_LSI;//RCC_RTCCLKSOURCE_LSE; //
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    while(1)
		{
			hal_mcu_reset();
		}
  }
	
  /* configure and start systemtick. */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);  
	
	/* systemtick clock source. */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}




/*------------------ end of file ---------------------------------------------*/

