/*
 * GPIO_config.h
 *
 *  Created on: Jun 23, 2023
 *      Author: noor elswefy
 */

#ifndef GPIO_CONFIG_H_
#define GPIO_CONFIG_H_

/**
 * Choose the mode
 *  00: INPUT_MODE (reset state)
 *  01: GPIO_MODE
 *  10: ALTERNATE_FUNC_MODE
 *  11: ANALOG_MODE
 * */
#define GPIO_DIRECTION_MODE_BIT_MASK 		0xFFFC

#define	INPUT_MODE 				0
#define OUTPUT_MODE				1
#define ALTERNATE_FUNC_MODE		2
#define ANALOG_MODE				3

/**
 * if the OUTPUT_MODE selected,
 * 	select output speed
 *  00: Low speed
 *	01: Medium speed
 *	10: High speed
 *	11: Very high speed/
 */
#define	LOW_SPEED				0
#define MEDIUM_SPEED			1
#define HIGH_SPEED				2
#define VERY_HIGH_SPEED			3

/**
 * if the OUTPUT_MODE selected,
 * 	select output type
 *  0: Output push-pull (reset state)
 *	1: Output open-drain
 **/
#define	PUSH-PULL			0
#define OPEN-DRAIN			1

/**
 * if the INPUT_MODE selected,
 * 	select  pull-up or pull-down
 *
 *  00: No pull-up, pull-down
 *	01: Pull-up
 *	10: Pull-down
 *	11: Reserve
 **/
#define	NO_PULL			0
#define PULL_UP			1
#define PULL_DOWN		2


#endif /* GPIO_CONFIG_H_ */
