#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

struct node {
  struct node *next;
  int data;
};

// insert at the beginning
void insert(node **root, int elem) {
  node *newN = (node *)malloc(sizeof(node));
  newN->data = elem;
  newN->next = *root;
  *root = newN;
}

// insert at the end -- O(n)
void insertAtEnd(struct node **root, int elem) {
  struct node *newN = (struct node *)malloc(sizeof(struct node));
  newN->data = elem;
  newN->next = NULL;
  if (!*root) {
    *root = newN;
  }
  else {
    node *n = *root;
    while (n->next)
      n = n->next;
    n->next = newN;
  }
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

int findLength(node *n) {
  int len = 0;
  for (len = 0; n; n = n->next, len++);
  return len;
}

// LSD first
void addNumbers1(node *num1, node *num2, node **res) {
  if (num1 == NULL && num2 == NULL)
    return;

  int sum = 0, rem = 0;
  while (num1 || num2) {
    sum = rem + (num1 ? num1->data : 0) + (num2 ? num2->data : 0);
    rem = sum / 10;
    insertAtEnd(res, sum % 10);
    if (num1)
      num1 = num1->next;
    if (num2)
      num2 = num2->next;
  }
  if (rem) {
    insertAtEnd(res, rem);
  }
}

void addEqualLengthNums(node *num1, node *num2, node **res, int *rem) {
  if (num1 == NULL || num2 == NULL)
    return;

  addEqualLengthNums(num1->next, num2->next, res, rem);

  int sum = (*rem + num1->data + num2->data);
  insert(res, sum % 10);
  *rem = sum / 10;
}

void copyRemaining(node *num, node **res, int *rem, int count) {
  if (count == 0)
    return;

  copyRemaining(num->next, res, rem, count - 1);

  int sum = (*rem + num->data);
  insert(res, sum % 10);
  *rem = sum / 10;
}

/* Add numbers when MSDs are at the beginning
 * * add equal length lists first
 * * carry over the remainder and copy over the remaining numbers
 */
void addNumbers2(node *num1, node *num2, node **res) {
  if (num1 && num2) {
    int len1 = findLength(num1);
    int len2 = findLength(num2);
    node *n;
    int rem = 0;

    if (len1 < len2) {
      n = num2;
      for (int i = 0; i < len2 - len1; i++, n = n->next);
      addEqualLengthNums(num1, n, res, &rem);
      copyRemaining(num2, res, &rem, len2 - len1);
    }
    else { // len1 > len2
      n = num1;
      for (int i = 0; i < len1 - len2; i++, n = n->next);
      addEqualLengthNums(n, num2, res, &rem);
      copyRemaining(num1, res, &rem, len1 - len2);
    }

    // the remainder, if present, should create a new node
    if (rem)
      insert(res, rem);
  }
}

int main() {
  /* int arr1[] = {9, 9, 3, 9, 4}; */
  /* int arr2[] = {4, 9, 7}; */
  int arr1[] = {9, 8, 7, 6, 9};
  int arr2[] = {5, 8, 6, 9, 3};
  /* int arr1[] = {9, 9, 9, 9}; */
  /* int arr2[] = {9, 9, 9}; */
  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);
  int i;

  node *num1 = NULL, *num2 = NULL;

  for (int i = 0; i < len1; i++)
    insertAtEnd(&num1, arr1[i]);
  for (int i = 0; i < len2; i++)
    insertAtEnd(&num2, arr2[i]);

  // printing the numbers
  printLL(num1);
  printLL(num2);

  /* node *res = NULL; */
  /* int rem = 0; */
  /* addNumbers1(num1, num2, &res); */

  node *res = NULL;
  addNumbers2(num1, num2, &res);
  printLL(res);
}
