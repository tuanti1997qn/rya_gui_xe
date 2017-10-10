/*
 * snake.c
 *
 *  Created on: Oct 6, 2017
 *      Author: tuanti1997qn
 */


#include "snake.h"

int8_t direction;    //  huong la so co 3 chu so va di chuyen nguoc thi huong am
uint8_t snake_length;
int16_t snake_body[snack_max_length], food , food_random_value;


//-----------------------------------------------------------------------------------------------------------------------
//* extern function
int8_t set_direct(int16_t dir)      // set huong cho con ran
{
    if(direction == -dir)           // kiem tra co bi nguoc huong khong
    {
        return fail;
    }
    direction = dir;
    return xem_fail;
}

void init_snake()
{
    snake_length = 3;
    snake_body[0] = 112;
    snake_body[1] = 113;
    snake_body[2] = 114;
    direction = 001;
    food = 777;
    set_led_cube(1, 1, 2);// set 3 điểm thân rắn
    set_led_cube(1, 1, 3);
    set_led_cube(1, 1, 4);
    set_led_cube(7, 7, 7);// set đồ ăn
}

char creat_food(int16_t random_value)       // hàm này lấy giá trị của giá trị random. lấy giá trị timer từ lần nhấn nút gần nhất. trong trường hợp fail lấy giá trị timer sau fail
// hàm được gọi khi vừa ăn
{
    int8_t food_place[3];
    int16_t food_place_10;
    convert_8(random_value,food_place);     // lấy giá trị random từ 1-8 cho đồ ăn
    food_place_10 = food_place[0]*100 + food_place[1]*10 +food_place[2];   // chuyển thành 10
    convert_10(food_place_10, food_place);
    if( get_led_cube(food_place[0],food_place[1],food_place[2]) == 1)  // kiểm tra có trùng hay không
    {
        return fail;
    }
    food = food_place_10;          // không trùng thì gán và set...
    set_led_cube(food_place[0],food_place[1],food_place[2]);
    return xem_fail;
}

void set_food_random_value(int16_t random_value)
{
    food_random_value = random_value;
}

//-----------------------------------------------------------------------------------------------------------------------



//-----------------------------------------------------------------------------------------------------------------------
//* static function


void snake_move()               // ran di chuyen
{
    int length_body_snake = 0;
    int8_t descartes[3];
    convert_10(snake_body[length_body_snake] , descartes);      // duyet tu duoi den dau ran
    clear_led_cube(descartes[0] , descartes[1] , descartes[2]);     // xoa cai duoi duoi trong mang led cube
    for(length_body_snake = 0 ; length_body_snake < snake_length ; length_body_snake++ )        // dich chuyen len 1 don vi theo huong
    {
        snake_body[length_body_snake] = snake_body[length_body_snake + 1];
    }
    snake_body[length_body_snake] += direction;             // tang cai dau
    convert_10(snake_body[length_body_snake] , descartes);
    set_led_cube(descartes[0] , descartes[1] , descartes[2]);       // set dau ran vao mang quet led
}

void convert_10(int16_t num,int8_t *goal)                       // ham convert 1 so sang 3 chu cai cua he 10 vi huong cua con ran o dang so co 3 so
{
    *(goal+2) = num % 10;
    num /= 10;
    *(goal + 1) = num % 10;
    num /= 10;
    *goal = num % 10;
}

char check_snake_die()                                          // check xem ran chet chua , check sau khi goi move
{
    int8_t check_status[3];
    convert_10(snake_body[snake_length], check_status);         // lay cai dau con ran
    int i;
    for(i=0 ; i<3 ; i++)
    {
        if( check_status[i] >= over_max_wall )    // check dung tuong (chan tren)
        {
            return die;
        }
    }
    for(i = 0 ; i < snake_length ; i++)             // check rắn cắn thân
    {
        if( snake_body[snake_length] == snake_body[i] )     // duyet het than ran
        {
            return die;
        }
    }
    return alive;
}

char check_snake_eat()      // check truoc khi move
{
    if((snake_body[snake_length] + direction) == food) // kiểm tra bước tiếp theo có ăn được không?
    {
        return eat;
    }
    return no_eat;
}

void convert_8(int16_t num,int8_t *goal)            // hàm convert qua hệ bát phân lấy random đồ ăn cho rắn
{
    *(goal + 2) = num % 7;
    num /= 7;
    *(goal + 1) = num %7 ;
    num /= 7;
    *goal = num % 7;
}

void snake_eat()        // rắn đã ăn mồi
{
    snake_length++;     // tăng biến độ dài rắn
    if(snake_length = snack_max_length)         // check độ dài rắn bằng độ dài mã thì win
    {
        snake_win();
    }
    snake_body[snake_length] = food;        // cái đồ ăn thành đầu con rắn
    int8_t descartes[3];
    convert_10(food, descartes);        // lấy 3 giá trị x y z vào trong mảng descartes
    set_led_cube(descartes[0], descartes[1], descartes[2]);
    while(!creat_food(food_random_value))                // đảo của cret_foot giá trị hêt fail mới ngừng làm
    {
        food_random_value = get_random_value();
    }
}

int16_t get_random_value()          // lấy giá trị "ngẫu nhiên" từ timer ra
{
    int16_t random_value;
                                    // ở đây là hàm lấy giá trị của timer lúc đếm khuyến cáo lấy timer nào mà không liên quan đến con rắn để tránh mất tính random.
    return random_value;            // trả về giá trị random
}

void snake_win()
{
                                // làm cái abc xyz gì đấy
                                // nghiên cứu thử reset bằng phần mềm. không thì cho treo luôn.
}
//-----------------------------------------------------------------------------------------------------------------------

