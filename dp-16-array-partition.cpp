#include<iostream>
using namespace std;

/*
 *
 * Can the given array be partitioned into two such that sum of elements in
 * both the parts is the same?
 *
 * false if sum of elements is false
 *
 */

bool subsetExists(const int arr[], const int n, int sum) {
  if (n < 0) {
    return false;
  }
  if (sum == 0) {
    return true;
  }
  if (arr[n-1] > sum) {
    return subsetExists(arr, n - 1, sum);
  }
  return subsetExists(arr, n - 1, sum - arr[n-1]) || // arr[n-1] is part of the subset
         subsetExists(arr, n - 1, sum);
}

bool subsetExistsDP(const int arr[], const int n, int sum) {
  bool hasSubset[sum+1][n+1];

  // true if sum == 0
  for (int i = 0; i <= n; i++) {
    hasSubset[0][i] = true;
  }

  // false if we have exhausted all the elements, and left with non-zero sum
  for (int i = 1; i <= sum; i++) {
    hasSubset[i][0] = false;
  }

  for (int s = 1; s <= sum; s++) {
    for (int i = 1; i <= n; i++) {
      if (arr[i-1] <= s) {
        hasSubset[s][i] = hasSubset[s][i] || hasSubset[s - arr[i-1]][i-1];
      }
      else {
        hasSubset[s][i] = hasSubset[s][i-1];
      }
    }
  }

  for (int s = 0; s <= sum; s++) {
    for (int i = 0; i <= n; i++) {
      printf("%d ", hasSubset[s][i]);
    }
    printf("\n");
  }
  return hasSubset[sum][n];
}

bool canPartition(const int arr[], const int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  // Array with odd sum cannot be partitioned
  if (sum % 2 == 1) {
    return false;
  }

  /* return subsetExists(arr, n, sum/2); */
  return subsetExistsDP(arr, n, sum/2);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {3, 1, 5, 9, 12}; */
  int arr[] = {3, 1, 1, 2, 2, 1};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << canPartition(arr, n) << endl;
  return 0;
}
