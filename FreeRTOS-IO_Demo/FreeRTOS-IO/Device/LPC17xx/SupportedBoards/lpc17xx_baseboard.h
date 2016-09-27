#ifndef LPCXPRESSO_BASE_BOARD_H
#define LPCXPRESSO_BASE_BOARD_H

/* Header files for all the driver libraries that can be used with this BSP. */
#include "lpc17xx_wdt.h"
#include "lpc17xx_gpio.h"

/*******************************************************************************
 * Definitions used by FreeRTOS+IO to determine the peripherals that are
 * available on the board, and the functions used to interface with the target
 * specific peripheral drivers.
 ******************************************************************************/

/*******************************************************************************
 * Definitions used by the UART-interrupt-driven-command-console.c example file.
 *
 * See http://www.freertos.org/FreeRTOS-Plus/FreeRTOS_Plus_IO/Board_Support_Packages.shtml
 *
 ******************************************************************************/
#define boardAVAILABLE_DEVICES_LIST												\
{																				\
	{ ( const int8_t * const ) "/WDT0/", eWDT_TYPE, ( void * ) LPC_WDT },		\
\
}

/*******************************************************************************
 * Map the FreeRTOS+IO interface to the LPC17xx specific functions.
 ******************************************************************************/
portBASE_TYPE vFreeRTOS_lpc17xx_PopulateFunctionPointers( const Peripheral_Types_t ePeripheralType, Peripheral_Control_t * const pxPeripheralControl );
#define boardFreeRTOS_PopulateFunctionPointers vFreeRTOS_lpc17xx_PopulateFunctionPointers

/*******************************************************************************
 * These define the number of peripherals available on the microcontroller -
 * not the number of peripherals that are supported by the software
 ******************************************************************************/
#define boardNUM_WDTS				1
//#define boardNUM_LCDS				1


/*******************************************************************************
 * GPIO/LED polarities
 ******************************************************************************/
#define boardGPIO_OUTPUT			( 1 )
#define boardGPIO_INPUT				( 0 )
#define boardLED_ON					( 1 )
#define boardLED_OFF				( 0 )

#endif /* LPCXPRESSO_BASE_BOARD_H */
