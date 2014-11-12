#include<iostream>
#include<algorithm>

// To sort arr1 using the order defined in arr2. Remaining elements in arr1 are
// to be appeneded in their sorted order

using namespace std;

int findFirstIdx(int arr[], int low, int high, int n) {
  if (low <= high) {
    int mid = (low + high)/2;
    if ((mid == 0 || n > arr[mid - 1]) && n == arr[mid]) {
      return mid;
    }
    if (n > arr[mid]) {
      return findFirstIdx(arr, mid + 1, high, n);
    }
    return findFirstIdx(arr, low, mid - 1, n);
  }
  return -1;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void sortArray(int arr1[], int arr2[], int len1, int len2) {
  // initializing the arr1-copy array, arr3, and a visited array
  int arr3[len1];
  bool visited[len1];
  for (int i = 0; i < len1; i++) {
    arr3[i] = arr1[i];
    visited[i] = false;
  }

  // sort arr1
  sort(arr3, arr3 + len1);

  int resIdx = 0, idx;

  // for every element in arr2, copy the corresponding elements over from arr3
  // to arr1
  for (int i = 0; i < len2; i++) {
    idx = findFirstIdx(arr3, 0, len1 - 1, arr2[i]);
    if (idx >= 0) {
      for (int j = idx; j < len1 && arr3[j] == arr2[i]; j++) {
        arr1[resIdx++] = arr3[j];
        visited[j] = true;
      }
    }
  }

  // copy the remaining ones which are anyways in sorted order
  for (int i = 0; i < len1; i++) {
    if (!visited[i]) {
      arr1[resIdx++] = arr3[i];
    }
  }
}

int main(int argc, const char *argv[])
{
  int arr1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
  int arr2[] = {5, 8, 9, 1};
  int len1 = 11;
  int len2 = 4;

  sortArray(arr1, arr2, len1, len2);
  printArray(arr1, len1);
  return 0;
}
