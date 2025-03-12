This program is designed for the **STM32F4 microcontroller** and controls an LED based on the state of a button. The button is connected to **PC13**, and the LED is connected to **PA5**. The program initializes the necessary GPIO pins: PC13 is configured as an input with a pull-up resistor, and PA5 is configured as an output. In the main loop, the program continuously checks the state of the button. If the button is pressed (detected by reading a low signal on PC13 due to the pull-up resistor), the LED on PA5 is turned on by setting the corresponding bit in the `GPIOA->ODR` register. When the button is released, the LED is turned off by clearing the same bit. This creates a direct and responsive interaction where the LED lights up only while the button is pressed, providing immediate visual feedback. The `delayMs` function is included but not actively used in this implementation, as the LED state is directly tied to the button's real-time input.
