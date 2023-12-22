#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main(void)
{
  int fahr;
  float celsius;

  printf("%2sF\t%5sC\n", " ", " ");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3d\t%6.1f\n", fahr, celsius);
  }
}
