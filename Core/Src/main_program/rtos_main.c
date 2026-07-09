/*
 * rtos_main.c
 *
 *  Created on: Jul 9, 2026
 *      Author: hsuanjung
 */


#include "stm32f4xx_hal.h"
#include "stm32f446xx.h"

// #include "init.h"
#include "uros_init.h"
// #include "servo_control.h"
// #include "DC_motor_ctrl.h"
// #include "motor_config.h"
#include "cmsis_os.h"

#define angle_1_1 0
#define angle_1_2 180
#define angle_2_1 40
#define angle_2_2 126

int sec = 0, test = 0;
volatile int enable = 0, dir = 0;

void StartDefaultTask(void *argument) {
	// initial();
	uros_init();
	for (;;) {

		uros_agent_status_check();
        osDelay(1000/FREQUENCY);

		//The code below should write in Timer Interrupt. NOT here!
		sec++;
		// if(enable) dc_motor(dir);
		// else dc_motor(0), dir = 0;
		// HAL_Delay(2000);
		// set_servo_angle(2, angle_2_2, angle_2_1 );
		// HAL_Delay(1000);
		// set_servo_angle(1, angle_1_2, angle_1_1 );
		// HAL_Delay(2000);
		// set_servo_angle(1, angle_1_1, angle_1_2 );
		// HAL_Delay(1000);
		// set_servo_angle(2, angle_2_1, angle_2_2 );
		// HAL_Delay(2000);
		osDelay(1);
	}
}

// void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
// 	if( GPIO_Pin == GPIO_PIN_1){
// 		test++;
// 	}
// }

