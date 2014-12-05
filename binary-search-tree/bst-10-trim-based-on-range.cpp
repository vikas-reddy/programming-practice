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

void freeSubtree(node *root) {
  if (root == NULL)
    return;

  freeSubtree(root->left);
  freeSubtree(root->right);

  /* printf("%d ", root->data); */
  free(root);
}

node* trimTree(node *root, int min, int max) {
  if (root == NULL)
    return NULL;

  // If root is more than max, we discard its right subtree, and the root
  // itself. And propagate it's left subtree upwards the recursion tree
  if (root->data > max) {
    /* printf("freeSubtree %d->right\n", root->data); */
    freeSubtree(root->right);
    node *rl = root->left;
    free(root);

    rl = trimTree(rl, min, max);
    return rl;
  }
  else if (root->data < min) {
    /* printf("freeSubtree %d->left\n", root->data); */
    freeSubtree(root->left);
    node *rr = root->right;
    free(root);

    rr = trimTree(rr, min, max);
    return rr;
  }
  else {
    root->left = trimTree(root->left, min, max);
    root->right = trimTree(root->right, min, max);
    return root;
  }
}

int main(int argc, const char *argv[])
{
  if (argc < 3) {
    cout << "Needs min and max values as command-line args" << endl;
    return 1;
  }
  int min = atoi(argv[1]);
  int max = atoi(argv[2]);

  int arr[] = {8, 84, 37, 82, 55, 99, 16, 40, 78, 64};
  int len = sizeof(arr)/sizeof(arr[0]);

  struct node *root = NULL;

  for (int i = 0; i < len; i++)
    root = insert(root, arr[i]);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  root = trimTree(root, min, max);
  inOrder(root); printf("\n");
  preOrder(root); printf("\n");
  return 0;
}
