#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(void)
{
  printf("char: %d - %d\n", CHAR_MIN, CHAR_MAX);
  printf("short: %d - %d\n", SHRT_MIN, SHRT_MAX);
  printf("int: %d - %d\n", INT_MIN, INT_MAX);
  printf("long: %ld - %ld\n", LONG_MIN, LONG_MAX);
  printf("float: %f - %f\n", FLT_MIN, FLT_MAX);
  printf("double: %f - %f\n", DBL_MIN, DBL_MAX);
  printf("long double: %Lf - %Lf\n", LDBL_MIN, LDBL_MAX);
  return 0;
}
