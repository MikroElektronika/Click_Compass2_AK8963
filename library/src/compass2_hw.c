/*******************************************************************************
* Title                 :   Compass 2 Click HW Layer
* Filename              :   compass2_hw.c
* Author                :   CAL
* Origin Date           :   04/27/2016
* Notes                 :   None
*******************************************************************************/
/*************** MODULE REVISION LOG ******************************************
*
*    Date    Software Version    Initials      Description
*  04/27/2016   XXXXXXXXXXX         CAL       Module Created.
*
*******************************************************************************/
/** @file compass2_hw.c
 *  @brief This module contains the hardware layer for Compass 2 Click.
 */
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "compass2_hw.h"
#include "compass2_hal.h"
/******************************************************************************
* Module Preprocessor Constants
*******************************************************************************/

/******************************************************************************
* Module Preprocessor Macros
*******************************************************************************/

/******************************************************************************
* Module Typedefs
*******************************************************************************/

/******************************************************************************
* Module Variable Definitions
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/

/******************************************************************************
* Function Definitions
*******************************************************************************/

uint8_t compass2_hw_init(uint8_t address, bus_mode_t mode)
{
    uint8_t reg    = CNTL1;
    uint8_t buffer = 0;

    compass2_hal_init( address, mode );

    buffer = MODE_POWER_DOWN;
    compass2_hal_write( &reg, &buffer, 1 );
    compass2_hal_delay( 10 );

    return 0;
}

float compass2_get_compass_heading( int16_t x, int16_t y, int16_t z )
{
    float heading = 0;

    heading = 180 * atan2( y, x ) / 3.14159265359;

    return heading;
}

uint8_t compass2_get_device_id( void )
{
    uint8_t reg    = DEVICE_ID;
    uint8_t buffer = 0;

    compass2_hal_read( &reg, &buffer, 1 );

    return buffer;
}

uint8_t compass2_get_information( void )
{
    uint8_t reg    = INFORMATION;
    uint8_t buffer = 0;

    compass2_hal_read( &reg, &buffer, 1 );

    return buffer;
}

int16_t compass2_get_x_val( void )
{
    uint8_t reg     = HXL;
    uint8_t reg_2   = HXH;
    int16_t retval  = 0;
    uint8_t buffer  = 0;

    compass2_hal_read( &reg, &buffer, 1 );
    retval = (int16_t)buffer;
    compass2_hal_read( &reg_2, &buffer, 1 );
    retval |= ( (int16_t)buffer << 8 );

    return retval;
}

int16_t compass2_get_y_val( void )
{
    uint8_t reg     = HYL;
    uint8_t reg_2   = HYH;
    int16_t retval  = 0;
    uint8_t buffer  = 0;

    compass2_hal_read( &reg, &buffer, 1 );
    retval = (int16_t)buffer;
    compass2_hal_read( &reg_2, &buffer, 1 );
    retval |= ( (int16_t)buffer << 8 );

    return retval;

}

int16_t compass2_get_z_val( void )
{
    uint8_t reg     = HZL;
    uint8_t reg_2   = HZH;
    int16_t retval  = 0;
    uint8_t buffer  = 0;

    compass2_hal_read( &reg, &buffer, 1 );
    retval = (int16_t)buffer;
    compass2_hal_read( &reg_2, &buffer, 1 );
    retval |= ( (int16_t)buffer << 8 );

    return retval;

}

uint8_t compass2_get_all_values(int16_t *x, int16_t *y, int16_t *z )
{
    uint8_t reg_1   = HXL;
    uint8_t reg_2   = HXH;
    uint8_t reg_3   = HYL;
    uint8_t reg_4   = HYH;
    uint8_t reg_5   = HZL;
    uint8_t reg_6   = HZH;
    int16_t retval  = 0;
    uint8_t buffer  = 0;

	if( compass2_get_data_ready() )
	{

        compass2_hal_read( &reg_1, &buffer, 1 );
        retval = (int16_t)buffer;
        compass2_hal_read( &reg_2, &buffer, 1 );
        retval |= ( (int16_t)buffer << 8 );

        *x = retval;

        compass2_hal_read( &reg_3, &buffer, 1 );
        retval = (int16_t)buffer;
        compass2_hal_read( &reg_4, &buffer, 1 );
        retval |= ( (int16_t)buffer << 8 );

        *y = retval;

        compass2_hal_read( &reg_5, &buffer, 1 );
        retval = (int16_t)buffer;
        compass2_hal_read( &reg_6, &buffer, 1 );
        retval |= ( (int16_t)buffer << 8 );

        *z = retval;

		reg_1 = STATUS_2;
		compass2_hal_read( &reg_1, &buffer, 1 );
		return 0;
    }
    return -1;

}

uint8_t compass2_set_output_res( output_res_t res )
{
    uint8_t reg    = CNTL1;
    uint8_t buffer = 0;

    buffer = ( res << 4 );

    compass2_hal_write( &reg, &buffer, 1 );

    return 0;

}

uint8_t compass2_set_mode( mode_t mode )
{
    uint8_t reg    = CNTL1;
    uint8_t buffer = 0;

	compass2_hal_read( &reg, &buffer, 1 );

    buffer &=  0xF0;
    compass2_hal_write( &reg, &buffer, 1 );
    compass2_hal_delay( 10 );

    buffer |= mode;
    compass2_hal_write( &reg, &buffer, 1 );

    return 0;

}

uint8_t compass2_get_adjustment( uint8_t *x, uint8_t *y, uint8_t *z )
{

    uint8_t reg_1  = CNTL1;
    uint8_t reg_2  = X_AXIS_SENS;
    uint8_t reg_3  = Y_AXIS_SENS;
    uint8_t reg_4  = Z_AXIS_SENS;
    uint8_t buffer = 0;

    buffer = MODE_POWER_DOWN;
    compass2_hal_write( &reg_1, &buffer, 1 );
    compass2_hal_delay( 10 );

    buffer = MODE_FUSE_ROM;
    compass2_hal_write( &reg_1, &buffer, 1 );
    compass2_hal_delay( 10 );

    // Now read Sensitivity Vaules
    compass2_hal_read( &reg_2, &buffer, 1 );
    *x = buffer;
    compass2_hal_read( &reg_3, &buffer, 1 );
    *y = buffer;
    compass2_hal_read( &reg_4, &buffer, 1 );
    *z = buffer;

    buffer = MODE_POWER_DOWN;
    compass2_hal_write( &reg_1, &buffer, 1 );
    compass2_hal_delay( 10 );

    return 0;
}

uint8_t compass2_get_self_test( int16_t *x, int16_t *y, int16_t *z )
{
    uint8_t reg_1 	      = CNTL1;
    uint8_t reg_2         = HXL;
    uint8_t reg_3         = HXH;
    uint8_t reg_4         = HYL;
    uint8_t reg_5         = HYH;
    uint8_t reg_6         = HZL;
    uint8_t reg_7         = HZH;
    uint8_t stat2         = STATUS_2;
    uint8_t buffer 	      = 0;
    uint8_t chk_buffer[7] = { 0 };

    buffer = MODE_POWER_DOWN;
    compass2_hal_write( &reg_1, &buffer, 1 );
    compass2_hal_delay( 10 );

    compass2_set_self_test( true );
    compass2_hal_delay( 10 );

    if( compass2_get_data_ready() )
    {
        compass2_hal_read( &reg_2, &buffer, 1 );
        chk_buffer[0] = buffer;
        compass2_hal_read( &reg_3, &buffer, 1 );
        chk_buffer[1] = buffer;
        compass2_hal_read( &reg_4, &buffer, 1 );
        chk_buffer[2] = buffer;
        compass2_hal_read( &reg_5, &buffer, 1 );
        chk_buffer[3] = buffer;
        compass2_hal_read( &reg_6, &buffer, 1 );
        chk_buffer[4] = buffer;
        compass2_hal_read( &reg_7, &buffer, 1 );
        chk_buffer[5] = buffer;
        compass2_hal_read( &stat2, &buffer, 1 );
        chk_buffer[6] = buffer;

        if( !( chk_buffer[6] & 0x08 ) )
        {
            *x = ( ( (int16_t)chk_buffer[1] ) << 8 ) | chk_buffer[0];
            *y = ( ( (int16_t)chk_buffer[3] ) << 8 ) | chk_buffer[2];
            *z = ( ( (int16_t)chk_buffer[5] ) << 8 ) | chk_buffer[4];
        }
    }

    compass2_set_self_test( false );

    buffer = MODE_POWER_DOWN;
    compass2_hal_write( &reg_1, &buffer, 1 );
    compass2_hal_delay( 10 );

    return 0;

}

uint8_t compass2_set_self_test( bool enable )
{
    uint8_t reg    = SELF_TEST;
    uint8_t buffer = 0;
    uint8_t choice = 0;

    if( enable )
        choice = 1;
    else choice = 0;

    buffer = ( choice << 6 );

    compass2_hal_write( &reg, &buffer, 1 );

    return 0;


}

uint8_t compass2_get_data_ready( void )
{
    uint8_t reg    = STATUS_1;
    uint8_t buffer = 0;

    compass2_hal_read( &reg, &buffer, 1 );

    buffer &= 1;

    return buffer;

}

uint8_t compass2_get_data_overrun( void )
{
    uint8_t reg    = STATUS_1;
    uint8_t buffer = 0;

    compass2_hal_read( &reg, &buffer, 1 );

    buffer &= 2;

    return buffer;
}

float compass2_set_scale_factor( output_res_t res )
{
    float retval = 0;

    switch( res )
    {
        case RES_14:
            retval = 10 * 4219 / 8190;
            break;
        case RES_16:
            retval = 10 * 4219 / 32760;
            break;
        default:
            return 0;
    }
    return retval;

}

uint8_t compass2_software_reset( void )
{
    uint8_t reg    = CNTL2;
    uint8_t buffer = 0;

    buffer = 1;
    compass2_hal_write( &reg, &buffer, 1 );

    return 0;
}

uint8_t compass2_i2c_disable( void )
{
    uint8_t reg    = I2C_DISABLE;
    uint8_t buffer = 0;

    buffer = 0x1B;

    compass2_hal_write( &reg, &buffer, 1 );

    return 0;
}



/*************** END OF FUNCTIONS **********************************************/
