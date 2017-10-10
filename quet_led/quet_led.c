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

void quet()
{
    static char tang = 0;
    layer_shift(tang);
    tang ++ ;
    if(tang == 8)
    {
        tang = 0;
    }
}

void set_led_cube(char x, char y, char z)
{
    led_cube[x][y][z] = 1;
}

void clear_led_cube(char x, char y, char z)
{
    led_cube[x][y][z] = 0;
}

char get_led_cube(char x, char y, char z)
{
    return led_cube[x][y][z];
}

//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
//* static function
void bit_shift(char bit)        //dich 1 bit vao 74HC595
{
    write_pin(PORT_control,CLK_PIN,CLK_PIN);        //xem lai
    delay();
    if(bit)
    {
        write_pin(PORT_control,DATA_PIN,DATA_PIN);
    }
    else
    {
        write_pin(PORT_control,DATA_PIN,0);
    }
    write_pin(PORT_control,CLK_PIN,0);
    delay();
}

void column_shift(char layer, char row)     // xem lai ve con dich  // dich 1 cot
{
    int column=0;
    for(column=0 ; column<8 ; column++)
    {
        bit_shift(led_cube[column][row][layer]);
    }
}


//void column_shift(char layer, char row)     // xem lai ve con dich  // dich 1 cot
//{
//    int column=0;
//    for(column=0 ; column<8 ; column++)
//    {
//        bit_shift(1);
//    }
//}

void layer_shift(char layer)            // dich 1 cot
{
    int row=0;
    choose_layer(layer);
    for(row=0 ; row<8 ; row++)
    {
        column_shift(layer, row);
    }
    write_pin(PORT_control,LATCH_PIN,LATCH_PIN);        //xem lai // latchs
    delay();
    write_pin(PORT_control,LATCH_PIN,0);
}

void choose_layer(char layer)
{
    char pin[8]= {GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7};
    write_pin(Layer_port_control , Layer_pin , pin[layer]);
}

//void choose_layer(char layer)
//{
//    write_pin(Layer_port_control, GPIO_PIN_4, GPIO_PIN_4);
//}
//-----------------------------------------------------------------------------------------------------------------------

//-----------------------------------------------------------------------------------------------------------------------
//hardware function
void write_pin(unsigned int port, unsigned int pin, unsigned int data)
{
    GPIOPinWrite(port, pin, data);
}
void delay()
{
    SysCtlDelay(50);
}
//-----------------------------------------------------------------------------------------------------------------------

