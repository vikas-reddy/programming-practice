#include<iostream>
#include<stdlib.h>
#include<list>
#include<set>
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

int depth(struct node *root) {
  if (root == NULL) {
    return 0;
  }
  int dleft = depth(root->left);
  int dright = depth(root->right);
  return (dleft > dright ? dleft : dright) + 1;
}

struct node *findLca(struct node *r, int a, int b) {
  if (!r) {
    return NULL;
  }
  if (r->data == a || r->data == b) {
    return r;
  }
  struct node *left = findLca(r->left, a, b);
  struct node *right = findLca(r->right, a, b);
  if (left && right) {
    return r;
  }
  return (left ? left : right);
}

int depthOfNode(struct node *r, int data) {
  if (!r) {
    return 0;
  }
  if (r->data == data) {
    return 1;
  }
  int dl = depthOfNode(r->left, data);
  int dr = depthOfNode(r->right, data);
  if (dl || dr) {
    return dl + dr + 1;
  }
  else {
    return 0;
  }
}

int distBetweenNodes(struct node *root, int a, int b) {
  struct node *lca = findLca(root, a, b);
  return depthOfNode(lca, a) + depthOfNode(lca, b) - 2;
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

  cout << distBetweenNodes(root, 60, 81) << endl;
  return 0;
}
