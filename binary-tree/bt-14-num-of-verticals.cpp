#include<iostream>
#include<stdlib.h>
using namespace std;

/*
 * Find the number of verticals
 * http://www.geeksforgeeks.org/amazon-interview-questions-set-146/
 */

void printArray(bool arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

int max (int a, int b) {
  return (a > b) ? a : b;
}

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

int getSize(node *r) {
  if (r == NULL) {
    return 0;
  }
  return 1 + getSize(r->left) + getSize(r->right);
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

void computeVerticals1(node *r, bool arr[], int size, int id) {
  if (r == NULL) {
    return;
  }
  arr[(id >= 0) ? id : size + 1 + id] = true;
  computeVerticals1(r->left, arr, size, id - 1);
  computeVerticals1(r->right, arr, size, id + 1);
}

void computeVerticals2(node *r, int *left, int *right, int id) {
  if (r == NULL) {
    return;
  }

  // maximize our extremes
  if (id > 0)
    *right = max(*right, id);
  else
    *left = max(*left, -1*id);

  computeVerticals2(r->left, left, right, id-1);
  computeVerticals2(r->right, left, right, id+1);
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(4);
  root->left->right->left = newNode(5);
  root->left->right->left->left = newNode(6);
  root->left->right->left->left->left = newNode(7);
  root->right = newNode(8);
  root->right->right = newNode(9);
  root->right->right->left = newNode(10);
  root->right->right->left->right = newNode(11);
  root->right->right->left->right->right = newNode(12);
  return root;
  /* struct node *root = newNode(1); */
  /* root->left = newNode(2); */
  /* root->left->left = newNode(4); */
  /* root->left->right = newNode(5); */
  /* root->left->right->left = newNode(8); */
  /* root->left->right->right = newNode(9); */
  /* root->right = newNode(3); */
  /* root->right->left = newNode(6); */
  /* root->right->right = newNode(7); */
  /* root->right->right->right = newNode(10); */
  /* return root; */
}

int main(int argc, const char *argv[]) {
  struct node *root = createTree();

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  /* Naive solution */
  /* int size = getSize(root); */
  /* // initializing the bool array */
  /* bool arr[2*size-1]; */
  /* for (int i = 0; i < 2*size-1; i++) */
  /*   arr[i] = false; */

  /* computeVerticals1(root, arr, size, 0); */
  /* printArray(arr, 2*size-1); */


  /* O(n) */
  int left = 0, right = 0;
  computeVerticals2(root, &left, &right, 0);
  cout << "Number of verticals: " << (root ? 1 : 0) + left + right << endl;
  return 0;
}
