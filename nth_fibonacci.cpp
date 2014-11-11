#include <stdio.h>
#include <iostream>

using namespace std;

unsigned long long int fib(unsigned long long int n, unsigned long long int *mem, unsigned int *count) {
  // compute it only if it's not in the "memory"
  if (mem[n] == 0) {
    (*count)++;
    if (n == 0 || n == 1) {
      return 1;
    }
    unsigned long long int val = fib(n - 1, mem, count) + fib(n - 2, mem, count);
    mem[n] = val;
  }
  return mem[n];
}

int main(int argc, const char *argv[])
{
  unsigned long long int mem[101] = {}, n = 100;
  unsigned int count = 0;
  /* printf("fib(%d) = %d\n", n, fib(n, mem, &count)); */
  cout << "fib(" << n << ") = " << fib(n, mem, &count) << endl;
  printf("number of calls:%d\n", count);

  return 0;
}
