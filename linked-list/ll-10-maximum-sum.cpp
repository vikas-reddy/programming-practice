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

// Joins the list `l` at the end of `res`
void joinAtEnd(node **res, node *l) {
  if (!*res) {
    *res = l;
  }
  else {
    node *n = *res;
    while (n->next)
      n = n->next;
    n->next = l;
  }
}

// Frees the memory
void remove(node *l) {
  node *n;
  while (l) {
    n = l;
    l = l->next;
    free(n);
  }
}

void createMaxSumLL(node *l1, node *l2, node **res) {
  // nothing much to do if one list is empty
  if (l1 == NULL || l2 == NULL) {
    *res = l1 ? l1 : l2;
    return;
  }

  int sum1 = 0, sum2 = 0;
  node *n1 = l1, *n2 = l2, *t1, *t2;

  // traversing the elements in both the lists until we encounter an equal
  // element, or until we exhaust one of the lists
  while (n1 && n2 && n1->data != n2->data) {
    /* printf("%d %d\n", n1->data, n2->data); */
    if (n1->data < n2->data) {
      sum1 += n1->data;
      n1 = n1->next;
    }
    else {
      sum2 += n2->data;
      n2 = n2->next;
    }
  }

  // we exhausted a list
  // we simply add the non-empty list (or NULL) at the end of the result
  if (n1 == NULL || n2 == NULL) {
    joinAtEnd(res, n1 ? l1 : l2);
    return;
  }

  // we encountered a common element
  if (n1->data == n2->data) {
    // store the next pointers for recursion
    t1 = n1->next;
    t2 = n2->next;

    // Cutting the lists
    // we retain the one with longest sum and discard the shorter one
    n1->next = NULL;
    n2->next = NULL;

    if (sum1 > sum2) {
      joinAtEnd(res, l1);
      remove(l2);
    }
    else {
      joinAtEnd(res, l2);
      remove(l1);
    }
    createMaxSumLL(t1, t2, res);
  }
}

void createLLs(node **l1, node **l2) {
  int arr1[] = {511, 240, 120, 90, 30, 3, 1};
  int arr2[] = {249, 240, 125, 90, 32, 12, 3, 0};
  int len1 = sizeof(arr1)/sizeof(arr1[0]);
  int len2 = sizeof(arr2)/sizeof(arr2[0]);

  for (int i = 0; i < len1; i++)
    insert(l1, arr1[i]);
  for (int i = 0; i < len2; i++)
    insert(l2, arr2[i]);
}

int main() {
  struct node *l1 = NULL;
  struct node *l2 = NULL;

  createLLs(&l1, &l2);

  printLL(l1);
  printLL(l2);

  struct node *res = NULL;
  createMaxSumLL(l1, l2, &res);
  printLL(res);
}
