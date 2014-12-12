#include<iostream>
#include<stdlib.h>
#include<limits.h>

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

void modifiedInOrder(struct node *r, struct node **pred, struct node **succ, int *size) {
  if (r == NULL) {
    return;
  }

  modifiedInOrder(r->left, pred, succ, size);
  printf("r:%d pred:%d\n", r->data, (*pred ? (*pred)->data : -1));
  *pred = r;
  modifiedInOrder(r->right, pred, succ, size);
}

/* O(n2) algorithm | visits some nodes many times */
void sizeOfBST(struct node *r, int *s) {
  if (r == NULL) {
    return;
  }

  int size_l = 0, size_r = 0;
  sizeOfBST(r->left, &size_l);
  sizeOfBST(r->right, &size_r);

  struct node *pred, *succ;
  // find the inOrder predecessor and successors
  for (pred = r->left; pred && pred->right; pred = pred->right);
  for (succ = r->right; succ && succ->left; succ = succ->left);

  if ( (pred == NULL || pred->data < r->data) && (succ == NULL || succ->data >= r->data) ) {
    // maximize the current max found
    if (*s < size_l + size_r + 1) {
      *s = size_l + size_r + 1;
    }
  }
  else {
    // propagate the max size to the root
    *s = (size_l > size_r) ? size_l : size_r;
  }
}

void preOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  printf("%d ", n->data);
  preOrder(n->left);
  preOrder(n->right);
}

void inOrder(struct node *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
}

int largestBST (node *r, int *min_ref, int *max_ref, bool *is_bst, int *max_bst) {
  // Base case
  if (r == NULL) {
    *is_bst = true;
    return 0;
  }

  // Left recursion
  int lmin = INT_MIN, lmax = INT_MAX;
  bool is_bst_l = false;
  int ls = largestBST(r->left, &lmin, &lmax, &is_bst_l, max_bst);

  // Right recursion
  int rmin = INT_MIN, rmax = INT_MAX;
  bool is_bst_r = false;
  int rs = largestBST(r->right, &rmin, &rmax, &is_bst_r, max_bst);

  // Actual root

  // If both the subtrees are BSTs, check whether the current root is a BST
  if (is_bst_l && is_bst_r) {
    if ( (lmax == INT_MAX || lmax < r->data) &&
         (rmin == INT_MIN || rmin > r->data) ) {
      *is_bst = true;
      *min_ref = (lmin == INT_MIN ? r->data : lmin);
      *max_ref = (rmax == INT_MAX ? r->data : rmax);
      *max_bst = max(*max_bst, ls+rs+1);
      /* printf("%d is BST; max: %d\n", r->data, *max_bst); */
      return *max_bst;
    }
  }

  // Control comes here only when one of root, left and right is not a bst
  /* printf("%d is not a BST; max: %d\n", r->data, *max_bst); */
  *is_bst = false;
  return 0;
}

struct node *createTree() {
  /* struct node *root = newNode(5); */
  /* root->left = newNode(2); */
  /* root->right = newNode(4); */
  /* root->left->left = newNode(1); */
  /* root->left->right = newNode(3); */
  /* return root; */

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

/*   struct node *r = newNode(50); */
/*   r->left = newNode(30); */
/*   r->left->left = newNode(5); */
/*   r->left->right = newNode(20); */
/*   r->right = newNode(60); */
/*   r->right->left = newNode(45); */
/*   r->right->right = newNode(70); */
/*   r->right->right->left = newNode(65); */
/*   r->right->right->right = newNode(80); */
/*   return r; */
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* struct node *pred = NULL, *succ = NULL; */
  /* int s = 0; */
  /* sizeOfBST(root, &s); */
  /* printf("%d\n", s); */

  int min = INT_MIN, max = INT_MAX;
  int max_bst = 0;
  bool is_bst = false;

  largestBST (root, &min, &max, &is_bst, &max_bst);

  cout << "Largest BST: " << max_bst << endl;

  return 0;
}
