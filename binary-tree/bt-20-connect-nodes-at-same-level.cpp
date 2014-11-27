#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->nextRight = NULL;
  return n;
}

int depth (node *r) {
  if (r == NULL) {
    return 0;
  }
  return 1 + max(depth(r->left), depth(r->right));
}

void inOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
}

void preOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  printf("%d ", n->data);
  preOrder(n->left);
  preOrder(n->right);
}

void connectNodes(node *r, int d, node **next) {
  if (r == NULL || d == 0) {
    return;
  }
  if (d == 1) {
    r->nextRight = *next;
    *next = r;
  }
  else if (d > 1) {
    connectNodes(r->right, d-1, next);
    connectNodes(r->left, d-1, next);
  }
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->left->right->right = newNode(9);
  root->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->right = newNode(10);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* depth-wise join the nodes */
  int d = depth(root);
  node *next;
  for (int i = 1; i <= d; i++) {
    next = NULL;
    connectNodes(root, i, &next);
  }

  /* printing */
  for (node *n = root->left->left; n; n = n->nextRight) {
    printf("%d ", n->data);
  }
  printf("\n");
  return 0;
}
