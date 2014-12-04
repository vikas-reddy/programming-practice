#include<iostream>
using namespace std;

/*
 *
 * Program to sort an array of 1s and 0s
 *
 */

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void sort(int arr[], int len) {
  int f = 0, l = len-1;
  while (f < l) {

    // seek to first 1 from the beginning
    while (f < l && arr[f] == 0) f++;

    // seek to first 0 from the ending
    while (f < l && arr[l] == 1) l--;

    // if nothing else has to be done
    if (f >= l) break;

    // swap the violating 0-1 pairs
    swap(&arr[f], &arr[l]);
    f++, l--;
  }
}

int main(int argc, const char *argv[])
{
  int arr[] = {0, 0, 1, 0, 0, 1, 0, 1, 0, 0};
  int len = sizeof(arr)/sizeof(arr[0]);

  sort(arr, len);
  printArray(arr, len);
  return 0;
}
