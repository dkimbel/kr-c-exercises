#include <stdio.h>

/* print Fahrenheit-Celsius table
    for fahr = 0, 20, ..., 300 */
int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;      /* lower limit of celsius temperature */
  upper = 300;    /* upper limit */
  step = 20;      /* step size*/

  printf("%2sF\t%5sC\n", " ", " ");
  fahr = lower;
  while (fahr <= upper) {
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f\t%6.1f\t\n", fahr, celsius);
    fahr = fahr + step;
  }
}

