#include <stdio.h>

char lower(char);

int main(void)
{
  printf("%c\n", lower('H'));
}

char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}
