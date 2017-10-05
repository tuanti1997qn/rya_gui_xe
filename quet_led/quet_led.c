/*
 * quetled.c
 *
 *  Created on: Oct 4, 2017
 *      Author: tuant
 */

#include "quet_led.h"

char led_cube[8][8][8];// x: row, y: column, z: layer

//-----------------------------------------------------------------------------------------------------------------------
//* extern function


//-----------------------------------------------------------------------------------------------------------------------


//-----------------------------------------------------------------------------------------------------------------------
//* static function
void bit_shift(char bit)        //dich 1 bit vao 74HC595
{
    write_pin(PORT_control,CLK_PIN,CLK_PIN);        //xem lai
    if(bit)
    {
        write_pin(PORT_control,DATA_PIN,DATA_PIN);
    }
    else
    {
        write_pin(PORT_control,DATA_PIN,0);
    }
    write_pin(PORT_control,CLK_PIN,0);
}

void column_shift(char layer, char row)     // xem lai ve con dich  // dich 1 hang
{
    int i=0;
    for(i=0 ; i<8 ; i++)
    {
        bit_shift(led_cube[i][row][layer]);
    }
}

void layer_shift(char layer)
{
    int i=0;
    choose_layer(layer);
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai
    for(i=0 ; i<8 ; i++)
    {
        column_shift(layer, i);
    }
    write_pin(PORT_control,LATCH_PIN,0);
}

void choose_layer(char layer)
{
    char pin[8]= {GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7};
    write_pin(Layer_port_control , Layer_pin , pin[layer]);
}
//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
//hardware function
void write_pin(unsigned int port, unsigned int pin, unsigned int data);
//-----------------------------------------------------------------------------------------------------------------------

