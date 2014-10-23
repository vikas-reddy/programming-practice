#include<iostream>

using namespace std;

void printArray(int *arr, int size) {
  for (int i=0; i < size; i++) {
    cout << arr[i];
    if (i != size - 1) {
      cout << " ";
    }
  }
  cout << endl;
}

int main(int argc, char* argv[]) {

  // the array to be sorted
  int input[16] = {3, 6, 2, 8, 0, 0, 6, 0, 4, 1, 4, 2, 0, 3, 6, 1},
      output[16] = {};

  // initialize count[] to 0s
  int count[10] = {};

  printArray(input, 16);

  // storing counts
  for (int i = 0; i < 16; i++) {
    count[input[i]]++;
  }

  printArray(count, 10);

  // storing cumulative counts / locations
  for (int i = 1; i < 10; i++) {
    count[i] += count[i-1];
  }

  printArray(count, 10);

  // generating the output array
  for (int i = 15; i >= 0; i--) {
    output[count[input[i]] - 1] = input[i];
    count[input[i]]--;
  }

  printArray(output, 16);
}
