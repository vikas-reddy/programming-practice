#include<iostream>
#include<algorithm>
using namespace std;

void printPeaks1(int arr[], int len) {
  if (len >= 3) {
    for (int i = 1; i <= len-2; i++) {
      if (arr[i-1] <= arr[i] && arr[i] >= arr[i+1]) {
        printf("%d ", arr[i]);
      }
    }
  }
  if (len >= 2) {
    if (arr[0] >= arr[1]) {
      printf("%d ", arr[0]);
    }
    if (arr[len-2] <= arr[len-1]) {
      printf("%d ", arr[len-1]);
    }
  }
  printf("\n");
}

void printPeaks2(int arr[], int f, int l) {
  /* printf("f:%d l:%d\n", f, l); */
  // base cases
  if (f > l) {
    return;
  }

  // == 1 element
  if (l - f == 0) {
    printf("%d ", arr[f]);
  }

  // ==2 elements
  else if (l - f == 1) {
    printf("%d ", max(arr[f], arr[l]));
  }

  // >= 3 elements
  else if (l - f >= 2) {
    int m = (f+l)/2;
    // m is either the peak
    if (arr[m-1] <= arr[m] && arr[m] >= arr[m+1]) {
      printf("%d ", arr[m]);
      return;
    }
    // or the peak lies in the left partition
    if (arr[m-1] > arr[m]) {
      printPeaks2(arr, f, m);
    }
    // or it lies in the right partition
    else if (arr[m] < arr[m+1]) {
      printPeaks2(arr, m, l);
    }
  }
}

int main(int argc, const char *argv[]) {
  /* int arr[] = {5, 10, 20, 15}; */
  /* int arr[] = {100, 80, 60, 50, 20}; */
  /* int arr[] = {20, 50, 60, 80, 100}; */
  int arr[] = {1, 3, 20, 4, 1, 0};
  /* int arr[] = {1, 1, 1, 1, 1, 1}; */
  int len = sizeof(arr)/sizeof(arr[0]);

  /* printPeaks1(arr, len); */
  printPeaks2(arr, 0, len-1);
  printf("\n");
  return 0;
}
