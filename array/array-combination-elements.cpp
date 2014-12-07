#include <iostream>
#include <stdlib.h>

using namespace std;

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printCombinations(int arr[], int n, int currSize) {
  if (currSize == n) {
    printArray(arr, n);
    return;
  }

  arr[currSize] = arr[currSize - 1] - 1;
  printCombinations(arr, n, currSize + 1);
  arr[currSize] = arr[currSize - 1] + 1;
  printCombinations(arr, n, currSize + 1);
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Needs d and n as command-line args" << endl;
    return 1;
  }

  int d = atoi(argv[1]);
  int n = atoi(argv[2]);

  int *arr = new int[n];
  arr[0] = d;

  printCombinations(arr, n, 1);
  return 0;
}
