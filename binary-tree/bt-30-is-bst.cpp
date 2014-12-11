#include<iostream>
#include<stdlib.h>
#include<limits.h>
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
  struct node *root = newNode(10);
  root->left = newNode(5);
  root->left->left = newNode(1);
  root->left->right = newNode(7);
  root->left->right->left = newNode(6);
  root->left->right->right = newNode(9);
  root->right = newNode(20);
  root->right->left = newNode(15);
  root->right->right = newNode(25);
  root->right->right->right = newNode(30);
  return root;
}

/* Top-down bst check
 * Runs in preOrder fashion */
bool isBST1 (node *r, int min, int max) {
  if (r == NULL)
    return true;

  if (r->data < min || max < r->data)
    return false;

  return isBST1(r->left, min, r->data-1) &&
    isBST1(r->right, r->data+1, max);
}

/* Bottom-up bst check
 * Runs in post-order fashion */
bool isBST2 (node *r, int *min, int *max) {
  // Base case
  if (r == NULL)
    return true;

  // Left recursion
  int lmin = INT_MIN, lmax = INT_MAX;
  bool is_bst_l = isBST2 (r->left, &lmin, &lmax);

  if (is_bst_l == false)
    return false;

  // Right recursion
  int rmin = INT_MIN, rmax = INT_MAX;
  bool is_bst_r = isBST2 (r->right, &rmin, &rmax);

  if (is_bst_r == false)
    return false;

  // The root
  // If either child is empty, we need not check its value
  if ( (lmax == INT_MAX || lmax < r->data) &&
       (rmin == INT_MIN || r->data <= rmin) ) {

    // if we have a NULL to the left, min is current node
    *min = (lmin == INT_MIN ? r->data : lmin);

    // if we have a NULL to the right, max is current node
    *max = (rmax == INT_MAX ? r->data : rmax);
    return true;
  }

  return false;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  cout << "isBST1: " << isBST1(root, INT_MIN, INT_MAX) << endl;

  int min = INT_MIN, max = INT_MAX;
  cout << "isBST2: " << isBST2(root, &min, &max) << endl;
  cout << "min: " << min << " max: " << max << endl;
  return 0;
}
