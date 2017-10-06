/*
 * snake.c
 *
 *  Created on: Oct 6, 2017
 *      Author: tuanti1997qn
 */


#include "snake.h"

int16_t direction;
char snake_length;
int16_t snake_body[snack_max_length];


//-----------------------------------------------------------------------------------------------------------------------
//* extern function
bool set_direct(int16_t dir)
{
    if(direction == -dir)
    {
        return fail;
    }
    direction = dir;
    return xem_fail;
}

//-----------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------
//* static function

void snake_move()
{
    int length_body_snake;
    for(length_body_snake = 0 ; length_body_snake < snake_length ; length_body_snake++ )
    {
        snake_body[length_body_snake] = snake_body[length_body_snake + 1];
    }
    snake_body[length_body_snake] += direction;
}

void conver_10(int16_t num,int8_t *goal)
{
    *goal = num % 10;
    num /= 10;
    *(goal + 1) = num % 10;
    num /= 10;
    *(goal + 2) = num % 10;
}
//-----------------------------------------------------------------------------------------------------------------------

