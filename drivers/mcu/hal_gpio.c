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
#define            DEBUG_TX_PORT               GPIOC
#define            DEBUG_TX_PIN                GPIO_PIN_12
#define            DEBUG_TX_MODE               GPIO_MODE_AF_PP
#define            DEBUG_TX_PULL               GPIO_NOPULL //GPIO_PULLUP //
#define            DEBUG_TX_SPEED              GPIO_SPEED_FREQ_LOW

#define            DEBUG_RX_PORT               GPIOD
#define            DEBUG_RX_PIN                GPIO_PIN_2
#define            DEBUG_RX_MODE               GPIO_MODE_INPUT
#define            DEBUG_RX_PULL               GPIO_NOPULL
#define            DEBUG_RX_SPEED              GPIO_SPEED_FREQ_LOW

#define            FLASH_SPI_CS_PORT           GPIOA
#define            FLASH_SPI_CS_PIN            GPIO_PIN_4 //GPIO_PIN_2  //
#define            FLASH_SPI_CS_MODE           GPIO_MODE_OUTPUT_PP
#define            FLASH_SPI_CS_PULL           GPIO_NOPULL
#define            FLASH_SPI_CS_SPEED          GPIO_SPEED_FREQ_LOW 

#define            FLASH_SPI_SCLK_PORT         GPIOA
#define            FLASH_SPI_SCLK_PIN          GPIO_PIN_5
#define            FLASH_SPI_SCLK_MODE         GPIO_MODE_AF_PP
#define            FLASH_SPI_SCLK_PULL         GPIO_NOPULL //GPIO_PULLUP
#define            FLASH_SPI_SCLK_SPEED        GPIO_SPEED_FREQ_HIGH 

#define            FLASH_SPI_MISO_PORT         GPIOA
#define            FLASH_SPI_MISO_PIN          GPIO_PIN_6
#define            FLASH_SPI_MISO_MODE         GPIO_MODE_INPUT
#define            FLASH_SPI_MISO_PULL         GPIO_NOPULL
#define            FLASH_SPI_MISO_SPEED        GPIO_SPEED_FREQ_HIGH 

#define            FLASH_SPI_MOSI_PORT         GPIOA
#define            FLASH_SPI_MOSI_PIN          GPIO_PIN_7
#define            FLASH_SPI_MOSI_MODE         GPIO_MODE_AF_PP
#define            FLASH_SPI_MOSI_PULL         GPIO_NOPULL //GPIO_PULLUP
#define            FLASH_SPI_MOSI_SPEED        GPIO_SPEED_FREQ_HIGH 

#define            FLASH_WP_PORT               GPIOC
#define            FLASH_WP_PIN                GPIO_PIN_4
#define            FLASH_WP_MODE               GPIO_MODE_OUTPUT_PP
#define            FLASH_WP_PULL               GPIO_NOPULL
#define            FLASH_WP_SPEED              GPIO_SPEED_FREQ_LOW 


/*-- typedef -----------------------------------------------------------------*/
typedef  struct  HalGpioConfigStruct
{
  GPIO_TypeDef*         port;
  u32_t                 pin;
  u32_t                 mode;
	u32_t                 pull;
	u32_t                 speed;
}HalGpioConfigStruct;


/*-- private variables -------------------------------------------------------*/
static  const  HalGpioConfigStruct  gpioConfigArray[] = 
{
	[DEBUG_TX_GPIO] = 
  {
    DEBUG_TX_PORT, DEBUG_TX_PIN, DEBUG_TX_MODE, DEBUG_TX_PULL, DEBUG_TX_SPEED
  },
	
	[DEBUG_RX_GPIO] = 
  {
    DEBUG_RX_PORT, DEBUG_RX_PIN, DEBUG_RX_MODE, DEBUG_RX_PULL, DEBUG_RX_SPEED
  },

	[FLASH_SPI_CS_GPIO] = 
	{
	  FLASH_SPI_CS_PORT, FLASH_SPI_CS_PIN, FLASH_SPI_CS_MODE, FLASH_SPI_CS_PULL, FLASH_SPI_CS_SPEED
	},
	
	[FLASH_SPI_SCLK_GPIO] = 
	{
		FLASH_SPI_SCLK_PORT, FLASH_SPI_SCLK_PIN, FLASH_SPI_SCLK_MODE, FLASH_SPI_SCLK_PULL, FLASH_SPI_SCLK_SPEED
	},
	
	[FLASH_SPI_MISO_GPIO] = 
	{
		FLASH_SPI_MISO_PORT, FLASH_SPI_MISO_PIN, FLASH_SPI_MISO_MODE, FLASH_SPI_MISO_PULL, FLASH_SPI_MISO_SPEED
	},
	
	[FLASH_SPI_MOSI_GPIO] = 
	{
		FLASH_SPI_MOSI_PORT, FLASH_SPI_MOSI_PIN, FLASH_SPI_MOSI_MODE, FLASH_SPI_MOSI_PULL, FLASH_SPI_MOSI_SPEED
	},
	
	[FLASH_WP_GPIO] = 
	{
		FLASH_WP_PORT, FLASH_WP_PIN, FLASH_WP_MODE, FLASH_WP_PULL, FLASH_WP_SPEED
	},
};

#define      GPIO_SIZE     sizeof(gpioConfigArray)/sizeof(HalGpioConfigStruct)
	

/*-- functions ---------------------------------------------------------------*/

/** 
  * @brief    
  * @param    NONE
  * @return   NONE
  */
void  hal_gpio_init(void)
{
  u8_t  i = 0;
  GPIO_InitTypeDef   hgpio;

	__HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();	
	__HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
	
  for(i=0; i<GPIO_SIZE; i++)
  {
		hgpio.Mode  = gpioConfigArray[i].mode;
		hgpio.Pin   = gpioConfigArray[i].pin;
		hgpio.Pull  = gpioConfigArray[i].pull;
		hgpio.Speed = gpioConfigArray[i].speed;
    HAL_GPIO_Init(gpioConfigArray[i].port, &hgpio);
  }
}


/** 
  * @brief    
  * @param    gpio     @see HalGpioSelect
  * @param    level    @see HalGpioOutLevel
  * @return   NONE
  */
void  hal_gpio_write(HalGpioSelect gpio, HalGpioOutLevel level)
{
  if(level == O_LOW_LEVEL)
  {
		HAL_GPIO_WritePin(gpioConfigArray[gpio].port, gpioConfigArray[gpio].pin, GPIO_PIN_RESET);
  }
  else if(level == O_HIGH_LEVEL)
  {
    HAL_GPIO_WritePin(gpioConfigArray[gpio].port, gpioConfigArray[gpio].pin, GPIO_PIN_SET);
  }
  else if(level == O_REVERSE_LEVEL)
  {
    HAL_GPIO_TogglePin(gpioConfigArray[gpio].port, gpioConfigArray[gpio].pin);
  }
}


/** 
  * @brief    
  * @param    gpio  @see HalGpioSelect
  * @return   @see HalGpioInLevel
  */
HalGpioInLevel  hal_gpio_read(HalGpioSelect gpio)
{
  if(GPIO_PIN_RESET == HAL_GPIO_ReadPin(gpioConfigArray[gpio].port, gpioConfigArray[gpio].pin))
  {
    return  I_LOW_LEVEL;
  }
  else
  {
    return  I_HIGH_LEVEL;
  }
}


/** 
  * @brief    
  * @param    
  * @return   
  */
void*  hal_gpio_ctrl(HalGpioCtrlType cmd, void* param)
{
	void*    ret = NULL;
	GPIO_InitTypeDef    hgpio;
	HalChangeIOStruct*  changeIOStruct;
	
	switch(cmd)
	{
	  case CHANGE_IO_MODE:
		{
			changeIOStruct = (HalChangeIOStruct*)param;
			/* It must init all structure param. */
			hgpio.Mode     = changeIOStruct->mode;		
			hgpio.Pull     = gpioConfigArray[changeIOStruct->gpio].pull;
			hgpio.Pin      = gpioConfigArray[changeIOStruct->gpio].pin;
			hgpio.Speed    = gpioConfigArray[changeIOStruct->gpio].speed; 
			HAL_GPIO_Init(gpioConfigArray[changeIOStruct->gpio].port, &hgpio);
		}break;
		
		default:
			break;
	}
	
	return  ret;
}


/*------------------ end of file ---------------------------------------------*/
