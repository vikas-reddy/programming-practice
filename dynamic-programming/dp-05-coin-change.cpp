#include<iostream>
using namespace std;

// Holds the memory 2d array for bottom-up approach
// ways[n+1][m]
int **ways;

int numWaysRecursive(int denominations[], int m, int n) {
  if (n < 0)  return 0; // no negative sums
  if (n == 0) return 1; // one way for zero sum. don't know why
  if (m <= 0 && n >= 1) return 0; // no denominations but positive n

  return numWaysRecursive(denominations, m, n - denominations[m - 1]) + // when denom[m] is included
         numWaysRecursive(denominations, m - 1, n); // when denom[m] is not included
}

int numWays(int denominations[], int m, int n) {
  for (int i = 0; i < m; i++)
    ways[0][i] = 1;

  int x, y;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 0; j < m; j++) {
      // ...includes denominations[j]
      x = (i >= denominations[j]) ? ways[i - denominations[j]][j] : 0;

      // ...not includes denominations[j]
      y = (j >= 1) ? ways[i][j - 1] : 0;

      ways[i][j] = x + y;
    }
  }
  return ways[n][m - 1];
}

int main(int argc, const char *argv[])
{
  int m = 4, n = 10;
  int denominations[] = {2, 3, 5, 6};

  /* Recursive */
  cout << "Number of ways: " << numWaysRecursive(denominations, m, n) << endl;

  /* DP bottom-up */
  ways = new int*[n + 1];
  for (int i = 0; i < n + 1; i++)
    ways[i] = new int[m];

  cout << "Number of ways: " << numWays(denominations, m, n) << endl;

  // printing the array
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", ways[i][j]);
    }
    printf("\n");
  }
  return 0;
}
