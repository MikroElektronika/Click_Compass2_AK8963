/*
Example for Compass2 Click

    Date          : avg 2018.
    Author        : Katarina Perendic

Test configuration KINETIS :
    
    MCU              : MK64
    Dev. Board       : HEXIWEAR
    ARM Compiler ver : v6.0.0.0

---

Description :

The application is composed of three sections :

- System Initialization - Initializes SPI or I2C module and sets RST and CS pin as OUTPUT and INT pin as INPUT
- Application Initialization - Initialization driver init, init chip, sets data output resolution and operation mode
- Application Task - (code snippet) - Reads X/Y/Z axis data and logs data on USBUART every 2 sec.

*/

#include "Click_Compass2_types.h"
#include "Click_Compass2_config.h"

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
    mikrobus_logInit( _LOG_USBUART, 9600 );
    mikrobus_logWrite("--- System Init ---", _LOG_LINE);
    Delay_ms( 100 );
}

void applicationInit()
{
    compass2_spiDriverInit( (T_COMPASS2_P)&_MIKROBUS1_GPIO, (T_COMPASS2_P)&_MIKROBUS1_SPI );
    compass2_init();
    Delay_100ms();
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
    
    IntToStr(X_Axis, demoText);
    mikrobus_logWrite("X: ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    IntToStr(Y_Axis, demoText);
    mikrobus_logWrite("Y: ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    IntToStr(Z_Axis, demoText);
    mikrobus_logWrite("Z: ", _LOG_TEXT);
    mikrobus_logWrite(demoText, _LOG_LINE);
    
    mikrobus_logWrite(" ", _LOG_LINE);
    Delay_ms( 2000 );
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