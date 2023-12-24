#include <stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
  int c, wordState;

  wordState = OUT;
  while ((c = getchar()) != EOF) {
    if (c != ' ' && c != '\t' && c != '\n') {
      putchar(c);
      wordState = IN;
    } else if (wordState == IN) {
      // we're witnessing the end of a word
      putchar('\n');
      wordState = OUT;
    }
  }
}
