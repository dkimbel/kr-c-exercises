#include <stdlib.h>

int binsearch_one_inner_test(int x, int v[], int n);

int main(int argc, char **argv)
{
  (void) argc;
  int num_ints = atoi(argv[1]);
  int sorted[num_ints];

  for (int i = 0; i < num_ints; ++i)
    sorted[i] = i;

  for (int j = 0; j < num_ints; ++j)
    binsearch_one_inner_test(j, sorted, num_ints);
}

// Note: this solution seems to execute more slowly than the book's original code, not more quickly.
// I had a hard time with this problem, and ultimately found the solution here:
// https://codereview.stackexchange.com/a/6156
// I was originally moving a test from the inner loop to the 'while' test; I knew that shouldn't
// really be a speedup, but didn't see a way to avoid the new 'while' test. The answer was, 'stop
// letting the while loop continue when low == high'. When the loop ends because low == high, that
// means I can safely use `low` (or honestly `high`) to check and see if v[low] == x.
//
// Part of the reason this might actually be slower is: it doesn't let us short-circuit. Like,
// if we found x really early on, we still have to keep iterating until our 'high' and 'low' values
// converge. So, the best case and worst case situations are now the same.
//
// My own solution -- where I stored last_value in an int var, and made `&& x != last_val` part of
// the while loop's condition -- might have been the fastest code of all. I do think I was missing
// the point of the exercise, though; any speedup from my code was basically a fluke.
int binsearch_one_inner_test(int x, int v[], int n)
{
  int mid;

  int low = 0;
  int high = n - 1;
  while (low < high) {
    mid = (low + high) / 2;
    if (v[mid] < x)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return (v[low] == x) ? low : -1;
}
