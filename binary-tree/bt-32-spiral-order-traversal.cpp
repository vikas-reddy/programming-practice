#include<iostream>
#include<stdlib.h>
#include<queue>
#include<stack>
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

void spiralOrderIterative (node *r) {
  if (r == NULL)
    return;

  node *n;
  stack<node*> fwd, bwd;
  fwd.push(r);

  while (!fwd.empty() || !bwd.empty()) {
    while (!fwd.empty()) {
      n = fwd.top();
      fwd.pop();

      printf("%d ", n->data);
      if (n->left) bwd.push(n->left);
      if (n->right) bwd.push(n->right);
    }
    while (!bwd.empty()) {
      n = bwd.top();
      bwd.pop();

      printf("%d ", n->data);
      if (n->right) fwd.push(n->right);
      if (n->left) fwd.push(n->left);
    }
  }
  printf("\n");
}

int height (node *r) {
  if (r == NULL)
    return 0;

  return max( height(r->left), height(r->right) ) + 1;
}

void spiralOrderRecUtil (node *r, int h, bool ltr) {
  if (r == NULL)
    return;

  if (h == 1) {
    printf("%d ", r->data);
    return;
  }

  if (ltr) {
    spiralOrderRecUtil(r->left, h - 1, ltr);
    spiralOrderRecUtil(r->right, h - 1, ltr);
  }
  else {
    spiralOrderRecUtil(r->right, h - 1, ltr);
    spiralOrderRecUtil(r->left, h - 1, ltr);
  }
}

void spiralOrderRec (node *r) {
  bool ltr = true;

  for (int h = 1; h <= height(r); h++) {
    spiralOrderRecUtil(r, h, ltr);
    ltr = ltr ? false : true;
  }
  printf("\n");
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

  spiralOrderIterative(root);

  spiralOrderRec(root);

  return 0;
}
