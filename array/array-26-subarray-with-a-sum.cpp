#include<iostream>
#include<stdlib.h>

using namespace std;

int swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray(int arr[], int f, int l) {
  for (int i = f; i <= l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void printSubarray (int arr[], int len, int sum) {
  int f = 0, curr_sum = arr[f];

  for (int i = 1; i <= len; i++) {
    while (curr_sum > sum && f < i-1) {
      curr_sum -= arr[f];
      f++;
    }

    if (curr_sum == sum) {
      printArray(arr, f, i-1);
      return;
    }

    if (i < len)
      curr_sum += arr[i];
  }

  printf("No\n");
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {1, 4, 20, 3, 10, 5}; */
  int arr[] = {1, 4, 0, 0, 3, 10, 5};
  /* int arr[] = {1, 4}; */
  int len = sizeof(arr)/sizeof(arr[0]);
  /* int sum = 33; */
  int sum = 15;
  /* int sum = 6; */

  printArray(arr, 0, len-1);

  printSubarray(arr, len, sum);

  return 0;
}
