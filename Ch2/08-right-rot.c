#include <stdio.h>
#include <limits.h>
#include <math.h>

unsigned rightrot(unsigned x, int n);

int main(void)
{
  printf("%x\n", rightrot(0xFF, (32 * 1000000) + 1));
}

// rotate bits to the right by n
unsigned rightrot(unsigned x, int n)
{
  // Before starting, we can transform n to n % (len x) so we never have to repeat work for large
  // values of n; I'm not sure if this math ultimately makes the code faster or not, though.
  int num_bits_in_uint = round(log2(UINT_MAX));
  n = n % num_bits_in_uint;
  // We could add special code to no-op if n == 0, but it doesn't seem very important.

  // 'Rotate right' can break down to:
  //   - capture the rightmost (least significant) n bits
  //   - shift all bits right by n, resulting in n 0s on the left
  //   - overwrite the n new left-inserted 0s with the original rightmost n bits
  // We start by creating a mask that achieves the first bullet point and, when applied, also
  // achieves the third. The mask is all zeros, except for the relevant bits from x, which have
  // been moved to the far left.
  unsigned mask = (~(~0 << n) & x) << (num_bits_in_uint - n);
  return (x >> n) | mask;
}
