#ifndef FREERTOS_LCD_H
#define FREERTOS_LCD_H

/* These are not public functions.  Do not call these functions directly.  Call
FreeRTOS_Open(), FreeRTOS_write(), FreeRTOS_read() and FreeRTOS_ioctl() only. */
portBASE_TYPE FreeRTOS_lcd_open( Peripheral_Control_t * const pxPeripheralControl );
size_t FreeRTOS_lcd_write( Peripheral_Descriptor_t const pxPeripheral, const void *pvBuffer, const size_t xBytes );
//portBASE_TYPE FreeRTOS_lcd_ioctl( Peripheral_Descriptor_t pxPeripheral, uint32_t ulRequest, void *pvValue );

#endif /* FREERTOS_LCD_H */
