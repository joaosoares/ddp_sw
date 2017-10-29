/*
 * util.h
 *
 */
#include <stdint.h>

#ifndef ADD_CARRY_H_
#define ADD_CARRY_H_

void add_carry(uint32_t *t, uint32_t i, uint32_t c);

/* Performs the operation
 * (C, S) = A * B + D
 * Inputs:
 * A, B => 32 bit numbers to be multiplied
 * D => 32 bit number added to the result of the multiplication
 * *C => Pointer to the variable that holds the carry
 *
 * Returns
 * S => The value of the sum
 */
uint32_t multiply_and_sum(uint32_t A, uint32_t B, uint32_t D, uint32_t *C);

#endif /* UTIL_H_ */
