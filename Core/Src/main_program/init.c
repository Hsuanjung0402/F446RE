/*
 * init.cpp
 *
 *  Created on: Jul 11, 2026
 *      Author: hsuanjung
 */

#include "stm32f4xx_hal.h"
#include "init.h"
extern TIM_HandleTypeDef htim5;
extern TIM_HandleTypeDef htim2;
extern TIM_HandleTypeDef htim3;

void initial() {
	HAL_TIM_Base_Start_IT(&htim5);
	HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
