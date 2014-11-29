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

int main() {
  int arr[10] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99};
  int len = 10, i;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
  }
  printLL(root);
}
