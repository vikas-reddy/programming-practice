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
  n->next = NULL;
  if (*root) {
    node *t = *root;
    while (t->next)
      t = t->next;
    t->next = n;
  }
  else {
    *root = n;
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

int findLength(node *num) {
  int len = 0;
  while (num) {
    num = num->next;
    len++;
  }
  return len;
}

void multiplyPolynomials(node *num1, node *num2, node **res) {
  int len1 = findLength(num1);
  int len2 = findLength(num2);
  int resLen = len1 + len2 - 1;
  for (int i = 0; i < resLen; i++)
    insert(res, 0);

  // Multiply each element of num2 with the whole num1 list
  int i = 0;
  for (node *ptr2 = num2; ptr2; ptr2 = ptr2->next, i++) {

    // seeking the resultPtr
    node *resPtr = *res;
    for (int ct = 0; ct < i; ct++, resPtr = resPtr->next);

    int elem = ptr2->data;

    for (node *ptr1 = num1; ptr1; ptr1 = ptr1->next, resPtr = resPtr->next) {
      resPtr->data += elem * ptr1->data;
    }
  }
}

int main() {
  int arr1[] = {5, 0, 10, 6};
  int arr2[] = {1, 2, 4};
  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);

  // initializing an empty LL
  struct node *num1 = NULL, *num2 = NULL;

  for (int i = 0; i < len1; i++)
    insert(&num1, arr1[i]);

  for (int i = 0; i < len2; i++)
    insert(&num2, arr2[i]);

  printLL(num1);
  printLL(num2);

  node *res = NULL;
  multiplyPolynomials(num1, num2, &res);
  printLL(res);
}
