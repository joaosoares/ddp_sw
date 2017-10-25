/*
 * mp_arith.c
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <math.h>

 
// Calculates res = a + b.
// a and b represent large integers stored in uint32_t arrays
// a and b are arrays of size elements, res has size+1 elements
void mp_add(uint32_t *a, uint32_t *b, uint32_t *res, uint32_t size)
{
  uint32_t c = 0;
  uint32_t i = 0;
  uint64_t single_result;
  for (i = 0; i < size; i++)
  {
    single_result = (uint64_t) a[i] + b[i] + c;
    res[i] = (uint32_t) single_result;
    c = (uint32_t) (single_result >> 32);
  }
  res[size] = c;
}

// Calculates res = a - b.
// a and b represent large integers stored in uint32_t arrays
// a, b and res are arrays of size elements
void mp_sub(uint32_t *a, uint32_t *b, uint32_t *res, uint32_t size)
{
  uint32_t c = 0;
  uint32_t i;
  uint64_t single_result;
  for (i = 0; i < size; i++)
  {
    single_result = (uint64_t) a[i] - b[i] + c;
    res[i] = (uint32_t) single_result;
    if ( (b[i] + c) > a[i]) {
      c = -1;
    } else {
      c = 0;
    }
  }
}

// Multiple precision greater than or equal
// Returns true if a is greater than or equal to b.
int mp_gte(uint32_t *a, uint32_t *b, uint32_t size_a, uint32_t size_b)
{
  if (size_a > size_b && a[size_a] != 0)
  {
    return 1;
  }
  else
  {
    int i;
    for (i = size_b - 1; i > -1; i--)
    {
      if (a[i] != b[i])
      {
        return a[i] >= b[i];
      }
    }
    return a[0] >= b[0];
  }
}

// Calculates res = (a + b) mod N.
// a and b represent operands, N is the modulus. They are large integers stored in uint32_t arrays of size elements
void mod_add(uint32_t *a, uint32_t *b, uint32_t *N, uint32_t *res, uint32_t size)
{
  uint32_t c = 0;
  uint32_t i;
  uint64_t single_result;
  for (i = 0; i < size; i++)
  {
    single_result = (uint64_t) a[i] + b[i] + c;
    res[i] = (uint32_t) single_result;
    c = (uint32_t) (single_result >> 32);
  }
  if (mp_gte(res, N, size+1, size)) {
    uint32_t paddedN[size+1];
    for(i = 0; i < size; i++) paddedN[i] = N[i];
    paddedN[size] = 0;
    mp_sub(res, paddedN, res, size+1);
  }
}

// Calculates res = (a - b) mod N.
// a and b represent operands, N is the modulus. They are large integers stored in uint32_t arrays of size elements
void mod_sub(uint32_t *a, uint32_t *b, uint32_t *N, uint32_t *res, uint32_t size)
{
  int c = 0;
  int i;
  // If a >= b, regular subtraction
  if (mp_gte(a, b, 32, 32)) {
    for (i = 0; i < size; i++)
    {
      res[i] = a[i] - b[i] + c;
      if ((long) a[i] - b[i] + c >= 0) {
        c = 0;
      } else {
        c = -1;
      }
    }
  } else { // If b > a, apply modulo
    for (i = 0; i < size; i++) {
      res[i] = N[i] - (b[i] - a[i]) + c;
      if ((long) N[i] - (b[i] - a[i]) + c >= 0) {
        c = 0;
      } else {
        c = -1;
      }
    }
  }
}