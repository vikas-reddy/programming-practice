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

int max (int a, int b) {
  return (a > b) ? a : b;
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

void maxChainSize(node *r, int *lChain, int *rChain, int *maxChain) {
  if (r == NULL) {
    *lChain = *rChain = 0;
    return;
  }
  int ll, lr, rl, rr;
  ll = lr = rl = rr = 0;
  maxChainSize(r->left, &ll, &lr, maxChain);
  maxChainSize(r->right, &rl, &rr, maxChain);

  // setting the values for the current node
  *lChain = ll + 1;
  *rChain = rr + 1;

  // calculating the chain size of the current node
  // maximizing it too
  int size = ll + 1 + rr;
  *maxChain = max(*maxChain, size);

  /* printf("%d (%d)\n", r->data, size); */
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->left->left = newNode(8);
  root->left->left->right = newNode(9);
  root->left->right->right = newNode(10);
  root->left->right->right->right = newNode(11);
  root->left->right->right->right->right = newNode(12);
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

  int lChain = 0, rChain = 0, maxChain = 0;
  maxChainSize(root, &lChain, &rChain, &maxChain);
  cout << "Max chain size: " << maxChain << endl;
  return 0;
}
