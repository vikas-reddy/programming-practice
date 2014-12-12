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

void findKth (node *head, unsigned k, int *curr, int *elem) {
  // base case
  if (head == NULL) {
    *curr = 0;
    return;
  }

  // recursion first
  findKth (head->next, k, curr, elem);

  // increment the curr index (idx from last)
  (*curr)++;

  // setting `elem` when we encounter kth element
  if (*curr == k) {
    *elem = head->data;
  }
}

int main(int argc, char* argv[]) {
  int arr[] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99};
  int len = sizeof(arr)/sizeof(arr[0]);

  // initializing an empty LL
  node *head = NULL, *tail = NULL;

  for (int i = 0; i < len; i++) {
    push (&head, arr[i]);
    /* push_back (&head, &tail, arr[i]); */
  }
  printLL(head);

  if (argc < 2)
    return 1;

  unsigned k = atoi(argv[1]);
  int curr, elem;
  findKth (head, k, &curr, &elem);
  printf("%dth element = %d\n", k, (curr >= k ? elem : -1));
}
