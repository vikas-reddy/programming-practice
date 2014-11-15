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

int max(int a, int b) {
  return (a >= b) ? a : b;
}

void inOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
}

int depth (struct node *r) {
  if (r == NULL) {
    return 0;
  }
  return 1 + max(depth(r->left), depth(r->right));
}

int diameter(struct node *r) {
  if (r == NULL) {
    return 0;
  }
  int depth_l = depth(r->left), depth_r = depth(r->right);
  int dia_l = diameter(r->left), dia_r = diameter(r->right);
  int x = depth_l + depth_r + 1;
  return max(x, max(dia_l, dia_r));
}

void createTrees(struct node **r1, struct node **r2) {
  (*r1) = newNode(1);
  (*r1)->left = newNode(2);
  (*r1)->left->left = newNode(4);
  (*r1)->left->right = newNode(5);
  (*r1)->left->right->left = newNode(6);
  (*r1)->left->right->right = newNode(7);
  (*r1)->right = newNode(3);
  (*r1)->right->right = newNode(8);
  (*r1)->right->right->right = newNode(9);
  (*r1)->right->right->right->right = newNode(11);
  (*r1)->right->right->right->left = newNode(10);
  (*r1)->right->right->right->left->left = newNode(12);
  (*r1)->right->right->right->left->right = newNode(13);

  (*r2) = newNode(1);
  (*r2)->left = newNode(2);
  (*r2)->left->left = newNode(5);
  (*r2)->left->right = newNode(6);
  (*r2)->left->right->right = newNode(12);
  (*r2)->left->right->right->left = newNode(13);
  (*r2)->left->right->right->right = newNode(14);
  (*r2)->left->right->right->right->right = newNode(15);
  (*r2)->left->left->left = newNode(7);
  (*r2)->left->left->right = newNode(8);
  (*r2)->left->left->right->left = newNode(9);
  (*r2)->left->left->right->left->left = newNode(10);
  (*r2)->left->left->right->left->right = newNode(11);
  (*r2)->right = newNode(3);
  (*r2)->right->right = newNode(4);
}

int main(int argc, const char *argv[])
{
  struct node *r1 = NULL, *r2 = NULL;
  createTrees(&r1, &r2);

  inOrder(r1);
  printf("\n");
  inOrder(r2);
  printf("\n");

  printf("%d, %d\n", diameter(r1), diameter(r2));
  return 0;
}
