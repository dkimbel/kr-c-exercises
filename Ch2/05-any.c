#include <stdio.h>

enum bool { FALSE, TRUE };
enum bool c_in_s(char, char[]);
int any(char[], char[]);

int main(void)
{
  char s1[100] = "hello";
  char s2[100] = "blah";

  printf("%d\n", any(s1, s2));
}

enum bool c_in_s(char c, char s[])
{
  int i, curr;

  for (i = 0; (curr = s[i]) != '\0'; ++i)
    if (c == curr)
      return TRUE;
  return FALSE;
}

// return position of first char in s1 that occurs in s2, or -1 if no match
int any(char s1[], char s2[])
{
  int i, c;

  for (i = 0; (c = s1[i]) != '\0'; ++i)
    if (c_in_s(c, s2))
      return i;
  return -1;
}

