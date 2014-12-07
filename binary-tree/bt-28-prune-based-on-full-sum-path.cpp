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

node *pruneTree (node *root, int minSum, int sum) {
  if (root == NULL)
    return NULL;

  // prune `root` if it's a leaf
  if (root->left == NULL && root->right == NULL) {
    if (sum + root->data < minSum) {
      printf("Pruning leaf: %d\n", root->data);
      free (root);
      return NULL;
    }
  }

  root->left = pruneTree (root->left, minSum, sum + root->data);
  root->right = pruneTree (root->right, minSum, sum + root->data);

  // prune the root if it has become a leaf
  if (root->left == NULL && root->right == NULL) {
    if (sum + root->data < minSum) {
      printf("Pruning leaf: %d\n", root->data);
      free (root);
      return NULL;
    }
  }

  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  if (argc < 2) {
    cout << "minSum not given" << endl;
    return 1;
  }

  int minSum = atoi(argv[1]);
  root = pruneTree (root, minSum, 0);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  return 0;
}
