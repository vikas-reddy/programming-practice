#include<iostream>
using namespace std;

/* Kadane's algorithm */
int maxSum(const int arr[], const int n) {
  int max_ending_here = 0;
  int max_so_far = 0;

  for (int i = 0; i < n; i++) {
    max_ending_here = max_ending_here + arr[i];
    if (max_ending_here < 0) {
      max_ending_here = 0;
    }
    else if (max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
    }
  }
  return max_so_far;
}

// Works for all-negative arrays too
int maxSum2(const int arr[], const int n) {
  int max_ending_here = arr[0];
  int max_so_far = arr[0];

  for (int i = 1; i < n; i++) {
    max_ending_here = max_ending_here + arr[i];
    if (max_ending_here < arr[i]) {
      max_ending_here = arr[i];
    }
    if (max_ending_here > max_so_far) {
      max_so_far = max_ending_here;
    }
  }
  return max_so_far;
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}; */
  int arr[] = {-2, -3, -4, -1, -2, -1, -5, -3};
  int len = sizeof(arr)/sizeof(arr[0]);

  cout << maxSum(arr, len) << endl;
  cout << maxSum2(arr, len) << endl;
  return 0;
}
