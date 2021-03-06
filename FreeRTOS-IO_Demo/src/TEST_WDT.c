#include "TEST_WDT.h"
#include "LPC17xx.h"

#include <stdio.h>

/**
**************************************************************************

****1111
  Function Name : delay()

  Description :This function suspends the tasks for specified ticks.

  Input :  ticks:no of ticks in multiple of 1 usec
            task: task to be suspended

  Output : void

  Note :
*******************************************************************************
*/

void delay(int count)
{
  int j=0,i=0;

  for(j=0;j<count;j++)
  {
    /* At 60Mhz, the below loop introduces
    delay of 10 us */
    for(i=0;i<35;i++);
  }
}

/**
  *******************************************************************
  	Funtion Name : Test_LED()

  	Description  :

  	Input        :

  	Output       : None

  	Note         :
  *****************************************************************
  */
  void test_wdt(void)
  {
	  int j;
	  for(j=0;j<5;j++)
	     {
		  	//LPC_GPIO0->FIOPIN |=  TEST_WDT_LED;
	 	    LPC_GPIO2->FIOPIN |=  TEST_WDT_BUZ;
	 	    delay(600);   /* Delay 500ms */
	 	    printf("betn\n");
	 	    //LPC_GPIO0->FIODIR |= ~TEST_WDT_LED;
	 	    LPC_GPIO2->FIOPIN &= ~TEST_WDT_BUZ;
	 	    delay(600);
	     }
	  //printf("endtstwt\n");
  }

