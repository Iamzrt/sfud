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
#define   DB_LOG(s)       					//hal_uart5_putstring(s)

/*-- private variables -------------------------------------------------------*/
static   SysTickCallBackFunc sysTickCallFunc = NULL;


/*-- functions ---------------------------------------------------------------*/

/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_init(void)
{
	/* When system start, it should be disable the global interrupt. */
	GLOBAL_INTERRUPT_DISABLE();
	
	hal_clk_init(16000000);
	
	hal_gpio_init();

	/* Enable global interrupt. */
	GLOBAL_INTERRUPT_ENABLE();
	
	hal_uart5_init(115200); /* debug */
	
	hal_spi1_init();
}



/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_reset(void)
{
	__set_FAULTMASK(1);
  HAL_NVIC_SystemReset();
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_tick_delay(u32_t delay)
{
	HAL_Delay(delay);
}

/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
u32_t   hal_get_tick(void)
{
  return  HAL_GetTick();
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_tick_suspend(void)
{
  HAL_SuspendTick();
	
	
	//__HAL_RCC_DBGMCU_CLK_ENABLE();
	//__HAL_DBGMCU_FREEZE_IWDG();
}

/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_tick_resume(void)
{
  HAL_ResumeTick();
	
	
	//__HAL_DBGMCU_UNFREEZE_IWDG();
}

/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_sleep(void)
{
  HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI); 
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_stop(void)
{
	HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON,PWR_STOPENTRY_WFI);
	//HAL_PWR_EnterSTOPMode(PWR_MAINREGULATOR_ON,PWR_STOPENTRY_WFI);
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_standby(void)
{
	HAL_PWR_EnterSTANDBYMode();
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void   hal_systick_update_callback_register(SysTickCallBackFunc func)
{
  sysTickCallFunc = func;
}



/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
u32_t  hal_get_sys_freq(void)
{
	u32_t freq = HAL_RCC_GetSysClockFreq();
  return  freq;
}



/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_mcu_low_power_exit(void)
{	
	hal_mcu_init();
	
	//HAL_PWR_DisableWakeUpPin(PWR_WAKEUP_PIN1);   /* for standby mode. */
}



/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */ 
INTERRUPT_FUNC  void SysTick_Handler(void)
{
	HAL_IncTick();
	
	if(sysTickCallFunc)		
		sysTickCallFunc();
}

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
INTERRUPT_FUNC void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
INTERRUPT_FUNC void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
		hal_mcu_reset();
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
INTERRUPT_FUNC void SVC_Handler(void)
{
	
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
INTERRUPT_FUNC void PendSV_Handler(void)
{
	
}
/*------------------ end of file ---------------------------------------------*/
