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

void convertToChildSum (node *r) {
  // Base case: do nothing!
  if (r == NULL ||
      r->left == NULL && r->right == NULL)
    return;

  convertToChildSum(r->left);
  convertToChildSum(r->right);

  r->data = (r->left ? r->left->data : 0) +
            (r->right ? r->right->data : 0);
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

struct node *createTree1() {
  struct node *r  = newNode(10);
  r->left         = newNode(8);
  r->right        = newNode(2);
  r->left->left   = newNode(3);
  r->left->right  = newNode(5);
  r->right->right = newNode(2);
  return r;
}

struct node *createTree2() {
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
  struct node *r1 = createTree1();

  inOrder(r1); printf("\n");
  preOrder(r1); printf("\n");

  /* Check for child-sum property */
  int sum = 0;
  cout << isChildSum1(r1, &sum) << endl;
  cout << isChildSum2(r1) << endl;

  node *r2 = createTree2();

  inOrder(r2); printf("\n");
  preOrder(r2); printf("\n");

  /* Convert a binary tree to a child-sum tree */
  convertToChildSum(r2);

  inOrder(r2); printf("\n");
  preOrder(r2); printf("\n");
  return 0;
}
