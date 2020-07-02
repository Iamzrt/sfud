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
#define   DB_LOG(s)       					hal_uart5_putstring(s)

/*-- private variables -------------------------------------------------------*/

static   UART_HandleTypeDef      uart5Handle;
static   UartRxIrqCallbackFunc   uart5RxIrqCallbackPt = NULL;


/*-- functions ---------------------------------------------------------------*/
	
	
/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
static  u16_t usart_receive_data(USART_TypeDef* USARTx)
{
  /* Receive Data */
  return (u16_t)(USARTx->DR & (uint16_t)0x01FF);
}



/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void hal_uart5_putchar(u8_t data)
{
	while(__HAL_UART_GET_FLAG(&uart5Handle, UART_FLAG_TC) == RESET){}
	uart5Handle.Instance->DR = (data & (u16_t)0x01FF);
}

void hal_uart5_putstring(const char* s)
{
	while(*s != '\0')
	{
		hal_uart5_putchar(*s);
		s++;
	}
}	


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void  hal_uart5_rx_callback_register(UartRxIrqCallbackFunc callback)
{
	if(callback)   
	{
		uart5RxIrqCallbackPt = callback;
	}
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void   hal_uart5_init(u32_t baud)
{
	/* Enable USARTx clock */
  __HAL_RCC_UART5_CLK_ENABLE();
	
//	if(HAL_UART_DeInit(&uart5Handle) != HAL_OK)
//  {
//  }
	
	/* UART configuration  */
	uart5Handle.Instance        = UART5;
  uart5Handle.Init.BaudRate   = baud;
  uart5Handle.Init.WordLength = UART_WORDLENGTH_8B;
  uart5Handle.Init.StopBits   = UART_STOPBITS_1;
  uart5Handle.Init.Parity     = UART_PARITY_NONE;
  uart5Handle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  uart5Handle.Init.Mode       = UART_MODE_TX_RX;
 
	__HAL_UART_DISABLE(&uart5Handle);
	
  if(HAL_UART_Init(&uart5Handle) != HAL_OK)
  {
  }
    	
	__HAL_UART_DISABLE_IT(&uart5Handle, UART_IT_TXE);
	__HAL_UART_ENABLE_IT(&uart5Handle, UART_IT_RXNE);
	
	  /*##-3- Configure the NVIC for UART ########################################*/
  /* NVIC for USART */
  HAL_NVIC_SetPriority(UART5_IRQn, 0, 1);
  HAL_NVIC_EnableIRQ(UART5_IRQn);
	
	__HAL_UART_ENABLE(&uart5Handle);
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void   hal_uart5_deinit(void)
{
	__HAL_UART_DISABLE_IT(&uart5Handle, UART_IT_TXE);
	__HAL_UART_DISABLE_IT(&uart5Handle, UART_IT_RXNE);
	__HAL_UART_CLEAR_FLAG(&uart5Handle, UART_FLAG_RXNE);
	__HAL_UART_CLEAR_FLAG(&uart5Handle, UART_FLAG_ORE);
	__HAL_UART_DISABLE(&uart5Handle);
//	if(HAL_UART_DeInit(&uart5Handle) != HAL_OK)
//  {
//  }
	__HAL_RCC_UART5_CLK_DISABLE();
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
INTERRUPT_FUNC  void UART5_IRQHandler(void)
{
	u16_t data = 0;
	
//	if( __HAL_UART_GET_FLAG(&uart5Handle, UART_FLAG_NE ) != RESET )
//  {
//		__HAL_UART_CLEAR_NEFLAG(&uart5Handle);
//	}
//	
//	if( __HAL_UART_GET_FLAG(&uart5Handle, UART_FLAG_FE ) != RESET )
//  {
//		__HAL_UART_CLEAR_FEFLAG(&uart5Handle);
//	}
	
  if( __HAL_UART_GET_FLAG(&uart5Handle, UART_FLAG_ORE ) != RESET )
  { 
		data = usart_receive_data( UART5 );
    __HAL_UART_CLEAR_OREFLAG(&uart5Handle);
  } 
  
  //if((__HAL_UART_GET_IT_SOURCE(&Uart5Handle, UART_IT_RXNE)!=RESET) && \
		 (__HAL_UART_GET_FLAG(&Uart5Handle, UART_FLAG_RXNE )!=RESET ))
	if(__HAL_UART_GET_FLAG(&uart5Handle, UART_FLAG_RXNE )!=RESET )
  {
		data = usart_receive_data( UART5 );
		if(uart5RxIrqCallbackPt != NULL)
		{
			uart5RxIrqCallbackPt(data);
		} 
		__HAL_UART_CLEAR_FLAG(&uart5Handle, UART_FLAG_RXNE);
  }
	
	/* when dma transmit finished, it can generate the flag -- USART_FLAG_TC*/
	//if(__HAL_UART_GET_FLAG(&Uart5Handle, UART_FLAG_TC )!=RESET )
  //{
	//	__HAL_UART_CLEAR_FLAG(&Uart5Handle, UART_FLAG_TC);
	//}
}


/*------------------ end of file ---------------------------------------------*/
