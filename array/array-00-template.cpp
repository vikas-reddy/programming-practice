#include<iostream>
#include<stdlib.h>

using namespace std;

int swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int main(int argc, const char *argv[])
{
  int arr[] = {94, 54, 16, 86, 84, 53, 22, 87, 18, 3};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);
  return 0;
}
