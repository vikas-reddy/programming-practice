#include<iostream>
#include<stdlib.h>
#include<limits.h>
#include<algorithm>
using namespace std;

/* look at bt-11 */

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

bool isBST(node *root, node **prev) {
  // base case
  if (root == NULL)
    return true;

  // left subtree
  if (isBST(root->left, prev) == false)
    return false;

  printf("%d -> %d\n", (*prev ? (*prev)->data : -1), root->data);
  if (!(*prev == NULL || (*prev)->data < root->data))
    return false;
  *prev = root;

  // right subtree
  if (isBST(root->right, prev) == false)
    return false;

  return true;
}

// This one probably takes O(n2)
int maxSizeBST1(node *root, int *maxSize) {
  // base case
  if (root == NULL)
    return 0;

  // all leaves are BSTs
  if (root->left == NULL && root->right == NULL) {
    *maxSize = max(*maxSize, 1);
    return 1;
  }

  int lSize = maxSizeBST1(root->left, maxSize);
  int rSize = maxSizeBST1(root->right, maxSize);

  // If one of the subtrees is not a BST, then the subtree with root as `root`
  // is also not a BST
  if (lSize == -1 || rSize == -1) {
    return -1;
  }

  /* printf("%d lSize: %d, rSize: %d\n", root->data, lSize, rSize); */

  // The predecessor of `root`
  node *pred = root->left;
  while (pred && pred->right)
    pred = pred->right;

  // The successor of `root`
  node *succ = root->right;
  while (succ && succ->left)
    succ = succ->left;

  // the actual BST check for `root`
  if ( (pred == NULL || pred->data < root->data) &&
       (succ == NULL || succ->data >= root->data) ) {
    *maxSize = max(*maxSize, lSize + rSize + 1);
  }

  // Not a BST;
  return -1;
}

int maxSizeBST2 (node *root, int *min_ref, int *max_ref, int *maxSize) {
  // base case 1: NULL
  if (root == NULL)
    return 0;

  // base case 2: leaves
  if (root->left == NULL && root->right == NULL) {
    *maxSize = max(*maxSize, 1);
    *min_ref = root->data;
    *max_ref = root->data;
    return 1;
  }

  // recursion
  *max_ref = INT_MIN;
  int lSize = maxSizeBST2(root->left, min_ref, max_ref, maxSize);
  if (lSize == -1 || root->data <= *max_ref) {
    lSize = -1;
  }
  int minFound = *min_ref;

  *min_ref = INT_MAX;
  int rSize = maxSizeBST2(root->right, min_ref, max_ref, maxSize);
  if (rSize == -1 || root->data > *min_ref) {
    rSize = -1;
  }
  int maxFound = *max_ref;

  if (lSize == -1 || rSize == -1) {
    return -1;
  }

  printf("%d -- %d -- %d\n", minFound, root->data, maxFound);
  // If `root` is a valid BST
  *min_ref = minFound;
  *max_ref = maxFound;
  *maxSize = max(*maxSize, lSize + rSize + 1);
  return *maxSize;

  return -1;
}

struct node *createTree() {
  struct node *root = newNode(1);
  root->left = newNode(2);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->left->right->left = newNode(8);
  root->left->right->right = newNode(19);
  root->right = newNode(3);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->right = newNode(10);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* node *prev = NULL; */
  /* cout << isBST(root, &prev) << endl; */

  /* int maxSize = 0; */
  /* maxSizeBST1(root, &maxSize); */

  int maxSize = 0;
  int min_ref = INT_MAX;
  int max_ref = INT_MIN;
  maxSizeBST2(root, &min_ref, &max_ref, &maxSize);
  cout << "Max size BST: " << maxSize << endl;

  return 0;
}
