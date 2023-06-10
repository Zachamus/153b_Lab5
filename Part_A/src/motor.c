/*
 * ECE 153B - Winter 2023
 *
 * Lab: 6A
 */

#include "stm32l476xx.h"
#include "motor.h"

static const uint32_t MASK = 65535;
static const uint32_t HalfStep[8] = {16,144,128,160,32,288,256,272};

static volatile int8_t dire = 0;
static volatile uint8_t step = 0;
static int mod = 0;
static int mod2 = 0;
void Motor_Init(void) {	
	//TODO
}

void rotate(void) {
	//TODO
	GPIOC->ODR &= ~(MASK);
	GPIOC->ODR |= HalfStep[0];
	if (dire == 0) {
	for (int i = 1; i <= 7; i++) {
		if (mod % 2 == 0) {
			GPIOC-> ODR |= HalfStep[i];
			mod += 1;
			
		}
		else {
			GPIOC-> ODR &= HalfStep[i];
			mod -= 1;
			
		}
	}
mod = 0;
	}		
	else {
		GPIOC->ODR &= ~(MASK);
		for (int j = 7; j > 0; j--) {
			if (mod % 2 == 0) {
				GPIOC-> ODR |= HalfStep[j];
				mod += 1;
				
				
			}
			else {
				GPIOC-> ODR &= HalfStep[j];
				mod -= 1;
			}
			
		}
		
		mod = 0;
		
		
	}
}

void setDire(int8_t direction) {
	//TODO
}
	


