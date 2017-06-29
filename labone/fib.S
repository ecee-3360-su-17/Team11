 	.syntax unified
 	.align	2
 	.global	fib
 	.global fib_recur
 	.global end
 	.thumb
 	.thumb_func
 fib:
   		push	{r7, lr}
  		sub	sp, sp, #8
  		add	r7, sp, #0
  		str	r0, [r7]  // input n, saved in r0

  		cmp r0, #1		  // if(n <=1) branch return n
  		ble end

  		// n > 2? compute fib(n-1) and fib(n-2)

		ldr r1, [r7] // r1 = n

  		// fib(n-1):
  		subs r1, r1, #1 // r1= n-1
  		mov r0, r1 // r0 = n-1, now call fib(n-1)
  		bl fib
  		mov r1, r0 // r2 = fib(n-1)
		push {r1}

		// fib(n-2)
  		ldr r2, [r7]
  		subs r2, r2, #2
  		mov r0, r2
  		bl fib // call fib(n-2)
  		pop {r1}
  		mov r2, r0	// r2 = fib(n-2)

  		adds r0, r2, r1
  		b end
end:
		mov	sp, r7
  		add	sp, sp, #8
  		pop	{r7, pc}
