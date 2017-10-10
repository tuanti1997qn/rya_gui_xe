

/**
 * main.c
 */
#include "include.h"
int main(void)
{
    SysCtlClockSet(SYSCTL_SYSDIV_2_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
    Config_LED();
    while(1)
    {
    quet();

    }
	return 0;
}
