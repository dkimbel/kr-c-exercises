#include <stdio.h>

#define MAX_STR_LEN 1000

void reverse(char original[], char reversed[], int len);
int get_line(char line[], int max);

int main(void)
{
  int len;
  char line[MAX_STR_LEN + 1];
  char reversed[MAX_STR_LEN + 1];
  // TODO do some form of logic based on MAX_STR_LEN
  // TODO teach `reverse` how to handle a newline
  while ((len = get_line(line, MAX_STR_LEN)) > 0) {
    if (line[len-1] != '\n') {
      // not really sure how to handle a too-long line; exit with error code
      return 1;
    }
    // subtract 1 from len so reverse fn doesn't see newline
    reverse(line, reversed, len - 1);
    printf("%s\n", reversed);
  }
  return 0;
}

void reverse(char original[], char reversed[], int len)
{
  int i;

  for (i = 0; i < len; ++i)
    reversed[len - 1 - i] = original[i];
  reversed[len] = '\0';
}

int get_line(char s[], int lim)
{
  int c, i;

  // checking 'i < lim' instead of 'i < lim - 1', because I've made the arrays hold 'max_len + 1'
  for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
