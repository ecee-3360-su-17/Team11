/*
 * main.c
 */

extern void asm_fib();

int main(void) {
	
    asm_fib();
	return 0;
}
#if 0
//blinking function
void blink (int n){
    char pattern = convert_to_morse(n);
    for( int i = 0; i < __; i++){
        int state = __;
        __SET__LED__STATE
        __WAIT between digits__
    }
    __long wait between numbers__
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
#endif
