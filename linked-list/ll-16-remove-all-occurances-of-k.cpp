#include<stdio.h>
#include<stdlib.h>
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

void freeNode (node *n) {
  printf("free(%d)\n", n->data);
  free(n);
}

// Remove all occurances of k
void removeK (node **root, int k) {
  node *n, *t;

  // remove ks from the beginning
  for (n = *root; n && n->data == k; ) {
    t = n;
    n = n->next;
    freeNode(t);
  }
  *root = n;

  // remove ks elsewhere
  for (n = *root; n->next; ) {
    if (n->next->data == k) {
      t = n->next;
      n->next = n->next->next;
      freeNode(t);
    }
    else {
      n = n->next;
    }
  }
}

int main() {
  int arr[] = {3, 3, 3, 2, 2, 1, 3, 0, 1, 3};
  int len = sizeof(arr)/sizeof(arr[0]);
  int i;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
  }
  printLL(root);

  removeK(&root, 12);
  printLL(root);
}
