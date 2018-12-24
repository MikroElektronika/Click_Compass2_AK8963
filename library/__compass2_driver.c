/*
    __compass2_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__compass2_driver.h"
#include "__compass2_hal.c"

/* ------------------------------------------------------------------- MACROS */

// Registers
const uint8_t _COMPASS2_REG_DEVICE_ID   = 0x00 ;
const uint8_t _COMPASS2_REG_INFORMATION = 0x01 ;
const uint8_t _COMPASS2_REG_STATUS_1    = 0x02 ;
const uint8_t _COMPASS2_REG_AXIS_X_LOW  = 0x03 ;
const uint8_t _COMPASS2_REG_AXIS_X_HIGH = 0x04 ;
const uint8_t _COMPASS2_REG_AXIS_Y_LOW  = 0x05 ;
const uint8_t _COMPASS2_REG_AXIS_Y_HIGH = 0x06 ;
const uint8_t _COMPASS2_REG_AXIS_Z_LOW  = 0x07 ;
const uint8_t _COMPASS2_REG_AXIS_Z_HIGH = 0x08 ;
const uint8_t _COMPASS2_REG_STATUS_2    = 0x09 ;
const uint8_t _COMPASS2_REG_CNTRL1      = 0x0A ;
const uint8_t _COMPASS2_REG_CNTRL2      = 0x0B ;
const uint8_t _COMPASS2_REG_SELF_TEST   = 0x0C ;
const uint8_t _COMPASS2_REG_TEST_1      = 0x0D ;
const uint8_t _COMPASS2_REG_TEST_2      = 0x0E ;
const uint8_t _COMPASS2_REG_I2C_DISABLE = 0x0F ;
const uint8_t _COMPASS2_REG_X_AXIS_SENS = 0x10 ;
const uint8_t _COMPASS2_REG_Y_AXIS_SENS = 0x11 ;
const uint8_t _COMPASS2_REG_Z_AXIS_SENS = 0x12 ;

const uint8_t _COMPASS2_MODE_POWER_DOWN     = 0x00;
const uint8_t _COMPASS2_MODE_SINGL_MEASUR   = 0x01;
const uint8_t _COMPASS2_MODE_CONT_MEAS_1    = 0x02;
const uint8_t _COMPASS2_MODE_CONT_MEAS_2    = 0x06;
const uint8_t _COMPASS2_MODE_EXT_TRIG       = 0x04;
const uint8_t _COMPASS2_MODE_SELF_TEST      = 0x08;
const uint8_t _COMPASS2_MODE_FUSE_ROM       = 0x0F;

const uint8_t _COMPASS2_SET_RESOLUTION_14bit = 0x00;
const uint8_t _COMPASS2_SET_RESOLUTION_16bit = 0x10;

const uint8_t _COMPASS2_MODE_SPI = 0x00;
const uint8_t _COMPASS2_MODE_I2C = 0x01;

const uint8_t _COMPASS2_X_AXIS = 0x00;
const uint8_t _COMPASS2_Y_AXIS = 0x01;
const uint8_t _COMPASS2_Z_AXIS = 0x02;

/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __COMPASS2_DRV_I2C__
static uint8_t _slaveAddress;
#endif

static uint8_t _operationMode;

static int8_t global_sens_x = 0;
static int8_t global_sens_y = 0;
static int8_t global_sens_z = 0;

static uint16_t _mode = 6;
static uint16_t _res = 1;

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __COMPASS2_DRV_SPI__

void compass2_spiDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    _operationMode = _COMPASS2_MODE_SPI;
    hal_gpio_csSet( 1 );
}

#endif
#ifdef   __COMPASS2_DRV_I2C__

void compass2_i2cDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    _operationMode = _COMPASS2_MODE_I2C;
}

#endif
#ifdef   __COMPASS2_DRV_UART__

void compass2_uartDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

void compass2_writeByte(uint8_t addr, uint8_t _data)
{
    uint8_t writeReg[ 2 ];
    
    writeReg[ 0 ] = addr;
    writeReg[ 1 ] = _data;
    
    if (_operationMode == _COMPASS2_MODE_I2C)
    {
        hal_i2cStart();
        hal_i2cWrite(_slaveAddress, writeReg, 2, END_MODE_STOP);
    }
    else
    {
        hal_gpio_csSet( 0 );
        hal_spiWrite( writeReg, 2 );
        hal_gpio_csSet( 1 );
    }
}

uint8_t compass2_readByte(uint8_t addr)
{
    uint8_t writeReg[ 2 ] = { 0 };
    uint8_t readReg[ 2 ];

    if (_operationMode == _COMPASS2_MODE_I2C)
    {
        writeReg[ 0 ] = addr;
        
        hal_i2cStart();
        hal_i2cWrite(_slaveAddress, writeReg, 1, END_MODE_RESTART);
        Delay_10ms();
        hal_i2cRead(_slaveAddress, readReg, 1, END_MODE_STOP);
    }
    else
    {
        writeReg[ 0 ] = addr | 0x80;
        hal_gpio_csSet( 0 );
        hal_spiTransfer( writeReg, readReg, 2 );
        hal_gpio_csSet( 1 );
    }
    
    return readReg[ 1 ];
}

void compass2_reset()
{
    hal_gpio_rstSet(0);
    Delay_100ms();
    hal_gpio_rstSet(1);
    Delay_100ms();
}

void compass2_init()
{
    compass2_reset();
    Delay_100ms();

    compass2_writeByte( _COMPASS2_REG_CNTRL1, _COMPASS2_MODE_POWER_DOWN );
    Delay_10ms();

    compass2_getAdjustment( &global_sens_x, &global_sens_y, &global_sens_z );

    if( _operationMode == _COMPASS2_MODE_SPI )
    {
        compass2_i2c_disable();
    }
}

void compass2_i2c_disable()
{
    compass2_writeByte( _COMPASS2_REG_I2C_DISABLE, 0x1B );
}


uint8_t compass2_softwareReset()
{
    compass2_writeByte( _COMPASS2_REG_CNTRL2, 0x01 );
}

float compass2_getResolutionParameter( uint8_t res )
{
    float retval = 0;

    switch( res )
    {
        case _COMPASS2_SET_RESOLUTION_14bit:
            retval = 10 * 4219 / 8190;
            break;
        case _COMPASS2_SET_RESOLUTION_16bit:
            retval = 10 * 4219 / 32760;
            break;
        default:
            return 0;
    }
    return retval;
}

uint8_t compass2_getRDY()
{
    uint8_t buffer = 0;

    buffer = compass2_readByte( _COMPASS2_REG_STATUS_1 );
    buffer &= 1;
    return buffer;
}

uint8_t compass2_getDataOverrun()
{
    uint8_t buffer = 0;
    
    buffer = compass2_readByte( _COMPASS2_REG_STATUS_1 );
    buffer &= 2;
    return buffer;
}

void compass2_getAdjustment( uint8_t *x, uint8_t *y, uint8_t *z )
{
    compass2_writeByte( _COMPASS2_REG_CNTRL1, _COMPASS2_MODE_FUSE_ROM );
    Delay_10ms();

    *x = compass2_readByte( _COMPASS2_REG_X_AXIS_SENS );
    *y = compass2_readByte( _COMPASS2_REG_Y_AXIS_SENS );
    *z = compass2_readByte( _COMPASS2_REG_Z_AXIS_SENS );
    
    compass2_writeByte( _COMPASS2_REG_CNTRL1, _COMPASS2_MODE_POWER_DOWN );
    Delay_10ms();
}

uint8_t compass2_setOUTResolution( uint8_t res )
{
    uint8_t buffer = 0;
    _res = res;
    
    compass2_writeByte( _COMPASS2_REG_CNTRL1, _res );

}

uint8_t compass2_setMode( uint8_t mode )
{
    _res &= 0xF0;
    _res |= mode;
    
    compass2_writeByte( _COMPASS2_REG_CNTRL1, _res );
    Delay_10ms();
}

void compass2_getAllData(int16_t *x, int16_t *y, int16_t *z )
{
    uint8_t lsb  = 0;
    uint8_t msb  = 0;
    int16_t axis_data;

    lsb = compass2_readByte( _COMPASS2_REG_AXIS_X_LOW );
    msb = compass2_readByte( _COMPASS2_REG_AXIS_X_HIGH );
    axis_data = msb;
    axis_data <<= 8;
    axis_data |= lsb;
    *x = axis_data;
    
    lsb = compass2_readByte( _COMPASS2_REG_AXIS_Y_LOW );
    msb = compass2_readByte( _COMPASS2_REG_AXIS_Y_HIGH );
    axis_data = msb;
    axis_data <<= 8;
    axis_data |= lsb;
    *y = axis_data;

    lsb = compass2_readByte( _COMPASS2_REG_AXIS_Z_LOW );
    msb = compass2_readByte( _COMPASS2_REG_AXIS_Z_HIGH );
    axis_data = msb;
    axis_data <<= 8;
    axis_data |= lsb;
    *z = axis_data;
}

int16_t compass2_getAxisData( uint8_t axis )
{
    uint8_t lsb  = 0;
    uint8_t msb  = 0;
    int16_t axis_data;

    compass2_writeByte( _COMPASS2_REG_CNTRL1, _COMPASS2_MODE_FUSE_ROM );
    Delay_10ms();

    if ( axis == _COMPASS2_X_AXIS )
    {
        lsb = compass2_readByte( _COMPASS2_REG_AXIS_X_LOW );
        msb = compass2_readByte( _COMPASS2_REG_AXIS_X_HIGH );
    }
    else if (axis == _COMPASS2_Y_AXIS)
    {
        lsb = compass2_readByte( _COMPASS2_REG_AXIS_Y_LOW );
        msb = compass2_readByte( _COMPASS2_REG_AXIS_Y_HIGH );
    }
    else
    {
        lsb = compass2_readByte( _COMPASS2_REG_AXIS_Z_LOW );
        msb = compass2_readByte( _COMPASS2_REG_AXIS_Z_HIGH );
    }

    compass2_writeByte( _COMPASS2_REG_CNTRL1, _COMPASS2_MODE_POWER_DOWN );
    Delay_10ms();
    
    axis_data = msb;
    axis_data <<= 8;
    axis_data |= lsb;
    
    return  axis_data;
}

void compass2_newMeasurement()
{
    compass2_reset();
    Delay_10ms();

    compass2_setOUTResolution( _res );
    compass2_setMode( _COMPASS2_MODE_CONT_MEAS_2 );
}

/* -------------------------------------------------------------------------- */
/*
  __compass2_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */