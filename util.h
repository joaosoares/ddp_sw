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

/* Performs the computation inside the FIOS nested loop.
 * Inputs:
 * t, a, b, n => Multiple precision numbers (in the order of SIZE x 32 bits)
 * C => carry from outside the loop
 * i, j => index for both outer and inner loops respectively
 * m => 32-bit integer
 */
void montgomery_loop(uint32_t* a, uint32_t* b, uint32_t * t, uint32_t C, uint32_t * n, uint32_t i, uint32_t j, uint32_t m);

void add_carry(uint32_t *t, uint32_t i, uint32_t c);

#endif /* UTIL_H_ */
