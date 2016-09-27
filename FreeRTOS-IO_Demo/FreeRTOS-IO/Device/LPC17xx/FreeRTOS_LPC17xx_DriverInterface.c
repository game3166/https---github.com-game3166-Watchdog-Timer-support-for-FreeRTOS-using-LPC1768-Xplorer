
/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include <stdio.h>
/* FreeRTOS IO library includes. */
#include "FreeRTOS_DriverInterface.h"
#include "FreeRTOS_wdt.h"
#include "FreeRTOS_lcd.h"

portBASE_TYPE vFreeRTOS_lpc17xx_PopulateFunctionPointers( const Peripheral_Types_t ePeripheralType, Peripheral_Control_t * const pxPeripheralControl )
{
portBASE_TYPE xReturn = pdFALSE;



	switch( ePeripheralType )
	{
		/* Open the peripheral. */

		case eWDT_TYPE :
			#if ioconfigINCLUDE_WDT == 1
			{

				xReturn = FreeRTOS_WDT_open( pxPeripheralControl );

			}
			#endif
			break;

		default :

			/* Nothing to do here.  xReturn is already set to pdFALSE. */
			//configASSERT( xReturn );
			break;
	}

	/* Just to prevent compiler warnings should FreeRTOSIOConfig.h be
	configured to exclude the above FreeRTOS_nnn_open() calls. */
	( void ) pxPeripheralControl;

	return xReturn;
}
