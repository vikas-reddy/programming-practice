#include<iostream>
#include<stdlib.h>
#include<algorithm>
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

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
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

struct node *createTree() {
  struct node *r  = newNode(10);
  r->left         = newNode(8);
  r->right        = newNode(2);
  r->left->left   = newNode(3);
  r->left->right  = newNode(5);
  r->right->right = newNode(2);
  return r;
}

bool isChildSum1 (node *r, int *sum) {
  if (r == NULL)
    return true;

  int lsum = 0, rsum = 0;

  if (!isChildSum1(r->left, &lsum))
    return false;

  if (!isChildSum1(r->right, &rsum))
    return false;

  if (!r->left && !r->right)
    *sum = r->data;
  else
    *sum = lsum + rsum;

  return (r->data == *sum);
}

bool isChildSum2 (node *r) {
  if (r == NULL || r->left == NULL && r->right == NULL)
    return true;

  int lsum = 0, rsum = 0;

  if (r->left)
    lsum = r->left->data;
  if (r->right)
    rsum = r->right->data;

  return (
      (r->data == lsum + rsum) &&
      isChildSum2(r->left) &&
      isChildSum2(r->right)
      );
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  int sum = 0;
  cout << isChildSum1(root, &sum) << endl;
  cout << isChildSum2(root) << endl;

  return 0;
}
