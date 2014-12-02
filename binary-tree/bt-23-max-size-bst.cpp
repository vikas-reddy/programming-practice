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

bool isBST(node *root, node **prev) {
  // base case
  if (root == NULL)
    return true;

  // left subtree
  if (isBST(root->left, prev) == false)
    return false;

  printf("%d -> %d\n", (*prev ? (*prev)->data : -1), root->data);
  if (!(*prev == NULL || (*prev)->data < root->data))
    return false;
  *prev = root;

  // right subtree
  if (isBST(root->right, prev) == false)
    return false;

  return true;
}

int maxSizeBST(node *root, node **prev, int *size) {
  // base case
  if (root == NULL)
    return 1;

  // left subtree
  if (maxSizeBST(root->left, prev, size) == 0)
    return 0;

  printf("%d -> %d\n", (*prev ? (*prev)->data : -1), root->data);
  if (!(*prev == NULL || (*prev)->data < root->data))
    return 0;
  (*size)++;
  *prev = root;

  // right subtree
  if (maxSizeBST(root->right, prev, size) == 0)
    return 0;

  return 1;
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(15);
  root->left->right->left = newNode(8);
  root->left->right->right = newNode(19);
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

  node *prev = NULL;
  cout << isBST(root, &prev) << endl;

  prev = NULL;
  int size = 0;
  maxSizeBST(root, &prev, &size);
  cout << "Max size BST: " << size << endl;

  return 0;
}
