.text

.global multiply_and_sum
.func multiply_and_sum, multiply_and_sum
.type multiply_and_sum, %function

multiply_and_sum:
	@ Input arguments: r0 -> A, r1 -> B, r2 -> D1, r3 -> D2
	@ Push registers to stack
	push {r4-r9}
	@ Multiply, save S in r4 and C in r5 
	umull r4, r5, r0, r1
	@ Add D1 to S with carry
	add r4, r4, r2
	@ Add carry bit to C
	adc r5, r5, #0
	@ Add D2 to S with carry
	add r4, r4, r3
	@ Add carry bit to C
	adc r5, r5, #0
	@ Define return value
	mov r0, r4
	mov r1, r5
	@ Restore registers and branch back
	pop {r4-r9}
	bx lr
.endfunc

.text

.global get_carry
.func get_carry, get_carry
.type get_carry, %function

get_carry:
	@ Returns r1
	mov r0, r1
	bx lr
.endfunc



@USEFUL FUNCTIONS

@ add Rx, Ry, Rz	//Rx = Ry + Rz  second operand can be constant
@ sub Rx, Ry, Rz	//Rx = Ry - Rz second operand can be constant
@ addc Rx, Ry, Rz	//Rx = Ry + Rz + CARRY   one operand can be constant
@ cmp Rx, Ry		//compares Rx and Ry and if they are equal sets Z flag, otherwise resets Z flag (works by subtracting two values and checks if result is zero)
@ b{cond} <label>		//Jumps to given label in the code if given condition is satisfied
@ umull Rn, Rm, Rx, Ry 	//{Rm, Rn} = Rx * Ry Multiplies unsigned 32bit values in Rx and Ry. Stores the higher 32 bits in Rm, and lower in Rn
@ ldr Rx, [Ry]		//Loads from memory pointed by Ry to register Rx, see addressing modes for post increment, pre decrement
@ str Rx, [Ry]		//Stores to memory pointed by Ry value in register Rx, see addressing modes for post increment, pre decrement
@ pop {}			//Pops values from stack to specified registers in order they are specified
@ push {}			//Push registers to stack in orded they are specified
@ ldmia rx, {set of registers} //Loads to specified set of registers memory values, starting from rx. Increasing addresses
@ stmia rx, {set of registers} //Stores specified set of registers in memory, starting from address pointed by rx. Increasing addresses
