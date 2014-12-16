#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

int swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int partition (int arr[], int f, int l) {
  if (f < l) {
    // Choose a random pivot
    int pivotIdx = f + rand() % (l - f + 1);
    int pivot = arr[pivotIdx];

    // Put the pivot at the back
    swap (&arr[pivotIdx], &arr[l]);

    // Index of the target element
    int targetIdx = f;

    for (int i = f; i < l; i++) {
      if (arr[i] < pivot) {
        swap (&arr[targetIdx++], &arr[i]);
      }
    }

    // Put the pivot back
    swap (&arr[targetIdx], &arr[l]);

    return targetIdx;
  }
}

void quicksort (int arr[], int f, int l) {
  if (f >= l)
    return;

  int pivotIdx = partition(arr, f, l);
  quicksort(arr, f, pivotIdx-1);
  quicksort(arr, pivotIdx+1, l);
}

int quickselect (int arr[], int k, int f, int l) {
  if (f == l)
    return arr[f];

  if (f < l) {
    int pivotIdx = partition(arr, f, l);

    if (pivotIdx == k)
      return arr[k];
    else if (k < pivotIdx)
      return quickselect (arr, k, f, pivotIdx - 1);
    else
      return quickselect (arr, k, pivotIdx + 1, l);
  }
}

int main(int argc, const char *argv[])
{
  // random seed
  srand( time(NULL) );

  // Random elements array
  int arr[10], len = 10;
  for (int i = 0; i < len; i++)
    arr[i] = rand() % 100;

  printf("Array: ");
  printArray(arr, len);

  // Random k
  int k = rand() % len;

  printf("kth (%d) element: %d\n", k+1, quickselect(arr, k, 0, len-1));

  printf("Array: ");
  printArray(arr, len);

  return 0;
}
