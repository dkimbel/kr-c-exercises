#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
  printf("%d\n", bitcount(0x8f));
}

// In two's complement (and one's complement?), subtracting one from an integer will cause the
// leftmost binary 1 to be replaced by a 0, and all 0s to the right of that digit to be replaced
// by 1. The fact that the 1 and all bits to the right were 'flipped' means that, when we apply
// the & operation on the 'before' and 'after' ints, they will all evaluate to 0 (they are either
// 0 and 1 or 1 and 0).
// I'm not sure this property is exclusive to two's complement. One's complement _may_ break this
// contract with 0, since it also has a representation of -0; unclear though.
//
// Count the number of '1' bits in the given unsigned int's binary representation. This should be
// as fast as or faster than an implementation based around >>; while a >> implementation will never
// iterate fewer times than a & implementation, the latter will often need fewer iterations. For
// instance, & only needs one iteration for the binary `1000`, while >> needs four.
int bitcount(unsigned x)
{
  int b = 0;

  while (x != 0) {
    x &= x - 1;
    ++b;
  }
  return b;
}
