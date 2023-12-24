#include <stdio.h>

// We ignore 'extended' ASCII char codes (128+) and 'control' codes (0-31).
#define MAX_CHAR_CODE 127
#define MIN_CHAR_CODE 32
#define NUM_CHAR_CODES MAX_CHAR_CODE - MIN_CHAR_CODE + 1

int main(void)
{
  int c, i, j;
  int nchar[NUM_CHAR_CODES];

  for (i = 0; i < NUM_CHAR_CODES; ++i)
    nchar[i] = 0;

  while ((c = getchar()) != EOF)
    if (c >= MIN_CHAR_CODE && c <= MAX_CHAR_CODE)
      ++nchar[c - MIN_CHAR_CODE];

  printf("Occurrences by char\n");
  for (j = 0; j < NUM_CHAR_CODES; ++j) {
    putchar(j + MIN_CHAR_CODE);
    putchar(' ');
    while (nchar[j] > 0) {
      putchar('|');
      --nchar[j];
    }
    putchar('\n');
  }
}
