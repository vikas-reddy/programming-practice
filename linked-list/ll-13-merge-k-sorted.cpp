#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<iostream>

using namespace std;

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

node *mergeTwo(node *a, node *b) {
  if (a && b) {
    if (a->data < b->data) {
      a->next = mergeTwo(a->next, b);
      return a;
    }
    else {
      b->next = mergeTwo(a, b->next);
      return b;
    }
  }
  // base case
  return (a ? a : b);
}

bool allEmpty(node *lists[], int k) {
  for (int i = 0; i < k; i++) {
    if (lists[i] != NULL)
      return false;
  }
  return true;
}

int getMinIdx(node *lists[], int k) {
  int min = INT_MAX, minIdx;
  for (int i = 0; i < k; i++) {
    if (lists[i] && lists[i]->data < min) {
      min = lists[i]->data;
      minIdx = i;
    }
  }
  return minIdx;
}

node *mergeK(node *lists[], int k) {
  // base cases
  if (allEmpty(lists, k))
    return NULL;

  // get the minimum from the start pointers of the k lists
  int minIdx = getMinIdx(lists, k);

  // `n` is the start for the current call
  node *n = lists[minIdx];

  // seeking the "min" list one step forward
  lists[minIdx] = lists[minIdx]->next;

  // recursing
  n->next = mergeK(lists, k);
  return n;
}

int main() {
  int arr1[] = {96, 92, 89, 68, 54, 52, 51, 48, 43, 23};
  int arr2[] = {99, 98, 86, 77, 75, 55, 53, 46, 30, 16};
  int arr3[] = {92, 88, 85, 71, 40, 30, 17, 16, 8, 3};
  int arr4[] = {96, 93, 88, 73, 61, 44, 33, 33, 20, 6};
  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);
  int len3 = sizeof(arr3)/sizeof(arr3[0]);
  int len4 = sizeof(arr4)/sizeof(arr4[0]);

  // k lists
  int k = 4;
  node **lists;
  lists = (node **) malloc(k * sizeof(node*));
  for (int i = 0; i < k; i++)
    lists[i] = NULL;

  for (int i = 0; i < len1; i++) insert(&lists[0], arr1[i]);
  for (int i = 0; i < len2; i++) insert(&lists[1], arr2[i]);
  for (int i = 0; i < len3; i++) insert(&lists[2], arr3[i]);
  for (int i = 0; i < len4; i++) insert(&lists[3], arr4[i]);

  printLL(lists[0]);
  printLL(lists[1]);
  printLL(lists[2]);
  printLL(lists[3]);

  /* node *result = mergeTwo(lists[0], lists[1]); */
  node *result = mergeK(lists, k);
  for (node *n = result; n; n = n->next)
    printf("%d ", n->data);
  printf("\n");
}
