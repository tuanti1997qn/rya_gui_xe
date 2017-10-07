/*
 * private_snake.h
 *
 *  Created on: Oct 6, 2017
 *      Author: tuant
 */

#ifndef SNAKE_PRIVATE_SNAKE_H_
#define SNAKE_PRIVATE_SNAKE_H_

#include "snake.h"

//-----------------------------------------------------------------------------------------------------------------------
//* static function

void snake_move();

void convert_10(int16_t num,int8_t *goal);

char check_snake_die();

char check_snake_eat();

void convert_8(int16_t num,int8_t *goal);
//-----------------------------------------------------------------------------------------------------------------------



#endif /* SNAKE_PRIVATE_SNAKE_H_ */
