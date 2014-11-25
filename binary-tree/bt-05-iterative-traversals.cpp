#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<stack>

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

void preOrderT(struct node *root) {
  if (root == NULL) {
    return;
  }
  printf("%d ", root->data);
  preOrderT(root->left);
  preOrderT(root->right);
}

void inOrderT(struct node *root) {
  if (root == NULL) {
    return;
  }
  inOrderT(root->left);
  printf("%d ", root->data);
  inOrderT(root->right);
}

void insertLeftDesc(struct node *root, stack<node*> *s) {
  while (root) {
    (*s).push(root);
    root = root->left;
  }
}

void iterativeInOrderT1(struct node *root) {
  if (root == NULL) {
    return;
  }

  node *t;
  stack<node*> s;
  insertLeftDesc(root, &s);
  while (!s.empty()) {
    t = s.top();
    printf("%d ", t->data);
    s.pop();

    if (t->right) {
      insertLeftDesc(t->right, &s);
    }
  }
}

void iterativeInOrderT2(struct node *root) {
  if (root == NULL) {
    return;
  }
  node *n = root;
  stack<node*> s;

  while (n || !s.empty()) {
    while (n) {
      s.push(n);
      n = n->left;
    }
    n = s.top();
    s.pop();
    printf("%d ", n->data);
    n = n->right;
  }
}

void iterativePreOrderT2(struct node *root) {
  if (root == NULL) {
    return;
  }
  node *n = root;
  stack<node*> s;

  while (n || !s.empty()) {
    while (n) {
      printf("%d ", n->data);
      s.push(n);
      n = n->left;
    }
    n = s.top();
    s.pop();
    n = n->right;
  }
}

void insertLeftDescPrint(struct node *root, stack<node*> *s) {
  while (root) {
    printf("%d ", root->data);
    (*s).push(root);
    root = root->left;
  }
}

void iterativePreOrderT1(struct node *root) {
  if (root == NULL) {
    return;
  }
  node *t;
  stack<node*> s;
  insertLeftDescPrint(root, &s);
  while (!s.empty()) {
    t = s.top();
    s.pop();

    if (t->right) {
      insertLeftDescPrint(t->right, &s);
    }
  }
}

struct node *createTree() {
  struct node *root = newNode(60);
  root->left = newNode(32);
  root->left->left = newNode(15);
  root->left->right = newNode(56);
  root->left->left->right = newNode(28);
  root->right = newNode(70);
  root->right->right = newNode(83);
  root->right->right->left = newNode(75);
  root->right->right->left->right = newNode(81);
  root->right->right->right = newNode(94);
  return root;
}

int main(int argc, const char *argv[])
{
  // the original tree
  struct node *root = createTree();
  inOrderT(root); printf("\n");
  preOrderT(root); printf("\n");

  iterativeInOrderT1(root); printf("\n");
  iterativeInOrderT2(root); printf("\n");
  iterativePreOrderT1(root); printf("\n");
  iterativePreOrderT2(root); printf("\n");
  return 0;
}
