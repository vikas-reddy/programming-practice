#include<iostream>
#include<stdlib.h>
#include<limits.h>
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

// Supposedly a O(n^2) solution
node *constructTree1(int arr[], int f, int l) {
  if (f > l)
    return NULL;

  // first is root
  node *n = newNode(arr[f]);

  if (f == l)
    return n;

  int i;
  for (i = f + 1; i < l; i++)
    if (arr[i] > arr[f])
      break;

  n->left = constructTree1(arr, f+1, i-1);
  n->right = constructTree1(arr, i, l);
  return n;
}

// O(n)
node *constructTree2(int arr[], int len, int min, int max, int *curr, int key) {
  /* printf("min: %d, key: %d, max: %d, *curr: %d\n", min, key, max, *curr); */
  // base case
  if (*curr >= len)
    return NULL;

  if (min < key && key < max) {
    node *n = newNode(key);
    (*curr)++;
    if (*curr < len) {
      n->left = constructTree2(arr, len, min, key, curr, arr[*curr]);
      n->right = constructTree2(arr, len, key, max, curr, arr[*curr]);
    }
    return n;
  }
  return NULL;
}

int main(int argc, const char *argv[])
{
  /* struct node *root = createTree(); */

  /* inOrder(root); printf("\n"); */
  /* preOrder(root); printf("\n"); */

  int arr[] = {10, 5, 1, 7, 40, 50};
  int len = sizeof(arr)/sizeof(arr[0]);

  /* node *r = constructTree1(arr, 0, len-1); */
  /* preOrder(r); printf("\n"); */

  int curr = 0;
  node *r = constructTree2(arr, len, INT_MIN, INT_MAX, &curr, arr[curr]);
  preOrder(r); printf("\n");

  return 0;
}
