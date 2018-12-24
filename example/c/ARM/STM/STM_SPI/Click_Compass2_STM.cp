#line 1 "C:/Users/katarina.perendic/Desktop/Compass_2_Click (1)/Compass_2_Click/SW/example/c/ARM/STM/STM_SPI/Click_Compass2_STM.c"
#line 1 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/example/c/arm/stm/stm_spi/click_compass2_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"





typedef signed char int8_t;
typedef signed int int16_t;
typedef signed long int int32_t;
typedef signed long long int64_t;


typedef unsigned char uint8_t;
typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef signed int int_least16_t;
typedef signed long int int_least32_t;
typedef signed long long int_least64_t;


typedef unsigned char uint_least8_t;
typedef unsigned int uint_least16_t;
typedef unsigned long int uint_least32_t;
typedef unsigned long long uint_least64_t;



typedef signed long int int_fast8_t;
typedef signed long int int_fast16_t;
typedef signed long int int_fast32_t;
typedef signed long long int_fast64_t;


typedef unsigned long int uint_fast8_t;
typedef unsigned long int uint_fast16_t;
typedef unsigned long int uint_fast32_t;
typedef unsigned long long uint_fast64_t;


typedef signed long int intptr_t;
typedef unsigned long int uintptr_t;


typedef signed long long intmax_t;
typedef unsigned long long uintmax_t;
#line 1 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/example/c/arm/stm/stm_spi/click_compass2_config.h"
#line 1 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/example/c/arm/stm/stm_spi/click_compass2_types.h"
#line 3 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/example/c/arm/stm/stm_spi/click_compass2_config.h"
const uint32_t _COMPASS2_SPI_CFG[ 2 ] =
{
 _SPI_FPCLK_DIV256,
 _SPI_FIRST_CLK_EDGE_TRANSITION |
 _SPI_CLK_IDLE_LOW |
 _SPI_MASTER |
 _SPI_MSB_FIRST |
 _SPI_8_BIT |
 _SPI_SSM_ENABLE |
 _SPI_SS_DISABLE |
 _SPI_SSI_1
};

const uint32_t _COMPASS2_I2C_CFG[ 1 ] =
{
 100000
};
#line 1 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for arm/include/stdint.h"
#line 58 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
extern const uint8_t _COMPASS2_REG_DEVICE_ID ;
extern const uint8_t _COMPASS2_REG_INFORMATION ;
extern const uint8_t _COMPASS2_REG_STATUS_1 ;
extern const uint8_t _COMPASS2_REG_AXIS_X_LOW ;
extern const uint8_t _COMPASS2_REG_AXIS_X_HIGH ;
extern const uint8_t _COMPASS2_REG_AXIS_Y_LOW ;
extern const uint8_t _COMPASS2_REG_AXIS_Y_HIGH ;
extern const uint8_t _COMPASS2_REG_AXIS_Z_LOW ;
extern const uint8_t _COMPASS2_REG_AXIS_Z_HIGH ;
extern const uint8_t _COMPASS2_REG_STATUS_2 ;
extern const uint8_t _COMPASS2_REG_CNTRL1 ;
extern const uint8_t _COMPASS2_REG_CNTRL2 ;
extern const uint8_t _COMPASS2_REG_SELF_TEST ;
extern const uint8_t _COMPASS2_REG_TEST_1 ;
extern const uint8_t _COMPASS2_REG_TEST_2 ;
extern const uint8_t _COMPASS2_REG_I2C_DISABLE ;
extern const uint8_t _COMPASS2_REG_X_AXIS_SENS ;
extern const uint8_t _COMPASS2_REG_Y_AXIS_SENS ;
extern const uint8_t _COMPASS2_REG_Z_AXIS_SENS ;

extern const uint8_t _COMPASS2_MODE_POWER_DOWN ;
extern const uint8_t _COMPASS2_MODE_SINGL_MEASUR ;
extern const uint8_t _COMPASS2_MODE_CONT_MEAS_1 ;
extern const uint8_t _COMPASS2_MODE_CONT_MEAS_2 ;
extern const uint8_t _COMPASS2_MODE_EXT_TRIG ;
extern const uint8_t _COMPASS2_MODE_SELF_TEST ;
extern const uint8_t _COMPASS2_MODE_FUSE_ROM ;

extern const uint8_t _COMPASS2_SET_RESOLUTION_14bit;
extern const uint8_t _COMPASS2_SET_RESOLUTION_16bit;

extern const uint8_t _COMPASS2_MODE_SPI;
extern const uint8_t _COMPASS2_MODE_I2C;

extern const uint8_t _COMPASS2_X_AXIS;
extern const uint8_t _COMPASS2_Y_AXIS;
extern const uint8_t _COMPASS2_Z_AXIS;
#line 109 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_spiDriverInit( const uint8_t*  gpioObj,  const uint8_t*  spiObj);


void compass2_i2cDriverInit( const uint8_t*  gpioObj,  const uint8_t*  i2cObj, uint8_t slave);
#line 119 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_gpioDriverInit( const uint8_t*  gpioObj);
#line 129 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_writeByte(uint8_t addr, uint8_t _data);
#line 137 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_readByte(uint8_t addr);
#line 142 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_reset();
#line 147 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_init();
#line 152 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_i2c_disable();
#line 157 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_softwareReset();
#line 162 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
float compass2_getResolutionParameter( uint8_t res );
#line 167 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_getRDY();
#line 172 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_getDataOverrun();
#line 181 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_getAdjustment( uint8_t *x, uint8_t *y, uint8_t *z );
#line 186 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_setOUTResolution( uint8_t res );
#line 193 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
uint8_t compass2_setMode( uint8_t mode );
#line 202 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_getAllData(int16_t *x, int16_t *y, int16_t *z );
#line 210 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
int16_t compass2_getAxisData( uint8_t axis );
#line 215 "c:/users/katarina.perendic/desktop/compass_2_click (1)/compass_2_click/sw/library/__compass2_driver.h"
void compass2_newMeasurement();
#line 29 "C:/Users/katarina.perendic/Desktop/Compass_2_Click (1)/Compass_2_Click/SW/example/c/ARM/STM/STM_SPI/Click_Compass2_STM.c"
char demoText[ 50 ];
int16_t X_Axis;
int16_t Y_Axis;
int16_t Z_Axis;

void systemInit()
{
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
 mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );

 mikrobus_spiInit( _MIKROBUS1, &_COMPASS2_SPI_CFG[0] );
 mikrobus_logInit( _LOG_USBUART_A, 9600 );
 mikrobus_logWrite("--- System Init ---", _LOG_LINE);
 Delay_ms( 100 );
}

void applicationInit()
{
 compass2_spiDriverInit( ( const uint8_t* )&_MIKROBUS1_GPIO, ( const uint8_t* )&_MIKROBUS1_SPI );
 compass2_init();
 Delay_ms( 300 );
 compass2_setOUTResolution( _COMPASS2_SET_RESOLUTION_16bit );
 compass2_setMode( _COMPASS2_MODE_CONT_MEAS_2 );
}

void applicationTask()
{
 compass2_newMeasurement();

 mikrobus_logWrite(" --- Axis ---", _LOG_LINE);
 X_Axis = compass2_getAxisData( _COMPASS2_X_AXIS );
 Y_Axis = compass2_getAxisData( _COMPASS2_Y_AXIS );
 Z_Axis = compass2_getAxisData( _COMPASS2_Z_AXIS );

 LongToStr(X_Axis, demoText);
 mikrobus_logWrite("X: ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_LINE);

 LongToStr(Y_Axis, demoText);
 mikrobus_logWrite("Y: ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_LINE);

 LongToStr(Z_Axis, demoText);
 mikrobus_logWrite("Z: ", _LOG_TEXT);
 mikrobus_logWrite(demoText, _LOG_LINE);

 mikrobus_logWrite(" ", _LOG_LINE);
 Delay_ms( 1000 );
}

void main()
{
 systemInit();
 applicationInit();

 while (1)
 {
 applicationTask();
 }
}
