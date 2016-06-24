/****************************************************************************
* Title                 :   Compass 2 Click HW layer
* Filename              :   compass2_hw.h
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
/** @file compass2_hw.h
 *  @brief Hardware Layer for Compass 2 Click
 *
 *  @date 27 Apr 2016
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

/**
 * @mainpage
 * @section Main General Description
 * @par
 *
 * 
 * 
 *
 * 
 * @section Schematic
 * @image doc Sch.PDF
 * 
 */

#ifndef COMPASS2_HW_H_
#define COMPASS2_HW_H_
/******************************************************************************
* Includes
*******************************************************************************/
#include <stdbool.h>
#include <stdint.h>

/******************************************************************************
* Preprocessor Constants
*******************************************************************************/
// Registers
#define DEVICE_ID   0x00    /**< Read Only  Device ID of AKM. It is described \
                            in one byte and fixed value.*/
#define INFORMATION 0x01    /**< Read Only  INFORMATION[7:0]: Device information \
                            for AKM.*/
#define STATUS_1    0x02    /**< Read Only  Bit 0: DRDY ( 0: Normal 1: Data Ready ) \
                                            Bit 1: DOR ( 0: Normal 1: Data Overrun )*/
#define HXL         0x03    /**< Read Only  Measurement data of magnetic sensor */
#define HXH         0x04    /**< Read Only  Measurement data of magnetic sensor */
#define HYL         0x05    /**< Read Only  Measurement data of magnetic sensor */
#define HYH         0x06    /**< Read Only  Measurement data of magnetic sensor */
#define HZL         0x07    /**< Read Only  Measurement data of magnetic sensor */
#define HZH         0x08    /**< Read Only  Measurement data of magnetic sensor */
#define STATUS_2    0x09    /**< Read Only  Bit 3: HOFL ( 0: Normal 1: Magnetic \
                                            Sensor overflow occurred ) \
                                            Bit 4: BITM ( 0: 14-bit output \
                                            1: 16-bit output )*/
#define CNTL1       0x0A    /**< Read/Write Bits 3:0 are for Operation Modes \
                                            Bit 4: BIT ( 0: 14-bit output \
                                            1: 16-bit output )*/
#define CNTL2       0x0B    /**< Read/Write Bit 0: SRST ( 0: Normal 1: Reset )*/
#define SELF_TEST   0x0C    /**< Read/Write Bit 6: SELF ( 0: Normal 1: Generate \
                                            magnetic field for self-test*/
#define TEST_1      0x0D    /**< Read/Write Don't Use*/
#define TEST_2      0x0E    /**< Read/Write Don't Use*/
#define I2C_DISABLE 0x0F    /**< Read/Write Write "00011011" for disable or 0x1B */
#define X_AXIS_SENS 0x10    /**< Read Only  Magnetic sensor X-axis sensitivity adjustment value*/
#define Y_AXIS_SENS 0x11    /**< Read Only  Magnetic sensor Y-axis sensitivity adjustment value*/
#define Z_AXIS_SENS 0x12    /**< Read Only  Magnetic sensor Z-axis sensitivity adjustment value*/

//Sensitivity Equation
// HADJ = H X ( ( ( ASA - 128 ) * .5 ) / 128 ) + 1;



// Operation Modes  ( CNTL1 Register Settings )
#define MODE_POWER_DOWN     0x00
#define MODE_SINGL_MEASUR   0x01
#define MODE_CONT_MEAS_1    0x02
#define MODE_CONT_MEAS_2    0x06
#define MODE_EXT_TRIG       0x04
#define MODE_SELF_TEST      0x08
#define MODE_FUSE_ROM       0x0F



/******************************************************************************
* Configuration Constants
*******************************************************************************/

/******************************************************************************
* Macros
*******************************************************************************/

/******************************************************************************
* Typedefs
*******************************************************************************/

typedef enum
{
   I2C = 0,
   SPI_bus
}bus_mode_t;

typedef enum
{
    RES_14 = 0,
    RES_16
}output_res_t;

typedef enum
{
    MODE_SINGLE = 1,
    MODE_CONT_1 = 2,
    MODE_CONT_2 = 6,
    MODE_EXT    = 4,
    MODE_SELF_T = 8,
    MODE_FUSE_R = 15
}mode_t;

/******************************************************************************
* Variables
*******************************************************************************/

/******************************************************************************
* Function Prototypes
*******************************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

/**
* @brief <h3> Compass 2 HW Initialize </h3>
*
* @par
*  Initializes the Compass 2 Click for usage at the hardware level.
*
* @param[in] address    - Address of Compass 2 for I2C bus.
* @param[in] mode       - Bus mode to use for Compass 2. ( SPI, I2C )
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful. (Wrong address)
*
*/
uint8_t compass2_hw_init(uint8_t address, bus_mode_t mode);

/**
* @brief <h3> Compass 2 HW Get Information </h3>
*
* @par
*  Device information for AKM.
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_get_information( void );

/**
* @brief <h3> Compass 2 Get Compass Heading </h3>
*
* @par
*  Gets the heading for finding the direction the compass is facing.
*   Only for use after compass2_get_all_values
*
* @param[in] x  - X Value
* @param[in] y  - Y Value
* @param[in] z  - Z Value
*
* @param[out] float -   heading
*
*/
float compass2_get_compass_heading( int16_t x, int16_t y, int16_t z );

/**
* @brief <h3> Compass 2 HW Get Device ID </h3>
*
* @par
*  Device ID of AKM. It is described in one byte and fixed value.
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_get_device_id( void );

/**
* @brief <h3> Compass 2 HW Get X Value </h3>
*
* @par
*  Device ID of AKM. It is described in one byte and fixed value.
*
* @param[out]    -   X value in format you program. always 2s complement
*
*/
int16_t compass2_get_x_val( void );

/**
* @brief <h3> Compass 2 HW Get Y Value </h3>
*
* @par
*  Device ID of AKM. It is described in one byte and fixed value.
*
* @param[out]    -   Y value in format you program. always 2s complement
*
*/
int16_t compass2_get_y_val( void );

/**
* @brief <h3> Compass 2 HW Get Z Value </h3>
*
* @par
*  Device ID of AKM. It is described in one byte and fixed value.
*
* @param[out]    -   Z value in format you program. always 2s complement
*
*/
int16_t compass2_get_z_val( void );

/**
* @brief <h3> Compass 2 Get All Values </h3>
*
* @par
*  Gets all ( x , y , z ) values from magnotometer
*
* @param[in] x       - int16_t for x value
* @param[in] y       - int16_t for y value
* @param[in] z       - int16_t for z value
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_get_all_values(int16_t *x, int16_t *y, int16_t *z );

/**
* @brief <h3> Compass 2 Set Output Resolution </h3>
*
* @par
*  Sets the output resolution for magnotometer readings
*
* @param[in] res    -   Resolution for output readings
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_set_output_res( output_res_t res );

/**
* @brief <h3> Compass 2 Set Mode </h3>
*
* @par
*  Sets the operation mode for Compass 2 Click
*
* @param[in] mode   -   Operation Mode
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_set_mode( mode_t mode );

/**
* @brief <h3> Compass 2 Get Adjustment </h3>
*
* @par
*  Gets the sensitivity values from the Compass 2 Click for adjustment.
*
* @param[in] x    -   x sensitivity
* @param[in] y    -   y sensitivity
* @param[in] z    -   z sensitivity
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_get_adjustment( uint8_t *x, uint8_t *y, uint8_t *z );

/**
* @brief <h3> Compass 2 Get Self Test </h3>
*
* @par
*  Sets the self test and then runs test for x y and z values.
*
* @param[in] x    -   x sensitivity
* @param[in] y    -   y sensitivity
* @param[in] z    -   z sensitivity
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_get_self_test( int16_t *x, int16_t *y, int16_t *z );

/**
* @brief <h3> Compass 2 Set Self Test </h3>
*
* @par
*  Sets the self test bit for testing enable
*
* @param[in] enable -   Enables the self test, or Disables the self test
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_set_self_test( bool enable );

/**
* @brief <h3> Compass 2 Get Data Ready </h3>
*
* @par
*  Checks if new data is ready
*
*
* @param[out] 0 -   Not Ready
* @param[out] 1 -   Data Ready.
*
*/
uint8_t compass2_get_data_ready( void );

/**
* @brief <h3> Compass 2 Set Scale Factor </h3>
*
* @par
*  Based on the output resolution, gets a scale factor for adjusting ( not used )
*
* @param[in] res    -   output resolution
*
* @param[out] float -   scale factor
*
*/
float compass2_set_scale_factor( output_res_t res );

/**
* @brief <h3> Compass 2 Get Data Overrun </h3>
*
* @par
*  Checks if data is overrun
*
* @param[out] 0 -   Data not overrun
* @param[out] 1 -   Data overrun
*
*/
uint8_t compass2_get_data_overrun( void );

/**
* @brief <h3> Compass 2 Software Resett </h3>
*
* @par
*  Resets the software of the AK8963
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_software_reset( void );

/**
* @brief <h3> Compass 2 I2C Disable </h3>
*
* @par
*  Disables the I2C for the AK8963
*
* @param[out] 0     -   Success
* @param[out] -1    -   Unsuccessful.
*
*/
uint8_t compass2_i2c_disable( void );





#ifdef __cplusplus
} // extern "C"
#endif

#endif /* MODULE_H_ */

/*** End of File **************************************************************/
