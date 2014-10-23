#include<iostream>
using namespace std;

int *firstMax(int *arr, int len, int a) {
  if (a >= len) {
    return arr;
  }

  int last = arr[len - 1];
  for (int i = len - 2; i >= a; i--) {
    arr[i+1] = arr[i];
  }
  arr[a] = last;
  return firstMax(arr, len, a+2);
}

void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i];
    if (i != len - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
  int arr[10] = { 5, 6, 8, 43, 45, 52, 57, 57, 90, 91 },
      len = 10;

  printArray(arr, len);

  arr = firstMax(arr, 0, len - 1);

  printArray(arr, len);

  return 0;
}
