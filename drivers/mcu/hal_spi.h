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

#ifndef   HAL_SPI_H
#define   HAL_SPI_H

/* C++ */
#ifdef __cplusplus
extern "C" {
#endif
  
  
/*-- includes ----------------------------------------------------------------*/
#include <string.h>
 

  
/*-- typedef  ----------------------------------------------------------------*/

  
/*-- External functions ------------------------------------------------------*/  
void   						hal_spi1_init(void); 
void   						hal_spi1_deinit(void);

SysStatusType  		hal_spi1_read_byte(u8_t addr, u8_t* readData);	
SysStatusType  		hal_spi1_write_byte(u8_t addr);
	
SysStatusType     hal_spi1_write_read(u8_t *writeBuf, size_t writeSize, u8_t *readBuf, size_t readSize);

  
#ifdef __cplusplus
}
#endif

#endif
/*------------------ end of file ---------------------------------------------*/
