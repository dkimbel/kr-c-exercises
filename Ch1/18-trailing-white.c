#include <stdio.h>

#define MAX_TRIMMABLE_WHITESPACE 1000
#define TRUE 1
#define FALSE 0

int print_and_reset_whitespace(char contigWhitespace[], int numContigWhitespace);
int reset_whitespace(char contigWhitespace[]);

int main(void)
{
  int c, isEmptyLine, numContigWhitespace;
  char contigWhitespace[MAX_TRIMMABLE_WHITESPACE + 1];

  isEmptyLine = TRUE;
  numContigWhitespace = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      if (!isEmptyLine) {
        isEmptyLine = TRUE;
        numContigWhitespace = reset_whitespace(contigWhitespace);
        putchar(c);
      }
      // if empty line, no-op
    } else if (c == ' ' || c == '\t') {
      isEmptyLine = FALSE;
      if (numContigWhitespace == MAX_TRIMMABLE_WHITESPACE)
        numContigWhitespace = print_and_reset_whitespace(contigWhitespace, numContigWhitespace);
      contigWhitespace[numContigWhitespace] = c;
      ++numContigWhitespace;
    } else {
      isEmptyLine = FALSE;
      numContigWhitespace = print_and_reset_whitespace(contigWhitespace, numContigWhitespace);
      putchar(c);
    }
  }
  return 0;
}

int reset_whitespace(char contigWhitespace[])
{
  contigWhitespace[0] = '\0';
  return 0;
}

int print_and_reset_whitespace(char contigWhitespace[], int numContigWhitespace)
{
  contigWhitespace[numContigWhitespace] = '\0';
  printf("%s", contigWhitespace);
  return reset_whitespace(contigWhitespace);
}
