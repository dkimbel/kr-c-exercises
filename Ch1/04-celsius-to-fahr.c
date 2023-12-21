#include <stdio.h>

int main(void)
{
  float fahr, celsius;
  int upper, lower, step;

  lower = -20;
  upper = 140;
  step = 10;

  celsius = lower;
  printf("%2sC\t%3sF\n", " ", " ");
  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32;
    printf("%3.0f\t%3.0f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
