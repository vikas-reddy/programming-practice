#include<iostream>
#include<limits.h>
#include<algorithm>
using namespace std;

/*
 * To find the max difference between two elements in the array, provided the
 * smaller element appears before the larger one.
 *
 * Turns out, we have to find the max sum subarray of the "differences array"
 *
 */

void printMaxDiff(int arr[], int n) {
  int diff, j;

  int globalStart = 0, globalEnd = 0;
  int globalMax = 0;
  int localStart = 0;
  int localMax = 0;

  /* Kadane algorithm for diffs */
  for (int i = 0; i <= n-2; i++) {
    diff = arr[i+1] - arr[i];
    printf("%d ", diff);
    localMax = localMax + diff;
    if (localMax < 0) {
      localMax = 0;
      localStart = i+1;
    }
    if (localMax > globalMax) {
      globalMax = localMax;
      globalStart = localStart;
      globalEnd = i+1;
    }
  }
  printf("\n");

  /* printf("%d \n", globalMax); */
  printf("%d (%d,%d)\n", globalMax, globalStart, globalEnd);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {2, 3, 10, 6, 11, 4, 8, 1}; */
  /* int arr[] = {7, 9, 5, 6, 3, 2}; */
  /* int arr[] = {44, 68, 50, 72, 2, 59, 51, 85, 58, 31}; */
  int arr[] = {78, 82, 39, 20, 4, 72, 7, 46, 36, 41};
  int len = sizeof(arr)/sizeof(arr[0]);

  printMaxDiff(arr, len);
  return 0;
}
