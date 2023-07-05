 /*
 * RCC_private.h
 *
 *  Created on: Jun 23, 2023
 *      Author: noor elswefy
 */

#ifndef RCC_PRIVATE_H_
#define RCC_PRIVATE_H_


#define RCC_BASE_ADDRESS			((u32)0x40023800)

#define RCC_CR						*((volatile u32 *)(0x00 + (RCC_BASE_ADDRESS)))
#define RCC_PLLCFGR					*((volatile u32 *)(0x04 + (RCC_BASE_ADDRESS)))
#define RCC_CFGR					*((volatile u32 *)(0x08 + (RCC_BASE_ADDRESS)))
#define RCC_CIR						*((volatile u32 *)(0x0C + (RCC_BASE_ADDRESS)))

#define RCC_AHB1ENR					*((volatile u32 *)(0x30 + (RCC_BASE_ADDRESS)))
#define RCC_APB1ENR					*((volatile u32 *)(0x40 + (RCC_BASE_ADDRESS)))
#define RCC_APB2ENR					*((volatile u32 *)(0x44 + (RCC_BASE_ADDRESS)))




#define RCC_HSI					1
#define RCC_HSE					2
#define RCC_PLL					3


#define PLLM_MASK				0xFFFFFFE0

#define PLLN_MASK				0xFFFFC01F

#define PLLP_MASK				0xFFFF3FFF

#define AHB1_MASK				0xFFFFFF0F

#define APB1_MASK				0xFFFFE3FF

#define APB2_MASK				0xFFFF1FFF


/*AHB1 Bus speed*/
#define AHB_NO_DIV				0b0000
#define AHB_DIV_2				0b1000
#define AHB_DIV_4				0b1001
#define AHB_DIV_8				0b1010
#define AHB_DIV_16				0b1011
#define AHB_DIV_64				0b1100
#define AHB_DIV_128				0b1101
#define AHB_DIV_256				0b1110
#define AHB_DIV_512				0b1111

/*APB1 & APB2 Bus Speed*/
#define APB_NO_DIV				0b000
#define APB_DIV_2				0b100
#define APB_DIV_4				0b101
#define APB_DIV_8				0b110
#define APB_DIV_16				0b111












#define RCC_BASE_ADDRESS			((u32)0x40023800)

#define RCC_CR						*((volatile u32 *)0x00 + (RCC_BASE_ADDRESS))
#define RCC_PLLCFGR					*((volatile u32 *)0x04 + (RCC_BASE_ADDRESS))
#define RCC_CFGR					*((volatile u32 *)0x08 + (RCC_BASE_ADDRESS))
#define RCC_CIR						*((volatile u32 *)0x0C + (RCC_BASE_ADDRESS))

#define RCC_AHB1ENR					*((volatile u32 *)0x30 + (RCC_BASE_ADDRESS))
#define RCC_APB1ENR					*((volatile u32 *)0x40 + (RCC_BASE_ADDRESS))
#define RCC_APB2ENR					*((volatile u32 *)0x44 + (RCC_BASE_ADDRESS))












#if 0
#define RCC_BASE_ADD		((u32)0x40023800)


#define RCC_CR				*((volatile u32 * ) (RCC_BASE_ADD+0x00))
#define RCC_PLLCFGR			*((volatile u32 * ) (RCC_BASE_ADD+0x04))
#define RCC_CFGR			*((volatile u32 * ) (RCC_BASE_ADD+0x08))
#define RCC_CIR				*((volatile u32 * ) (RCC_BASE_ADD+0x0C))
#define RCC_AHB1RSTR		*((volatile u32 * ) (RCC_BASE_ADD+0x10))
#define RCC_AHB2RSTR		*((volatile u32 * ) (RCC_BASE_ADD+0x14))
#define RCC_RESERVED0		*((volatile u32 * ) (RCC_BASE_ADD+0x18))
#define RCC_RESERVED20		*((volatile u32 * ) (RCC_BASE_ADD+0x1C))
#define RCC_APB1RSTR		*((volatile u32 * ) (RCC_BASE_ADD+0x20))
#define RCC_APB2RSTR		*((volatile u32 * ) (RCC_BASE_ADD+0x24))
#define RCC_RESERVED2		*((volatile u32 * ) (RCC_BASE_ADD+0x28))
#define RCC_RESERVED3		*((volatile u32 * ) (RCC_BASE_ADD+0x2C))
#define RCC_AHB1ENR			*((volatile u32 * ) (RCC_BASE_ADD+0x30))
#define RCC_AHB2ENR			*((volatile u32 * ) (RCC_BASE_ADD+0x34))
#define RCC_RESERVED4		*((volatile u32 * ) (RCC_BASE_ADD+0x38))
#define RCC_RESERVED5		*((volatile u32 * ) (RCC_BASE_ADD+0x3C))
#define RCC_APB1ENR			*((volatile u32 * ) (RCC_BASE_ADD+0x40))
#define RCC_APB2ENR			*((volatile u32 * ) (RCC_BASE_ADD+0x44))
#define RCC_RESERVED6		*((volatile u32 * ) (RCC_BASE_ADD+0x48))
#define RCC_RESERVED7		*((volatile u32 * ) (RCC_BASE_ADD+0x4C))
#define RCC_AHB1LPENR		*((volatile u32 * ) (RCC_BASE_ADD+0x50))
#define RCC_AHB2LPENR		*((volatile u32 * ) (RCC_BASE_ADD+0x54))
#define RCC_RESERVED8		*((volatile u32 * ) (RCC_BASE_ADD+0x58))
#define RCC_RESERVED9		*((volatile u32 * ) (RCC_BASE_ADD+0x5C))
#define RCC_APB1LPENR       *((volatile u32 * ) (RCC_BASE_ADD+0x60))
#define RCC_APB2LPENR		*((volatile u32 * ) (RCC_BASE_ADD+0x64))
#define RCC_RESERVED10		*((volatile u32 * ) (RCC_BASE_ADD+0x68))
#define RCC_RESERVED11		*((volatile u32 * ) (RCC_BASE_ADD+0x6C))
#define RCC_BDCR			*((volatile u32 * ) (RCC_BASE_ADD+0x70))
#define RCC_CSR				*((volatile u32 * ) (RCC_BASE_ADD+0x74))
#define RCC_RESERVED12		*((volatile u32 * ) (RCC_BASE_ADD+0x78))
#define RCC_RESERVED13		*((volatile u32 * ) (RCC_BASE_ADD+0x7C))
#define RCC_SSCGR			*((volatile u32 * ) (RCC_BASE_ADD+0x80))
#define RCC_PLLI2SCFGR		*((volatile u32 * ) (RCC_BASE_ADD+0x84))
#define RCC_RESERVED14		*((volatile u32 * ) (RCC_BASE_ADD+0x88))
#define RCC_DCKCFGR			*((volatile u32 * ) (RCC_BASE_ADD+0x8C))







#define PLLM_MASK				0xFFFFFFE0

#define PLLN_MASK				0xFFFFC01F

#define PLLP_MASK				0xFFFF3FFF

#define AHB1_MASK				0xFFFFFF0F

#define APB1_MASK				0xFFFFE3FF

#define APB2_MASK				0xFFFF1FFF


/*AHB1 Bus speed*/
#define AHB_NO_DIV				0b0000
#define AHB_DIV_2				0b1000
#define AHB_DIV_4				0b1001
#define AHB_DIV_8				0b1010
#define AHB_DIV_16				0b1011
#define AHB_DIV_64				0b1100
#define AHB_DIV_128				0b1101
#define AHB_DIV_256				0b1110
#define AHB_DIV_512				0b1111

/*APB1 & APB2 Bus Speed*/
#define APB_NO_DIV				0b000
#define APB_DIV_2				0b100
#define APB_DIV_4				0b101
#define APB_DIV_8				0b110
#define APB_DIV_16				0b111

#endif
#endif /* RCC_PRIVATE_H_ */
