#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main(void)
{
  printf("%x\n", invert(0xAA, 5, 3));
}

// invert (flip) the n bits starting at position p
unsigned invert(unsigned x, int p, int n)
{
  // We use the fact that 'xor 0' is a no-op and 'xor 1' flips a bit. So, we make a mask of all
  // 0s except with n 1s starting at position p, then xor that against the input x.
  return x ^ (~(~0 << n) << (p + 1 - n));
}
