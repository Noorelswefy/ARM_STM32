/*
 * SYSTICK_program.c
 *
 *  Created on: Jun 25, 2023
 *      Author: noor elswefy
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "SYSTICK_interface.h"
#include "SYSTICK_private.h"
#include "SYSTICK_config.h"

#ifndef NULL
#define NULL		(void * )0)
#endif
static u8 Mode;
static void (*STK_CallBack)(void) = NULL;
void STK_voidInit() {
	/* Enable sysTick  */

	SET_BIT(STK->STK_CTRL, STK_CTRL_EN);

	/* Select clock source */

#if		CLOCK_SOURCE_SELECTION == AHB_8

	CLR_BIT(STK->STK_CTRL, STK_CTRL_CLKSOURCE);

#elif	CLOCK_SOURCE_SELECTION == AHB

	SET_BIT(STK->STK_CTRL,STK_CTRL_CLKSOURCE );
#endif

}
void STK_voidBusyWait(u32 Tick) {
	/* Disable sysTick timer */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_EN);		//For safety
	/* Load the Tick */
	STK->STK_LOAD = Tick;
	/* Enable sysTick timer */
	SET_BIT(STK->STK_CTRL, STK_CTRL_EN);

	/* Busy Waiting*/
	while (GET_BIT(STK -> STK_CTRL, STK_CTRL_COUNTFLAG) == 0) {
		asm("NOP");
		//Accurate delay assembly instruction
	}

	/* Disable sysTick timer control reg */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_EN);
	STK->STK_LOAD = 0;
	STK->STK_VAL = 0;

}
void STK_voidSingleInterval(u32 Tick, void (*PF)(void)) {
	/* Disable sysTick timer		 */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_EN);
	/* Load the Tick 				*/
	STK->STK_LOAD = Tick;
	/*	Set the mode of interrupt	*/
	Mode = SINGLE_INTERVAL;
	/* Assign CallBack */
	STK_CallBack = PF;
	/* Enable Exception request PIE */
	SET_BIT(STK-> STK_CTRL, STK_CTRL_TICKINT);
	/*	Enable Timer				*/
	SET_BIT(STK -> STK_CTRL, STK_CTRL_EN);

}
void STK_voidDoupleInterval(u32 Tick, void (*PF)(void)) {
	/* Disable sysTick timer		 */
	CLR_BIT(STK->STK_CTRL, STK_CTRL_EN);
	/* Load the Tick 				*/
	STK->STK_LOAD = Tick;
	/*	Set the mode of interrupt	*/
	Mode = PERIOD_INTERVAL;
	/* Assign CallBack */
	STK_CallBack = PF;
	/* Enable Exception request PIE */
	SET_BIT(STK-> STK_CTRL, STK_CTRL_TICKINT);
	/*	Enable Timer				*/
	SET_BIT(STK -> STK_CTRL, STK_CTRL_EN);

}
void STK_voidStopInterval() {
	/*	Disable Systick timer		*/
	CLR_BIT(STK -> STK_CTRL, STK_CTRL_EN);
	STK->STK_LOAD = 0;
	STK->STK_VAL = 0;
}

void STK_Handler() {
	u8 Local_u8Temp = 0;
	if (Mode == SINGLE_INTERVAL) {
		/*	Disable Interrupt		*/
		CLR_BIT(STK -> STK_CTRL, STK_CTRL_TICKINT);
		/*	Disable Timer			*/
		CLR_BIT(STK -> STK_CTRL, STK_CTRL_EN);
		STK->STK_LOAD = 0;
		STK->STK_VAL = 0;
	}
	STK_CallBack();
	/*	Clear Interrupt Flag		*/
	Local_u8Temp = GET_BIT(STK -> STK_CTRL, STK_CTRL_COUNTFLAG);

}
u32 STK_voidGetRemainingTick()
{
	u8 Local_u8Result = 0;
	Local_u8Result = 	(STK->STK_LOAD) - (STK->STK_VAL);
	return Local_u8Result;
}

