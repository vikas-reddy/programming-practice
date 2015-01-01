#include<iostream>
#include<stdlib.h>

#define MAX_SIZE 100

using namespace std;

void printParens(int n, int pos, int open, int close) {
  static char str[MAX_SIZE];

  // base case
  if (close == n) {
    printf("%s\n", str);
    return;
  }

  if (open > close) {
    str[pos] = '}';
    printParens(n, pos+1, open, close+1);
  }
  if (open < n) {
    str[pos] = '{';
    printParens(n, pos+1, open+1, close);
  }
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int n = atoi(argv[1]);

  int pos = 0, open = 0, close = 0;

  printParens(n, pos, open, close);
  return 0;
}
