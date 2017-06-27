asm_fib:
	push {r7, lr}
	sub sp, sp, #12
	add r7, sp, #0
	str r0, [r7, #4]
	cmp r0, 0		//compare with 0
	beq end
	cmp r0, #1		//compare with 1
	beq end
	ldr r2, [r7, #4]
	cmp r2, #2		//
	blt fib
	sub r2, r2, #1	//fib(n-1) is r2
	mov r0, r2		// r2 into r3
	mov r3, r0		// r3 is fib(n-1)

fib:
	ldr r2, [r7, #4]
	sub r2, r2, #2	//fib(n-2) is r2
	mov r0, r2		//move to return register
	mov r2, r0
	add r0, r2, r3	//fib(n-1) + fib(n-2)
	b end

end:	//return n
	mov sp, r7
	add sp, sp, #12
	pop {r7, pc}
