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

void snake_eat();

int16_t get_random_value();         // chưa hoàn thành

void snake_win();                   // chưa hoàn thành
//-----------------------------------------------------------------------------------------------------------------------



#endif /* SNAKE_PRIVATE_SNAKE_H_ */
