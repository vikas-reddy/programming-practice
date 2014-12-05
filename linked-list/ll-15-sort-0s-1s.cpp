#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
  struct node *next;
  bool data;
};

void insert(struct node **root, bool elem) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = elem;
  n->next = *root;
  *root = n;
  return;
}

void insertNode(node **root, node *n) {
  if (n == NULL)
    return;
  n->next = *root;
  *root = n;
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

void sortLLUtil(node *root, node **zero, node **one) {
  if (root == NULL)
    return;
  node *n = root;
  root = root->next;

  // insert nodes into coorect lists
  insertNode( (n->data ? one : zero), n );

  // recurse
  sortLLUtil(root, zero, one);
}

void sortLL(node **root) {
  if (*root == NULL)
    return;

  // LL holding all 0s
  node *zero = NULL;

  // LL holding all 1s
  node *one = NULL;

  sortLLUtil(*root, &zero, &one);

  // join the zero and one lists
  if (zero == NULL) {
    *root = one;
  }
  else {
    node *n;
    for (n = zero; n->next; n = n->next);
    n->next = one;
    *root = zero;
  }
}

int main() {
  bool arr[10] = {1, 0, 1, 1, 0, 0, 1, 1, 0, 1};
  int len = 10, i;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
  }
  printLL(root);

  sortLL(&root);

  printLL(root);
}
