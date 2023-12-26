#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);

int main(void)
{
  int len;
  char line[MAXLINE];

  while ((len = get_line(line, MAXLINE)) > 0 )
    printf("%d\n", len);
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  // the exercise was just to rewrite this particular loop
  // for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
  //   s[i] = c;
  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) != EOF) {
      if (c != '\n')
        s[i] = c;
      else
        break;
    } else {
      break;
    }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

