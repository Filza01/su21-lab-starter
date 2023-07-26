// Copyright [2023] <Filza Shahid>

#include <stdio.h>

#define CSR_VAL 0x8000abcd00001234UL

#define ADDRESS 0x5300f000U

unsigned long int my_csr = CSR_VAL;
unsigned long int addr = ADDRESS;

int main(void) {
  unsigned long int bits;
  // (a) here:
  my_csr = my_csr | 1;

  // (b) here:
  my_csr = my_csr & ~(1 << 2);

  // (c) here:
  my_csr = my_csr & ~(0xff << 8);
  my_csr = my_csr | (0xee << 8);

  // (d) here:
  bits = addr >> 12;
  bits = bits & ((1 << (27-12))-1);
  my_csr = my_csr & ~(0xff << 16);
  my_csr = my_csr | (bits << 16);

  printf("%lx \n", my_csr);
  return 0;
}
