#ifndef ___traffic_mannual_light_H_
#define ___traffic_mannual_light_H_
typedef enum{
	RED = 0, YELLOW =1,GREEN = 2

} State;
#include "main.h"
#include "global.h"
extern int time_1  , time_2 ;
extern int time_red_select,time_green_select,time_yellow_select ;
void  traffic_display(GPIO_TypeDef * GPIOx, uint16_t LED_RED, uint16_t LED_YELLOW, uint16_t LED_GREEN, State type);
void  traffic_double_display(GPIO_TypeDef * GPIOx1, uint16_t LED_RED1, uint16_t LED_YELLOW1, uint16_t LED_GREEN1,GPIO_TypeDef * GPIOx2, uint16_t LED_RED2, uint16_t LED_YELLOW2, uint16_t LED_GREEN2, int status);
void traffic_init();
void traffic_green_red();
void traffic_yellow_red();
void traffic_red_green();
void traffic_red_yellow();
void traffic_red_red1();
//void traffic_red_red2();
void traffic_mannual_green_red();
void traffic_mannual_yellow_red();
void traffic_mannual_red_green();
void traffic_mannual_red_yellow();
void traffic_set_time_red();
void traffic_set_time_yellow();
void traffic_set_time_green();
void update_timers() ;
void display_times();

#endif /* INC_traffic_mannual_light_H_*/
