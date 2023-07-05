#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_config.h"
#include "GPIO_Interface.h"
#include "GPIO_Private.h"

void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8PinValue) {

	if (Copy_u8Pin >= 0 && Copy_u8Pin <= 15) {
		/*if the pin is selected as high*/
		if (Copy_u8PinValue == GPIO_HIGH) {
			switch (Copy_u8Port) {
			case GPIOA:
				SET_BIT(GPIOA_ODR , Copy_u8Pin); break;
			case GPIOB:
				SET_BIT(GPIOB_ODR , Copy_u8Pin);break;
			case GPIOC:
				SET_BIT(GPIOC_ODR , Copy_u8Pin);break;
			case GPIOD:
				SET_BIT(GPIOD_ODR , Copy_u8Pin);break;
			case GPIOE:
				SET_BIT(GPIOE_ODR , Copy_u8Pin);break;
			case GPIOH:
				SET_BIT(GPIOD_ODR , Copy_u8Pin);break;
			}
		}
		/*if the pin is selected as low*/
		else if (Copy_u8PinValue == GPIO_LOW) {
			switch (Copy_u8Port) {
			case GPIOA:
				CLR_BIT(GPIOA_ODR , Copy_u8Pin); break;
			case GPIOB:
				CLR_BIT(GPIOB_ODR , Copy_u8Pin);break;
			case GPIOC:
				CLR_BIT(GPIOC_ODR , Copy_u8Pin);break;
			case GPIOD:
				CLR_BIT(GPIOD_ODR , Copy_u8Pin);break;
			case GPIOE:
				CLR_BIT(GPIOE_ODR , Copy_u8Pin);break;
			case GPIOH:
				CLR_BIT(GPIOD_ODR , Copy_u8Pin);break;

			}
		}

	}

}

u32 GPIO_u8GetPinValue(u8 copy_u8PortID, u8 copy_PinID) {
	u32 Local_PinVal;

	switch (copy_u8PortID) {
	case GPIOA:

		GET_BIT(GPIOA_IDR,copy_PinID);
		break;
	case GPIOB:

		GET_BIT(GPIOB_IDR,copy_PinID );

		break;
	case GPIOC:

		GET_BIT(GPIOC_IDR, copy_PinID );
		break;
	case GPIOD:

		GET_BIT(GPIOD_IDR, copy_PinID );
		break;
	case GPIOE:

		GET_BIT(GPIOE_IDR, copy_PinID );
		break;
	case GPIOH:

		GET_BIT(GPIOH_IDR, copy_PinID );
		break;
	}

	return Local_PinVal;

}


void GPIO_voidSetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin,
			u8 Copy_u8Direction) {

		/*if the parameter passed is in the valid range*/
		if (Copy_u8Pin >= 0 && Copy_u8Pin <= 15) {
			/*if the pin is selected as output push pull*/
			if (Copy_u8Direction == GPIO_OUTPUT_PP) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOA_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOA_OTYPER &= ~( 1 << Copy_u8Pin);
					break;

				case GPIOB:
					GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOB_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOB_OTYPER &= ~( 1 << Copy_u8Pin);break;

				case GPIOC:
					GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOC_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOC_OTYPER &= ~( 1 << Copy_u8Pin);
					break;

				case GPIOD:
					GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOD_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOD_OTYPER &= ~( 1 << Copy_u8Pin);
					break;
				default:
					break;
				}
			}

			/*if the pin is selected as output open drain*/
			else if (Copy_u8Direction == GPIO_OUTPUT_OD) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOA_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOA_OTYPER |= ( 1 << Copy_u8Pin);
					break;

				case GPIOB:
					GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOB_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOB_OTYPER |= ( 1 << Copy_u8Pin);break;

				case GPIOC:
					GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOC_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOC_OTYPER |= ( 1 << Copy_u8Pin);
					break;

				case GPIOD:
					GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
					GPIOD_MODER |= ( 0b01 << (Copy_u8Pin*2) );
					GPIOD_OTYPER |= ( 1 << Copy_u8Pin);
					break;
				default:
					break;
				}
			}

			/*if the pin is selected as input pull up*/
			else if (Copy_u8Direction == GPIO_INPUT_PU) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR |= (0b01 << (Copy_u8Pin*2));
					break;

				case GPIOB:
					GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR |= (0b01 << (Copy_u8Pin*2));
					break;

				case GPIOC:
					GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR |= (0b01 << (Copy_u8Pin*2));
					break;

				case GPIOD:
					GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR |= (0b01 << (Copy_u8Pin*2));
					break;

				default:
					break;
				}
			}

			/*if the pin selected is input pull down*/
			else if (Copy_u8Direction == GPIO_INPUT_PD) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR |= (0b10 << (Copy_u8Pin*2));
					break;

				case GPIOB:
					GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR |= (0b10 << (Copy_u8Pin*2));
					break;

				case GPIOC:
					GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR |= (0b10 << (Copy_u8Pin*2));
					break;

				case GPIOD:
					GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR |= (0b10 << (Copy_u8Pin*2));
					break;

				default:
					break;
				}
			}
			/*if the pin selected is input floating*/
			else if (Copy_u8Direction == GPIO_INPUT_F) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOA_PUPDR |= (0b00 << (Copy_u8Pin*2));
					break;

				case GPIOB:
					GPIOB_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOB_PUPDR |= (0b00 << (Copy_u8Pin*2));
					break;

				case GPIOC:
					GPIOC_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOC_PUPDR |= (0b00 << (Copy_u8Pin*2));
					break;

				case GPIOD:
					GPIOD_MODER &= ~( 0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR &= ~(0b11 << (Copy_u8Pin*2));
					GPIOD_PUPDR |= (0b00 << (Copy_u8Pin*2));
					break;

				default:
					break;
				}
			}

			/*if the pin selected is analog*/
			else if (Copy_u8Direction == GPIO_ANALOG) {
				switch (Copy_u8Port) {
				case GPIOA:
					GPIOA_MODER |= ( 0b11 << (Copy_u8Pin*2));
					break;

				case GPIOB:
					GPIOB_MODER |= ( 0b11 << (Copy_u8Pin*2));
					break;

				case GPIOC:
					GPIOC_MODER |= ( 0b11 << (Copy_u8Pin*2));
					break;

				case GPIOD:
					GPIOD_MODER |= ( 0b11 << (Copy_u8Pin*2));
					break;

				default:
					break;
				}
			}

			/*if the pin is selected as Alternate function*/
			else if (Copy_u8Direction >= GPIO_AF0
					&& Copy_u8Direction <= GPIO_AF15) {
				if (Copy_u8Pin >= GPIO_PIN0 && Copy_u8Pin <= GPIO_PIN7) {
					switch (Copy_u8Port) {
					case GPIOA:
						GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOA_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOA_AFRL &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOA_AFRL |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOB:
						GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOB_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOB_AFRL &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOB_AFRL |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOC:
						GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOC_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOC_AFRL &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOC_AFRL |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOD:
						GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOD_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOD_AFRL &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOD_AFRL |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					default:
						break;
					}
				} else if (Copy_u8Pin >= GPIO_PIN8
						&& Copy_u8Pin <= GPIO_PIN15) {
					switch (Copy_u8Port) {
					case GPIOA:
						GPIOA_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOA_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOA_AFRH &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOA_AFRH |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOB:
						GPIOB_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOB_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOB_AFRH &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOB_AFRH |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOC:
						GPIOC_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOC_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOC_AFRH &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOC_AFRH |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					case GPIOD:
						GPIOD_MODER &= ~(0b11<<(Copy_u8Pin*2));
						GPIOD_MODER |= ( 0b10 << (Copy_u8Pin*2) );
						GPIOD_AFRH &= ~(0b1111 << (Copy_u8Pin * 4));
						GPIOD_AFRH |= (Copy_u8Direction << (Copy_u8Pin * 4));
						break;

					default:
						break;
					}
				}

			}
		}
}
#if 0
/*
 void DIO_voidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinID,
 u8 Copy_u8PinMode, u8 Copy_u8PinDir) {

 if (Copy_u8PinID <= 7 && Copy_u8PortID <= 15) {

 switch (Copy_u8PortID) {
 GPIOA_MODER &= GPIODIRECTION_MODE_BIT_MASK;
 GPIOA_MODER |= copy_u8pinMode;

 if(Copy_u8PinID <=15 && Copy_u8PinDir == LOGIC_HIGH){ 	//

 }
 case GPIOB:
 SET_BIT(GPIOB_MODER, Copy_u8PinID * 2U);
 break;
 case GPIOA:
 SET_BIT(GPIOA_MODER, Copy_u8PinID * 2U);
 break;
 case GPIOA:
 SET_BIT(GPIOA_MODER, Copy_u8PinID * 2U);
 break;
 case GPIOA:
 SET_BIT(GPIOA_MODER, Copy_u8PinID * 2U);
 break;
 case GPIOA:
 SET_BIT(GPIOA_MODER, Copy_u8PinID * 2U);
 break;

 }
 }

 }
 */
/*
 void	GPIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode)
 {

 if (Copy_u8PinID <= 15 && Copy_u8PortID <= 6) {
 if (Copy_u8PinValue == PIN_HIGH) //High
 {

 switch (Copy_u8PortID) {
 case GPIOA:
 //SET_BIT(GPIOA_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOA_ODR, Copy_u8PinID);
 break;
 case GPIOB:
 //SET_BIT(GPIOB_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOB_ODR, Copy_u8PinID );

 break;
 case GPIOAC:
 //SET_BIT(GPIOC_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOC_ODR, Copy_u8PinID );
 break;
 case GPIOD:
 //SET_BIT(GPIOD_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOD_ODR, Copy_u8PinID );
 break;
 case GPIOE:
 //SET_BIT(GPIOE_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOE_ODR, Copy_u8PinID );
 break;
 case GPIOH:
 //SET_BIT(GPIOH_ODR, Copy_u8PinID * 2U);
 SET_BIT(GPIOH_ODR, Copy_u8PinID );
 break;

 }
 } else if (Copy_u8PinValue == PIN_LOW) //Low
 {
 switch (Copy_u8PortID) {
 case GPIOA:
 //SET_BIT(GPIOA_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOA_ODR, Copy_u8PinID);
 break;
 case GPIOB:
 //SET_BIT(GPIOB_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOB_ODR, Copy_u8PinID );

 break;
 case GPIOAC:
 //SET_BIT(GPIOC_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOC_ODR, Copy_u8PinID );
 break;
 case GPIOD:
 //SET_BIT(GPIOD_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOD_ODR, Copy_u8PinID );
 break;
 case GPIOE:
 //SET_BIT(GPIOE_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOE_ODR, Copy_u8PinID );
 break;
 case GPIOH:
 //SET_BIT(GPIOH_ODR, Copy_u8PinID * 2U);
 CLR_BIT(GPIOH_ODR, Copy_u8PinID );
 break;

 }
 }
 }
 }
 */
#endif
