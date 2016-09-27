#ifndef FREERTOS_IO_UART_H
#define FREERTOS_IO_UART_H

portBASE_TYPE FreeRTOS_WDT_open( Peripheral_Control_t * const pxPeripheralControl );
portBASE_TYPE FreeRTOS_WDT_ioctl( Peripheral_Descriptor_t pxPeripheral, uint32_t ulRequest, void *pvValue );

#endif /* FREERTOS_IO_UART_H */
