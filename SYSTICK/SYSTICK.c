/*
 * SYSTICK.c
 *
 *  Created on: Oct 15, 2017
 *      Author: tuant
 */
#include "SYSTICK.h"

static void sys_tick_int(void)
{
    quet();
}
void config_systick( uint32_t num_tick )
{
    SysTickIntRegister(&sys_tick_int);
    SysTickPeriodSet(SysCtlClockGet()/1000*num_tick);
    SysTickIntEnable();
    SysTickEnable();
}





