#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iterator>

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

void inOrder(struct node *n, int depth, int hdist) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left, depth + 1, hdist - 1);
  printf("%d (%d, %d)\n", n->data, depth, hdist);
  inOrder(n->right, depth + 1, hdist + 1);
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

int main(int argc, const char *argv[])
{
  struct node *root = createTree();
  map<struct node*, int[2]> m;

  inOrder(root, 1, 0);
  printf("\n");

  return 0;
}
