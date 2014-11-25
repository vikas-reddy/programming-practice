#include<iostream>
using namespace std;

int numWays(int n, int m, int sum, int *callCount) {
  if (n <= 0 || sum <= 0) {
    return 0;
  }
  (*callCount)++;
  if (n == 1) {
    if (sum > m) return 0;
    else         return 1;
  }
  int currSum = 0;
  for (int i = 1; i<= m; i++) {
    currSum += numWays(n - 1, m, sum - i, callCount);
  }
  return currSum;
}

int numWaysDP(int n, int m, int sum) {
  int ways[n+1][sum+1];

  // initializing the array
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= sum; j++)
      ways[i][j] = 0;

  // base case: with just one die, we can have just one way
  for (int s = 1; s <= sum; s++) {
    if (s <= m) {
      ways[1][s] = 1;
    }
    else {
      ways[1][s] = 0;
    }
  }

  for (int i = 2; i <= n; i++) {
    for (int s = 1; s <= sum; s++) {
      int currSum = 0;
      for (int j = 1; j <= m; j++) {
        /* printf("i-1:%d s-j:%d\n", i - 1, s - j); */
        currSum += ways[i-1][s - j];
      }
      ways[i][s] = currSum;
    }
  }

  // printing the array
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      printf("%d ", ways[i][j]);
    }
    printf("\n");
  }
  return ways[n][sum];
}

int main(int argc, const char *argv[])
{
  // n dice, m faces each... X sum
  int n = 3, m = 6, X = 13;

  int callCount = 0;
  cout << numWays(n, m, X, &callCount) << endl;
  /* cout << numWays(2, 4, 1, &callCount) << endl; */
  /* cout << numWays(2, 2, 3, &callCount) << endl; */
  /* cout << numWays(3, 6, 8, &callCount) << endl; */
  /* cout << numWays(2, 4, 5, &callCount) << endl; */
  /* cout << numWays(3, 4, 5, &callCount) << endl; */
  cout << "Number of calls: " << callCount << endl;

  /* DP: bottom-up */
  cout << numWaysDP(n, m, X) << endl;
  /* cout << numWaysDP(2, 4, 1) << endl; */
  /* cout << numWaysDP(2, 2, 3) << endl; */
  /* cout << numWaysDP(3, 6, 8) << endl; */
  /* cout << numWaysDP(2, 4, 5) << endl; */
  /* cout << numWaysDP(3, 4, 5) << endl; */
  return 0;
}
