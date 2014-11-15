#include<stdio.h>
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

void preOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  printf("%d ", n->data);
  preOrder(n->left);
  preOrder(n->right);
}

void inOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
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

struct node *create_binary_tree(int arr[], int f, int l) {
  if (f > l) {
    return NULL;
  }
  int m = (f + l)/2;
  node *r = newNode(arr[m]);
  if (f == l) {
    return r;
  }
  r->left = create_binary_tree(arr, f, m - 1);
  r->right = create_binary_tree(arr, m + 1, l);
  return r;
}

struct node *binary_tree(int arr[], int len) {
  return create_binary_tree(arr, 0, len - 1);
}

int main(int argc, const char *argv[])
{
  /* int arr[] = {1, 16, 21, 31, 32, 33, 44, 64, 67, 94}; */
  int arr[] = {31, 42, 47, 47, 48, 79, 83, 89, 93, 98};
  int len = 10;
  struct node *root = binary_tree(arr, len);

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  return 0;
}
