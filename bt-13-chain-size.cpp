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

void longestChainSize(node *r, int *chainSize) {
  if (r == NULL) {
    return;
  }
  int leftChainSize = 0, rightChainSize = 0;
  int currChainSize = getChainSize(r);
  longestChainSize(r->left, &leftChainSize);
  longestChainSize(r->right, &rightChainSize);
  *chainSize = max(currChainSize, leftChainSize, rightChainSize);
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

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  int chainSize = 0;
  longestChainSize(root->left, &chainSize);
  cout << chainSize << endl;
  return 0;
}
