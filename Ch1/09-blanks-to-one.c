#include <stdio.h>

int main(void)
{
  int isEliminatingBlanks, c;

  isEliminatingBlanks = 0;
  while ((c = getchar()) != EOF) {
    if (!isEliminatingBlanks || c != ' ')
      putchar(c);
    if (c == ' ')
      isEliminatingBlanks = 1;
    else
      isEliminatingBlanks = 0;
  }
}
