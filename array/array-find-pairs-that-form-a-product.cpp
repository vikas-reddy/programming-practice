#include<iostream>
#include<stdlib.h>

using namespace std;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void insertionSort(int arr[], int len) {
  int elem, j;
  for (int i = 1; i < len; i++) {
    elem = arr[i];
    for (j = i-1; j >= 0 && arr[j] > elem; j--) {
      arr[j+1] = arr[j];
    }
    arr[j+1] = elem;
  }
}

void printPairs1(int arr[], int len, int x) {
  int k, y;
  // for all elements in arr
  for (int i = 0; i < len; i++) {
    // find a partner for arr[i] only if x is divisible by arr[i]
    if (arr[i] == 0 || x % arr[i] != 0) {
      // do nothing
    }
    else {
      y = x/arr[i];
      for (int j = i+1; j < len; j++) {
        if (arr[j] == y) {
          cout << "(" << arr[i] << ", " << arr[j] << ")" << endl;
        }
      }
    }
  }
}

void findNext(int arr[], int len, int *idx) {
  int i;
  for (i = (*idx); i < len && arr[i] == arr[*idx]; i++);
  (*idx) = i;
}

void findPrev(int arr[], int len, int *idx) {
  int i;
  for (i = (*idx); i >= 0 && arr[i] == arr[*idx]; i--);
  (*idx) = i;
}


// sliding window
void printPairs2(int arr[], int len, int x) {
  int first = 0, last = len - 1, product;
  while (first <= last) {
    product = arr[first] * arr[last];
    if (product == x) {
      cout << "(" << arr[first] << ", " << arr[last] << ")" << endl;
      findNext(arr, len, &first);
      findPrev(arr, len, &last);
    }
    else if (product < x) {
      findNext(arr, len, &first);
    }
    else {
      findPrev(arr, len, &last);
    }
  }
}

int main(int argc, const char *argv[])
{
  int arr[18] = {12, 12, 6, 10, 4, 6, 7, 4, 11, 5, 9, 3, 4, 2, 6, 1, 8, 3}, len = 18;
  int x = 36;

  printArray(arr, len);
  insertionSort(arr, len);
  printArray(arr, len);

  // to find a and b such that a*b = x
  printPairs2(arr, len, x);
  return 0;
}
