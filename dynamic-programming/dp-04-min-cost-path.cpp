#include<iostream>
#include<string.h>
using namespace std;

/*
 *
 * Program to compute Min Cost Path
 *
 * (0,0) to (2,2) in the costs matrix takes 8
 *
 * Method: Dynamic Programming in bottom-up fashion, and pure recursive
 *
 *
 */

// the costs array
const int m = 3, n = 3;
const int costs[3][3] = {
  {1, 2, 3},
  {4, 8, 2},
  {1, 5, 3}
};

// the bottom-up array
int **minCosts;

// computes minimum of three numbers
int min(int a, int b, int c) {
  int min_ab = (a < b) ? a : b;
  return (min_ab < c) ? min_ab : c;
}

// print the minCosts array
void printMinCostsArray(int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", minCosts[i][j]);
    }
    printf("\n");
  }
}

int minCostPathRecursive(int a, int b) {
  if (a == 0 && b == 0) return costs[a][b];
  if (a == 0) return minCostPathRecursive(a, b - 1) + costs[a][b];
  if (b == 0) return minCostPathRecursive(a - 1, b) + costs[a][b];

  return min(
        minCostPathRecursive(a - 1, b - 1),
        minCostPathRecursive(a, b - 1),
        minCostPathRecursive(a - 1, b)
      ) + costs[a][b];
}

int minCostPath(int a, int b) {
  minCosts[0][0] = costs[0][0];

  for (int i = 1; i < m; i++) {
    minCosts[i][0] = minCosts[i - 1][0] + costs[i][0];
  }
  for (int i = 1; i < n; i++) {
    minCosts[0][i] = minCosts[0][i - 1] + costs[0][i];
  }

  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      minCosts[i][j] = min(
                         minCosts[i - 1][j - 1],
                         minCosts[i - 1][j],
                         minCosts[i][j - 1]
                       ) + costs[i][j];
    }
  }
  return minCosts[a][b];
}

int main(int argc, char *argv[])
{
  /* Recursive */
  /* cout << "Min cost path: " << minCostPathRecursive(2, 2) << endl; */
  /* return 0; */

  /* Dynamic Programming */
  // initializing the array
  minCosts = new int*[m];
  for (int i = 0; i < m; i++) {
    minCosts[i] = new int[n];
  }

  cout << "Min cost path: " << minCostPath(2, 2) << endl;

  printMinCostsArray(m, n);
  return 0;
}
