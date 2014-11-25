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

int generateSumTree(node *r) {
  if (r == NULL) {
    return 0;
  }
  int ltree = generateSumTree(r->left);
  int rtree = generateSumTree(r->right);
  int temp = r->data;
  r->data = ltree + rtree;
  return temp + r->data;
}

struct node *createTree() {
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

  node *root = newNode(10);
  root->left = newNode(-2);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right = newNode(6);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  generateSumTree(root);

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  return 0;
}
