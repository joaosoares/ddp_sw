/******************************************************************************
*
* Copyright (C) 2009 - 2014 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* Use of the Software is limited solely to applications:
* (a) running on a Xilinx device, or
* (b) that interact with a Xilinx device through a bus or interconnect.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* XILINX  BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
* WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF
* OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
* Except as contained in this notice, the name of the Xilinx shall not be used
* in advertising or otherwise to promote the sale, use or other dealings in
* this Software without prior written authorization from Xilinx.
*
******************************************************************************/

/*
 * helloworld.c: simple test application
 *
 * This application configures UART 16550 to baud rate 9600.
 * PS7 UART (Zynq) is not initialized by this application, since
 * bootrom/bsp configures it to baud rate 115200
 *
 * ------------------------------------------------
 * | UART TYPE   BAUD RATE                        |
 * ------------------------------------------------
 *   uartns550   9600
 *   uartlite    Configurable only in HW design
 *   ps7_uart    115200 (configured by bootrom/bsp)
 */

#include <stdio.h>
// #include "platform.h"
// #include "xil_printf.h"
#include <stdint.h>
#include <inttypes.h>
#include "montgomery.h"
#include "asm_func.h"
#include "mp_arith.h"

uint32_t a[32];
uint32_t b[32];
uint32_t N[32];
uint32_t r[32];
uint32_t N_prime0[32];

// void customprint(uint32_t *a, int size);

// int main()
// {
//     init_platform();

//     uint32_t a[32] = {0xf484e847, 0x4ae251f1, 0xedfa617d, 0x58ab6bf4, 0x46bf4848, 0xf67c1061, 0x8811c17a, 0x578fde16, 0x493ee595, 0x1eafc4c3, 0xc4f11a2e, 0x8cb6fba7, 0x724c03a4, 0x2e6c1dbd, 0x57ebc43d, 0x3e6ee260, 0x4089c050, 0xf0384e03, 0x7357f72c, 0x87acb658, 0x7ea2490e, 0x61069112, 0x42e3f8b9, 0x9e778cef, 0x5cdf77c7, 0x10bce41c, 0x1121beec, 0x3db59a36, 0xc34620c5, 0xc6b030ae, 0xe8fc5934, 0x63a0a0cb};
//     uint32_t b[32] = {0xfeb1b9f4, 0xe91d3bec, 0xfb09354d, 0x07f21d6d, 0x9ece9e1b, 0x18def18b, 0x4119e1e9, 0x55c85f24, 0x60ef0e23, 0x10e8ab54, 0x1e95cdcc, 0x4373912f, 0x6f42204d, 0x7126650d, 0xb61c1c8d, 0x98af9011, 0xa42c03b4, 0xd29e0870, 0x7923cb60, 0xdf87cfe5, 0xde4fffa0, 0x3ce537ca, 0x201040c6, 0x6e54b058, 0x814c53dc, 0xf16243f0, 0x57decf64, 0x8d0d4f37, 0x9b6d93e5, 0x45396d71, 0x615213c4, 0x65f89f9f};
//     uint32_t N[32] = {0x4aeeb107, 0x5d78aa98, 0x6c55dd05, 0x6f5326c9, 0xf93f738c, 0xc10fa093, 0x20478120, 0x099d6d70, 0x833d9b82, 0x1248f3ed, 0xa43ed737, 0xc1c1da45, 0x9f23e5c7, 0xb17c3598, 0xe8938df6, 0x7ae59036, 0x9f84d87b, 0xc8710dc6, 0x249ee0f8, 0x46eeae2f, 0x66a3bb9b, 0xfeef4c6b, 0xc7b55eae, 0x7951dd0c, 0x0b4391e8, 0x141ad586, 0x1a568588, 0x908293dd, 0x472c0bea, 0x8d00abfe, 0xed17377f, 0x83a01efe};
//     uint32_t res_mp_add[33];
//     uint32_t res_mp_sub[33];
//     uint32_t res_mod_add[33];
//     uint32_t res_mod_sub[33];
  
//     init_performance_counters(1);
//     uint32_t start_time = get_cycle_counter();
//     // Mp addition
//     mp_add(a, b, res_mp_add, 32);
//     // Mp subtraction
//     mp_sub(a, b, res_mp_sub, 32);
//     // Modular addition
//     mod_add(a, b, N, res_mod_add, 32);
//     // Modular subtraction
//     mod_sub(a, b, N, res_mod_sub, 32);

//     uint32_t stop_time = get_cycle_counter();

//     xil_printf("(a + b) = ");
//     customprint(res_mp_add, 33);

//     xil_printf("(a - b) = ");
//     customprint(res_mp_sub, 33);
    
//     xil_printf("(a + b) mod N = ");
//     customprint(res_mod_add, 33);
    
//     xil_printf("(a - b) mod N = ");
//     customprint(res_mod_sub, 33);
    
//     xil_printf("Cycles: %d\r\n\r\n", stop_time - start_time);
//     cleanup_platform();
//     return 0;
// }

// void customprint(uint32_t *a, int size)
// {
//   int i;
//   for (i = 0; i < size; i++)
//   {
//     xil_printf("%08x", a[size - i - 1]);
//   }
//   xil_printf("\n\r");
// }



void customprint(uint32_t *a, int size);

int main()
{
    // init_platform();

    uint32_t a[32] = {0xf484e847, 0x4ae251f1, 0xedfa617d, 0x58ab6bf4, 0x46bf4848, 0xf67c1061, 0x8811c17a, 0x578fde16, 0x493ee595, 0x1eafc4c3, 0xc4f11a2e, 0x8cb6fba7, 0x724c03a4, 0x2e6c1dbd, 0x57ebc43d, 0x3e6ee260, 0x4089c050, 0xf0384e03, 0x7357f72c, 0x87acb658, 0x7ea2490e, 0x61069112, 0x42e3f8b9, 0x9e778cef, 0x5cdf77c7, 0x10bce41c, 0x1121beec, 0x3db59a36, 0xc34620c5, 0xc6b030ae, 0xe8fc5934, 0x63a0a0cb};
    uint32_t b[32] = {0xfeb1b9f4, 0xe91d3bec, 0xfb09354d, 0x07f21d6d, 0x9ece9e1b, 0x18def18b, 0x4119e1e9, 0x55c85f24, 0x60ef0e23, 0x10e8ab54, 0x1e95cdcc, 0x4373912f, 0x6f42204d, 0x7126650d, 0xb61c1c8d, 0x98af9011, 0xa42c03b4, 0xd29e0870, 0x7923cb60, 0xdf87cfe5, 0xde4fffa0, 0x3ce537ca, 0x201040c6, 0x6e54b058, 0x814c53dc, 0xf16243f0, 0x57decf64, 0x8d0d4f37, 0x9b6d93e5, 0x45396d71, 0x615213c4, 0x65f89f9f};
    uint32_t N[32] = {0x4aeeb107, 0x5d78aa98, 0x6c55dd05, 0x6f5326c9, 0xf93f738c, 0xc10fa093, 0x20478120, 0x099d6d70, 0x833d9b82, 0x1248f3ed, 0xa43ed737, 0xc1c1da45, 0x9f23e5c7, 0xb17c3598, 0xe8938df6, 0x7ae59036, 0x9f84d87b, 0xc8710dc6, 0x249ee0f8, 0x46eeae2f, 0x66a3bb9b, 0xfeef4c6b, 0xc7b55eae, 0x7951dd0c, 0x0b4391e8, 0x141ad586, 0x1a568588, 0x908293dd, 0x472c0bea, 0x8d00abfe, 0xed17377f, 0x83a01efe};
    uint32_t res_mp_add[33];
    uint32_t res_mp_sub[33];
    uint32_t res_mod_add[33];
    uint32_t res_mod_sub[33];
  
    // init_performance_counters(1);
    // uint32_t start_time = get_cycle_counter();
    // Mp addition
    mp_add(a, b, res_mp_add, 32);
    // Mp subtraction
    mp_sub(a, b, res_mp_sub, 32);
    // Modular addition
    mod_add(a, b, N, res_mod_add, 32);
    // Modular subtraction
    mod_sub(a, b, N, res_mod_sub, 32);

    // uint32_t stop_time = get_cycle_counter();

    printf("(a + b) = ");
    customprint(res_mp_add, 33);

    printf("(a - b) = ");
    customprint(res_mp_sub, 33);
    
    printf("(a + b) mod N = ");
    customprint(res_mod_add, 33);
    
    printf("(a - b) mod N = ");
    customprint(res_mod_sub, 33);
    
    // printf("Cycles: %d\r\n\r\n", stop_time - start_time);
    // cleanup_platform();
    return 0;
}

void customprint(uint32_t *a, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    printf("%08x", a[size - i - 1]);
  }
  printf("\n\r");
}