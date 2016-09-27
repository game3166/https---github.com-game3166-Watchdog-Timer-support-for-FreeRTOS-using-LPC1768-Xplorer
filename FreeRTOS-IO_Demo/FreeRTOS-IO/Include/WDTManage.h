#ifndef WDT_MANAGE_H
#define WDT_MANAGE_H

#include "FreeRTOS.h"
#include "task.h"
#include "StackMacros.h"


#define MAX_TCB_MNGABLE		5
#define TCBMANAGE_ERR		0xFF

/*
typedef struct tskTaskControlBlock
{
	volatile portSTACK_TYPE	*pxTopOfStack;
	xListItem				xGenericListItem;
	xListItem				xEventListItem;
	unsigned portBASE_TYPE	uxPriority;
	portSTACK_TYPE			*pxStack;
	signed portCHAR			pcTaskName[ configMAX_TASK_NAME_LEN ];

	#if ( portSTACK_GROWTH > 0 )
		portSTACK_TYPE *pxEndOfStack;
	#endif

	#if ( portCRITICAL_NESTING_IN_TCB == 1 )
		unsigned portBASE_TYPE uxCriticalNesting;
	#endif

	#if ( configUSE_TRACE_FACILITY == 1 )
		unsigned portBASE_TYPE	uxTCBNumber;
	#endif

	#if ( configUSE_MUTEXES == 1 )
		unsigned portBASE_TYPE uxBasePriority;
	#endif

	#if ( configUSE_APPLICATION_TASK_TAG == 1 )
		pdTASK_HOOK_CODE pxTaskTag;
	#endif

	#if ( configGENERATE_RUN_TIME_STATS == 1 )
		unsigned portLONG ulRunTimeCounter;
	#endif

} MytskTCB;

MytskTCB * volatile MyCurrentTCB = NULL;

#define GetTCBHandle ( ( MytskTCB * ) MyCurrentTCB )
*/

struct ManageStruct
{
	unsigned int * volatile count;
	unsigned int bcount;
};

int register_wdtmanage( unsigned int * counter );
int check_switch( void );
//void config_switch( void );
int get_totalTCB( void );

uint8_t check_counters( void );

#endif /* WDT_MANAGE_H */
