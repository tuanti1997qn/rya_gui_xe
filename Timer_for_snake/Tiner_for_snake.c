/*
 * Tiner_for_snake.c
 *
 *  Created on: Oct 15, 2017
 *      Author: tuant
 */
#include "Timer_for_snake.h"

void init_timer_for_snake(void)     //con rắn dùng timer 1
{
    uint32_t ui32Period;
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER1);
    TimerConfigure(timer_snake_base, TIMER_CFG_PERIODIC);
    ui32Period = min_speed
    TimerLoadSet(TIMER1_BASE, _timer, ui32Period - 1);
    TimerIntRegister(timer_snake_base, _timer , pfnHandler);
    IntEnable(INT_TIMER0A);
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);
    TimerEnable(TIMER0_BASE, TIMER_A);
}

static int timer_for_snake_int(void)
{
    if(snake_eat())
    {
        creat_food(get_random_value());
        return 1;
    }
    else
    {
        snake_move();
        return 0;
    }
}
