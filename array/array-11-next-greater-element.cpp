#include<iostream>
#include<stack>
#include<string.h>
using namespace std;

void printArray(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    printf("%2d ", arr[i]);
  }
  printf("\n");
}

void printNge1(int arr[], int len) {
  for (int i = 0; i < len; i++) {
    int nge = -1;
    for (int j = i+1; j < len; j++) {
      if (arr[j] > arr[i]) {
        nge = arr[j];
        break;
      }
    }
    printf("%2d ", nge);
  }
  printf("\n");
}

void printNge2(int arr[], int len) {
  int elem, next;

  stack<int> s;

  // Push the first element
  s.push(arr[0]);

  for (int i = 1; i < len; i++) {

    // 'next' starts from 1
    next = arr[i];

    if (!s.empty()) {

      // Pop the first element
      elem = s.top();
      s.pop();

      // Print all elements (pairs) which are lesser than 'next'
      while (elem < next) {
        printf("%2d -> %2d\n", elem, next);
        if (s.empty())
          break;
        elem = s.top();
        s.pop();
      }

      // If the NGE of the first element cannot be computed now (because of the
      // fact that we have not yet encountered its NGE yet), it should be
      // pushed back into the stack
      if (elem > next) {
        s.push(elem);
      }
    }

    s.push(next);
  }

  while (!s.empty()) {
    elem = s.top();
    s.pop();
    printf("%2d -> %2d\n", elem, -1);
  }
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {4, 5, 2, 25}; */
  /* int arr[] = {13, 7, 6, 12}; */
  int arr[] = {39, 59, 24, 21, 42, 57, 12, 4, 73, 65};
  int len = sizeof(arr)/sizeof(arr[0]);

  printNge1(arr, len);

  printNge2(arr, len);

  return 0;
}
