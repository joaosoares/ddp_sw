
.text

.global add_carry
.func add_carry, add_carry
.type add_carry, %function

add_carry:
	mov r6,#4	// store 4 for later use
	mul r1, r1, r6	//i*4
	add r0,r0,r1 //move the address of t until get the position
	mov r6,#0	// store 0 for later use

	add_loop_mont:
		cmp r2, #0 //while(c!=0)
		beq end_loop_mont
		ldr r5, [r0]	//load t[i] to r5
		adds r4,r5,r2 //sum =t[i] + c; Lower 32 bits
		adc  r2,r6,r6 // write higher 32 bits to c using the carry from adds
		str r4, [r0],#4
		b  add_loop_mont
	end_loop_mont:

end_add_mont:
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
