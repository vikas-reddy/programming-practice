#include<iostream>
#include<stdlib.h>

using namespace std;

/* In-place heap sort -- O(nlogn)
 *
 */
void printArray (int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

int ceil (float num) {
  int n = (int) num;
  return (n == num) ? n : n + 1;
}

void maxHeapify (int arr[], int len, int idx) {
  int l = 2*idx + 1;
  int r = 2*idx + 2;
  int largest = idx;

  if (l < len && arr[l] > arr[idx])
    largest = l;
  if (r < len && arr[r] > arr[largest])
    largest = r;
  if (largest != idx) {
    swap (&arr[idx], &arr[largest]);
    maxHeapify (arr, len, largest);
  }
}

void buildHeap (int arr[], int len) {
  for (int i = ceil((len - 1)/2.0); i >= 0; i--) {
    maxHeapify (arr, len, i);
  }
}

void heapSort (int arr[], int len) {
  buildHeap (arr, len);

  for (int i = len-1; i > 1; i--) {
    // get the max element from the max heap and put it at the end
    swap (&arr[0], &arr[i]);

    // heapify the heap again
    maxHeapify (arr, i, 0);
  }
}

int main(int argc, const char *argv[])
{
  int arr[] = {89, 29, 37, 32, 64, 35, 22, 36, 93, 92, 32, 18, 5, 85, 22, 44, 15, 22, 47, 45};
  /* int arr[] = {27, 52, 82, 50, 90, 39, 78, 19, 14, 64}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  heapSort (arr, len);

  printArray (arr, len);
  return 0;
}
