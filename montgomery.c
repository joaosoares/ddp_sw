/*
 * montgomery.c
 *
 */

#include "montgomery.h"
#include "util.h"
#include "xil_printf.h"
#include <stdint.h>
#include <stdio.h>

void sub_cond(uint32_t *u, uint32_t *n, uint32_t size);


void mont(uint32_t *a, uint32_t *b, uint32_t *n, uint32_t *n0, uint32_t *res,
          uint32_t size) {
  uint32_t t[size + 2];
  uint32_t S;
  uint32_t C;
  uint64_t sum;
  int i;
  for (i = 0; i < size + 2; i++) {
    t[i] = 0;
  }

  for (i = 0; i < size; i++) {
    S = multiply_and_sum(a[0], b[i], t[0], 0);
    C = get_carry();
    add_carry(t, 1, C);
    uint32_t m = multiply_and_sum(S, n0[0], 0, 0);
    S = multiply_and_sum(m, n[0], S, 0);
    C = get_carry();
    int j;
    if(size = 32) {
    	j = 1;
        S = multiply_and_sum(a[1], b[i], t[1], C);
        C = get_carry();
        add_carry(t, 2, C);
        S = multiply_and_sum(m, n[1], S, 0);
        C = get_carry();
        t[0] = S;
        S = multiply_and_sum(a[2], b[i], t[2], C);
        C = get_carry();
        add_carry(t, 3, C);
        S = multiply_and_sum(m, n[2], S, 0);
        C = get_carry();
        t[1] = S;
        S = multiply_and_sum(a[3], b[i], t[3], C);
        C = get_carry();
        add_carry(t, 4, C);
        S = multiply_and_sum(m, n[3], S, 0);
        C = get_carry();
        t[2] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;

    } else {
      for (j = 1; j < size; j++) {
        S = multiply_and_sum(a[j], b[i], t[j], C);
        C = get_carry();
        add_carry(t, j + 1, C);
        S = multiply_and_sum(m, n[j], S, 0);
        C = get_carry();
        t[j - 1] = S;
      }
    }
    sum = t[size] + C;
    S = (uint32_t)sum;
    C = (uint32_t)(sum >> 32);
    t[size - 1] = S;
    t[size] = t[size + 1] + C;
    t[size + 1] = 0;
  }
  sub_cond(t, n, size);
  res = t;
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
