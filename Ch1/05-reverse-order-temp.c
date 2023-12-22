#include <stdio.h>

int main(void)
{
  int fahr;
  float celsius;

  printf("%2sF\t%5sC\n", " ", " ");
  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3d\t%6.1f\n", fahr, celsius);
  }
}
