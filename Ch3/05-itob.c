#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void itob(int n, char s[], int base);
void reverse(char s[]);

int main(int argc, char** argv)
{
  if (argc != 3) {
    fprintf(stderr, "Expected exactly two arguments\n");
    return 1;
  }

  char s[MAX_STR_LEN];
  int input_n = atoi(argv[1]);
  int input_base = atoi(argv[2]);
  itob(input_n, s, input_base);
  printf("%s\n", s);
}

// we're just trusting that input >= 2 and <= 16-ish
void itob(int n, char s[], int base)
{
  int i, sign, digit, c;

  sign = n;
  i = 0;
  do {
    digit = n % base;
    digit = digit < 0 ? -digit : digit;
    c = (digit < 10) ? digit + '0' : digit - 10 + 'A';
    s[i++] = c;
  } while ((n /= base) != 0);
  if (sign < 0)
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

void reverse(char s[])
{
  int i, j, c;
  for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
    c = s[i], s[i] = s[j], s[j] = c;
  }
}
