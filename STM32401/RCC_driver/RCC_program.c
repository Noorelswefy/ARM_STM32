#include "std_types.h"
#include "bit_math.h"
#include "RCC_interface.h"
#include "RCC_private.h"
//#include "RCC_config.h"

void  RCC_voidSysClkInit(void)
{
	/* RCC_CR + RCC_CFGR */   ///HSI internal
	RCC_CR    =	0X00000001; // IN HEX
	RCC_CFGR  = 0X00000000;
}
//prephiral id 
void RCC_voidEnablePreClk(u8 BusId , u8 PreId)
{
		/* Range check */
	if(BusId<3 && PreId< 31)
	{
	
			switch (BusId) {
			case RCC_AHB1 : SET_BIT(RCC_AHB1ENR,PreId);		break;
			case RCC_APB1 : SET_BIT(RCC_APB1ENR,PreId);		break;
			case RCC_APB2 : SET_BIT(RCC_APB1ENR,PreId);		break;
			}
			 
	}else{ /* Report Error*/ 
	}

}

void RCC_voidDisablePreClk(u8 BusId , u8 PreId)
{
		/* Range check */
	if(BusId<3 && PreId< 31)
	{
	
			switch (BusId) {
			case RCC_AHB1 : CLR_BIT(RCC_AHB1ENR,PreId);		break;
			case RCC_APB1 : CLR_BIT(RCC_APB1ENR,PreId);		break;
			case RCC_APB2 : CLR_BIT(RCC_APB1ENR,PreId);		break;
			}
			 
	}else{ /* Report Error*/ 
		}

}
