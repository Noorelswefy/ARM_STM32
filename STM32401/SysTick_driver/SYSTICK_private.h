/*
 * SYSTICK_private.h
 *
 *  Created on: Jun 25, 2023
 *      Author: noor elswefy
 */

#ifndef SYSTICK_PRIVATE_H_
#define SYSTICK_PRIVATE_H_

typedef struct {
	volatile u32 STK_CTRL;
	volatile u32 STK_LOAD;
	volatile u32 STK_VAL;
	volatile u32 STK_CALIB;
}STK_type;

#define SYSTICK_BASE_ADD ((u32) 0xE000E010)	/* Systick base Address*/
//((volatile STK_type *) (0xE000E010))
#define STK ((volatile STK_type * )(SYSTICK_BASE_ADD))

#define STK_CTRL_EN		  		0		/* Enable or Disable Systick */
#define STK_CTRL_TICKINT		1		/* Enable Exception request  in Systick */
#define STK_CTRL_CLKSOURCE		2		/* Select clock source */
#define STK_CTRL_COUNTFLAG 		16		/* Count-down flag */

#define	SINGLE_INTERVAL			0
#define	PERIOD_INTERVAL			1

#endif /* SYSTICK_PRIVATE_H_ */
