

/**
 * main.c
 */
#include "include.h"
int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    Config_LED();
    config_systick(100);
    init_snake()
    init_timer_for_snake();
    while(1);
	return 0;
}
