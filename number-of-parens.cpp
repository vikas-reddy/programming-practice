#include<iostream>
#include<stdlib.h>

using namespace std;

/*
 * Given a number N, find the number of correct combination of parentheses possible.
 *
 *   Input: N=2 => ()()
 *     Output: 2 [(()),()()]
 *
 *   Input: N=3 => ()()()
 *     Output: 5 [()()(),((())),(())(),(()()),()(())]
 */
void numParens (int n, int open, int closed, int *count) {
  if (closed == n) {
    (*count)++;
    return;
  }

  if (open < n) {
    numParens (n, open+1, closed, count);
  }
  if (open > closed) {
    numParens (n, open, closed+1, count);
  }
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int n = atoi(argv[1]);

  int count = 0;
  numParens(n, 0, 0, &count);
  
  cout << count << endl;

  return 0;
}
