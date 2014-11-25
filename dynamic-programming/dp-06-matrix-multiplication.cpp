#include<iostream>
#include<limits.h>
using namespace std;

/*
 *
 * Program to find the number of multiplication operations to be made to perform multiplication of n matrices
 *
 * Algorithm:
 *  A1, A2, A3, ... , An-1, An
 * can be [singly] split in (n - 1) ways, and recursed.
 *
 * Dynamic Programming
 *
 *
 */

int **arr;
int n; // num of matrices

int numMultiplications(int p[]) {
  // n is len
  for (int i = 1; i <= n; i++)
    arr[i][i] = 0;

  int cost, j;

  for (int l = 2; l <= n-1; l++) {
    for (int i = 1; i < n - l + 1; i++) {
      j = i + l - 1;
      arr[i][j] = INT_MAX;
      for (int k = i; k <= j - 1; k++) {
        cost = arr[i][k] + arr[k+1][j] + p[i-1]*p[k]*p[j];
        // minimizing the cost
        if (arr[i][j] > cost) {
          arr[i][j] = cost;
        }
      }
    }
  }
  return arr[1][n];
}

int numMultiplicationsRec(int p[], int f, int l) {
  if (f == l) {
    return 0;
  }
  int min = INT_MAX, count;
  for (int i = f; i < l; i++) {
    count = numMultiplicationsRec(p, f, i) +
            numMultiplicationsRec(p, i + 1, l) +
            (p[f - 1] * p[i] * p[l]);

    if (min > count) {
      min = count;
    }
  }
  return min;
}

int main(int argc, const char *argv[])
{
  int p[] = {40, 20, 30, 10, 30};
  int len = 5, f = 1, l = 4;
  // Ai is a p[i-1] x p[i] matrix

  /* Recursive; takes exponential time */
  cout << numMultiplicationsRec(p, f, l) << endl;

  /* DP + bottom-up approach */
  n = len - 1; // number of matrices
  arr = new int*[n + 1];
  for (int i = 0; i <= n; i++)
    arr[i] = new int [n + 1];

  cout << numMultiplications(p) << endl;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }

  return 0;
}
