/**
  ******************************************************************************
  * @file     main.c
  * @author   ZRT
  * @version  V1.0
  * @date     2019/08/02
  * @attention  VECT_TAB_OFFSET
	* @warning	
  ******************************************************************************  
  * 
  * 
  ******************************************************************************
  */
/*-- includes ----------------------------------------------------------------*/
#include "../drivers/mcu/hal_mcu.h"
#include "./main.h"
#include "./fs_user.h"
#include "sfud.h"



/*-- defined -----------------------------------------------------------------*/
#define   DB_LOG(fmt, ...)       					LOG("[MAIN]");LOG(fmt, ##__VA_ARGS__)

  



/*-- private variables -------------------------------------------------------*/


/*-- private functions -------------------------------------------------------*/



/*-- functions ---------------------------------------------------------------*/

void __aeabi_assert(const char *s1, const char *s2, int a)
{

}

/** @function
	* @brief
	* @param
	* @return 
	* @note
	*/
int fputc(int ch, FILE *f)
{
  hal_uart5_putchar(ch);
  return ch;
}


/** @function
	* @brief
	* @param
	* @return 
	* @note
	*/
void  sys_power_on(void)
{

}


/* USER CODE BEGIN 0 */
void sfud_demo(uint32_t addr, size_t size, uint8_t *data);

#define SFUD_DEMO_TEST_BUFFER_SIZE                     1024
static uint8_t sfud_demo_test_buf[SFUD_DEMO_TEST_BUFFER_SIZE];


/**
 * SFUD demo for the first flash device test.
 *
 * @param addr flash start address
 * @param size test flash size
 * @param size test flash data buffer
 */
void sfud_demo(uint32_t addr, size_t size, uint8_t *data)
{
    sfud_err result = SFUD_SUCCESS;
    extern sfud_flash *sfud_dev;
    const sfud_flash *flash = sfud_get_device(SFUD_GD25Q16C_DEVICE_INDEX);
    size_t i;
    /* prepare write data */
    for (i = 0; i < size; i++)
    {
        data[i] = i;
    }
    /* erase test */
    result = sfud_erase(flash, addr, size);
    if (result == SFUD_SUCCESS)
    {
        printf("Erase the %s flash data finish. Start from 0x%08X, size is %zu.\r\n", flash->name, addr, size);
    }
    else
    {
        printf("Erase the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* write test */
    result = sfud_write(flash, addr, size, data);
    if (result == SFUD_SUCCESS)
    {
        printf("Write the %s flash data finish. Start from 0x%08X, size is %zu.\r\n", flash->name, addr, size);
    }
    else
    {
        printf("Write the %s flash data failed.\r\n", flash->name);
        return;
    }
    /* read test */
    result = sfud_read(flash, addr, size, data);
    if (result == SFUD_SUCCESS)
    {
        printf("Read the %s flash data success. Start from 0x%08X, size is %zu. The data is:\r\n", flash->name, addr, size);
        printf("Offset (h) 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F\r\n");
        for (i = 0; i < size; i++)
        {
            if (i % 16 == 0)
            {
                printf("[%08X] ", addr + i);
            }
            printf("%02X ", data[i]);
            if (((i + 1) % 16 == 0) || i == size - 1)
            {
                printf("\r\n");
            }
        }
        printf("\r\n");
    }
    else
    {
        printf("Read the %s flash data failed.\r\n", flash->name);
    }
    /* data check */
    for (i = 0; i < size; i++)
    {
				
        if (data[i] != i % 256)
        {
            printf("Read and check write data has an error. Write the %s flash data failed.\r\n", flash->name);
            break;
        }
    }
    if (i == size)
    {
        printf("The %s flash test is success.\r\n", flash->name);
    }
}


/** @function  
  * @brief   
  * @param    
  * @param    
  * @return  
  */
int main(void)
{	
	/* mcu common init. */
	hal_mcu_init();
	
	sys_power_on();
  hal_gpio_write(FLASH_WP_GPIO, O_HIGH_LEVEL);
	
	//fs_user_init();
  if (sfud_init() == SFUD_SUCCESS)
  {
    /* enable qspi fast read mode, set one data lines width */
    //sfud_qspi_fast_read_enable(sfud_get_device(SFUD_W25_DEVICE_INDEX), 1);
    
#if  0    
    sfud_demo(0, sizeof(sfud_demo_test_buf), sfud_demo_test_buf);
#endif
  }
	
	//printf("Compile at %s,%s\r\n", __DATE__, __TIME__);
	
	/* main loop. */
	while(1)
	{

	}
}



/*------------------ end of file ---------------------------------------------*/

