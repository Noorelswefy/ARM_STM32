#ifndef	_GPIO_INTERFACE_H_
#define	_GPIO_INTERFACE_H_


/*PORTA: */
#define GPIOA        (0x00)
#define GPIOB        (0x01)
#define GPIOC        (0x02)
#define GPIOD        (0x03)
#define GPIOE        (0x04)
#define GPIOH        (0x05)

/*
 * Pin ID Macros
 */
#define GPIO_PIN0         (0x00)
#define GPIO_PIN1         (0x01)
#define GPIO_PIN2         (0x02)
#define GPIO_PIN3         (0x03)
#define GPIO_PIN4         (0x04)
#define GPIO_PIN5         (0x05)
#define GPIO_PIN6         (0x06)
#define GPIO_PIN7         (0x07)
#define GPIO_PIN8         (0x08)
#define GPIO_PIN9         (0x09)
#define GPIO_PIN10        (0x0A)
#define GPIO_PIN11        (0x0B)
#define GPIO_PIN12        (0x0C)
#define GPIO_PIN13        (0x0D)
#define GPIO_PIN14        (0x0E)
#define GPIO_PIN15        (0x0F)


/*DIRECTIONS*/
#define GPIO_AF0				0
#define GPIO_AF1				1
#define GPIO_AF2				2
#define GPIO_AF3				3
#define GPIO_AF4				4
#define GPIO_AF5				5
#define GPIO_AF6				6
#define GPIO_AF7				7
#define GPIO_AF8				8
#define GPIO_AF9				9
#define GPIO_AF10				10
#define GPIO_AF11				11
#define GPIO_AF12				12
#define GPIO_AF13				13
#define GPIO_AF14				14
#define GPIO_AF15				15

#define GPIO_INPUT_PU			16
#define GPIO_INPUT_PD			17
#define GPIO_INPUT_F			18
#define GPIO_OUTPUT_PP			19
#define GPIO_OUTPUT_OD			20
#define GPIO_ANALOG				21

/*
 * GPIO Values
 */

#define GPIO_HIGH           (0x01)
#define GPIO_LOW            (0x00)





/*Prototypes*/


void	GPIO_voidSetPinDirection(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinMode);

void    GPIO_voidSetPinValue(u8 Copy_u8PortID,u8 Copy_u8PinID,u8 Copy_u8PinValue);

u32     GPIO_u8GetPinValue(u8 copy_u8PortID , u8 copy_PinID );
/*void    DIO_voidGetPinValue(u8 copy_u8PortID , u8 copy_PinID ,u8 *copy_u8PinVal );*/


#endif
