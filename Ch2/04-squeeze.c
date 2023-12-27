#include <stdio.h>

enum bool { FALSE, TRUE };
enum bool char_in_s(char, char[]);
void squeeze(char[], char[]);

int main(void)
{
  char s1[100] = "hello";
  char s2[100] = "blah";

  squeeze(s1, s2);
  printf("%s\n", s1);
  return 0;
}

enum bool char_in_s(char c, char s[])
{
  int i, curr;

  for (i = 0; (curr = s[i]) != '\0'; ++i)
    if (curr == c)
      return TRUE;
  return FALSE;
}

// delete all chars from s1 that occur in s2
void squeeze(char s1[], char s2[])
{
  int i, j, c;

  // i iterates through all of s1; j only advances if we didn't want to delete a char
  for (i = j = 0; (c = s1[i]) != '\0'; ++i)
    if (!char_in_s(c, s2))
      s1[j++] = c;
  s1[j] = '\0';
}
