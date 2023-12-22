#include <stdio.h>

int main(void)
{
  int boolTrue, boolFalse;

  boolTrue = 'f' != EOF;
  printf("True: %d\n", boolTrue);

  boolFalse = EOF != EOF;
  printf("False: %d\n", boolFalse);

  printf("Everything is as expected: %d", boolTrue == 1 && boolFalse == 0);
}
