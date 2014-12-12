#include<iostream>
#include<stdlib.h>

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void insertionSort (int arr[], int len) {
  for (int i = 1; i < len; i++) {

    int temp = arr[i];
    int j;

    // shifting elements which are greater than arr[i] towards right
    for (j = i; j > 0 && arr[j-1] > temp; j--)
      arr[j] = arr[j-1];

    arr[j] = temp;
  }
}

int main(int argc, const char *argv[])
{
  int arr[] = {74, 85, 90, 42, 99, 46, 20, 1, 72, 60};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  insertionSort(arr, len);
  printArray(arr, len);

  return 0;
}
