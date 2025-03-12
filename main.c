#include "stm32f4xx.h"

volatile uint32_t msTicks = 0;

void delayMs(int t) {
    int i;
    SysTick->LOAD = 16000;
    SysTick->VAL = 0;
    SysTick->CTRL = 0x5;

    for (i = 0; i < t; i++) {
        while ((SysTick->CTRL & 0x10000) == 0) {}
    }
    SysTick->CTRL = 0;
}

int main(void) {
    RCC->AHB1ENR |= 5; 
    GPIOC->MODER &= ~0xC000000; 
    GPIOC->PUPDR |= 0x4000000; 
    GPIOA->MODER &= ~0xC00; 
    GPIOA->MODER |= 0x400; 

    while (1) {
        if (!(GPIOC->IDR & 0x2000)) { 
            GPIOA->ODR |= 0x20; 
        } else {
            GPIOA->ODR &= ~0x20; 
        }
    }
}
