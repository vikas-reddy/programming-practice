#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

/*
 * Given an unsorted array of integers, assume the elements are inserted into
 * BST. Search for an element and print the path if found. If the element is
 * left of previous in BST then path variable is 1 else 0. Eg:
 *
 *  Input: Given array[] = {8, 2, 4, 9, 12, 3, 1} 
 *  Corresponding BST would be  BSTAmazon

 *  Output: Search key = 3 should print “101”, 
 *    key = 11 shouldn’t print any. 
 */

void printBoolArray (bool arr[], int n) {
  if (n == 0) {
    printf("ROOT");
  }
  else {
    for (int i = 0; i < n; i++) {
      printf("%d", arr[i]);
    }
  }
  printf("\n");
}

void printPath (int arr[], int n, int k) {
  if (n < 1) {
    printf("NULL\n");
    return;
  }

  bool op[n];
  memset(op, false, sizeof(op));

  bool found = false;

  int pos = 0;
  int curr = arr[0];

  for (int i = 1; i < n; i++) {
    if (k == curr) {
      found = true;
      break;
    }

    // Go right
    if (k > curr && arr[i] > curr) {
      printf("%d > %d \n", arr[i], curr);
      op[pos++] = 0;
      curr = arr[i];
    }
    // Go left
    else if (k < curr && arr[i] < curr) {
      printf("%d < %d \n", arr[i], curr);
      op[pos++] = 1;
      curr = arr[i];
    }
  }

  if (found)
    printBoolArray(op, pos);
  else
    printf("NULL\n");
}

int main(int argc, const char *argv[])
{
  int arr[] = {8, 2, 4, 9, 12, 3, 1};
  int len = sizeof(arr)/sizeof(arr[0]);

  if (argc < 2)
    return 1;

  int k = atoi(argv[1]);
  printPath(arr, len, k);

  return 0;
}
