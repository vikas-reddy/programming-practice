#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

/*
 * Quicksort
 */
void printArray (int arr[], int f, int l) {
  for (int i = f; i <= l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

int partition (int arr[], int f, int l) {
  if (f >= l)
    return f;

  // random pivot
  int pivotIdx = f + rand() % (l-f+1);
  int pivot = arr[pivotIdx];

  // ++targetIdx is where the next element which is less than pivot to go
  int targetIdx = f;

  for (int i = f; i <= l; i++) {
    // bring all elements which are less than pivot to the beginning of the array
    if (arr[i] < pivot) {

      // if we are putting some other element in pivot's position, update pivotIdx
      if (targetIdx == pivotIdx)
        pivotIdx = i;

      swap (&arr[i], &arr[targetIdx++]);
    }
  }

  swap (&arr[pivotIdx], &arr[targetIdx]);

  // position of the pivot element
  return targetIdx;
}

void quicksort (int arr[], int f, int l) {
  if (f < l) {
    int pivotIdx = partition (arr, f, l);

    // recursion
    quicksort (arr, f, pivotIdx-1);
    quicksort (arr, pivotIdx+1, l);
  }
}

int main(int argc, const char *argv[])
{
  // random seed
  srand(time(NULL));

  /* int arr[] = {89, 29, 37, 32, 64, 35, 22, 36, 93, 92, 32, 18, 5, 85, 22, 44, 15, 22, 47, 45}; */
  int arr[] = {3, 7, 13, 8, 51, 70, 34, 21, 0, 5, 79, 49, 4, 86, 48, 21, 37, 18, 79, 31};
  /* int arr[] = {27, 52, 82, 50, 90, 39, 78, 19, 14, 64}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray (arr, 0, len-1);

  quicksort (arr, 0, len-1);
  /* partition (arr, 0, len-1); */

  printArray (arr, 0, len-1);
  return 0;
}
