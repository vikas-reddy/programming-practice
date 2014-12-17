#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

/*
 * Program to find the number of ways of travelling from (0,0) to (m-1,n-1) in
 * an mxn matrix
 */

// Number of ways of reaching (1,1) from (m,n)
int numWaysRec (int m, int n) {
  // Base cases
  if (m < 1 || n < 1)   return 0;
  if (m == 1 || n == 1) return 1;

  return numWaysRec(m - 1, n) + numWaysRec(m, n - 1) + numWaysRec(m - 1, n - 1);
}

// DP bottom-up
int numWaysDP (int rows, int cols) {
  // Space for memoization
  int ways[rows+1][cols+1];
  memset(ways, 0, sizeof(ways));

  // When there is only one way for going (for last row and column), its
  // ways[] is 1
  for (int r = 0; r <= rows; r++)
    ways[r][1] = 1;
  for (int c = 0; c <= cols; c++)
    ways[1][c] = 1;

  for (int r = 2; r <= rows; r++)
    for (int c = 2; c <= cols; c++)
      ways[r][c] = ways[r-1][c] + ways[r][c-1] + ways[r-1][c-1];

  return ways[rows][cols];
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Needs m and n as command-line args" << endl;
    return 1;
  }

  int m = atoi(argv[1]);
  int n = atoi(argv[2]);

  /* cout << "Num of ways: " << numWays1(m, n, 0, 0) << endl; */
  cout << "Num of ways: " << numWaysRec(m, n) << endl;
  cout << "Num of ways: " << numWaysDP(m, n) << endl;
  return 0;
}
