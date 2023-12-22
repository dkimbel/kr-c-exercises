#include <stdio.h>

// to use, pipe in chars from a short text file; e.g. `cat myfile | ./a.out`
int main(void)
{
  int c;

  while ((c = getchar()) != EOF)
    printf("%d\n", c != EOF);
  printf("%d\n", c != EOF);
}
