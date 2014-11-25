#include<iostream>
#include<queue>
#include<stdlib.h>
using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
  struct node *nextRight;
};

struct node *newNode(int data) {
  struct node *n = (struct node*)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->nextRight = NULL;
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

void levelOrder(node *r) {
  if (r == NULL) {
    return;
  }

  node *n;
  bool levelEnd = false;

  queue<node*> q;
  q.push(r);

  /* NULLs are level delimiters */
  q.push(NULL);

  while (!q.empty()) {
    if (q.front() == NULL) {
      levelEnd = true;
      q.pop();
      if (q.empty()) {
        // end of the tree
        break;
      }
    }

    n = q.front();
    q.pop();

    /* connecting the pointers */
    n->nextRight = q.front();

    if (levelEnd) {
      levelEnd = false;
      q.push(NULL);
    }

    if (n->left)
      q.push(n->left);
    if (n->right)
      q.push(n->right);
  }
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

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  levelOrder(root);

  node *n = root->left;
  while (n) {
    printf("%d ", n->data);
    n = n->nextRight;
  }
  printf("\n");
  return 0;
}
