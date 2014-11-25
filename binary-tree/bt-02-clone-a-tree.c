#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *random;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->random = NULL;
  return n;
}

void inOrder(struct node *root) {
  if (root == NULL) {
    return;
  }
  inOrder(root->left);
  printf("%d ", root->data);
  inOrder(root->right);
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

struct node *cloneTree(struct node *root) {
  if (root == NULL) {
    return NULL;
  }
  struct node *clonedRoot = newNode(root->data);
  clonedRoot->left = cloneTree(root->left);
  clonedRoot->right = cloneTree(root->right);
  return clonedRoot;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();
  inOrder(root);
  printf("\n");

  struct node *root2 = cloneTree(root);
  root2->left->data = 100;
  inOrder(root2);
  printf("\n");
  return 0;
}
