#include<iostream>
#include<limits.h>
using namespace std;

/*
 *
 * Problem: coeff(n, k) -- coefficient of x^k in the expansion of (1 + x)^n
 *
 * Constructing Pascal's triangle
 * ........1 
 * ......./..\ 
 * ......1...1 .
 * ...../..\./..\ 
 * ....1...2...1 ...
 * .../..\../..\./..\ 
 * ..1...3...3....1 ...
 * ./..\./..\../..\./..\ 
 * 1...4...6....4...1.....
 *
 */

int n;
int **arr;

int coefficient(int k) {
  if (k < 0 || k > n) {
    return -1;
  }

  // coefficients of 1 or x^0 are always 1
  for (int i = 0; i <= n; i++) {
    arr[i][0] = 1;
  }

  // coefficients of x^n are always 1
  for (int i = 1; i <= n; i++) {
    arr[i][i] = 1;
  }

  // the remaining ones
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
  }
  
  return arr[n][k];
}

int coefficientRecursive(int n, int k) {
  if (k == 0 || k == n) {
    return 1;
  }

  return coefficientRecursive(n - 1, k - 1) + coefficientRecursive(n - 1, k);
}

int main(int argc, const char *argv[])
{
  int k;

  // input from stdin
  cin >> n >> k;

  /* Recursive */
  printf("Coefficient of x^%d = %d\n", k, coefficientRecursive(n, k));

  /* DP: bottom-up */
  arr = new int*[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = new int[n + 1];
  }

  printf("Coefficient of x^%d in (1+x)^%d is %d\n", k, n, coefficient(k));
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
  return 0;
}
