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

void createDLL(node *root, node **pre, node **dll) {
  if (root == NULL)
    return;
  createDLL(root->left, pre, dll);

  /* printf("%d - %d\n", (*pre ? (*pre)->data : -1), root->data); */
  if (*pre == NULL) {
    *dll = root;
  }
  else {
    (*pre)->right = root;
    root->left = *pre;
  }
  *pre = root;

  createDLL(root->right, pre, dll);
}

int main(int argc, const char *argv[])
{
  int arr[] = {8, 84, 37, 82, 55, 99, 16, 40, 78, 64};
  int len = sizeof(arr)/sizeof(arr[0]);

  struct node *root = NULL;

  for (int i = 0; i < len; i++)
    root = insert(root, arr[i]);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  node *pre = NULL;
  node *dll = NULL;
  createDLL(root, &pre, &dll);

  node *n;

  // printing the DLL
  for (n = dll; n; n = n->right)
    printf("%d ", n->data);
  printf("\n");

  // printing the DLL in reverse
  for (n = dll; n->right; n = n->right);
  for (  ; n; n = n->left)
    printf("%d ", n->data);
  printf("\n");

  return 0;
}
