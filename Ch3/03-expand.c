#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 1000

void expand(char s1[], char s2[]);
void push_range_inclusive(char s[], int i, int end_i, char start, int direction_positive);

int main(int argc, char** argv)
{
  if (argc != 2) {
    fprintf(stderr, "Expected exactly one argument\n");
    return 1;
  }

  // initialize our s2 string
  char s2[MAX_STR_LEN + 1];
  int i;
  for (i = 0; i < MAX_STR_LEN; ++i)
    s2[i] = 'a';
  s2[i] = '\0';

  expand(argv[1], s2);
  printf("%s\n", s2);
  return 0;
}

void expand(char s1[], char s2[])
{
  int i, j, c, d, e, end_j, direction_positive, last_i_expanded = -1;
  int max_j = strlen(s2) - 1;
  s2[0] = '\0'; // treat s2 as empty for edge cases
  for (i = j = 0; j <= max_j && (c = s1[i]) != '\0'; i++)
    if ((d = s1[i + 1]) == '-' && (e = s1[i + 2]) != '\0') { 
      // handle special case of e.g. a-c-e; make sure that if we already expanded 'c' as part
      // of a-c, we won't expand it again during c-e
      if (last_i_expanded == i)
        j--;
      if (e >= c) {
        // range is forwards (e.g. a-z)
        end_j = (e - c) + j;
        direction_positive = 1;
      } else {
        // range is backwards (e.g. z-a)
        end_j = (c - e) + j;
        direction_positive = 0;
      }
      // stop short at max_j if we're running out of room in our output string
      end_j = (max_j < end_j) ? max_j : end_j;
      push_range_inclusive(s2, j, end_j, c, direction_positive);
      j = end_j + 1;
      ++i;
      last_i_expanded = i + 1;
    } else if (last_i_expanded != i)
      // interpret a char that isn't part of a range -- even a hyphen -- as a literal char;
      // however, avoid printing a char that was already seen as the end of a range
      s2[j++] = c;
  s2[j] = '\0';
}

void push_range_inclusive(char s[], int i, int end_i, char start, int direction_positive)
{
  int j, end_j;
  for (j = 0, end_j = end_i - i; j <= end_j; ++i, ++j) {
    s[i] = direction_positive ? start + j : start - j;
  }
  s[i] = '\0';
}
