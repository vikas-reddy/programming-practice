#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

/* Given a binary tree, where cost of travelling to the left child is ‘1’ and
 * same for the right child is ‘2’. Now, given the root of the tree and a value
 * ‘k’, find the total number of nodes that are at a distance/cost of ‘k’ from
 * the root.
 */
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

void numNodesAtK(node *root, int *count, int k, int cost) {
  if (root == NULL)
    return;
  if (cost == k) {
    (*count)++;
  }
  else if (cost < k) {
    numNodesAtK(root->left, count, k, cost + 1);
    numNodesAtK(root->right, count, k, cost + 2);
  }
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  int k = 1;
  int count = 0;
  numNodesAtK(root, &count, k, 0);
  printf("Num of nodes at %d distance: %d\n", k, count);

  return 0;
}
