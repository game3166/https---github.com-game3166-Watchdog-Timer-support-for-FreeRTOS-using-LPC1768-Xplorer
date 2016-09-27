

#ifndef __TEST_H
#define __TEST_H
void test_wdt(void);
void delay(int count);
#define TEST_WDT_LED (1 << 10)
#define TEST_WDT_BUZ (1 << 2)
#define TEST_WDT_SW  (1<<12)

#endif
