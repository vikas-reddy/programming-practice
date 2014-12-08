#include<iostream>
#include<stdlib.h>
#include<algorithm>
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

int depth (node *r) {
  if (r == NULL) {
    return 0;
  }
  return 1 + max(depth(r->left), depth(r->right));
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

void connectNodesAtDepth(node *r, int d, node **next) {
  if (r == NULL || d == 0) {
    return;
  }
  if (d == 1) {
    r->nextRight = *next;
    *next = r;
  }
  else if (d > 1) {
    connectNodesAtDepth(r->right, d-1, next);
    connectNodesAtDepth(r->left, d-1, next);
  }
}

/*
 *            1
 *         2     3
 *       4  5   6  7
 *         8 9       10
 *
 */
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

// Returns the nextRight of the next sibling of root
node *getNextRight (node *root) {
  if (root == NULL)
    return NULL;

  node *t = root->nextRight;
  while (t) {
    if (t->left)
      return t->left;
    if (t->right)
      return t->right;
    t = t->nextRight;
  }
  return NULL;
}

/* depth-wise join the nodes -- O(n2) */
void connectNodes1 (node *root) {
  int d = depth(root);
  node *next;
  for (int i = 1; i <= d; i++) {
    next = NULL;
    connectNodesAtDepth(root, i, &next);
  }
}

/* O(n) - iterative */
void connectNodes2 (node *root) {
  // Base case
  if (root == NULL)
    return;

  // `root`s case is simple
  root->nextRight = NULL;

  node *a = root, *b;

  while (a) {

    // go horizontally for each level
    b = a;
    while (b) {
      if (b->left) {
        if (b->right) {
          b->left->nextRight = b->right;
        }
        else {
          b->left->nextRight = getNextRight(b);
        }
      }
      if (b->right) {
        b->right->nextRight = getNextRight(b);
      }

      // proceed one step to the right
      b = b->nextRight;
    }

    // proceed to next level
    if (a->left)
      a = a->left;
    else if (a->right)
      a = a->right;
    else
      a = getNextRight(a);

  }
}

/* O(n) - recursive */
void connectNodes3 (node *root) {
  if (root == NULL)
    return;

  // connect the right portion via recursion
  connectNodes3 (root->nextRight);

  // Now all the connections are present towards our right
  if (root->left) {
    if (root->right) {
      root->left->nextRight = root->right;
      root->right->nextRight = getNextRight(root);
    }
    else {
      root->left->nextRight = getNextRight(root);
    }
    connectNodes3(root->left);
  }
  else if (root->right) {
    root->right->nextRight = getNextRight(root);
    connectNodes3(root->right);
  }
  else {
    connectNodes3(getNextRight(root));
  }
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* connectNodes1 (root); */
  /* connectNodes2 (root); */
  connectNodes3 (root);
  /* node *n = getNextRight (root->left->left); */
  /* printf("%d\n", n ? n->data : -1); */

  /* printing */
  for (node *n = root; n; n = n->nextRight)
    printf("%d ", n->data);
  printf("\n");

  for (node *n = root->left; n; n = n->nextRight)
    printf("%d ", n->data);
  printf("\n");

  for (node *n = root->left->left; n; n = n->nextRight)
    printf("%d ", n->data);
  printf("\n");

  for (node *n = root->left->right->left; n; n = n->nextRight)
    printf("%d ", n->data);
  printf("\n");

  return 0;
}
