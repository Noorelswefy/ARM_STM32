/*
 * SYSTICK_interface.h
 *
 *  Created on: Jun 25, 2023
 *      Author: noor elswefy
 */

#ifndef SYSTICK_INTERFACE_H_
#define SYSTICK_INTERFACE_H_



#define AHB_8 			0		//pre-scaler 8 for mC speed
#define AHB				1		//mC speed



void STK_voidInit();
void STK_voidBusyWait();
void STK_voidSingleInterval( u32 Tick , void (*PF)(void));
void STK_voidDoupleInterval( u32 Tick , void (*PF)(void));
void STK_voidStopInterval();
void STK_Handler();
u32  STK_voidGetRemainingTick();

#endif /* SYSTICK_INTERFACE_H_ */
