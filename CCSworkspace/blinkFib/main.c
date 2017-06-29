/*
 * main.c
 */

extern int fib(int n);

int main(void) {
	
//    fib(5);
	blink(9);
	return 0;
}

void read_


//blinking function
void blink (int n){
    char pattern = convert_to_morse(n);
    int dotDash = 0;
    int pinLED = 0;

    for( int i = 0; i < 5; i++){             // 5 bits (0-4)
        dotDash = (pattern >> i) & 0x01;     // read a bit at a time
        if(dotDash == 1){
        	pinLED = 1;
        	for (int i = 0; i < 50000; i++){}    // long pause while LED on for a 1
        	pinLED = 0;
        }
        if else(dotDash == 0){
        	pinLED = 1;
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
