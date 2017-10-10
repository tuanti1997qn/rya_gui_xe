/*
 * GPIO.h
 *
 *  Created on: Apr 30, 2017
 *      Author: tuanti1997qn
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "../include.h"

extern void Config_LED(void);
extern void Plinky_LED(void);
extern void Config_BUTTON(void);
static void SWITCH_ISR(void);

#endif /* GPIO_GPIO_H_ */
