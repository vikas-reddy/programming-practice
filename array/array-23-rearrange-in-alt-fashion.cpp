#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

/*
 * Given an array of numbers, arrange them in an alternate fashion such that
 * every number is followed by a number of opposite sign. Also the order was to
 * be maintained. If the count of negative numbers is more keep the extra at
 * last in array and same for positive numbers.
 *
 * Example :
 * Input: -3 -2 6 0 7 -1 -8
 * Output: -3 6 -2 0 -1 7 -8
 *
 */

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void rearrange (int arr[], int n) {
  int a = 0, b = 0;

  // Sort the array in such a way that positive numbers appear at the end, and
  // negative ones at the beginning, retaining their relative order
  while (true) {
    for (     ; a < n && arr[a] <  0; a++);
    for (b = a; b < n && arr[b] >= 0; b++);

    if (a >= n || b >= n || a >= b)
      break;

    // Shift the subarray (a,b-1) to right by one
    int temp = arr[b];
    for (int i = b-1; i >= a; i--)
      arr[i+1] = arr[i];
    arr[a] = temp;
  }
  // Now there `a` negative numbers and `n-a` positive numbers

  int negIdx = 0, posIdx = a;
  while (negIdx < n && posIdx < n && arr[negIdx] < 0 && negIdx + 1 < posIdx) {
    // Shift subarray
    int temp = arr[posIdx];
    for (int i = posIdx; i > negIdx; i--)
      arr[i] = arr[i-1];
    arr[negIdx+1] = temp;

    negIdx += 2;
    posIdx++;
  }
}

int main(int argc, const char *argv[])
{
  // Random seed
  srand(time(NULL));

  /* int arr[] = {-3, -2, 6, 0, 7, -1, -8}; */
  /* int n = sizeof(arr)/sizeof(arr[0]); */
  int n = 10;
  int *arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = rand() % 100 - 50;

  printArray (arr, n);
  rearrange (arr, n);
  printArray (arr, n);

  return 0;
}
