#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

/* Sort a stack with O(1) extra space */

struct node {
  int data;
  node *next;
};

node *newNode (int data) {
  node *n = (node *)malloc(sizeof(node));
  n->data = data;
  n->next = NULL;
  return n;
}

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

// Inserts an element into the sorted stack/LL
node *insert (node *head, node *n) {
  // base case
  if (head == NULL || head->data > n->data) {
    n->next = head;
    return n;
  }

  // recursion
  head->next = insert(head->next, n);
  return head;
}

// Sort a stack
node *sort (node *head) {
  if (head == NULL || head->next == NULL)
    return head;

  head->next = sort(head->next);
  return insert(head->next, head);
}


int main (int argc, char* argv[]) {
  int arr[] = {59, 46, 31, 82, 26, 56, 92, 55, 75, 60, 54, 65, 87, 25, 24, 75, 72, 15, 97, 38};
  int len = sizeof(arr)/sizeof(arr[0]);

  // initializing an empty LL
  node *head = NULL, *tail = NULL;

  for (int i = 0; i < len; i++) {
    /* push (&head, arr[i]); */
    push_back (&head, &tail, arr[i]);
  }
  printLL(head);

  head = sort(head);

  printLL(head);
}
