#include<iostream>
#include<stdlib.h>
#include<string.h>

using namespace std;

/*
 * An array is given where nodes are represented by array indices, and the data
 * in the array represent the position of the parent. Root has -1. Find the
 * depth/height of the tree
 *
 *  Input: parent[] = {1 2 -1 2}
 *           2
 *          /  \
 *         1    3
 *        /
 *       0
 *  Output: 4
 */

void printArr (int arr[], int len) {
  for (int i = 0; i < len; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

// O(n2)
int computeHeight1 (int arr[], int len) {
  int maxDepth = 0;
  for (int i = 0; i < len; i++) {
    int depth = 0, node = i;
    // navigate till the root from all nodes
    while (node != -1) {
      node = arr[node];
      depth++;
    }
    maxDepth = max(depth, maxDepth);
  }
  return maxDepth;
}

// O(n)
int computeHeight2 (int arr[], int len) {
  // `ht` array will hold the heights of nodes from leaves at some point of
  // time
  int *ht = new int[len];
  for (int i = 0; i < len; i++)
    ht[i] = 0;

  int maxDepth = 0;
  for (int i = 0; i < len; i++) {
    // already-visited node
    if (ht[i] > 0)
      continue;

    int node = i, x = 1;
    // navigate till the root from all nodes
    while (node != -1) {
      if (ht[node] >= x)
        break;
      ht[node] = x;
      node = arr[node];
      x++;
    }
    if (arr[node] == -1) {
      ht[node] = max(x, ht[node]);;
    }
    /* maxDepth = max(x, maxDepth); */

    printArr(ht, len);
  }
  return maxDepth;
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {-1, 0, 0, 1, 1, 2, 2, 4, 4, 6, 9}; */
  int arr[] = {9, 5, 5, 7, 2, 7, 9, -1, 3, 3};
  int len = sizeof(arr)/sizeof(arr[0]);

  cout << "Height: " << computeHeight2(arr, len) << endl;
  return 0;
}
