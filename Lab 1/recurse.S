/*
 * recurse.S
 *
 *  Created on: Jun 13, 2017
 *      Author: haffizi
 */

int loop_asm(){
for (int iter = 0; iter < 100; iter ++){
counter++
}
return counter;
}

loop asm:
	mov r0, #0
	mov r1, #5

top_loop:
	cmp r0, #100
	add r0, #1
	blte top_loop //not valid inst

exit:
	mov r0, r1
	mov pc, lr

int fun_asm (int base, int pow){
	if(pow == 0)
	return 1;
	if(pow == 1)
	return base;
	return base*(fun_asm(base), pow-1);

fun_asm:
	cmp r1, #0
	bgt base_case_two
	mov r0, #1
	mov pc, lr

base_case_two:
	cmp r1, #0
	blt base_case_three
	mov r0, #-1
	mov pc, lr

base_case_three:
	cmp r1,
	beq recurse
	mov pc, lr

beq recurse:
	push {lr, r0}
	sub r1, #1
	b fun_asm
	pop {r3}
	mul r0, r0, r3
	pop {pc}
