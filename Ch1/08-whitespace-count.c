#include <stdio.h>

int main(void)
{
  int c, wc;

  wc = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\t' || c == '\n')
      ++wc;

  printf("%d\n", wc);
}
