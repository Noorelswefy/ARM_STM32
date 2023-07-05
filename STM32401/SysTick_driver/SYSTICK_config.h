/*
 * SYSTICK_config.h
 *
 *  Created on: Jun 25, 2023
 *      Author: noor elswefy
 */

#ifndef SYSTICK_CONFIG_H_
#define SYSTICK_CONFIG_H_

#define COUNTER_ENABLE			1
#define COUNTER_DISABLE			0

/******
 * Please Select the clock source
 *	 1- AHB_8	( AHB/8)
 *	 2- AHB		(Processor clock )
 ******/
#define CLOCK_SOURCE_SELECTION 		AHB_8


#endif /* SYSTICK_CONFIG_H_ */
