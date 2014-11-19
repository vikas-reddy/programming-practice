#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

/*
 *
 * To find the length of the longest chain in the tree
 *
 * Chain of a node = 1 + length of left node series + right node series
 *
 *
 */

int max(int a, int b, int c) {
  int max_ab = (a > b) ? a : b;
  return (max_ab > c) ? max_ab : c;
}

struct node {
  int data;
  int lSeries, rSeries;
  struct node *left;
  struct node *right;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->lSeries = 0;
  n->rSeries = 0;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void populateAttrs(node *r, int *maxChain) {
  if (r == NULL) {
    return;
  }
  int leftMaxChain = 0, rightMaxChain = 0;
  if (r->left) {
    populateAttrs(r->left, &leftMaxChain);
    r->lSeries = r->left->lSeries + 1;
  }
  if (r->right) {
    populateAttrs(r->right, &rightMaxChain);
    r->rSeries = r->right->rSeries + 1;
  }
  *maxChain = max(r->lSeries + r->rSeries + 1, leftMaxChain, rightMaxChain);
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

void inOrderExtra(node *r) {
  if (r == NULL) {
    return;
  }
  inOrderExtra(r->left);
  printf("%d(%d,%d) ", r->data, r->lSeries, r->rSeries);
  inOrderExtra(r->right);
}

int getChainSize(node *r) {
  if (r == NULL) {
    return 0;
  }

  int lSeries = 0, rSeries = 0;
  node *n = r->left;
  while (n) {
    n = n->left;
    lSeries++;
  }
  n = r->right;
  while (n) {
    n = n->right;
    rSeries++;
  }
  return 1 + lSeries + rSeries;
}

void maxChainSize(node *r, int *chainSize) {
  if (r == NULL) {
    return;
  }
  int leftMax = 0, rightMax = 0;
  int currChainSize = getChainSize(r);
  maxChainSize(r->left, &leftMax);
  maxChainSize(r->right, &rightMax);
  *chainSize = max(currChainSize, leftMax, rightMax);
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* O(n) solution: populate the lSeries and rSeries attributes in bottom-up
   * fashion, and use them to compute max chain sizes later, or in the same
   * iteration */
  int maxChain = 0;
  populateAttrs(root, &maxChain);
  inOrderExtra(root);
  printf("\n");
  printf("max chain size: %d\n", maxChain);


  /* This one supposedly takes O(n^2) */
  int chainSize = 0, count = 0;
  maxChainSize(root, &chainSize);
  cout << "max chain size: " << chainSize << endl;
  return 0;
}
