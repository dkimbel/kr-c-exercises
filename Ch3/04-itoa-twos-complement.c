#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void itoa(int n, char s[]);
void reverse(char s[]);

int main(int argc, char** argv)
{
  if (argc != 2) {
    fprintf(stderr, "Expected exactly one argument\n");
    return 1;
  }

  char s[MAX_STR_LEN];
  int input = atoi(argv[1]);
  itoa(input, s);
  printf("%s\n", s);
}

// The original book definition of this function couldn't handle -2^n-1 becaues it started by
// multiplying a negative n input by -1 to make it positive. This would have resulted in positive
// 2^n-1, which is not representable under two's complement (or really any binary system?). Rather,
// the maximum positive integer that can be represented is (2^n-1) - 1.
// The reason this problem only appears on two's complement machines is, machines using other
// systems wouldn't even be able to represent -2^n-1 in the first place. Rather, their most extreme
// negative value would be (-2^n-1) + 1, symmetrical with their greatest positive value.
void itoa(int n, char s[])
{
  int i, sign, digit;

  // exercise was just to tweak code within this book-defined function; book also defined `reverse`
  sign = n;
  i = 0;
  do {
    digit = n % 10;
    // there should be more efficient options where we only deal with the "what if negative?" case
    // once -- like, after the first iteration (which could happen outside a loop), flip n to
    // positive (just wait for one iteration to handle edge case of -2^n-1)
    digit = digit < 0 ? -digit : digit;
    s[i++] = digit + '0';
  } while ((n /= 10) != 0);
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
