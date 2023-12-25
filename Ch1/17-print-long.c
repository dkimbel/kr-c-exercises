#include <stdio.h>

#define MIN_PRINT_LEN 81

int get_line(char line[], int limit);

int main(void)
{
  int c, i;
  char line_start[MIN_PRINT_LEN + 1];

  i = 0;
  while ((c = getchar()) != EOF) {
    if (i <= MIN_PRINT_LEN - 1)
      line_start[i] = c;
    if (i == MIN_PRINT_LEN - 1) {
      line_start[i + 1] = '\0';
      printf("%s", line_start);
    } else if (i > MIN_PRINT_LEN - 1)
      putchar(c);

    if (c == '\n')
      i = 0;
    else
      ++i;
  }
}
