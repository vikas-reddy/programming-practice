#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

/*
 * Reverse every k elements of a linked list. The remaining elements are to be
 * left as it is.
 *
 * 1 2 3 4 5 6 7 8 9 10
 *   k = 4
 * 4 3 2 1 8 7 6 5 9 10
 *
 */

struct node {
  struct node *next;
  int data;
};

void insert(struct node **root, int elem) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = elem;
  n->next = *root;
  (*root) = n;
  return;
}

int sizeLL(struct node *root) {
  int size = 0;
  struct node *n = root;
  for (size = 0; n; n = n->next, size++);
  return size;
}

void printLL(struct node *root) {
  if (root) {
    struct node *n = root;
    for (n = root; n; n = n->next) {
      printf("%d ", n->data);
    }
    printf("\n");
  }
}

void reverseEvery(node **r, int k) {
  if (r == NULL || k <= 1) {
    return;
  }

  node *n;
  int count;
  for (n = *r, count = 0; n && count < k - 1; n = n->next, count++);

  // if the list has < k elements
  if (n == NULL) {
    return; // do nothing
  }
  // if the list has >= k elements
  else {
    node *a, *temp, *res = NULL;

    // storing the starting point of the next element for recursion
    node *nextList = n->next;
    int count = 0;

    // Reverse the first k elements. After this operation, *r will still point
    // the start of the list. This should be joined with the nextList.
    // res will point to the new start.
    // 4   3   2   1   5        6   7   8 ...
    // res         *r  nextList
    a = *r;
    while (count < k) {
      temp = a->next;
      a->next = res;
      res = a;
      a = temp;
      count++;
    }

    reverseEvery(&nextList, k);
    (*r)->next = nextList;
    *r = res;
    return;
  }
}

int main() {
  /* int arr[10] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99}; */
  int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int len = 10, i;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
  }
  printLL(root);

  int k = 4;
  reverseEvery(&root, k);
  printLL(root);
}
