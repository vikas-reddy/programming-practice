#include<iostream>
#include<stdlib.h>
#include<stack>
#include<algorithm>
using namespace std;

struct node {
  int data;
  int level;
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

void swapChildren (node *r) {
  if (r == NULL)
    return;

  /* printf("rotate: %d \n", r->data); */
  node *temp = r->left;
  r->left = r->right;
  r->right = temp;
}

void rotate_recursive (node *r, int level) {
  if (r == NULL)
    return;

  if (level % 2)
    swapChildren(r);

  rotate_recursive(r->left, level + 1);
  rotate_recursive(r->right, level + 1);
}

void iterative_recursive (node *r) {
  int level = 0;
  stack<node*> s;
  node *n = r, *t;

  while (n) {
    n->level = ++level;
    s.push(n);
    n = n->left;
  }

  while (!s.empty()) {
    n = s.top();
    s.pop();

    level = n->level;
    t = n->right;
    while (t) {
      t->level = ++level;
      s.push(t);
      t = t->left;
    }

    if (n->level % 2)
      swapChildren(n);
  }
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* rotate_recursive(root, 1); */
  /* rotate_recursive(root, 1); */
  iterative_recursive(root);
  iterative_recursive(root);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  return 0;
}
