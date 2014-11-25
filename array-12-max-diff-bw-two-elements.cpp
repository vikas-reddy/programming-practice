#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

/*
 * To find the max difference between two elements in the array, provided the
 * smaller element appears before the larger one.
 *
 */

void printMaxDiff(int arr[], int n) {
  int diff;
  int localMax, globalMax = INT_MIN;
  int localStart, globalStart;
  int localEnd, globalEnd;
  int j;

  for (int i = 0; i <= n-2; i++) {
    diff = arr[i+1] - arr[i];
    if (diff > 0) {

      localMax = 0;
      localStart = i;

      for (j = i; j <= n-2 && (diff = arr[j+1] - arr[j]) > 0; j++) {
        localMax += diff;
      }

      localEnd = j;

      if (localMax > globalMax) {
        globalMax = localMax;
        globalStart = localStart;
        globalEnd = localEnd;
      }

      // we reached the end
      if (j == n-1) {
        break;
      }

      // setting the correct index
      i = j-1;
    }
  }

  printf("%d (%d,%d)\n", globalMax, globalStart, globalEnd);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {2, 3, 10, 6, 4, 8, 1}; */
  int arr[] = {7, 9, 5, 6, 3, 2};
  /* int arr[] = {44, 68, 50, 72, 2, 59, 51, 85, 58, 31}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  printMaxDiff(arr, len);
  return 0;
}
