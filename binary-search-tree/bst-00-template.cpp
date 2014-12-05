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

node* insert(node *root, int data) {
  if (root == NULL) {
    root = newNode(data);
  }
  else {
    if (data < root->data)
      root->left = insert(root->left, data);
    else
      root->right = insert(root->right, data);
  }
  return root;
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

int main(int argc, const char *argv[])
{
  int arr[] = {81, 7, 64, 59, 5, 92, 65, 36, 65, 34};
  int len = sizeof(arr)/sizeof(arr[0]);

  struct node *root = NULL;

  for (int i = 0; i < len; i++)
    root = insert(root, arr[i]);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  return 0;
}
