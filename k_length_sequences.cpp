#include <iostream>

using namespace std;

void printArray(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void printSequences(int f, int l, int curr_len, int len, int *arr) {
  if (curr_len == 0 || f > l) {
    return;
  }

  for (int i = f; i <= l - curr_len + 1; i++) {
    arr[len - curr_len] = i;
    if (curr_len == 1) {
      printArray(arr, len);
    }
    else {
      printSequences(i + 1, l, curr_len - 1, len, arr);
    }
  }
}

int main(int argc, char *argv[]) {
  int k = 0, n = 0;
  cout << "k = ";
  cin >> k;
  cout << "n = ";
  cin >> n;

  int arr[k];

  printSequences(1, n, k, k, arr);
  return 0;
}
