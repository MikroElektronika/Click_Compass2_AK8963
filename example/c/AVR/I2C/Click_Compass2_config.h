#include "Click_Compass2_types.h"

const uint32_t _COMPASS2_SPI_CFG[ 3 ] = 
{ 
	_SPI_MASTER, 
	_SPI_FCY_DIV32, 
	_SPI_CLK_LO_LEADING 
};

const uint32_t _COMPASS2_I2C_CFG[ 1 ] = 
{
	100000
};
