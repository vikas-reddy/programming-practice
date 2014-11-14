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

struct node *findIntersectionBasic(struct node *r1, struct node *r2) {
  if (r1 == NULL || r2 == NULL) {
    return NULL;
  }
  for (struct node *n1 = r1; n1; n1 = n1->next) {
    for (struct node *n2 = r2; n2; n2 = n2->next) {
      if (n1 == n2) {
        return n1;
      }
    }
  }
  return NULL;
}

struct node *getCycleStartingPoint(struct node *r) {
  struct node *slow_p = r, *fast_p = r;
  while (slow_p && fast_p && fast_p->next) {
    slow_p = slow_p->next;
    fast_p = fast_p->next->next;
    if (slow_p == fast_p) {
      break;
    }
  }
  // if there is a cycle
  if (slow_p && fast_p && slow_p == fast_p) {
    struct node *cycle_p = slow_p;
    int cycle_size = 0;
    do {
      cycle_p = cycle_p->next;
      cycle_size++;
    } while (cycle_p != slow_p);
    /* printf("%d\n", cycle_size); */

    // first_p and second_p will be cycle_size distance apart, and they will
    // move one node by one node
    struct node *first_p = r, *second_p = r;
    for (int i = 0; i < cycle_size; i++, second_p = second_p->next);

    // go one node each step
    while (first_p != second_p) {
      first_p = first_p->next;
      second_p = second_p->next;
    }
    return first_p;
  }
  else {
    return NULL;
  }
}

struct node *findIntersection(struct node *r1, struct node *r2) {
  if (r1 == NULL || r2 == NULL) {
    return NULL;
  }
  // make r1 as a cycle
  struct node *n;
  for (n = r1; n->next; n = n->next);
  n->next = r1;

  return getCycleStartingPoint(r2);
}

int main() {
  int arr[10] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99};
  int len = 10, i;

  // initializing an empty LL
  struct node *r1 = NULL;

  for (i = 0; i < len; i++) {
    insert(&r1, arr[i]);
  }
  printLL(r1);

  // r1 and r2 intersect
  struct node *r2 = NULL;
  insert(&r2, 72);
  insert(&r2, 10);
  insert(&r2, 14);
  insert(&r2, 1);
  r2->next->next->next->next = r1->next->next->next;
  printLL(r2);

  // r1 and r3 do not
  struct node *r3 = NULL;
  insert(&r3, 23);
  insert(&r3, 25);
  insert(&r3, 27);
  insert(&r3, 37);
  printLL(r3);

  struct node *int12 = findIntersection(r1, r2);
  if (int12) {
    printf("Intersection at: %d\n", int12->data);
  }
  else {
    printf("No intersection\n");
  }
}
