 .global asm_fib

asm_fib:
	push {lr}
	cmp r0, #0
	beq end
	pop {pc}
	cmp r0, #1
	beq end
	pop {pc}

body:
	push {r0}
	sub r0, r0, #1
	bl asm_fib
	mov r1, r0
	pop {r0}
	sub r0, r0, #2
	bl asm_fib

end:
	add r0, r0,
	pop {pc}



