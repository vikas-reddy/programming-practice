#include<iostream>
#include<limits.h>

using namespace std;

/* Recursive -- quite inefficient */
int maxSumRec (int arr[], int n) {
  if (n < 1)  return 0;
  if (n == 1) return arr[0];

  int curr_max_sum = INT_MIN;
  int sum;

  // Including current element (arr[n-1])
  for (int i = 0; i <= n-2; i++) {
    sum = maxSumRec(arr, i) + arr[n-1];
    if (curr_max_sum < sum)
      curr_max_sum = sum;
  }

  // Excluding current element
  sum = maxSumRec(arr, n - 1);
  if (curr_max_sum < sum)
    curr_max_sum = sum;

  return curr_max_sum;
}

/* O(n) solution */
int maxSum (int arr[], int n) {
  int incl = arr[0];
  int excl = 0;
  int temp;

  for (int i = 1; i < n; i++) {
    temp = max(excl, incl);

    // sum of 'excl' of prev element, and the current element
    incl = excl + arr[i];

    // 'excl' of current element is the max value of prev element
    excl = temp;
  }

  return max(incl, excl);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {3, 2, 7, 10}; */
  int arr[] = {5, 5, 10, 40, 50, 35};
  int n = sizeof(arr)/sizeof(arr[0]);

  cout << maxSum(arr, n) << endl;

  return 0;
}
