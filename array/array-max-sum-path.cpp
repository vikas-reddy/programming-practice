#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(int argc, const char *argv[])
{
  int arr1[] = {2, 3, 7, 10, 12, 15, 30, 34};
  int arr2[] = {1, 5, 7, 8, 10, 15, 16, 19};
  int len1 = 8, len2 = 8;
  /* int arr1[] = {2, 3, 6, 10, 12}; */
  /* int arr2[] = {1, 5, 7, 8}; */
  /* int len1 = 5, len2 = 4; */
  int sum1 = 0, sum2 = 0, sum = 0;
  int idx1 = 0, idx2 = 0;

  // sum of common elements (indexes)
  while (idx1 < len1 && idx2 < len2) {
    if (arr1[idx1] == arr2[idx2]) {
      /* cout << "common: " << arr1[idx1] << "; sum1: " << sum1 << "; sum2: " << sum2 << "; sum: " << sum << endl; */
      sum1 += arr1[idx1++];
      sum2 += arr2[idx2++];
      sum += (sum1 > sum2) ? sum1 : sum2;
      sum1 = sum2 = 0;
    }
    else if (arr1[idx1] < arr2[idx2]) {
      sum1 += arr1[idx1++];
    }
    else {
      sum2 += arr2[idx2++];
    }
  }

  // sum of the remaining elements
  while (idx1 < len1) {
    sum1 += arr1[idx1++];
  }
  while (idx2 < len2) {
    sum2 += arr2[idx2++];
  }
  sum += (sum1 > sum2) ? sum1 : sum2;

  cout << sum << endl;
  return 0;
}
