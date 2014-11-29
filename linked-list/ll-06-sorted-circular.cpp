#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
  struct node *next;
  int data;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->next = NULL;
  return n;
}

void insert(struct node **root, int data) {
  struct node *n, *newElem = newNode(data);

  // empty list
  if (!*root) {
    newElem->next = newElem;
    *root = newElem;
  }

  // non-empty list
  else {
    // insertion at the beginning
    if (newElem->data < (*root)->data) {
      newElem->next = *root;
      for (n = *root; n->next != *root; n = n->next);
      n->next = newElem;
      *root = newElem;
    }

    // insertion elsewhere
    else {
      for (n = *root; n->next != *root; n = n->next) {
        if (n->data < newElem->data && newElem->data <= n->next->data) {
          break;
        }
      }
      newElem->next = n->next;
      n->next = newElem;
    }
  }
}

int sizeLL(struct node *root) {
  int size = 0;
  struct node *n = root;
  for (size = 0; n->next != root; n = n->next, size++);
  return size;
}

void printLL(struct node *root) {
  if (root) {
    struct node *n = root;
    do {
      printf("%d ", n->data);
      n = n->next;
    } while (n != root);
    printf("\n");
  }
}

int main() {
  int arr[10] = {10, 23, 92, 16, 24, 51, 8, 20, 66, 5};
  int len = 10, i;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
    printf("%d: ", arr[i]);
    printLL(root);
  }
}
