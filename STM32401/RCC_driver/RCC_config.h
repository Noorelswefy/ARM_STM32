/*
 * RCC_config.h
 *
 *  Created on: Jun 24, 2023
 *      Author: noor elswefy
 */

#ifndef RCC_CONFIG_H_
#define RCC_CONFIG_H_

#define RCC_CLOCK_SOURCE 	RCC_HSI

/*From 2 -----> 63*/
#define PLLM_DIV			2

/*From 192 -----> 432*/
#define PLLN_MUL			192

/*From 2 ----> 8*/
#define PLLP_DIV			2


/**
 * choose AHB1 speed
 * NO_DIV
 * DIV_2
 * DIV_4
 * DIV_8
 * DIV_16
 * DIV_64
 * DIV_128
 * DIV_256
 * DIV_512
 * 	*/
/*AHB_DIV_2 -----> AHB_DIV_512 or AHB_NO_DIV*/
#define AHB1_PRESCALER		APB_DIV_2

/*APB_DIV_2 -----> APB_DIV_512 or APB_NO_DIV*/
#define APB1_PRESCALER		APB_NO_DIV

/*APB_DIV_2 -----> APB_DIV_512 or APB_NO_DIV*/
#define APB2_PRESCALER		APB_NO_DIV




#endif /* RCC_CONFIG_H_ */
