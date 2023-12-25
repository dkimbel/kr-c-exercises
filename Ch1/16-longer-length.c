#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy_line(char to[], char from[]);

int main(void)
{
  int len, max, runningLen;
  char line[MAXLINE];
  char longest[MAXLINE];
  // it's hard to interpret the exercise's "print as much as possible of the text"; my code will
  // potentially print the first 1000 chars in addition to the last 1000 chars of the longest line
  char currFirst[MAXLINE];
  char longestFirst[MAXLINE];

  max = 0;
  runningLen = 0;
  while ((len = get_line(line, MAXLINE)) > 0 ) {
    runningLen = runningLen + len;
    if (runningLen == len)
      copy_line(currFirst, line);
    if (runningLen > max) {
      max = runningLen;
      copy_line(longest, line);
    }
    // reset runningLen when we saw newline; len-1 is safe because loop ended if len==0
    if (line[len-1] == '\n') {
      if (runningLen == max)
        copy_line(longestFirst, currFirst);
      runningLen = 0;
    }
  }
  if (max > 0)
    printf("%d: %s", max, longestFirst);
  // We'll only ever get MAXLINE - 1 meaningful chars per line, since the last spot is reserved
  // for the null char. If we got more than two full lines, print an ellipsis to indicate that
  // we're omitting part of the real line.
  if (max > (MAXLINE - 1) * 2)
    printf("...");
  // If there's more than one line of output to print, print the last line -- whether or not we
  // had to omit anything between the first and last.
  if (max > MAXLINE - 1)
    printf("%s", longest);
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

void copy_line(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0')
    ++i;
}

