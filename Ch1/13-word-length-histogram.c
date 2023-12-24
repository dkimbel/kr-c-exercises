#include <stdio.h>

#define MAX_WORD_LEN 12

int main(void)
{
  int c, i, j, wordlen;
  int nwordlen[MAX_WORD_LEN];

  for (i = 0; i < MAX_WORD_LEN; ++i)
    nwordlen[i] = 0;

  wordlen = 0;
  while ((c = getchar()) != EOF)
    if (c == ' ' || c == '\n' || c == '\t') {
      if (wordlen > 0) {
        wordlen = wordlen > MAX_WORD_LEN ? MAX_WORD_LEN : wordlen;
        // since no words can have length 0, we use 'length - 1' as index/subscript
        ++nwordlen[wordlen - 1];
        wordlen = 0;
      }
    } else
      ++wordlen;

  printf("Word lengths\n");
  for (j = 0; j < MAX_WORD_LEN; ++j) {
    printf("%2d ", j + 1);
    while (nwordlen[j] > 0) {
      putchar('#');
      --nwordlen[j];
    }
    putchar('\n');
  }
}
