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

#ifndef   _ADDR_DEFINED_H
#define   _ADDR_DEFINED_H


/*----------------------   External flash address    --------------------------*/
#define		EX_ADDR_START										  0x00000000
#define		EX_ADDR_END											  0x00200000


/**
* {
*/
/*< Address base. >*/
#define   EX_PARAM_ADDR_BASE               	EX_ADDR_START

#define   PACK_SERIAL_NUM_MAX_SIZE          14

/*< Flag and manufacture address. >*/
#define		EX_BATT_ACTIVE_FLAG_ADDR					(EX_PARAM_ADDR_BASE+0) 

#define		EX_MANUFACTURE_YEAR_ADDR					(EX_PARAM_ADDR_BASE+1) 
#define		EX_MANUFACTURE_MONTH_ADDR					(EX_PARAM_ADDR_BASE+2) 
#define		EX_MANUFACTURE_DAY_ADDR					  (EX_PARAM_ADDR_BASE+3)  

#define		EX_DESIGN_CAPACITY_L_ADDR					(EX_PARAM_ADDR_BASE+4)
#define		EX_DESIGN_CAPACITY_H_ADDR					(EX_PARAM_ADDR_BASE+5)

#define		EX_SERIES_NUM_ADDR								(EX_PARAM_ADDR_BASE+6)
#define		EX_PARALLEL_NUM_ADDR							(EX_PARAM_ADDR_BASE+7)

#define		EX_SOC_ALARM_ADDR									(EX_PARAM_ADDR_BASE+8)
#define		EX_SOH_ALARM_ADDR									(EX_PARAM_ADDR_BASE+9)

#define		EX_DESIGN_VOLT_L_ADDR							(EX_PARAM_ADDR_BASE+10)
#define		EX_DESIGN_VOLT_H_ADDR							(EX_PARAM_ADDR_BASE+11)

#define		EX_FULL_VOLT_L_ADDR								(EX_PARAM_ADDR_BASE+12)
#define		EX_FULL_VOLT_H_ADDR								(EX_PARAM_ADDR_BASE+13)

#define		EX_DISCHARGE_RATE_ADDR						(EX_PARAM_ADDR_BASE+14)

#define		EX_INNER_RES_ADDR									(EX_PARAM_ADDR_BASE+15)

#define   EX_PACK_SERIAL_NUM_ADDR          	(EX_PARAM_ADDR_BASE+16)   
#define   EX_PACK_SERIAL_NUM_LEN_ADDR       (EX_PACK_SERIAL_NUM_ADDR+PACK_SERIAL_NUM_MAX_SIZE)

#define   EX_USER_DEFINED_ADDR              (EX_PACK_SERIAL_NUM_LEN_ADDR+1)

#define   EX_SHA1_H0_1_ADDR                 (EX_USER_DEFINED_ADDR+0)
#define   EX_SHA1_H0_2_ADDR                 (EX_USER_DEFINED_ADDR+1)
#define   EX_SHA1_H0_3_ADDR                 (EX_USER_DEFINED_ADDR+2)
#define   EX_SHA1_H0_4_ADDR                 (EX_USER_DEFINED_ADDR+3)

#define   EX_SHA1_H1_1_ADDR                 (EX_USER_DEFINED_ADDR+4)
#define   EX_SHA1_H1_2_ADDR                 (EX_USER_DEFINED_ADDR+5)
#define   EX_SHA1_H1_3_ADDR                 (EX_USER_DEFINED_ADDR+6)
#define   EX_SHA1_H1_4_ADDR                 (EX_USER_DEFINED_ADDR+7)

#define   EX_SHA1_H2_1_ADDR                 (EX_USER_DEFINED_ADDR+8)
#define   EX_SHA1_H2_2_ADDR                 (EX_USER_DEFINED_ADDR+9)
#define   EX_SHA1_H2_3_ADDR                 (EX_USER_DEFINED_ADDR+10)
#define   EX_SHA1_H2_4_ADDR                 (EX_USER_DEFINED_ADDR+11)

#define   EX_SHA1_H3_1_ADDR                 (EX_USER_DEFINED_ADDR+12)
#define   EX_SHA1_H3_2_ADDR                 (EX_USER_DEFINED_ADDR+13)
#define   EX_SHA1_H3_3_ADDR                 (EX_USER_DEFINED_ADDR+14)
#define   EX_SHA1_H3_4_ADDR                 (EX_USER_DEFINED_ADDR+15)

#define   EX_SHA1_H4_1_ADDR                 (EX_USER_DEFINED_ADDR+16)
#define   EX_SHA1_H4_2_ADDR                 (EX_USER_DEFINED_ADDR+17)
#define   EX_SHA1_H4_3_ADDR                 (EX_USER_DEFINED_ADDR+18)
#define   EX_SHA1_H4_4_ADDR                 (EX_USER_DEFINED_ADDR+19)

/**
* }
*/	


/**
* {
*/
/*< Protection parameter address. >*/
#define		EX_PRO_ADDR_OFFSET                				64       /* 64 bytes offset. */
#define		EX_PRO_ADDR_BASE													(EX_PARAM_ADDR_BASE+EX_PRO_ADDR_OFFSET)

#define   EX_PRO_SAVE_FLAG_ADDR				 							(EX_PRO_ADDR_BASE+0)	


/*--------  Charge OC.  -------- */
#define   EX_OCC_L_ADDR	     										    (EX_PRO_ADDR_BASE+1)   
#define   EX_OCC_H_ADDR	     										    (EX_PRO_ADDR_BASE+2) 
#define   EX_OCC_DELAY_ADDR	            				    (EX_PRO_ADDR_BASE+3)
#define   EX_OCC_RELEASE_L_ADDR	     						    (EX_PRO_ADDR_BASE+4) 
#define   EX_OCC_RELEASE_H_ADDR	     						    (EX_PRO_ADDR_BASE+5) 
#define   EX_OCC_RELEASE_DELAY_ADDR	                (EX_PRO_ADDR_BASE+6)


/*--------  Cell OV. -------- */
#define   EX_COV_L_ADDR	     									      (EX_PRO_ADDR_BASE+7)   
#define   EX_COV_H_ADDR	     									      (EX_PRO_ADDR_BASE+8) 
#define   EX_COV_DELAY_ADDR	            			      (EX_PRO_ADDR_BASE+9)
#define   EX_COV_RELEASE_L_ADDR	     					      (EX_PRO_ADDR_BASE+10) 
#define   EX_COV_RELEASE_H_ADDR	     					      (EX_PRO_ADDR_BASE+11) 
#define   EX_COV_RELEASE_DELAY_ADDR	                (EX_PRO_ADDR_BASE+12)


/*--------  DisCharge OC. -------- */
#define   EX_OCD_L_ADDR	     				        		    (EX_PRO_ADDR_BASE+13)   
#define   EX_OCD_H_ADDR	     				        		    (EX_PRO_ADDR_BASE+14) 
#define   EX_OCD_DELAY_ADDR	                        (EX_PRO_ADDR_BASE+15)
#define   EX_OCD_RELEASE_L_ADDR	                    (EX_PRO_ADDR_BASE+16) 
#define   EX_OCD_RELEASE_H_ADDR	                    (EX_PRO_ADDR_BASE+17) 
#define   EX_OCD_RELEASEDELAY_ADDR	                (EX_PRO_ADDR_BASE+18)


/*--------  Cell UV. -------- */
#define   EX_CUV_L_ADDR	     		          		      (EX_PRO_ADDR_BASE+19)  
#define   EX_CUV_H_ADDR	     		          		      (EX_PRO_ADDR_BASE+20) 
#define   EX_CUV_DELAY_ADDR	                        (EX_PRO_ADDR_BASE+21)
#define   EX_CUV_RELEASE_L_ADDR	                    (EX_PRO_ADDR_BASE+22)
#define   EX_CUV_RELEASE_H_ADDR	                    (EX_PRO_ADDR_BASE+23)
#define   EX_CUV_RELEASE_DELAY_ADDR	                (EX_PRO_ADDR_BASE+24)



/*--------  DisCharge short current. -------- */
#define 	EX_SCD_L_ADDR															(EX_PRO_ADDR_BASE+25) 
#define 	EX_SCD_H_ADDR															(EX_PRO_ADDR_BASE+26) 


/*--------  Charge OT. -------- */
#define   EX_OTC_L_ADDR	     										    (EX_PRO_ADDR_BASE+27)   
#define   EX_OTC_H_ADDR	     										    (EX_PRO_ADDR_BASE+28) 
#define   EX_OTC_DELAY_ADDR	         						    (EX_PRO_ADDR_BASE+29)
#define   EX_OTC_RELEASE_L_ADDR	  							    (EX_PRO_ADDR_BASE+30) 
#define   EX_OTC_RELEASE_H_ADDR	  							    (EX_PRO_ADDR_BASE+31) 
#define   EX_OTC_RELEASE_DELAY_ADDR	  					    (EX_PRO_ADDR_BASE+32) 


/*--------  Charge UT. -------- */
#define   EX_UTC_L_ADDR	     										    (EX_PRO_ADDR_BASE+33)
#define   EX_UTC_H_ADDR	     										    (EX_PRO_ADDR_BASE+34)
#define   EX_UTC_DELAY_ADDR	         						    (EX_PRO_ADDR_BASE+35)
#define   EX_UTC_RELEASE_L_ADDR	  							    (EX_PRO_ADDR_BASE+36)
#define   EX_UTC_RELEASE_H_ADDR	  							    (EX_PRO_ADDR_BASE+37)
#define   EX_UTC_RELEASE_DELAY_ADDR	  					    (EX_PRO_ADDR_BASE+38)


/*--------  DisCharge OT. -------- */
#define   EX_OTD_L_ADDR	     										    (EX_PRO_ADDR_BASE+39)  
#define   EX_OTD_H_ADDR	     										    (EX_PRO_ADDR_BASE+40) 
#define   EX_OTD_DELAY_ADDR	         						    (EX_PRO_ADDR_BASE+41)
#define   EX_OTD_RELEASE_L_ADDR	  							    (EX_PRO_ADDR_BASE+42)
#define   EX_OTD_RELEASE_H_ADDR	  							    (EX_PRO_ADDR_BASE+43)
#define   EX_OTD_RELEASE_DELAY_ADDR	  					    (EX_PRO_ADDR_BASE+44)


/*--------  DisCharge UT. -------- */
#define   EX_UTD_L_ADDR	     										    (EX_PRO_ADDR_BASE+45)  
#define   EX_UTD_H_ADDR	     										    (EX_PRO_ADDR_BASE+46) 
#define   EX_UTD_DELAY_ADDR	         						    (EX_PRO_ADDR_BASE+47)
#define   EX_UTD_RELEASE_L_ADDR	  							    (EX_PRO_ADDR_BASE+48)
#define   EX_UTD_RELEASE_H_ADDR	  							    (EX_PRO_ADDR_BASE+49)
#define   EX_UTD_RELEASE_DELAY_ADDR	  					    (EX_PRO_ADDR_BASE+50)


/*--------  Cell voltage differ large. -------- */
#define   EX_UNBAL_L_ADDR	     						          (EX_PRO_ADDR_BASE+51)  
#define   EX_UNBAL_H_ADDR	     						          (EX_PRO_ADDR_BASE+52)  
#define   EX_UNBAL_DELAY_ADDR	         		          (EX_PRO_ADDR_BASE+53)
#define   EX_UNBAL_RELEASE_L_ADDR	 				          (EX_PRO_ADDR_BASE+54)
#define   EX_UNBAL_RELEASE_H_ADDR	 				          (EX_PRO_ADDR_BASE+55)
#define   EX_UNBAL_RELEASE_DELAY_ADDR	 		          (EX_PRO_ADDR_BASE+56)


/*--------  Low voltage. -------- */
#define   EX_LOW_VOLT_L_ADDR	     									(EX_PRO_ADDR_BASE+57)   
#define   EX_LOW_VOLT_H_ADDR	     									(EX_PRO_ADDR_BASE+58) 
#define   EX_LOW_VOLT_DELAY_ADDR	            			(EX_PRO_ADDR_BASE+59)
#define   EX_LOW_VOLT_RELEASE_L_ADDR	     					(EX_PRO_ADDR_BASE+60) 
#define   EX_LOW_VOLT_RELEASE_H_ADDR	     					(EX_PRO_ADDR_BASE+61) 
#define   EX_LOW_VOLT_RELEASE_DELAY_ADDR	          (EX_PRO_ADDR_BASE+62)

/*--------  Bus over voltage. -------- */
#define   EX_BOV_L_ADDR	     										    (EX_PRO_ADDR_BASE+63)   
#define   EX_BOV_H_ADDR	     										    (EX_PRO_ADDR_BASE+64) 
#define   EX_BOV_DELAY_ADDR	            				    (EX_PRO_ADDR_BASE+65)
#define   EX_BOV_RELEASE_L_ADDR	     						    (EX_PRO_ADDR_BASE+66) 
#define   EX_BOV_RELEASE_H_ADDR	     						    (EX_PRO_ADDR_BASE+67) 
#define   EX_BOV_RELEASE_DELAY_ADDR	          	    (EX_PRO_ADDR_BASE+68)

/*--------  Bus under voltage. -------- */
#define   EX_BUV_L_ADDR	     										    (EX_PRO_ADDR_BASE+69)   
#define   EX_BUV_H_ADDR	     										    (EX_PRO_ADDR_BASE+70) 
#define   EX_BUV_DELAY_ADDR	            				    (EX_PRO_ADDR_BASE+71)
#define   EX_BUV_RELEASE_L_ADDR	     						    (EX_PRO_ADDR_BASE+72) 
#define   EX_BUV_RELEASE_H_ADDR	     						    (EX_PRO_ADDR_BASE+73) 
#define   EX_BUV_RELEASE_DELAY_ADDR	          	    (EX_PRO_ADDR_BASE+74)


/**
* }
*/


/**
* {
*/
/*< Error record address. >*/
#define		EX_ERROR_RECORD_ADDR_OFFSET                				256       /* 256 bytes offset. */
#define		EX_ERROR_RECORD_ADDR_BASE													(EX_PRO_ADDR_BASE+EX_ERROR_RECORD_ADDR_OFFSET)

#define   EX_ERROR_RECORD_BASE_ADDR				 									(EX_ERROR_RECORD_ADDR_BASE+0)	


/* Total error */
#define		EX_TOTAL_ERROR_SUM_L_ADDR													(EX_ERROR_RECORD_BASE_ADDR+0) 
#define		EX_TOTAL_ERROR_SUM_H_ADDR													(EX_ERROR_RECORD_BASE_ADDR+1)

#define		EX_OTC_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+2) 
#define		EX_OTC_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+3)

#define		EX_UTC_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+4) 
#define		EX_UTC_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+5)

#define		EX_OTD_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+6) 
#define		EX_OTD_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+7)

#define		EX_UTD_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+8) 
#define		EX_UTD_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+9)

#define		EX_COV_ERR_L_ADDR																	(EX_ERROR_RECORD_BASE_ADDR+10) 
#define		EX_COV_ERR_H_ADDR																	(EX_ERROR_RECORD_BASE_ADDR+11)

#define		EX_CUV_ERR_L_ADDR																	(EX_ERROR_RECORD_BASE_ADDR+12) 
#define		EX_CUV_ERR_H_ADDR																	(EX_ERROR_RECORD_BASE_ADDR+13)

#define		EX_UNBALANCE_ERR_L_ADDR											      (EX_ERROR_RECORD_BASE_ADDR+14) 
#define		EX_UNBALANCE_ERR_H_ADDR											      (EX_ERROR_RECORD_BASE_ADDR+15)

#define		EX_LOW_VOLT_ERR_L_ADDR														(EX_ERROR_RECORD_BASE_ADDR+16) 
#define		EX_LOW_VOLT_ERR_H_ADDR														(EX_ERROR_RECORD_BASE_ADDR+17)

#define		EX_OCD_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+18) 
#define		EX_OCD_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+19)

#define		EX_OCC_ERR_L_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+20) 
#define		EX_OCC_ERR_H_ADDR															    (EX_ERROR_RECORD_BASE_ADDR+21)


/* Single error record. */
#define		EX_SINGLE_ERR_SIZE																14
#define		EX_SINGLE_ERR_NUM																	10000  /* Items */
#define		EX_SINGLE_ERR_START_ADDR													(EX_ERROR_RECORD_BASE_ADDR+22)
#define		EX_SINGLE_ERR_END_ADDR														(EX_SINGLE_ERR_START_ADDR+EX_SINGLE_ERR_NUM*EX_SINGLE_ERR_SIZE)
/**
* }
*/


/**
* {
*/
#define		EX_LIFE_TIME_ADDR_BASE														(EX_SINGLE_ERR_END_ADDR+1)


/* Total use days */
#define		EX_TOTAL_USE_DAYS_L_ADDR													(EX_LIFE_TIME_ADDR_BASE+0) 
#define		EX_TOTAL_USE_DAYS_H_ADDR													(EX_LIFE_TIME_ADDR_BASE+1)

/* Last record date. */
#define		EX_LAST_LIFE_TIME_DATE_L_ADDR											(EX_LIFE_TIME_ADDR_BASE+2)
#define		EX_LAST_LIFE_TIME_DATE_H_ADDR											(EX_LIFE_TIME_ADDR_BASE+3)

/* Charge count */
#define		EX_CHG_COUNT_L_ADDR																(EX_LIFE_TIME_ADDR_BASE+4)
#define		EX_CHG_COUNT_H_ADDR																(EX_LIFE_TIME_ADDR_BASE+5)

/* Charge Full count */
#define		EX_CHG_FULL_COUNT_L_ADDR													(EX_LIFE_TIME_ADDR_BASE+6)
#define		EX_CHG_FULL_COUNT_H_ADDR													(EX_LIFE_TIME_ADDR_BASE+7)

/* DisCharge count */
#define		EX_DSG_COUNT_L_ADDR																(EX_LIFE_TIME_ADDR_BASE+8)
#define		EX_DSG_COUNT_H_ADDR																(EX_LIFE_TIME_ADDR_BASE+9)

/* Total fly time */
#define		EX_TOTAL_FLY_TIME_L_ADDR													(EX_LIFE_TIME_ADDR_BASE+10)
#define		EX_TOTAL_FLY_TIME_H_ADDR													(EX_LIFE_TIME_ADDR_BASE+11)

/* Illegal chg count */
#define		EX_ILLEGAL_CHG_COUNT_L_ADDR												(EX_LIFE_TIME_ADDR_BASE+12)
#define		EX_ILLEGAL_CHG_COUNT_H_ADDR												(EX_LIFE_TIME_ADDR_BASE+13)

/* Illegal dsg count */
#define		EX_ILLEGAL_DSG_COUNT_L_ADDR												(EX_LIFE_TIME_ADDR_BASE+14)
#define		EX_ILLEGAL_DSG_COUNT_H_ADDR												(EX_LIFE_TIME_ADDR_BASE+15)

/* Illegal dsg count */
#define		EX_ILLEGAL_FLAY_TIME_L_ADDR												(EX_LIFE_TIME_ADDR_BASE+16)
#define		EX_ILLEGAL_FLAY_TIME_H_ADDR												(EX_LIFE_TIME_ADDR_BASE+17)

/* Single lifetime record. */
#define		EX_SINGLE_LIFETIME_SIZE														(14+2) /* date+data */
#define		EX_SINGLE_LIFETIME_NUM														10000  /* Items */
#define		EX_SINGLE_LIFETIME_START_ADDR											(EX_LIFE_TIME_ADDR_BASE+18)
#define		EX_SINGLE_LIFETIME_END_ADDR												(EX_SINGLE_LIFETIME_START_ADDR+EX_SINGLE_LIFETIME_NUM*EX_SINGLE_LIFETIME_SIZE)

/**
* }
*/







/*----------------------   Internal flash address    --------------------------*/

/*< Bootloader address base. >*/
#define   			BOOTLOADER_ADDR_BASE               			0x08000000   /* bootloader: 32KB */


/*< APP address base. 96KB >*/
#define 				APP_START_ADDR       										0x8008000  

 
/*< Parameter address base. 2KB. >*/
#define   			PARAM_ADDR_BASE               					0x08020000
#define   			UPDATE_FLAG_L8_ADDR                     (PARAM_ADDR_BASE+0)
#define   			UPDATE_FLAG_H8_ADDR                     (PARAM_ADDR_BASE+1)
#define  	 			APP_SIZE_L8_ADDR                        (PARAM_ADDR_BASE+2)
#define   			APP_SIZE_M1_ADDR                        (PARAM_ADDR_BASE+3)
#define   			APP_SIZE_M2_ADDR                        (PARAM_ADDR_BASE+4)
#define   			APP_SIZE_H8_ADDR                        (PARAM_ADDR_BASE+5)
#define   			APP_CRC_L8_ADDR                         (PARAM_ADDR_BASE+6)	
#define   			APP_CRC_H8_ADDR                         (PARAM_ADDR_BASE+7)	

//#define					BLE_BAUDRATE_FLAG_ADDR									(PARAM_ADDR_BASE+8)	
//#define					BLE_BAUDRATE_L_ADDR											(PARAM_ADDR_BASE+9)	
//#define					BLE_BAUDRATE_H_ADDR											(PARAM_ADDR_BASE+10)	


/*< APP TEMP address base. 96KB  >*/
#define 				APP_TEMP_START_ADDR       							0x08020800  


/*< Deserve address base. 30KB  >*/
#define 				DESERVE_ADDR_START       							  0x08038800  





#endif
/*------------------ end of file ---------------------------------------------*/
