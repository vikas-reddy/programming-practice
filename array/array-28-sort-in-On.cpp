#include<iostream>
#include<queue>
#include<iterator>

using namespace std;

void printArray (int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

/* Radix sort with base n as elements in the array are between 0 and n^2 - 1 */
void sort (int arr[], int n) {
  queue<int> *queues = new queue<int>[n];

  // All elements can be expressed in a two-digit notation in base-n system
  for (int d = 0; d < 2; d++) {

    // Putting the elements into the appropriate queues
    for (int i = 0; i < n; i++)
      queues[(arr[i]/(d ? n : 1)) % n].push(arr[i]);

    // Copying the elements back from the queues into the array
    for (int i = 0, k = 0; i < n; i++) {
      while (!queues[i].empty()) {
        arr[k++] = queues[i].front();
        queues[i].pop();
      }
    }
  }
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {0, 23, 14, 12, 9}; /1* 5 *1/ */
  /* int arr[] = {75, 43, 60, 96, 95, 51, 71, 26, 18, 0}; /1* 10 *1/ */
  int arr[] = {104, 33, 112, 108, 99, 68, 105, 11, 122, 11, 135, 76}; /* 12 */
  int len = sizeof(arr)/sizeof(arr[0]);

  printArray(arr, len);

  sort(arr, len);

  printArray(arr, len);
  return 0;
}
