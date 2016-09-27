
/* Standard includes. */
#include <string.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"
#include "semphr.h"
#include <stdio.h>

/* FreeRTOS IO library includes. */
#include "FreeRTOS_IO.h"

/*-----------------------------------------------------------*/

/* Holds the list of peripherals that are available to the FreeRTOS+IO
interface.  boardAVAILABLE_DEVICED_LIST is defined in FreeRTOS_IO_BSP.h, and is
specific to a hardware platform. */
static const Available_Peripherals_t xAvailablePeripherals[] = boardAVAILABLE_DEVICES_LIST;

/*-----------------------------------------------------------*/

/* See the function prototype definition for documentation information. */
Peripheral_Descriptor_t FreeRTOS_open( const int8_t *pcPath, const uint32_t ulFlags )
{

portBASE_TYPE xIndex, xInitialiseResult;
const portBASE_TYPE xNumberOfPeripherals = sizeof( xAvailablePeripherals ) / sizeof( Available_Peripherals_t );


int8_t cPeripheralNumber;
Peripheral_Control_t *pxPeripheralControl = NULL;

	/* The flags exist to maintain a standard looking interface, but are not
	(yet) used. */
	( void ) ulFlags;

	/* Search for the peripheral in the list of peripherals for the board being
	used. */
	for( xIndex = 0; xIndex < xNumberOfPeripherals; xIndex++ )
	{
		if( strcmp( ( const char * const ) pcPath, ( const char * const ) xAvailablePeripherals[ xIndex ].pcPath ) == 0 )
		{
			/* pcPath is a valid path, search no further. */


			break;
		}
	}


	if( xIndex < xNumberOfPeripherals )
	{
		/* pcPath was a valid path.  Extract the peripheral number.  The
		peripheral number cannot appear in the middle of a string, so must be
		followed by the end of string character. */
		while( ( ( *( pcPath + 1 ) ) != '/' ) && ( ( *( pcPath + 1 ) ) != 0x00 ) )
		{
			pcPath++;
			while( ( *pcPath < '0' ) || ( *pcPath > '9' ) )
			{
				pcPath++;
			}
		}

		/* Convert the number from its ASCII representation. */
		cPeripheralNumber = *pcPath - '0';

		/* Create the peripheral control structure used by FreeRTOS+IO to
		access the peripheral.  This is also used as the handle to the
		peripheral. */
		pxPeripheralControl = pvPortMalloc( sizeof( Peripheral_Control_t ) );
		if( pxPeripheralControl != NULL )
		{
			/* Initialise the common parts of the control structure. */
			pxPeripheralControl->pxTxControl = NULL;
			pxPeripheralControl->pxRxControl = NULL;
			pxPeripheralControl->pxDevice = &( xAvailablePeripherals[ xIndex ] );
			pxPeripheralControl->cPeripheralNumber = cPeripheralNumber;

			/* Initialise the peripheral specific parts of the control
			structure, and call the peripheral specific open function. */
			xInitialiseResult = boardFreeRTOS_PopulateFunctionPointers( xAvailablePeripherals[ xIndex ].xPeripheralType, pxPeripheralControl );

			if( xInitialiseResult != pdPASS )
			{

				/* Something went wrong.  Free up resources and return NULL. */
				vPortFree( pxPeripheralControl );
				pxPeripheralControl = NULL;
			}
		}
	}

	return ( Peripheral_Descriptor_t ) pxPeripheralControl;
}
/*-----------------------------------------------------------*/

/* See the function prototype definition for documentation information. */
portBASE_TYPE FreeRTOS_ioctl( Peripheral_Descriptor_t const xPeripheral, uint32_t ulRequest, void *pvValue )
{
Peripheral_Control_t *pxPeripheralControl = ( Peripheral_Control_t * ) xPeripheral;
portBASE_TYPE xReturn = pdFAIL, xCommandIsDeviceSpecific = pdFALSE;

	//configASSERT( pxPeripheralControl );

	/* Handle any non peripheral specific commands here. */
	switch( ulRequest )
	{
	/************************/

		default :
			//printf("in switch\n");
			xCommandIsDeviceSpecific = pdTRUE;
			xReturn = pdPASS;
			break;
	}

	/* Handle any device specific commands. */
	if( ( xCommandIsDeviceSpecific == pdTRUE ) && ( xReturn != pdFAIL ) )
	{
		//printf("dev specific\n");
		xReturn = pxPeripheralControl->ioctl( pxPeripheralControl, ulRequest, pvValue );
	}

	return xReturn;
}
/*-----------------------------------------------------------*/







