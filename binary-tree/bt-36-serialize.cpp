#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<fstream>

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

void serialize (node *r, ostream &fs) {
  if (r == NULL) {
    fs << -1 << " ";
    return;
  }

  fs << r->data << " ";
  serialize(r->left, fs);
  serialize(r->right, fs);
}

node *deserialize (istream &is) {
  if (is.eof())
    return NULL;

  int num;
  is >> num;

  if (num == -1)
    return NULL;

  node *n = newNode(num);
  n->left = deserialize(is);
  n->right = deserialize(is);
  return n;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  ofstream ofs("tree.txt");
  serialize(root, ofs);
  ofs.close();

  ifstream ifs("tree.txt");
  node *r2 = deserialize(ifs);
  ifs.close();

  inOrder(r2); printf("\n");
  preOrder(r2); printf("\n");

  return 0;
}
