![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# Compass2 Click

- **CIC Prefix**  : COMPASS2
- **Author**      : Katarina Perendic
- **Verison**     : 1.0.0
- **Date**        : avg 2018.

---

### Software Support

We provide a library for the Compass2 Click on our [LibStock](https://libstock.mikroe.com/projects/view/1833/compass-2-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the I2C bus or SPI bus driver and drivers that offer a choice for writing data in register and reads data from the register.
The library includes function for read X/Y/Z axis data.
The user also has the function for initializes chip, set resolutions, software reset and hardware reset.

Key functions :

- ``` void compass2_init() ``` - Functions for initialization chip
- ``` int16_t compass2_getAxisData( uint8_t axis ) ``` - Functions for reads axis data
- ``` void compass2_newMeasurement() ``` - Functions for starts new measurement

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI or I2C module and sets RST and CS pin as OUTPUT and INT pin as INPUT
- Application Initialization - Initialization driver init, init chip, sets data output resolution and operation mode
- Application Task - (code snippet) - Reads X/Y/Z axis data and logs data on USBUART every 2 sec.

```.c
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
```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/1833/compass-2-click) page.

Other mikroE Libraries used in the example:

- I2C
- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
