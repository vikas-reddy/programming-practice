#include<iostream>
#include<queue>
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

void printLeftView(node *r) {
  if (r == NULL) {
    return;
  }
  node *n, *marker;
  bool endOfLevel = false;

  queue<node*> q;
  q.push(r);
  q.push(marker);

  // root is a "left view" node
  printf("%d ", r->data);

  while (!q.empty()) {
    // we hit a marker when we exhaust a level
    if (q.front() == marker) {

      endOfLevel = true;
      q.pop();

      // last level ends the loop
      if (q.empty()) {
        break;
      }
      else {
        // node after marker node is "left view"
        printf("%d ", q.front()->data);

        // node before marker node is "left view"
        /* printf("%d ", q.back()->data); */
      }
    }

    // next element
    n = q.front();
    q.pop();

    // re-inserting the marker for the next level
    if (endOfLevel) {
      q.push(marker);
      endOfLevel = false;
    }

    /* printf("%d ", n->data); */

    // insert the two children into the queue
    if (n->left)  q.push(n->left);
    if (n->right) q.push(n->right);
  }
  printf("\n");
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
  root->right->right->right->left = newNode(11);
  root->right->right->right->right = newNode(12);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root);
  printf("\n");
  preOrder(root);
  printf("\n");

  printLeftView(root);
  return 0;
}
