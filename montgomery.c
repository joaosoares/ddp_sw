/*
 * montgomery.c
 *
 */

#include "montgomery.h"

void mont(uint32_t *a, uint32_t *b, uint32_t *n, uint32_t *n0, uint32_t *res, uint32_t SIZE)
{
  uint32_t t[SIZE];
  int i;
  for (i = 0; i < SIZE; i++)
  {
    t[i] = 0;
  }

  for (int i = 0; i < SIZE; i++) {
    uint32_t sum = t[0] + a[0] * b[i];

  }
}

/* Carry addition algorithm
 *
 */
void add_carry(uint32_t *t, uint32_t i, uint32_t c, uint32_t size)
{
  uint32_t sum = 0;
  while (c != 0)
  {
    sum = t[i] + c;
    uint32_t c = t[size];
    uint32_t S = 
    // C, S <- sum_((2w-1)...w), sum_((w-1)...0)
    t[i] = S;
    i++;
  }
}

/* Conditional subtraction algorithm
 */
void sub_cond(uint32_t *u, uint32_t *n, uint32_t *res, uint32_t size)
{
  uint32_t b = 0;
  uint32_t t[size];
  int i;
  for (i = 0; i < size; i++)
  {
    t[i] = 0;
  }

  for (i = 0; i < size; i++)
  {
    uint32_t sub = u[i] - n[i] - b;
    if (u[i] >= n[i] + b)
    {
      b = 0;
    }
    else
    {
      b = 1;
    }
    t[i] = sub;
  }
  if (b == 0)
  {
    for (i = 0; i < size; i++)
    {
      res[i] = t[i];
    }
  }
  else
  {
    for (i = 0; i < size; i++)
    {
      res[i] = u[i];
    }
  }
}
