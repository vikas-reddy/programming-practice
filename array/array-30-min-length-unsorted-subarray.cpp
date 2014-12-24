#include<iostream>
#include<stdlib.h>
#include<limits.h>

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

void findUnsorted (int arr[], int n) {
  int a, b;

  // Seek our pointers to boundaries of the violating subarray
  for (a = 0; a <= n-2 && arr[a] < arr[a+1]; a++);
  for (b = n-1; b >= 1 && arr[b] > arr[b-1]; b--);

  // Nothing else to do
  if (a == n-1 || b == 0 || a > b)
    return;

  // Finding the min and max elements of the violating subarray
  int min_elem = INT_MAX, max_elem = INT_MIN;
  for (int i = a; i <= b; i++) {
    min_elem = min(min_elem, arr[i]);
    max_elem = max(max_elem, arr[i]);
  }

  // Our pointers may need some adjustment depending on the min and max values
  // we found inside the violating subarray
  while (a == 0 || arr[a-1] > min_elem) a--;
  while (b == n-1 || arr[b+1] < max_elem) b++;

  printf("%d %d\n", a, b);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60}; */
  int arr[] = {0, 1, 15, 25, 6, 7, 30, 40, 50};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  findUnsorted(arr, len);

  return 0;
}
