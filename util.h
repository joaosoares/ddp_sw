/*
 * util.h
 *
 */
#include <stdint.h>

#ifndef UTIL_H_
#define UTIL_H_

//void add_carry(uint32_t *t, uint32_t i, uint32_t c);

/* Performs the operation
 * (C, S) = A * B + D
 * Inputs:
 * A, B => 32 bit numbers to be multiplied
 * D1, D2 => 32 bit numbers added to the result of the multiplication
 *
 * Returns
 * S => The value of the sum
 */
uint32_t multiply_and_sum(uint32_t A, uint32_t B, uint32_t D1, uint32_t D2);

/* Returns the MSBs of the multiplication. Must be called
 * immediately after multiply_and_sum.
 * Inputs: none
 * Returns:
 * C => 32-bit integer
 */
uint32_t get_carry();

void add_carry(uint32_t *t, uint32_t i, uint32_t c);

#endif /* UTIL_H_ */
