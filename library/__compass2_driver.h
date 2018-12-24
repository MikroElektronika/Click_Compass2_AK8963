/*
    __compass2_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __compass2_driver.h
@brief    Compass2 Driver
@mainpage Compass2 Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   COMPASS2
@brief      Compass2 Click Driver
@{

| Global Library Prefix | **COMPASS2** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **avg 2018.**      |
| Developer             | **Katarina Perendic**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _COMPASS2_H_
#define _COMPASS2_H_

/** 
 * @macro T_COMPASS2_P
 * @brief Driver Abstract type 
 */
#define T_COMPASS2_P    const uint8_t*

/** @defgroup COMPASS2_COMPILE Compilation Config */              /** @{ */

   #define   __COMPASS2_DRV_SPI__                            /**<     @macro __COMPASS2_DRV_SPI__  @brief SPI driver selector */
   #define   __COMPASS2_DRV_I2C__                            /**<     @macro __COMPASS2_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __COMPASS2_DRV_UART__                           /**<     @macro __COMPASS2_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup COMPASS2_VAR Variables */                           /** @{ */

// Registers
extern const uint8_t _COMPASS2_REG_DEVICE_ID   ;
extern const uint8_t _COMPASS2_REG_INFORMATION ;
extern const uint8_t _COMPASS2_REG_STATUS_1    ;
extern const uint8_t _COMPASS2_REG_AXIS_X_LOW  ;
extern const uint8_t _COMPASS2_REG_AXIS_X_HIGH ;
extern const uint8_t _COMPASS2_REG_AXIS_Y_LOW  ;
extern const uint8_t _COMPASS2_REG_AXIS_Y_HIGH ;
extern const uint8_t _COMPASS2_REG_AXIS_Z_LOW  ;
extern const uint8_t _COMPASS2_REG_AXIS_Z_HIGH ;
extern const uint8_t _COMPASS2_REG_STATUS_2    ;
extern const uint8_t _COMPASS2_REG_CNTRL1      ;
extern const uint8_t _COMPASS2_REG_CNTRL2      ;
extern const uint8_t _COMPASS2_REG_SELF_TEST   ;
extern const uint8_t _COMPASS2_REG_TEST_1      ;
extern const uint8_t _COMPASS2_REG_TEST_2      ;
extern const uint8_t _COMPASS2_REG_I2C_DISABLE ;
extern const uint8_t _COMPASS2_REG_X_AXIS_SENS ;
extern const uint8_t _COMPASS2_REG_Y_AXIS_SENS ;
extern const uint8_t _COMPASS2_REG_Z_AXIS_SENS ;

extern const uint8_t _COMPASS2_MODE_POWER_DOWN     ;
extern const uint8_t _COMPASS2_MODE_SINGL_MEASUR   ;
extern const uint8_t _COMPASS2_MODE_CONT_MEAS_1    ;
extern const uint8_t _COMPASS2_MODE_CONT_MEAS_2    ;
extern const uint8_t _COMPASS2_MODE_EXT_TRIG       ;
extern const uint8_t _COMPASS2_MODE_SELF_TEST      ;
extern const uint8_t _COMPASS2_MODE_FUSE_ROM       ;

extern const uint8_t _COMPASS2_SET_RESOLUTION_14bit;
extern const uint8_t _COMPASS2_SET_RESOLUTION_16bit;

extern const uint8_t _COMPASS2_MODE_SPI;
extern const uint8_t _COMPASS2_MODE_I2C;

extern const uint8_t _COMPASS2_X_AXIS;
extern const uint8_t _COMPASS2_Y_AXIS;
extern const uint8_t _COMPASS2_Z_AXIS;

                                                                       /** @} */
/** @defgroup COMPASS2_TYPES Types */                             /** @{ */



                                                                       /** @} */
#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup COMPASS2_INIT Driver Initialization */              /** @{ */

#ifdef   __COMPASS2_DRV_SPI__
void compass2_spiDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P spiObj);
#endif
#ifdef   __COMPASS2_DRV_I2C__
void compass2_i2cDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P i2cObj, uint8_t slave);
#endif
#ifdef   __COMPASS2_DRV_UART__
void compass2_uartDriverInit(T_COMPASS2_P gpioObj, T_COMPASS2_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void compass2_gpioDriverInit(T_COMPASS2_P gpioObj);
                                                                       /** @} */
/** @defgroup COMPASS2_FUNC Driver Functions */                   /** @{ */

/**
 * @brief Functions for write one byte in register
 *
 * @param[in] addr    Register in which the data will be written
 * @param[in] _data  Data which be written in the register
 */
void compass2_writeByte(uint8_t addr, uint8_t _data);

/**
 * @brief Functions for read byte from register
 *
 * @param[in] addr    Register which will be read
 * @retval one byte data which is read from the register
 */
uint8_t compass2_readByte(uint8_t addr);

/**
 * @brief Functions for reset chip
 */
void compass2_reset();

/**
 * @brief Functions for initialization chip
 */
void compass2_init();

/**
 * @brief Functions for disable I2C 
 */
void compass2_i2c_disable();

/**
 * @brief Software reset functions 
 */
uint8_t compass2_softwareReset();

/**
 * @brief Functions for gets resolution parameter
 */
float compass2_getResolutionParameter( uint8_t res );

/**
 * @brief Functions for gets data ready state
 */
uint8_t compass2_getRDY();

/**
 * @brief Functions for gets data overrun state
 */
uint8_t compass2_getDataOverrun();

/**
 * @brief Functions for read all axis adjustment data
 *
 * @param[ out ] x     X axis data
 * @param[ out ] y     Y axis data
 * @param[ out ] z     Z axis data
 */
void compass2_getAdjustment( uint8_t *x, uint8_t *y, uint8_t *z );

/**
 * @brief Functions for sets output data resolution
 */
uint8_t compass2_setOUTResolution( uint8_t res );

/**
 * @brief Functions for sets mode
 *
 * @param[ in ] mode     Mode to be set
 */
uint8_t compass2_setMode( uint8_t mode );

/**
 * @brief Functions for read all axis data
 *
 * @param[ out ] x     X axis data
 * @param[ out ] y     Y axis data
 * @param[ out ] z     Z axis data
 */
void compass2_getAllData(int16_t *x, int16_t *y, int16_t *z );

/**
 * @brief Functions for read axis data
 *
 * @param[ in ] axis    Axis data which will be read
 * @retval Axis data 
 */
int16_t compass2_getAxisData( uint8_t axis );

/**
 * @brief Functions for start new measurement
 */
void compass2_newMeasurement();






                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_Compass2_STM.c
    @example Click_Compass2_TIVA.c
    @example Click_Compass2_CEC.c
    @example Click_Compass2_KINETIS.c
    @example Click_Compass2_MSP.c
    @example Click_Compass2_PIC.c
    @example Click_Compass2_PIC32.c
    @example Click_Compass2_DSPIC.c
    @example Click_Compass2_AVR.c
    @example Click_Compass2_FT90x.c
    @example Click_Compass2_STM.mbas
    @example Click_Compass2_TIVA.mbas
    @example Click_Compass2_CEC.mbas
    @example Click_Compass2_KINETIS.mbas
    @example Click_Compass2_MSP.mbas
    @example Click_Compass2_PIC.mbas
    @example Click_Compass2_PIC32.mbas
    @example Click_Compass2_DSPIC.mbas
    @example Click_Compass2_AVR.mbas
    @example Click_Compass2_FT90x.mbas
    @example Click_Compass2_STM.mpas
    @example Click_Compass2_TIVA.mpas
    @example Click_Compass2_CEC.mpas
    @example Click_Compass2_KINETIS.mpas
    @example Click_Compass2_MSP.mpas
    @example Click_Compass2_PIC.mpas
    @example Click_Compass2_PIC32.mpas
    @example Click_Compass2_DSPIC.mpas
    @example Click_Compass2_AVR.mpas
    @example Click_Compass2_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __compass2_driver.h

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