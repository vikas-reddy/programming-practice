#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
  int data;
  node *next;
};

void push (node **head, int elem) {
  node *n = (node *)malloc(sizeof(node));
  n->data = elem;
  n->next = *head;
  (*head) = n;
  return;
}

void push_back (node **head, node **tail, int elem) {
  node *n = (node*)malloc(sizeof(node));
  n->data = elem;
  n->next = NULL;

  if (*head == NULL) {
    *head = *tail = n;
  }
  else {
    (*tail)->next = n;
    *tail = n;
  }
}

void insert (node **head, int elem) {
  node *n = new node;
  n->data = elem;

  if (!*head) {
    n->next = n;
    *head = n;
  }
  else {
    node *temp = *head;

    // We either find a valid interval, or insert 'elem' at the end of the
    // sorted cycle if it fits in there
    do {
      if ((temp->data < elem && temp->next->data > elem) || // valid interval
          (temp->next->data < temp->data && (temp->data < elem ||
                                             temp->next->data > elem))) // end of the sorted cycle
        break;
      temp = temp->next;
    } while (temp != *head);

    n->next = temp->next;
    temp->next = n;
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

    do {
      printf("%d ", n->data);
      n = n->next;
    } while (n && n != head);

    printf("\n");
  }
}

int main(int argc, char *argv[]) {
  int arr[] = {10, 20, 30, 40, 50, 60, 70, 80};
  int len = sizeof(arr)/sizeof(arr[0]);

  // initializing an empty LL
  node *head = NULL, *tail = NULL;

  for (int i = 0; i < len; i++) {
    /* push (&head, arr[i]); */
    push_back (&head, &tail, arr[i]);
  }

  // Rotate and make it circular
  tail->next = head;
  head = head->next->next->next;
  printLL(head);

  if (argc < 2)
    return 1;

  int elem = atoi(argv[1]);
  insert(&head, elem);

  printLL(head);
}
