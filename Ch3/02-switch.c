#include <stdio.h>

void escape(char s[], const char t[]);
void unescape(char s[], const char t[]);

int main(int argc, char** argv)
{
  if (argc != 2) {
    fprintf(stderr, "Expected one argument\n");
    return 1;
  }
  printf("Input: %s\n", argv[1]);

  int i;
  for (i = 0; argv[1][i] != '\0'; ++i)
    ;
  int input_len = i + 1;
  int max_output_len = 2 * input_len;

  // declare our output string to have twice the length length of input, in case we have to
  // escape every single input char
  char s[max_output_len];
  escape(s, argv[1]);
  printf("Escaped: %s\n", s);

  // declare another output string for unescaped version of what we just escaped
  char s2[input_len];
  unescape(s2, s);
  printf("Unescaped: %s\n", s2);
  return 0;
}

void escape(char s[], const char t[])
{
  int c;
  int j = 0;
  for (int i = 0; (c = t[i]) != '\0'; ++i)
    switch (c) {
      case '\n':
        s[j++] = '\\';
        s[j++] = 'n';
        break;
      case '\t':
        s[j++] = '\\';
        s[j++] = 't';
        break;
      case '\\':
        s[j++] = '\\';
        s[j++] = '\\';
        break;
      default:
        s[j++] = c;
        break;
    }
  s[j] = '\0';
}

void unescape(char s[], const char t[])
{
  int c, d;
  int j = 0;
  for (int i = 0; (c = t[i]) != '\0'; ++i)
    if (c == '\\' && (d = t[i + 1]) != '\0') {
      switch (d) {
        case 'n':
          s[j++] = '\n';
          ++i;
          break;
        case 't':
          s[j++] = '\t';
          ++i;
          break;
        case '\\':
          s[j++] = '\\';
          ++i;
          break;
        default:
          s[j++] = c;
          break;
      }
    } else
      s[j++] = c;
  s[j] = '\0';
}
