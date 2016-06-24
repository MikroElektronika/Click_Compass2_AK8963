/****************************************************************************
* Title                 :   Compass 2 Click HW layer
* Filename              :   compass2_hal.h
* Author                :   CAL
* Origin Date           :   04/27/2016
* Notes                 :   None
*****************************************************************************/
/**************************CHANGE LIST **************************************
*
*    Date      Software Version    Initials       Description
*  04/27/2016    XXXXXXXXXXX         CAL       Interface Created.
*
*****************************************************************************/
/**
 * @file compass2_hal.h
 *  @brief Hardware Access Layer for Compass 2 Click
 *
 *  @date 27 April 2016
 *  @author Corey Lakey
 *  @copyright GNU Public License
 *
 *  @version .1 - Initial testing and verification
 *
 *  @note Test configuration:
 *   MCU:             STM32F107VC
 *   Dev.Board:       EasyMx Pro v7
 *   Oscillator:      72 Mhz internal
 *   Ext. Modules:    Compass 2 Click
 *   SW:              ARM 4.5.2
 *
 */
#ifndef COMPASS_2_HAL_H
#define COMPASS_2_HAL_H
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
#define READ                    1                /**<  READ BIT	*/
#define WRITE                   0                /**<  WRITE BIT */
#define COMMAND_SIZE            1                /**<  COMMAND OR REGISTER SIZE ( Bytes ) */
#define MAX_BUFF_SIZE           256              /**<  BUFFER SIZE ( Bytes ) */
/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/
        
/******************************************************************************
* Typedefs
*******************************************************************************/

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

void compass2_hal_init( uint8_t address_id, uint8_t mode );

void compass2_hal_reset( void );

void compass2_hal_write(uint8_t *command, uint8_t *buffer,
                          uint8_t count);

void compass2_hal_read( uint8_t *command, uint8_t *buffer,
                         uint8_t count );
void compass2_hal_cs_high();

void compass2_hal_cs_low();

void compass2_hal_reset( void );

void compass2_hal_delay( uint32_t ms );


#ifdef __cplusplus
} // extern "C"
#endif

#endif /* CLICKNAME_HAL_H_ */

/*** End of File **************************************************************/
