#include<stdio.h>
#include<iostream>
#include<stdlib.h>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void modifiedInOrder(struct node *r, struct node **pred, struct node **succ, int *size) {
  if (r == NULL) {
    return;
  }

  modifiedInOrder(r->left, pred, succ, size);
  printf("r:%d pred:%d\n", r->data, (*pred ? (*pred)->data : -1));
  *pred = r;
  modifiedInOrder(r->right, pred, succ, size);
}

void sizeOfBST(struct node *r, int *s) {
  if (r == NULL) {
    return;
  }

  int size_l = 0, size_r = 0;
  sizeOfBST(r->left, &size_l);
  sizeOfBST(r->right, &size_r);

  struct node *pred, *succ;
  // find the inOrder predecessor and successors
  for (pred = r->left; pred && pred->right; pred = pred->right);
  for (succ = r->right; succ && succ->left; succ = succ->left);

  if ( (pred == NULL || pred->data < r->data) && (succ == NULL || succ->data >= r->data) ) {
    // maximize the current max found
    if (*s < size_l + size_r + 1) {
      *s = size_l + size_r + 1;
    }
  }
  else {
    // propagate the max size to the root
    *s = (size_l > size_r) ? size_l : size_r;
  }
}

void preOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  printf("%d ", n->data);
  preOrder(n->left);
  preOrder(n->right);
}

void inOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
}

struct node *createTree() {
  /* struct node *root = newNode(5); */
  /* root->left = newNode(2); */
  /* root->right = newNode(4); */
  /* root->left->left = newNode(1); */
  /* root->left->right = newNode(3); */
  /* return root; */

  struct node *r = newNode(50);
  r->left = newNode(30);
  r->left->left = newNode(5);
  r->left->right = newNode(20);
  r->right = newNode(60);
  r->right->left = newNode(45);
  r->right->right = newNode(70);
  r->right->right->left = newNode(65);
  r->right->right->right = newNode(80);
  return r;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  struct node *pred = NULL, *succ = NULL;
  int s = 0;
  sizeOfBST(root, &s);
  /* modifiedInOrder(root, &pred, &succ, &s); */
  printf("%d\n", s);
  return 0;
}
