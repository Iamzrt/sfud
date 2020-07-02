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
static   SPI_HandleTypeDef    spi1Handle;



/*-- functions ---------------------------------------------------------------*/

	
	
/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
void   hal_spi1_init(void)
{
	__HAL_RCC_SPI1_CLK_ENABLE();
	
  spi1Handle.Instance = SPI1;
  spi1Handle.Init.Mode = SPI_MODE_MASTER;
  spi1Handle.Init.Direction = SPI_DIRECTION_2LINES;
  spi1Handle.Init.DataSize = SPI_DATASIZE_8BIT;
  spi1Handle.Init.CLKPolarity = SPI_POLARITY_HIGH;
  spi1Handle.Init.CLKPhase = SPI_PHASE_2EDGE;
  spi1Handle.Init.NSS = SPI_NSS_SOFT;
  spi1Handle.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  spi1Handle.Init.FirstBit = SPI_FIRSTBIT_MSB;
  spi1Handle.Init.TIMode = SPI_TIMODE_DISABLE;
  spi1Handle.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  spi1Handle.Init.CRCPolynomial = 7;
  HAL_SPI_Init(&spi1Handle);
	
	__HAL_SPI_ENABLE(&spi1Handle);
}

void   hal_spi1_deinit(void)
{
	__HAL_SPI_DISABLE(&spi1Handle);
	__HAL_RCC_SPI1_CLK_DISABLE();
}


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
SysStatusType  hal_spi1_read_byte(u8_t addr, u8_t* readData)
{
	u16_t retry = 0;
	
	while(__HAL_SPI_GET_FLAG(&spi1Handle, SPI_FLAG_TXE) == RESET) 
	{
		retry++;
		if(retry>200)
		{
			return OPERATE_FAIL;
		}
	}		
	
  SPI1->DR = addr;
	retry = 0;

	while (__HAL_SPI_GET_FLAG(&spi1Handle, SPI_FLAG_RXNE) == RESET)
	{
		retry++;
		if(retry>500)
		{
			return OPERATE_FAIL;
		}
	}	  	
  
  *readData = SPI1->DR;
	
	return OPERATE_OK;
}	
	


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
SysStatusType  hal_spi1_write_byte(u8_t addr)
{
	u16_t retry = 0;
	
	while (__HAL_SPI_GET_FLAG(&spi1Handle, SPI_FLAG_TXE) == RESET) 
	{
		retry++;
		if(retry>200)
		{
			return OPERATE_FAIL;
		}
	}		

  SPI1->DR = addr;
	
	retry = 0;
	while (__HAL_SPI_GET_FLAG(&spi1Handle, SPI_FLAG_RXNE) == RESET)
	{
		retry++;
		if(retry>500)
		{
			return OPERATE_FAIL;
		}
	}	  	
  
  retry = SPI1->DR;
	
	return OPERATE_OK;
}	  


/** 
  * @brief   
  * @param    
  * @param    
  * @return  
  */
SysStatusType   hal_spi1_write_read(u8_t *writeBuf, size_t writeSize, u8_t *readBuf, size_t readSize)
{
	SysStatusType ret = OPERATE_OK;

  if(writeSize > 0)
	{
	  HAL_SPI_Transmit(&spi1Handle, writeBuf, writeSize, 0xffffffff);
	}
	
	if(readSize > 0)
	{
	  HAL_SPI_Receive(&spi1Handle, readBuf, readSize, 0xffffffff);
	}

	return ret;
}

/*------------------ end of file ---------------------------------------------*/
