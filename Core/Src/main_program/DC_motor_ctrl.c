/*
 * DC_motor_ctrl.c
 *
 *  Created on: Jul 11, 2026
 *      Author: hsuanjung
 */


#include "stm32f4xx_hal.h"
#include "DC_motor_ctrl.h"

void dc_motor(int dir)
{
	switch (dir)
	{
	case 0:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_RESET);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_3, GPIO_PIN_SET);
		HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET);
		break;

	default:
		break;
	}
}
