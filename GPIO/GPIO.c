/*
 * GPIO.c
 *
 *  Created on: Apr 30, 2017
 *      Author: tuanti1997qn
 */

#include "../include.h"
#include "GPIO.h"

static uint32_t LED_Status=GPIO_PIN_1;
int a;

extern void Config_LED(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);// cap xung clock cho port F hoat dong
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);// port F pin 1
//    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);// port F pin 1 la out put
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,0); // xuat ra

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);// cap xung clock cho port F hoat dong
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);// port F pin 1 la out put
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4,GPIO_PIN_4); // xuat ra
}

extern void Plinky_LED(void){
    static uint8_t i=0;
    if(i==0)
        i=LED_Status;
    else
        i=0;
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3,i);
    SysCtlDelay(SysCtlClockGet()/3);// delay 1s
}

extern void Config_BUTTON(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);// cap xung clock cho port F hoat dong
//    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);// port F pin 1
//    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1,0);
    GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, GPIO_PIN_4);// port F pin 1 la out put
    GPIOPadConfigSet(GPIO_PORTF_BASE,GPIO_PIN_4,GPIO_STRENGTH_8MA,GPIO_PIN_TYPE_STD_WPU);//
    GPIOIntRegister(GPIO_PORTF_BASE,&SWITCH_ISR);// dang ky
    GPIOIntEnable (GPIO_PORTF_BASE,GPIO_INT_PIN_4);// enable pin
    IntEnable(INT_GPIOF);// enable port
    IntMasterEnable();// enable master
}

static void SWITCH_ISR(void){
    GPIOIntClear(GPIO_PORTF_BASE,GPIOIntStatus(GPIO_PORTF_BASE,true) );// xoa co ngat
    if (LED_Status==GPIO_PIN_1)
        LED_Status=GPIO_PIN_2;
    else
        LED_Status=GPIO_PIN_1;
}
