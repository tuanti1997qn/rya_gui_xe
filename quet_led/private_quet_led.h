/*
 * private_quet_led.h
 *
 *  Created on: Oct 5, 2017
 *      Author: tuant
 */

#ifndef QUET_LED_PRIVATE_QUET_LED_H_
#define QUET_LED_PRIVATE_QUET_LED_H_

#include "quet_led.h"


//-----------------------------------------------------------------------------------------------------------------------
//* static function
void bit_shift(char bit);
void column_shift(char layer, char row);
void layer_shift(char layer);
void choose_layer(char layer);

//-----------------------------------------------------------------------------------------------------------------------


///-----------------------------------------------------------------------------------------------------------------------
//hardware function
void write_pin(unsigned int port, unsigned int pin, unsigned int data);
//-----------------------------------------------------------------------------------------------------------------------
#endif /* QUET_LED_PRIVATE_QUET_LED_H_ */
