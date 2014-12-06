#include<iostream>
#include<stdlib.h>
#include<deque>

using namespace std;

void printDeque (deque<int> q) {
  for (deque<int>::iterator i = q.begin(); i != q.end(); ++i) {
    printf("%d ", *i);
  }
  printf("\n");
}

void printMax (int arr[], int len, int k) {
  // q holds the indexes of max elements
  deque<int> q;

  for (int i = 0; i < k; i++) {
    // remove the elements which are less than arr[i] from the back of the
    // queue so that only "useful" elements remain in it
    while (!q.empty() && arr[q.back()] <= arr[i])
      q.pop_back();

    q.push_back(i);
  }

  /* printDeque(q); */
  for (int i = k; i < len; i++) {
    printf("%d ", arr[q.front()]);

    // remove the last out-of-range element from the front of the queue
    if (!q.empty() && q.front() == i-k)
      q.pop_front();
    /* while (!q.empty() && q.front() <= i-k) */
    /*   q.pop_front(); */

    while (!q.empty() && arr[q.back()] <= arr[i])
      q.pop_back();

    q.push_back(i);
  }

  printf("%d\n", arr[q.front()]);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13}; */
  /* int arr[] = {1, 2, 3, 1, 4, 5, 2, 3, 6}; */
  int arr[] = {12, 1, 78, 90, 57, 89, 56};
  int len = sizeof(arr)/sizeof(arr[0]);
  int k = 3;

  printMax(arr, len, k);
  return 0;
}
