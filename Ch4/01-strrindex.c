#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";

int main(void)
{
  int index;
  char line[MAXLINE];
  int found = 0;

  while (get_line(line, MAXLINE) > 0)
    if ((index = strrindex(line, pattern)) >= 0) {
      printf("%d: %s", index, line);
      found++;
    }
  // not sure why the book wants us to return `found` -- that means if we DID successfully
  // find a match, we effectively exit with an error code
  return found;
}

/* getline: get line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strrindex: return index of rightmost occurrence of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  int i, j, k, rightmost = -1;

  // I could iterate backwards from the end, but finding the end of the string requires a full
  // scan; in the name of efficiency, I'll work from the left. This still requires a full scan,
  // but only the single scan, not up to two.
  // If we were also taking the len of s as an input, _then_ we'd do best to work backwards from
  // the right.
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      rightmost = i;
  }
  return rightmost;
}
