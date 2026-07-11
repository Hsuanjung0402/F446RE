/*
 * servo_control.cpp
 *
 *  Created on: Jul 11, 2026
 *      Author: hsuanjung
 */

#include "servo_control.h"
#include "stm32f4xx_hal.h"
#include "motor_config.h"

extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

#define per_1 7.3
#define per_2 6.65
#define period 100

void set_servo_angle(int num , float target_angle , float last_angle ){
	float pulse;
	float delta = target_angle - last_angle;
	float unit = delta / period;
	float next_angle = last_angle + unit;

	for (int i = 0; i < period; i++)
	{
		if (num == 1)
		{
			pulse = (500 + (next_angle * per_1));
			__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, pulse);
		}
		else if (num == 2)
		{
			pulse = (500 + (next_angle * per_2));
			__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, pulse);
		}
		osDelay(10);
		next_angle += unit;
	}
}
