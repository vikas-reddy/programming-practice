#include<iostream>
#include<stdlib.h>
#include<limits.h>

using namespace std;

// calculate a^n
// log(n)
unsigned long long pow(int a, int n) {
  if (n == 0) return 1;

  unsigned long long p = pow(a, n/2);
  // odd number
  if (n % 2)
    return a*p*p;
  else
    return p*p;
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Usage: ./a.out a n" << endl;
    return 1;
  }

  unsigned int a = atoi(argv[1]);
  unsigned int n = atoi(argv[2]);

  cout << pow(a, n) << endl;
  return 0;
}
