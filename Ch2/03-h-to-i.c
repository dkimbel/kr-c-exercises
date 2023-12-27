#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

int htoi(const char s[]);
int get_line(char s[], int lim);

int main(void)
{
  char s[MAXLINE];

  while (get_line(s, MAXLINE) > 0)
    printf("%d\n", htoi(s));
  return 0;
}

int htoi(const char s[])
{
  int i, c, lower, n, next;

  n = 0;
  for (i = 0; (c = s[i]) != '\0'; ++i) {
    if ((i == 0 && c == '0') || (i == 1 && (c == 'x' || c == 'X')))
      continue;
    else if (c >= '0' && c <= '9')
      next = c - '0';
    else if ((lower = tolower(c)) >= 'a' && lower <= 'f')
      next = (lower - 'a') + 10;
    else
      fprintf(stderr, "Illegal character %c\n", c);

    n = n * 16 + next;
  }
  return n;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  // note: modified to NOT include newline
  s[i] = '\0';
  return i;
}
