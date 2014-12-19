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

// O(n2)
int diameter1(struct node *r) {
  if (r == NULL) {
    return 0;
  }
  int depth_l = depth(r->left), depth_r = depth(r->right);
  int dia_l = diameter1(r->left), dia_r = diameter1(r->right);
  int x = depth_l + depth_r + 1;
  return max(x, max(dia_l, dia_r));
}

// O(n), works in post order fashion
// Returns the depth of the tree, but stores the [maximum] diameter in *dia
// reference
int diameter2 (node *r, int *dia) {
  if (r == NULL)
    return 0;

  int l_depth = diameter2(r->left, dia);
  int r_depth = diameter2(r->right, dia);

  int curr_dia = l_depth + r_depth + 1;
  int curr_depth = max(l_depth, r_depth) + 1;

  // Maximizing the diameter
  if (*dia < curr_dia)
    *dia = curr_dia;

  return curr_depth;
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

  inOrder(r1); printf("\n");
  inOrder(r2); printf("\n");

  printf("%d, %d\n", diameter1(r1), diameter1(r2));

  int dia1 = 0, dia2 = 0;
  diameter2(r1, &dia1), diameter2(r2, &dia2);
  printf("%d, %d\n", dia1, dia2);

  return 0;
}
