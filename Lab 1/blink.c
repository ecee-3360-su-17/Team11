/*
 * main.c
 */

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"

#define GREEN GPIO_PIN_3
#define BLUE GPIO_PIN_2
#define RED GPIO_PIN_1

extern int fib(int n);

int main(void) {
	
//    mod(fib(39));    // commented out while getting running fib code  
	mod(231);          // reads the number in fib sequence, sent to modulus function
                       // need to add for loop for multiple digits
	return 0;
}

// read the amount of digits, seperate and then blink them
void mod(int a) {
	
	int b = numPlaces (a);
	int m = 10;
	for(int i = 0; i < b; i++){
		blink((a % m)/(m * 0.1));    
		m = m * 10;
	}
}

int numPlaces (int n) {     //stolen code, used to find the amount of digits in an integer.
	    int r = 1;
	    if (n < 0) n = (n == MININT) ? MAXINT : -n;
	    while (n > 9) {
	        n /= 10;
	        r++;
	    }
	    return r;
	}

//blinking function 
void blink (int n){

    volatile uint32_t ui32Loop;     // Loop counter
    int i;                          // Loop counter

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){}

    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, BLUE);       // Enable the blue LED
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, RED);        // Enable the red LED

    char pattern = convert_to_morse(n);

    for( int i = 0; i < 5; i++){             // 5 bits (0-4)
        dotDash = (pattern >> i) & 0x01;     // read a bit at a time
        if(dotDash == 1){
            GPIOPinWrite(GPIO_PORTF_BASE, BLUE, BLUE);   // Turn off blue LED
                    else GPIOPinWrite(GPIO_PORTF_BASE, RED, RED);               // Turn on red LED
        	for (int i = 0; i < 50000; i++){}    // long pause while LED on for a 1
        	pinLED = 0;
        }
        if else(dotDash == 0){
            PIOPinWrite(GPIO_PORTF_BASE, BLUE, 0x0);    // Turn off blue LED
                    else GPIOPinWrite(GPIO_PORTF_BASE, RED, 0x0);               // Turn off red LED

        	for (int i = 0; i < 20000; i++){}    // short pause while LED on for a 0
        	pinLED = 0;
        }
        else {
        	break;
        }
		for(int i = 0; i < 50000; i++){}     // long pause while LED off between dot/dash
    }
}

//convert to Morse code
char convert_to_morse (int n){
    switch(n){
    case 0:
        return 0b11111;
        break;
    case 1:
        return 0b01111;
        break;
    case 2:
        return 0b00111;
        break;
    case 3:
        return 0b00011;
        break;
    case 4:
        return 0b00001;
        break;
    case 5:
        return 0b00000;
        break;
    case 6:
        return 0b10000;
        break;
    case 7:
        return 0b11000;
        break;
    case 8:
        return 0b11100;
        break;
    case 9:
        return 0b11110;
        break;
    default:
        break;
    }

}
