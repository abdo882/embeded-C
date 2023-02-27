#include "stdint.h"

#define RCC_BASE 0x40021000
#define PORTA_BASE 0x40010800
#define RCC_APB2ENR  *(volatile uint32_t*) (RCC_BASE +0x18)
#define PORTA_BASE_CRH  *(volatile uint32_t*) (PORTA_BASE+0x04)
#define PORTA_BASE_ODR  *(volatile uint32_t*) (PORTA_BASE+0x0C)
int main(void)
{
	RCC_APB2ENR |=1<<2;
	PORTA_BASE_CRH=0xff0fffff ;
	PORTA_BASE_CRH=0x00200000 ;
	while(1)
	{

		PORTA_BASE_ODR|=1<<13 ;//set pin 13
		for (int i=0;i<5000;i++);
		PORTA_BASE_ODR &=~(1<<13) ;//clear pin 13
		for (int i=0;i<5000;i++);
	}
}
