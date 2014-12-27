#include<iostream>
#include<stdlib.h>
#include<algorithm>

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

/*
 * O(n^2) algorithm
 * for every `a`, `b` and `c` travel till the end only once
 *
 */
int numTriangles (int arr[], int n) {
  if (n < 3)
    return 0;

  // Sort the array first
  sort(arr, arr + n);

  int a = 0, b = 1, c;
  int count = 0;

  for (int a = 0; a < n-2; a++) {
    int c = a + 2;
    for (int b = a+1; b < n-1; b++) {

      while (c < n && arr[c] < arr[a] + arr[b])
        c++;

      count += c - b - 1;
    }
  }
  return count;
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {10, 21, 22, 100, 101, 200, 300}; */
  /* int arr[] = {4, 6, 3, 7}; */
  int arr[] = {20, 25, 30, 35, 40, 45, 50, 55, 60};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  cout << numTriangles(arr, len) << endl;

  return 0;
}
