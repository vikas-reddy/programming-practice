#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%2d ", arr[i]);
  }
  cout << endl;
}

int longestIncreasingSequence(int arr[], int len) {
  int lis[len];
  int max;

  for (int i = 0; i < len; i++) {
    max = 0;
    for (int j = 0; j < i; j++) {
      if (arr[i] > arr[j]) {
        if (max < lis[j]) {
          max = lis[j];
        }
      }
    }
    lis[i] = max + 1;
  }

  max = 0;
  for (int i = 0; i < len; i++) {
    if (max < lis[i]) {
      max = lis[i];
    }
  }

  printArray(arr, len);
  printArray(lis, len);
  return max;
}

int main(int argc, const char *argv[])
{
  int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 55};
  int len = 10;
  cout << longestIncreasingSequence(arr, len) << endl;
  return 0;
}
