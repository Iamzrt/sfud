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

#ifndef   HAL_MCU_H
#define   HAL_MCU_H

/* C++ */
#ifdef __cplusplus
extern "C" {
#endif
  
  
/*-- includes ----------------------------------------------------------------*/
	
#include "../../includes/_sys_std.h"
#include "../../includes/_sys_config.h"	


#include "./hal_clk.h" 
#include "./hal_gpio.h"
#include "./hal_uart.h"
#include "./hal_spi.h"
	
	
  
/*-- typedef  ----------------------------------------------------------------*/
#define      GLOBAL_INTERRUPT_DISABLE()      do{                            \
	                                                __disable_irq();          \
																								}while(0)

#define      GLOBAL_INTERRUPT_ENABLE()       do{                            \
	                                                __enable_irq();           \
																								}while(0)
 

typedef   void   (*SysTickCallBackFunc)(void);																								

																								
/*-- External functions ------------------------------------------------------*/  
void     			hal_mcu_init(void);
void  				hal_mcu_reset(void);																								
u32_t         hal_get_sys_freq(void);
u32_t    			hal_get_tick(void);
void  				hal_tick_delay(u32_t delay);
void					hal_gpio_low_power_config(void);																								
void  				hal_tick_suspend(void);
void  				hal_tick_resume(void);				
void  				hal_mcu_sleep(void);		
void  				hal_mcu_stop(void);
void  				hal_mcu_standby(void);	
void  				hal_mcu_low_power_prepare(void);
void  				hal_mcu_low_power_exit(void);																								
void          hal_systick_update_callback_register(SysTickCallBackFunc func);

#endif
  
#ifdef __cplusplus
}
#endif



/*------------------ end of file ---------------------------------------------*/
