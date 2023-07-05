/*
 * RCC_interface.h
 *
 *  Created on: Jun 23, 2023
 *      Author: noor elswefy
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_



#define RCC_AHB1		6
#define RCC_APB1		5
#define RCC_APB2		4

#define RCC_HSI			1
#define RCC_HSE			2
#define RCC_PLL			3


/*#define AHB1_GPIOHEN		7
#define AHB1_GPIOEEN		4
#define AHB1_GPIODEN		3
#define AHB1_GPIOCEN		2
#define AHB1_GPIOBEN		1
#define AHB1_GPIOAEN		0

#define APB2_SYSCFG			14
*/

void RCC_voidSysClkInit(void);

void RCC_voidEnablePreClk(u8 BusId , u8 PreId);

void RCC_voidDisablePreClk(u8 BusId , u8 PreId);

#endif /* RCC_INTERFACE_H_ */
