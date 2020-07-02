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

#ifndef   HAL_UART_H
#define   HAL_UART_H

/* C++ */
#ifdef __cplusplus
extern "C" {
#endif
  
  
/*-- includes ----------------------------------------------------------------*/

 

  
/*-- typedef  ----------------------------------------------------------------*/
typedef  void  (*UartRxIrqCallbackFunc)(u16_t  dat);
	
  
/*-- External functions ------------------------------------------------------*/  

void   				hal_uart5_init(u32_t baud);	
void   				hal_uart5_deinit(void);
void 					hal_uart5_putchar(u8_t data);
void 					hal_uart5_putstring(const char* s);
void  				hal_uart5_rx_callback_register(UartRxIrqCallbackFunc callback);


#endif
  
#ifdef __cplusplus
}
#endif


/*------------------ end of file ---------------------------------------------*/
