#include <stdio.h>

#define MAX_LINE_LEN 1000
#define MIN_PRINT_LEN 80

int get_line(char line[], int limit);

int main(void)
{
  int len, runningLen;
  char line[MAX_LINE_LEN];

  while ((len = get_line(line, MAX_LINE_LEN)) > 0) {
    runningLen = runningLen + len;
    if (runningLen > 80)
      printf("%s", line);
    if (line[len-1] == '\n')
      runningLen = 0;
  }
}

int get_line(char line[], int limit)
{
  int i, c;

  for (i = 0; i < (limit - 1) && ((c = getchar()) != EOF) && c != '\n'; ++i)
    line[i] = c;
  if (c == '\n') {
    line[i] = c;
    ++i;
  }
  line[i] = '\0';
  return i;
}
