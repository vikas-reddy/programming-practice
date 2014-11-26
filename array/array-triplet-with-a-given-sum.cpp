#include<iostream>
#include<stdlib.h>

using namespace std;

int computeSum(int temp[]) {
  return (temp[0] + temp[1] + temp[2]);
}

int print(int temp[]) {
  cout << "triplet: " << temp[0] << " " << temp[1] << " " << temp[2] << endl;
}

void triplets(int arr[], int first, int len, int sum, int temp[], int tempLen) {
  for (int i = first; i < len; i++) {
    temp[tempLen] = arr[i];
    if (tempLen == 2) {
      if (computeSum(temp) == sum) {
        cout << computeSum(temp) << "; ";
        print(temp);
      }
    }
    else {
      triplets(arr, i + 1, len, sum, temp, tempLen + 1);
    }
  }
}

int main(int argc, const char *argv[])
{
  int arr[10] = {6, 14, 17, 19, 27, 47, 59, 92, 95, 98};
  int len = 10, temp[3], sum = 93;

  triplets(arr, 0, len, sum, temp, 0);
  return 0;
}
