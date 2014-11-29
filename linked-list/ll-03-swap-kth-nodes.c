#include<stdio.h>
#include<stdlib.h>

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

void swapNodes(struct node **root, int k) {
  int size = sizeLL(*root);
  int f, l;
  if (k <= 0 || k > size) {
    printf("Invalid k!\n");
    return;
  }
  if (k <= size/2) {
    f = k;
    l = size - k + 1;
  }
  else {
    f = size - k + 1;
    l = k;
  }

  // f is always <= l
  struct node *n1, *n1_prev, *n2, *n2_prev, *temp;
  int i;

  // seeking the pointers to n1
  n1 = *root;
  n1_prev = NULL;
  for (i = 1; i < f && n1; i++) {
    n1_prev = n1;
    n1 = n1->next;
  }

  // seeking the pointers to n2
  n2 = *root;
  n2_prev = NULL;
  for (i = 1; i < l && n2; i++) {
    n2_prev = n2;
    n2 = n2->next;
  }

  // do this only for non-root n1
  if (n1_prev) {
    n1_prev->next = n2;
  }
  else {
    (*root) = n2;
  }
  n2_prev->next = n1;
  temp = n1->next;
  n1->next = n2->next;
  n2->next = temp;
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

int main() {
  int arr[10] = {96, 7, 64, 50, 53, 89, 54, 6, 60, 99};
  int len = 9, i = 0;

  // initializing an empty LL
  struct node *root = NULL;

  for (i = 0; i < len; i++) {
    insert(&root, arr[i]);
  }
  printf("original list:\n");
  printLL(root);

  for (i = 0; i < 12; i++) {
    printf("%d\n", i);
    printLL(root);
    swapNodes(&root, i);
    printLL(root);
    printf("\n\n");
  }
}
