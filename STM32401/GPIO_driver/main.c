/**
 ******************************************************************************
 * @file           : main.c
 * @author         : noor elswefy
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_Interface.h"
//#include "SYSTICK_interface.h"
/*
void Toggle_LED() {
	GPIO_voidSetPinValue(GPIOA, GPIO_PIN5, GPIO_LOW);
	STK_voidBusyWait(1000000);  //1sec
	GPIO_voidSetPinValue(GPIOA, GPIO_PIN5, GPIO_HIGH);
}
*/
int main(void) {
	RCC_voidSysClkInit();
	RCC_vidEnablePerClk(RCC_AHB1,0);
	//STK_voidInit();
	GPIO_voidSetPinDirection(GPIOA, GPIO_PIN5, GPIO_OUTPUT_PP);
	while (1) {
		//GPIO_voidSetPinValue(GPIOA, GPIO_PIN5, GPIO_LOW);
		//STK_voidBusyWait(1000000);  //1sec
		GPIO_voidSetPinValue(GPIOA, GPIO_PIN5, GPIO_HIGH);
		//STK_voidBusyWait(1000000);  //1sec
	}
}
