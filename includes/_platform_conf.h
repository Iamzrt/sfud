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
#ifndef  PLATFORM_CONFIG_H
#define  PLATFORM_CONFIG_H


/* C++Ö§³Ö */
#ifdef __cplusplus
extern "C" {
#endif
 
   

/* platform select, only one can select */
#define    STM32F1_PLATFORM 
 


/*-- includes ----------------------------------------------------------------*/
#include "./_sys_std.h"
	
/* platform include header. */
#if defined(STM32F1_PLATFORM)

  #include "../drivers/mcu/STM32F1xx_HAL_Driver/Inc/stm32f1xx_hal.h"

#elif defined(STM8S003_PLATFORM)

  #error "no STM8S003_PLATFORM"
  
#elif defined(STM8L05X_PLATFORM)
  
  #error "no STM8L05X_PLATFORM"
  
#else

  #error "please select a platform!"
  
#endif



#ifdef __cplusplus
}
#endif

#endif    /* PLATFORM_CONFIG_H */

/*------------------ end of file ---------------------------------------------*/
