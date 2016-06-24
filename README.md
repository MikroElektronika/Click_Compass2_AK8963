![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

![Compass 2 Click](http://cdn.mikroe.com/img/click/compass-2/compass-2-click.png)

---
[Product Page](http://www.mikroe.com/click/compass-2/)

[Manual Page](http://docs.mikroe.com/Compass_2_Click)

[Learn Page](http://learn.mikroe.com/this-nand-nor-that-nand/)

---

### General Description

Compass 2 click

Compass 2 click is a mikroBUS add-on board with an AK8963 3-axis electronic compass. The high sensitivity sensor is based on the Hall effect. The built-in ADC converter can be set up at either 14 or 16 bit resolution, for each of the 3 axes. The sensitivity is 0.6µT/LSB typ. at 14-bit, and 0.15µT/LSB at 16-bit. Compass 2 click communicates with the target MCU through either through the I2C or SPI interface, with an added INT pin. Onboard jumpers enable you to switch between two interfaces. The board is designed to use a 3.3 power supply only.

Applications

Position detection, navigation and orientation for portable devices.

Key features

    AK8963 IC
    Sensitivity: 0.6µT/LSB typ. at 14-bit, and 0.15µT/LSB at 16-bit
    SPI or I2C interface
    3.3V

Key benefits

    Selectable interface
    Configurable ADC resolution
    Ready-to-use examples save development time
    Supported in all MikroElektronika compilers

---

### Example

#### Configuration
* MCU:             STM32F107VC
* Dev.Board:       EasyMx Pro v7
* Oscillator:      72 Mhz internal
* Ext. Modules:    Compass 2 click
* SW:              MikroC PRO for ARM 4.7.4

```
#include <stdint.h>
#include "compass2_hw.h"

sbit COMPASS2_CS at GPIOD_ODR.B13;

void system_setup( bus_mode_t mode, uint8_t addr );

float mRes;                  // scale resolutions per LSB for the sensors
uint8_t asax, asay, asaz;
float adjusted_ASAX, adjusted_ASAY, adjusted_ASAZ;
float heading, adjusted_MX, adjusted_MY, adjusted_MZ, magbias[3];
int16_t mx, my, mz;
char text[20] = { 0 };


/*      Functions
 ****************************/


void system_setup( bus_mode_t mode, uint8_t addr )
{
        // GPIOs
        GPIO_Digital_Output( &GPIOB_BASE, _GPIO_PINMASK_13 );

        // UART
        UART1_Init( 9600 );
        UART1_Write_Text( "UART Initialized\r\n" );

        // I2C
        I2C1_Init_Advanced( 100000, &_GPIO_MODULE_I2C1_PB67 );
        UART1_Write_Text( "I2C Initialized\r\n" );

        // Compass 2
        compass2_hw_init( addr, mode );
        compass2_set_mode( MODE_CONT_1 );
        compass2_set_scale_factor( RES_16 );


```

```

void main()
{
  // Local Declarations
        uint8_t address = 0x0F;
        bus_mode_t my_mode = I2C;
        float heading = 0;
        char uart_text[5] = { 0 };

        system_setup( my_mode, address );

        while(1)
        {
            compass2_get_all_values( &mx, &my, &mz );
            heading = compass2_get_compass_heading( mx, my, mz );

            if( heading < 0 )
                heading += 360;

            UART1_Write_Text( "Heading: " );
            FloatToStr( heading, text );
            UART1_Write_Text( text );
            UART1_Write_Text( " Direction: " );

            if( heading >= 330 || heading <= 30 )
            {
                uart_text[0] = 'N';
                uart_text[1] = '\n';
            }
            else if( heading >= 300 && heading <= 330 )
            {
                uart_text[0] = 'N';
                uart_text[1] = 'W';
                uart_text[2] = '\n';
            }
            else if( heading >= 240 && heading <= 300)
            {
                uart_text[0] = 'W';
                uart_text[1] = '\n';
            }
            else if( heading >= 210 && heading <= 240 )
            {
                uart_text[0] = 'S';
                uart_text[1] = 'W';
                uart_text[2] = '\n';
            }
            else if( heading <= 210 && heading >= 150 )
            {
                uart_text[0] = 'S';
                uart_text[1] = '\n';
            }
            else if( heading <= 150 && heading >= 120 )
            {
                uart_text[0] = 'S';
                uart_text[1] = 'E';
                uart_text[2] = '\n';
            }
            else if( heading <= 120 && heading >= 60 )
            {
                uart_text[0] = 'E';
                uart_text[1] = '\n';
            }
            else if( heading <= 60 && heading >= 30 )
            {
                uart_text[0] = 'N';
                uart_text[1] = 'E';
                uart_text[2] = '\n';
            }

            UART1_Write_Text( uart_text );
            UART1_Write_Text( "\r\n" );

            Delay_ms(100);
        }

}
```