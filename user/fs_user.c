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
#include "../drivers/mcu/hal_mcu.h"
#include "./console.h"
#include "./fs_user.h"
#include "./spi_flash.h"
#include "../components/lfs/lfs.h"
#include "../components/lfs/lfs_util.h"

/*-- defined -----------------------------------------------------------------*/
#define    DB_LOG(fmt, ...)               LOG("[FS_U]");LOG(fmt, ##__VA_ARGS__)
#define    FUN_EXPORT( FNAME , INFO)   		CO_CONSOLE_EXPORT( FNAME , INFO)



/*-- typedef -----------------------------------------------------------------*/



/*-- private variables -------------------------------------------------------*/
static  lfs_t  lfs;
static  lfs_file_t  file;
static  struct  lfs_config cfg;

static  u8_t lfsReadBuff[SPI_FLASH_PAGE_SIZE];
static  u8_t lfsProgBuff[SPI_FLASH_PAGE_SIZE];
static  u8_t lfsLookAheadBuff[SPI_FLASH_PAGE_SIZE];
static  u8_t lfsFileBuff[SPI_FLASH_PAGE_SIZE];

/*-- functions ---------------------------------------------------------------*/

/** @function
	* @brief
	* @param
	* @return 
	*/
static  int  block_device_read(const struct  lfs_config* c, lfs_block_t block, \
	                             lfs_off_t off, void* buffer, lfs_size_t size)
{
	int ret = 0;

  if(OPERATE_OK != spi_flash_read_buff(block * (c->block_size) + off, (u8_t*)buffer,  size))
	{
	  ret = -1;
		DB_LOG("Read device fail.\r\n");
	}
	
	return ret;
}	
	
/** @function
	* @brief
	* @param
	* @return 
	*/
static  int  block_device_prog(const struct  lfs_config* c, lfs_block_t block, \
	                             lfs_off_t off, const void* buffer, lfs_size_t size)
{
	int ret = 0;

  if(OPERATE_OK != spi_flash_write_buff(block * (c->block_size) + off, (u8_t*)buffer,  size))
	{
	  ret = -1;
		DB_LOG("Write device fail.\r\n");
	}
	
	return ret;
}	

/** @function
	* @brief
	* @param
	* @return 
	*/
static  int  block_device_erase(const struct  lfs_config* c, lfs_block_t block)
{
	int ret = 0;

  //if(OPERATE_OK != spi_flash_erase_sector(block * (c->block_size)))
	if(OPERATE_OK != spi_flash_erase_sector(block))
	{
	  ret = -1;
		DB_LOG("Erase device fail.\r\n");
	}
	
	return ret;
}	
	
/** @function
	* @brief
	* @param
	* @return 
	*/
static  int  block_device_sync(const struct  lfs_config* c)
{

	return 0;
}	

/** @function
	* @brief
	* @param
	* @return 
	*/
SysStatusType  		fs_user_init(void)
{
  SysStatusType  ret;
	
	cfg.read_size      = SPI_FLASH_PAGE_SIZE;
	cfg.prog_size      = SPI_FLASH_PAGE_SIZE;
	cfg.lookahead_size = SPI_FLASH_PAGE_SIZE;
	cfg.block_size     = SPI_FLASH_SECTOR_SIZE;
	cfg.block_count    = 2048;
	
	cfg.read_buffer      = lfsReadBuff;
	cfg.prog_buffer      = lfsProgBuff;
	cfg.lookahead_buffer = lfsLookAheadBuff;
	//cfg.file_buffer      = lfsFileBuff;
	
	cfg.read  = block_device_read;
	cfg.prog  = block_device_prog;
	cfg.erase = block_device_erase;
  cfg.sync  = block_device_sync;
	
	int err = lfs_mount(&lfs, &cfg);
	if(err)
	{
		DB_LOG("Mount fs fail.\r\n");
	  err = lfs_format(&lfs, &cfg);
		err = lfs_mount(&lfs, &cfg);
	}
	else
	{
	  DB_LOG("Mount fs sucessfull.\r\n");
	}
	
	return ret;
}

/*------------------ end of file ---------------------------------------------*/


