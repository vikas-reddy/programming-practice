#include<iostream>
#include<stdlib.h>

using namespace std;

int nearestSquare (int n, int f, int l) {
  /* printf("f: %d, l: %d\n", f, l); */
  // Base cases
  if (f > l)  return -1;
  if (f == l) return f*f;

  // The mid element
  int m = f + (l - f)/2;

  if (m*m == n)
    return m*m;

  // We're finding an (m)-(m+1) pair such that n lies between squares of m and
  // m+1
  if (m*m < n) {
    if ( (m+1)*(m+1) > n ) {
      if (n - m*m > (m+1)*(m+1) - n)
        return (m+1)*(m+1);
      else
        return m*m;
    }
    else {
      return nearestSquare(n, m+1, l);
    }
  }
  else
    return nearestSquare(n, f, m);
}

int main(int argc, const char *argv[])
{
  if (argc < 2)
    return 1;

  int n = atoi(argv[1]);

  for (int i = 0; i < 100; i++)
    printf("Nearest perfect square of %d is %d \n", i, nearestSquare(i, 1, i));

  /* printf("Nearest perfect square of %d is %d \n", n, nearestSquare(n, 1, n)); */
  return 0;
}
