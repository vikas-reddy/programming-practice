#include<iostream>
using namespace std;

void printArray(int arr[], int f, int l) {
  for (int i = f; i <= l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubbleSort(int arr[], int len, int k) {
  for (int e = len-1; e >= len-k; e--) {
    for (int i = 0; i < e; i++) {
      if (arr[i] > arr[i+1]) {
        swap(arr[i], arr[i+1]);
      }
    }
    printArray(arr, 0, len-1);
  }
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {76, 57, 13, 85, 58, 91, 81, 10, 98, 92}; */
  int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  int len = sizeof(arr)/sizeof(arr[0]);
  int k = 4;

  printArray(arr, 0, len-1);
  bubbleSort(arr, len, k);
  printArray(arr, len-k, len-1);
  printArray(arr, 0, len-1);
  return 0;
}
