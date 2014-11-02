#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
  int isThreaded;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->isThreaded = 0;
  return n;
}

void preOrderT(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preOrderT(root->left);
  preOrderT(root->right);
}

void inOrderT(struct node *root) {
  if (root == NULL) {
    return;
  }
  inOrderT(root->left);
  printf("%d ", root->data);
  inOrderT(root->right);
}

void printThreadedTree(struct node *root) {
  while (root) {
    while (root->left) {
      root = root->left;
    }
    printf("%d ", root->data);
    root = root->right;
  }
  printf("\n");
}

void makeThreaded(struct node *root, struct node **pred) {
  if (root == NULL) {
    return;
  }
  makeThreaded(root->left, pred);
  if (*pred) {
    (*pred)->right = root;
    (*pred)->isThreaded = 1;
    *pred = NULL;
  }
  if (root->right == NULL) {
    *pred = root;
  }
  makeThreaded(root->right, pred);
}

struct node *createTree() {
  struct node *root = newNode(60);
  root->left = newNode(32);
  root->left->left = newNode(15);
  root->left->right = newNode(56);
  root->left->left->right = newNode(28);
  root->right = newNode(70);
  root->right->right = newNode(83);
  root->right->right->left = newNode(75);
  root->right->right->left->right = newNode(81);
  root->right->right->right = newNode(94);
  return root;
}

int main(int argc, const char *argv[])
{
  // the original tree
  struct node *root = createTree();
  inOrderT(root); printf("\n");
  preOrderT(root); printf("\n");

  struct node *pred = NULL;
  makeThreaded(root, &pred);
  printf("%d:%d\n", root->left->left->right->right->data, root->left->left->right->isThreaded);
  printf("%d:%d\n", root->left->right->right->data, root->left->right->isThreaded);
  printf("%d:%d\n", root->right->right->left->right->right->data, root->right->right->left->right->isThreaded);
  /* printThreadedTree(root); */
  return 0;
}
