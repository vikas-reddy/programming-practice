#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printCombinations(int n, int arr[], int currSize) {
  if (currSize >= n) {
    printArray(arr, n);
    return;
  }

  arr[currSize] = arr[currSize - 1] - 1;
  printCombinations(n, arr, currSize + 1);
  arr[currSize] = arr[currSize - 1] + 1;
  printCombinations(n, arr, currSize + 1);
}

int main(int argc, const char *argv[])
{
  int d = 4, n = 5;
  int arr[n];
  arr[0] = d;
  printArray(arr, n);
  printCombinations(n, arr, 1);
  return 0;
}
