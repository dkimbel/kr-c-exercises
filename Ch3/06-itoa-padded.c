#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1000

void itoa(int n, char s[], int min_len);
void reverse(char s[]);

int main(int argc, char** argv)
{
  if (argc != 3) {
    fprintf(stderr, "Expected exactly two arguments\n");
    return 1;
  }

  char s[MAX_STR_LEN];
  int input_n = atoi(argv[1]);
  int input_min_len = atoi(argv[2]);
  itoa(input_n, s, input_min_len);
  printf("%s\n", s);
}

void itoa(int n, char s[], int min_len)
{
  int i, sign, digit;

  sign = n;
  i = 0;
  do {
    digit = n % 10;
    digit = digit < 0 ? -digit : digit;
    s[i++] = digit + '0';
  } while ((n /= 10) != 0);
  if (sign < 0)
    s[i++] = '-';
  while (i < min_len)
    s[i++] = ' ';
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
