#include<iostream>
#include<stdlib.h>
#include<cmath>
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

int reverse (int n, int bits) {
  int res = 0;
  for (int i = 0; i < bits; i++) {
    if (n & (1 << i)) {
      res |= (1 << (bits - i - 1));
    }
  }
  return res;
}

node *getNode (node *r, int num, int bits) {
  num = reverse(num, bits);
  for (int i = 0; i < bits; num >>= 1, i++) {
    r = (num & 1 ? r->right : r->left);
  }
  return r;
}

void traversal (node *r) {
  int height = 0;
  for (node *n = r; n; n = n->left, height++);

  if (height == 0)
    return;

  int level = height - 1;

  for (int level = height - 1; level > 0; level--) {
    int bits = level, last = pow(2, level);

    for (int i = 0, j = last-1; i < j; i++, j--) {
      cout << getNode(r, i, bits)->data << " ";
      cout << getNode(r, j, bits)->data << " ";
    }
  }
  cout << r->data << endl;
}

struct node *createTree() {
  struct node *r = newNode(15);
  r->right = newNode(14);
  r->left = newNode(13);
  r->right->right = newNode(12);
  r->right->left = newNode(11);
  r->left->right = newNode(10);
  r->left->left = newNode(9);
  r->right->right->right = newNode(8);
  r->right->right->left = newNode(7);
  r->right->left->right = newNode(6);
  r->right->left->left = newNode(5);
  r->left->right->right = newNode(4);
  r->left->right->left = newNode(3);
  r->left->left->right = newNode(2);
  r->left->left->left = newNode(1);
  return r;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  traversal(root);

  return 0;
}
