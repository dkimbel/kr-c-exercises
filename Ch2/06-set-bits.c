#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main(void)
{
  printf("%x\n", setbits(0x1f44, 8, 1, 0x0));
}

// Return x with the n bits starting at position p replaced by the rightmost n bits of y
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned xmask, ymask;

  // create a mask of all 1s with "n bits starting at p" of 0s to zero-out the key part of x
  xmask = ~(~(~0 << n) << (p + 1 - n));
  // create a mask of all leading 0s plus the rightmost n bits of y, shifted over to match up with
  // 'n bits starting at position p' (ending with trailing 0s)
  ymask = (~(~0 << n) & y) << (p + 1 - n);
  return (x & xmask) | ymask;
}
