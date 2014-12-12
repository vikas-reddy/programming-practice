#include<iostream>
#include<stdlib.h>

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

void printLL(node *head, node *tail) {
  if (head) {
    for (node *n = head; n; n = n->next)
      printf("%d ", n->data);
    printf("\n");
  }
  if (tail) {
    for (node *n = tail; n; n = n->prev)
      printf("%d ", n->data);
    printf("\n");
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
  printLL(head, tail);
}
