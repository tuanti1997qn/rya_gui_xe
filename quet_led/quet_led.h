/*
 * quetled.h
 *
 *  Created on: Oct 4, 2017
 *      Author: tuant
 */

#ifndef QUET_LED_QUET_LED_H_
#define QUET_LED_QUET_LED_H_

#include "private_quet_led.h"
#include "../include.h"

#define DATA_PIN            GPIO_PORTF_BASE
#define CLK_PIN             GPIO_PIN_1
#define LATCH_PIN           GPIO_PIN_2
#define PORT_control        GPIO_PIN_3
#define Layer_port_control  GPIO_PORTA_BASE
#define Layer_pin           0xFF


// function
extern void quet();
extern void set_led_cube(char x, char y, char z);
extern char get_led_cube(char x, char y, char z);
extern void clear_led_cube(char x, char y, char z);

#endif /* QUET_LED_QUET_LED_H_ */
