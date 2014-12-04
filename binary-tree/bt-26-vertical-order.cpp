#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

/*
 *
 *        1
 *      /    \
 *     2      3
 *    / \    / \
 *   4   5  6   7
 *           \   \
 *            8   9
 *
 *
 *   4
 *   2
 *   1 5 6
 *   3 8
 *   7
 *   9
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

void computeExtremes(node *r, int *left, int *right, int idx) {
  if (r == NULL)
    return;
  if (idx < 0)
    *left = max(*left, -1*idx);
  else
    *right = max(*right, idx);

  computeExtremes(r->left, left, right, idx - 1);
  computeExtremes(r->right, left, right, idx + 1);
}

void printVertical(node *r, int idx, int l) {
  if (r == NULL)
    return;
  if (l == idx) {
    printf("%d ", r->data);
  }
  printVertical(r->left, idx - 1, l);
  printVertical(r->right, idx + 1, l);
}

void verticalOrder(node *r) {
  int left = 0, right = 0;
  computeExtremes(r, &left, &right, 0);
  /* cout << left << " " << right << endl; */

  for (int i = -1*left; i <= right; i++) {
    printVertical(r, 0, i);
    printf("\n");
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

  verticalOrder(root);
  return 0;
}
