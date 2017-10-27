/*
 * montgomery.c
 *
 */

#include "montgomery.h"
#include <stdio.h>

void mont(uint32_t *a, uint32_t *b, uint32_t *n, uint32_t *n0, uint32_t *res,
          uint32_t size) {
  uint32_t t[size + 2];
  int i;
  for (i = 0; i < size + 2; i++) {
    t[i] = 0;
  }

  for (int i = 0; i < size; i++) {
    uint64_t sum = (uint64_t)t[0] + (uint64_t)a[0] * (uint64_t)b[i];
    uint32_t S = (uint32_t)sum;
    uint32_t C = (uint32_t)(sum >> 32);
    add_carry(t, 1, C);
    uint32_t m = (uint64_t)S * (uint64_t)n0[0];
    sum = (uint64_t)S + (uint64_t)m * (uint64_t)n[0];
    S = (uint32_t)sum;
    C = (uint32_t)(sum >> 32);

    int j;
    for (j = 1; j < size; j++) {
      sum = (uint64_t)t[j] + (uint64_t)a[j] * (uint64_t)b[i] + (uint64_t)C;
      S = (uint32_t)sum;
      C = (uint32_t)(sum >> 32);
      add_carry(t, j + 1, C);
      sum = (uint64_t)S + (uint64_t)m * (uint64_t)n[j];
      S = (uint32_t)sum;
      C = (uint32_t)(sum >> 32);
      t[j - 1] = S;
    }
    
    sum = t[size] + C;
    S = (uint32_t)sum;
    C = (uint32_t)(sum >> 32);
    t[size - 1] = S;
    t[size] = t[size + 1] + C;
    t[size + 1] = 0;
  }
  sub_cond(t, n, size);
  for (i = 0; i < size; i++) {
    res[i] = t[i];
  }
}

/* Carry addition algorithm
 *
 */
void add_carry(uint32_t *t, uint32_t i, uint32_t c) {
  while (c != 0) {
    uint64_t sum = (uint64_t) t[i] + (uint64_t) c;
    uint32_t S = (uint32_t)sum;
    c = (uint32_t)(sum >> 32);
    t[i] = S;
    i++;
  }
}

/* Conditional subtraction algorithm
 */
void sub_cond(uint32_t *u, uint32_t *n, uint32_t size) {
  uint32_t b = 0;
  uint32_t t[size];
  int i;
  for (i = 0; i < size; i++) {
    uint32_t sub = u[i] - n[i] - b;
    if (u[i] >= n[i] + b) {
      b = 0;
    } else {
      b = 1;
    }
    t[i] = sub;
  }
  if (b == 0) {
    for (i = 0; i < size; i++) {
      u[i] = t[i];
    }
  }
}
