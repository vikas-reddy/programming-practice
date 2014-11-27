#include<iostream>
#include<stdlib.h>
using namespace std;

/*
 *
 * To construct the "greater value tree" of a BST
 *
 * http://www.geeksforgeeks.org/add-greater-values-every-node-given-bst/
 *
 */

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

void greaterValueTree(node *r, int *val) {
  if (r == NULL) {
    return;
  }
  greaterValueTree(r->right, val);

  // getting greater value from the right
  r->data += *val;
  *val = r->data;

  greaterValueTree(r->left, val);
}

struct node *createTree() {
  struct node *r = newNode(50);
  r->left = newNode(30);
  r->left->left = newNode(20);
  r->left->right = newNode(40);
  r->right = newNode(70);
  r->right->left = newNode(60);
  r->right->right = newNode(80);
  return r;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  int val = 0;
  greaterValueTree(root, &val);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  return 0;
}
