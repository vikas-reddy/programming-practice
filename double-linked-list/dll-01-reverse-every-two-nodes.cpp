#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
  int data;
  node *next, *prev;
};

void push (node **head, node **tail, int data) {
  node *n = (node *)malloc(sizeof(node));
  n->data = data;
  n->next = *head;
  n->prev = NULL;
  *head = n;
  if (*head == NULL) {
    *tail = n;
  }
}

void push_back (node **head, node **tail, int data) {
  node *n = (node*)malloc(sizeof(node));
  n->data = data;
  n->next = NULL;
  n->prev = *tail;

  if (*head == NULL) {
    *head = *tail = n;
  }
  else {
    (*tail)->next = n;
    *tail = n;
  }
}

int sizeLL (node *head) {
  int size = 0;
  node *n = head;
  for (size = 0; n; n = n->next, size++);
  return size;
}

void printLL(node *head) {
  if (head) {
    node *n = head;
    for (n = head; n; n = n->next) {
      printf("%d ", n->data);
    }
    printf("\n");
  }
}

void printLLRev (node *tail) {
  if (tail) {
    for (node *n = tail; n; n = n->prev)
      printf("%d ", n->data);
    printf("\n");
  }
}

void swapTwo (node **head, node **tail) {
  if (*head && (*head)->next) {
    node *a = *head, *b = a->next, *c = b->next;

    // recursion
    swapTwo(&c, tail);

    // current
    a->next = c;

    if (c)
      c->prev = a;
    else
      *tail = a;

    b->next = a;
    a->prev = b;
    b->prev = NULL;

    // setting the correct head pointer
    *head = b;
  }
}

int main() {
  int arr[] = {96, 7, 64, 50, 53, 89, 54, 6, 60};
  int len = sizeof(arr)/sizeof(arr[0]);

  // initializing an empty LL
  node *head = NULL, *tail = NULL;

  for (int i = 0; i < len; i++) {
    /* push (&head, arr[i]); */
    push_back (&head, &tail, arr[i]);
  }
  printLL(head);
  printLLRev(tail);

  swapTwo (&head, &tail);

  printLL(head);
  printLLRev(tail);
}
