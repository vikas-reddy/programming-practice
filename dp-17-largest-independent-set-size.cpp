#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

struct node {
  int data;
  int lisSize;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->lisSize = 0;
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

/* There can be two cases here:
 * * r is part of the LIS --> a = 1 + sum of LIS sizes of grandchildren
 * * r is not a part of the LIS --> b = sum of LIS sizes of children
 * max of a and b
 */
int lisSize(node *r, int *numCalls) {
  if (r == NULL) return 0;
  (*numCalls)++;

  int a = (lisSize(r->left, numCalls) + lisSize(r->right, numCalls)); // if r is not part of the lis
  int b = 1; // if r is part of the lis
  if (r->left) {
    b += lisSize(r->left->left, numCalls) + lisSize(r->left->right, numCalls);
  }
  if (r->right) {
    b += lisSize(r->right->left, numCalls) + lisSize(r->right->right, numCalls);
  }
  return (a > b) ? a : b;
}

int lisSizeDP(node *r, int *numCalls) {
  // boundary conditions
  if (r == NULL) return 0;
  if (r->lisSize) return r->lisSize;

  (*numCalls)++;

  int a = 0, b = 1;
  a = lisSizeDP(r->left, numCalls) + lisSizeDP(r->right, numCalls);
  if (r->left) {
    b += lisSizeDP(r->left->left, numCalls) + lisSizeDP(r->left->right, numCalls);
  }
  if (r->right) {
    b += lisSizeDP(r->right->left, numCalls) + lisSizeDP(r->right->right, numCalls);
  }
  int lis = (a > b) ? a : b;
  r->lisSize = lis;
  return lis;
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

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  int numCalls = 0;
  cout << lisSize(root, &numCalls) << endl;
  cout << "Number of calls: " << numCalls << endl;

  numCalls = 0;
  cout << lisSizeDP(root, &numCalls) << endl;
  cout << "Number of calls: " << numCalls << endl;
  return 0;
}
