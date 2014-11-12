#include <iostream>
using namespace std;

/*
 * Partition an array of 0s, 1s and 2s in such a way that all 0s are together,
 * 1s are together and 2s are together. In other words, sort the array
 *
 */

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void sortArray(int arr[], int len) {
  // Invariant:
  //   arr[0..a-1] contains 0s
  //   arr[a..b-1] contains 1s
  //   arr[b..c] contains unknown numbers
  //   arr[c..n-1] contains 2s
  int a = 0;
  int b = 0;
  int c = len - 1;

  while (b <= c) {
    // this is to reduce unnecessary swaps of 2s
    /*
    while (arr[c] == 2 && b <= c) {
      c--;
    }
    if (b > c) {
      break;
    }
    */

    /* printf("a: %d, b: %d, c: %d\n", a, b, c); */
    if (arr[b] == 0) {
      swap(&arr[a++], &arr[b++]);
    }
    else if (arr[b] == 1) {
      b++;
    }
    else { // == 2
      swap(&arr[b], &arr[c--]);
    }
    /* printArray(arr, len); */
  }
}

int main(int argc, const char *argv[])
{
  int arr[] = {0, 0, 1, 2, 1, 2, 0, 1, 1, 1};
  int len = 10;
  printArray(arr, len);
  sortArray(arr, len);
  printArray(arr, len);
  return 0;
}
