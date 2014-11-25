#include<stdio.h>
#include<iostream>
#include<limits.h>
#include<algorithm>

using namespace std;

int maxSumRec(const int arr[], const int len, int k, int *maxSum) {
  if (k < 1 || k > len) return 0;

  int max = arr[k-1], res;

  /* Find the maximum sum of all its predecessors */
  for (int i = 1; i < k; i++) {
    res = maxSumRec(arr, len, i, maxSum);
    if (arr[k-1] > arr[i-1] && res + arr[k-1] > max) {
      max = res + arr[k-1];
    }
  }

  /* Computing the overall max */
  if (max > *maxSum) {
    *maxSum = max;
  }

  /* Yet, returning the current max and not the overall max */
  return max;
}

int findMax(const int arr[], const int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

int maxSumDP (const int arr[], const int n) {
  int maxSums[n];

  // By default, for all i, maxSums[i] are >= arr[i]
  for (int i = 0; i < n; i++) {
    maxSums[i] = arr[i];
  }

  // The actual computation
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i < l; i++) {
      if (arr[i-1] < arr[l-1]) {
        if (maxSums[i-1] + arr[l-1] > maxSums[l-1]) {
          maxSums[l-1] = maxSums[i-1] + arr[l-1];
        }
      }
    }
  }

  /* Printing the array */
  for (int l = 1; l <= n; l++) {
    printf("%d ", maxSums[l-1]);
  }
  printf("\n");

  /* Finding the maximum */
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    if (maxSums[i] > max) {
      max = maxSums[i];
    }
  }
  return max;
}

int main(int argc, const char *argv[])
{
  int arr[] = {1, 101, 2, 3, 100, 4, 5};
  int len = 7;

  /* Recursive */
  int maxSum = INT_MIN;
  maxSumRec(arr, len, len, &maxSum);
  cout << maxSum << endl;

  /* DP: bottom-up */
  cout << maxSumDP(arr, len) << endl;
  return 0;
}
