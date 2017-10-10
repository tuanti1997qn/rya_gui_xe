/*
 * snake.h
 *
 *  Created on: Oct 6, 2017
 *      Author: tuant
 */

#ifndef SNAKE_SNAKE_H_
#define SNAKE_SNAKE_H_

#include "../include.h"
#include "private_snake.h"

#define fail 0
#define xem_fail 1

#define die   0
#define alive   1

#define win        2

#define over_max_wall 8
#define over_min_wall -1

#define eat 1
#define no_eat 0

#define snack_max_length 100


//-----------------------------------------------------------------------------------------------------------------------
//* extern function

extern int8_t set_direct(int16_t dir);
extern void init_snake();
extern char creat_food(int16_t random_value);
extern void set_food_random_value(int16_t random_value);
//-----------------------------------------------------------------------------------------------------------------------

#endif /* SNAKE_SNAKE_H_ */
