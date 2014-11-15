#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// if any three consecutive points lie on same horizontal or vertical line, we
// had to remove the middle node
// (1,2) (2,3) (2,4) (2,5) (3,4)
// becomes
// (1,2) (2,3) (2,5) (3,4)

struct node {
  int x, y;
  struct node *next;
};

void insert(struct node **root, int x, int y) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->x = x;
  n->y = y;
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
      printf("(%d, %d) ", n->x, n->y);
    }
    printf("\n");
  }
}

struct node* createLL() {
  struct node *root = NULL;
  insert(&root, 3, 4);
  insert(&root, 4, 6);
  insert(&root, 3, 6);
  insert(&root, 2, 6);
  insert(&root, 2, 5);
  insert(&root, 2, 4);
  insert(&root, 2, 3);
  insert(&root, 1, 2);
  return root;
}

bool onALine(struct node *a, struct node *b, struct node *c) {
  /* printf("a:(%d,%d) b:(%d,%d) c:(%d,%d)\n", (a ? a->x : -1), (a ? a->y : -1), (b ? b->x : -1), (b ? b->y : -1), (c ? c->x : -1), (c ? c->y : -1)); */
  return ( (a->x == b->x && b->x == c->x) || (a->y == b->y && b->y == c->y) );
}

void remove (struct node *r) {
  if (r == NULL) {
    return;
  }
  if (r->next && r->next->next) {
    if (onALine(r, r->next, r->next->next)) {
      r->next = r->next->next;
      remove(r);
    }
    else {
      remove(r->next);
    }
  }
}

int main() {
  struct node *root = createLL();
  printLL(root);

  remove(root);
  printLL(root);

}
