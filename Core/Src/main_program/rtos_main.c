/*
 * rtos_main.c
 *
 *  Created on: Jul 9, 2026
 *      Author: hsuanjung
 */


#include "stm32f4xx_hal.h"
#include "stm32f446xx.h"

#include "init.h"
#include "uros_init.h"
#include "DC_motor_ctrl.h"
#include "servo_control.h"
#include "motor_config.h"
#include "cmsis_os.h"

int test = 0;
volatile int limsw = 0;
volatile int mission_status_ = 0;

extern TIM_HandleTypeDef htim5;
extern int mission_status;

void StartDefaultTask(void *argument) {
	initial();
	uros_init();
	for (;;) {
		uros_agent_status_check();
        osDelay(1000/FREQUENCY);
	}
}

//You need to create a task first before using the function below.
//GO to cubeMX, FREERTOS-> TASK and QUEUE-> ADD
void StartServoTask(void *argument)
{
	for (;;)
	{
		switch (mission_status_)
		{
		case 1:
			mission_status_ = 0;
			set_servo_angle(2, angle_2_2, angle_2_1);
			osDelay(1000);
			set_servo_angle(1, angle_1_2, angle_1_1);
			osDelay(2000);
			set_servo_angle(1, angle_1_1, angle_1_2);
			osDelay(1000);
			set_servo_angle(2, angle_2_1, angle_2_2);
			osDelay(2000);
			break;

		case 2:
            mission_status_ = 0;
            limsw = 0;
            dc_motor(1);
            while (limsw == 0)
            {
                osDelay(10);
            }
            dc_motor(0);
            dc_motor(2);
            osDelay(1000);
            limsw = 0;
            while (limsw == 0)
            {
                osDelay(10);
            }
            dc_motor(0);
            break;
		default:
			break;
		}

		osDelay(1);
	}
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
    static uint32_t last_trigger_time = 0;
    uint32_t current_time = HAL_GetTick();

    if( GPIO_Pin == GPIO_PIN_1){
        // 限制兩次觸發之間至少間隔 50 毫秒
        if (current_time - last_trigger_time > 50) {
            limsw = 1; // 建議用 boolean 狀態取代 ++，避免數值溢位或難以預測
            last_trigger_time = current_time;
        }
    }
}
