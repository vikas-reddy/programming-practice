#include<iostream>
#include<stdlib.h>
#include<time.h>

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

void shuffleArray(int arr[], int len) {
  // different seed
  srand(time(NULL));

  for (int i = len-1; i >= 0; i--) {
    int j = rand() % (i+1);
    swap(&arr[i], &arr[j]);
  }
}

int main(int argc, const char *argv[])
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  shuffleArray(arr, len);
  printArray(arr, len);

  return 0;
}
