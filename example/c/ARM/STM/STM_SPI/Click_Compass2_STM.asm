_systemInit:
;Click_Compass2_STM.c,34 :: 		void systemInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Compass2_STM.c,36 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_INT_PIN, _GPIO_INPUT );
MOVS	R2, #1
MOVS	R1, #7
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Compass2_STM.c,37 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_RST_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #1
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Compass2_STM.c,38 :: 		mikrobus_gpioInit( _MIKROBUS1, _MIKROBUS_CS_PIN, _GPIO_OUTPUT );
MOVS	R2, #0
MOVS	R1, #2
MOVS	R0, #0
BL	_mikrobus_gpioInit+0
;Click_Compass2_STM.c,40 :: 		mikrobus_spiInit( _MIKROBUS1, &_COMPASS2_SPI_CFG[0] );
MOVW	R0, #lo_addr(__COMPASS2_SPI_CFG+0)
MOVT	R0, #hi_addr(__COMPASS2_SPI_CFG+0)
MOV	R1, R0
MOVS	R0, #0
BL	_mikrobus_spiInit+0
;Click_Compass2_STM.c,41 :: 		mikrobus_logInit( _LOG_USBUART_A, 9600 );
MOVW	R1, #9600
MOVS	R0, #32
BL	_mikrobus_logInit+0
;Click_Compass2_STM.c,42 :: 		mikrobus_logWrite("--- System Init ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr1_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr1_Click_Compass2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,43 :: 		Delay_ms( 100 );
MOVW	R7, #20351
MOVT	R7, #18
NOP
NOP
L_systemInit0:
SUBS	R7, R7, #1
BNE	L_systemInit0
NOP
NOP
NOP
;Click_Compass2_STM.c,44 :: 		}
L_end_systemInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _systemInit
_applicationInit:
;Click_Compass2_STM.c,46 :: 		void applicationInit()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Compass2_STM.c,48 :: 		compass2_spiDriverInit( (T_COMPASS2_P)&_MIKROBUS1_GPIO, (T_COMPASS2_P)&_MIKROBUS1_SPI );
MOVW	R1, #lo_addr(__MIKROBUS1_SPI+0)
MOVT	R1, #hi_addr(__MIKROBUS1_SPI+0)
MOVW	R0, #lo_addr(__MIKROBUS1_GPIO+0)
MOVT	R0, #hi_addr(__MIKROBUS1_GPIO+0)
BL	_compass2_spiDriverInit+0
;Click_Compass2_STM.c,49 :: 		compass2_init();
BL	_compass2_init+0
;Click_Compass2_STM.c,50 :: 		Delay_ms( 300 );
MOVW	R7, #61055
MOVT	R7, #54
NOP
NOP
L_applicationInit2:
SUBS	R7, R7, #1
BNE	L_applicationInit2
NOP
NOP
NOP
;Click_Compass2_STM.c,51 :: 		compass2_setOUTResolution( _COMPASS2_SET_RESOLUTION_16bit );
MOVS	R0, __COMPASS2_SET_RESOLUTION_16bit
BL	_compass2_setOUTResolution+0
;Click_Compass2_STM.c,52 :: 		compass2_setMode( _COMPASS2_MODE_CONT_MEAS_2 );
MOVS	R0, __COMPASS2_MODE_CONT_MEAS_2
BL	_compass2_setMode+0
;Click_Compass2_STM.c,53 :: 		}
L_end_applicationInit:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationInit
_applicationTask:
;Click_Compass2_STM.c,55 :: 		void applicationTask()
SUB	SP, SP, #4
STR	LR, [SP, #0]
;Click_Compass2_STM.c,57 :: 		compass2_newMeasurement();
BL	_compass2_newMeasurement+0
;Click_Compass2_STM.c,59 :: 		mikrobus_logWrite(" --- Axis ---", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr2_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr2_Click_Compass2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,60 :: 		X_Axis = compass2_getAxisData( _COMPASS2_X_AXIS );
MOVS	R0, __COMPASS2_X_AXIS
BL	_compass2_getAxisData+0
MOVW	R1, #lo_addr(_X_Axis+0)
MOVT	R1, #hi_addr(_X_Axis+0)
STRH	R0, [R1, #0]
;Click_Compass2_STM.c,61 :: 		Y_Axis = compass2_getAxisData( _COMPASS2_Y_AXIS );
MOVS	R0, __COMPASS2_Y_AXIS
BL	_compass2_getAxisData+0
MOVW	R1, #lo_addr(_Y_Axis+0)
MOVT	R1, #hi_addr(_Y_Axis+0)
STRH	R0, [R1, #0]
;Click_Compass2_STM.c,62 :: 		Z_Axis = compass2_getAxisData( _COMPASS2_Z_AXIS );
MOVS	R0, __COMPASS2_Z_AXIS
BL	_compass2_getAxisData+0
MOVW	R1, #lo_addr(_Z_Axis+0)
MOVT	R1, #hi_addr(_Z_Axis+0)
STRH	R0, [R1, #0]
;Click_Compass2_STM.c,64 :: 		LongToStr(X_Axis, demoText);
MOVW	R0, #lo_addr(_X_Axis+0)
MOVT	R0, #hi_addr(_X_Axis+0)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_LongToStr+0
;Click_Compass2_STM.c,65 :: 		mikrobus_logWrite("X: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr3_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr3_Click_Compass2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,66 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,68 :: 		LongToStr(Y_Axis, demoText);
MOVW	R0, #lo_addr(_Y_Axis+0)
MOVT	R0, #hi_addr(_Y_Axis+0)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_LongToStr+0
;Click_Compass2_STM.c,69 :: 		mikrobus_logWrite("Y: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr4_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr4_Click_Compass2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,70 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,72 :: 		LongToStr(Z_Axis, demoText);
MOVW	R0, #lo_addr(_Z_Axis+0)
MOVT	R0, #hi_addr(_Z_Axis+0)
LDRSH	R0, [R0, #0]
MOVW	R1, #lo_addr(_demoText+0)
MOVT	R1, #hi_addr(_demoText+0)
BL	_LongToStr+0
;Click_Compass2_STM.c,73 :: 		mikrobus_logWrite("Z: ", _LOG_TEXT);
MOVW	R0, #lo_addr(?lstr5_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr5_Click_Compass2_STM+0)
MOVS	R1, #1
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,74 :: 		mikrobus_logWrite(demoText, _LOG_LINE);
MOVS	R1, #2
MOVW	R0, #lo_addr(_demoText+0)
MOVT	R0, #hi_addr(_demoText+0)
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,76 :: 		mikrobus_logWrite(" ", _LOG_LINE);
MOVW	R0, #lo_addr(?lstr6_Click_Compass2_STM+0)
MOVT	R0, #hi_addr(?lstr6_Click_Compass2_STM+0)
MOVS	R1, #2
BL	_mikrobus_logWrite+0
;Click_Compass2_STM.c,77 :: 		Delay_ms( 1000 );
MOVW	R7, #6911
MOVT	R7, #183
NOP
NOP
L_applicationTask4:
SUBS	R7, R7, #1
BNE	L_applicationTask4
NOP
NOP
NOP
;Click_Compass2_STM.c,78 :: 		}
L_end_applicationTask:
LDR	LR, [SP, #0]
ADD	SP, SP, #4
BX	LR
; end of _applicationTask
_main:
;Click_Compass2_STM.c,80 :: 		void main()
;Click_Compass2_STM.c,82 :: 		systemInit();
BL	_systemInit+0
;Click_Compass2_STM.c,83 :: 		applicationInit();
BL	_applicationInit+0
;Click_Compass2_STM.c,85 :: 		while (1)
L_main6:
;Click_Compass2_STM.c,87 :: 		applicationTask();
BL	_applicationTask+0
;Click_Compass2_STM.c,88 :: 		}
IT	AL
BAL	L_main6
;Click_Compass2_STM.c,89 :: 		}
L_end_main:
L__main_end_loop:
B	L__main_end_loop
; end of _main
