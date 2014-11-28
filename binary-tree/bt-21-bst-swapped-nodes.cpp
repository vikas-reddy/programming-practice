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

void swap(node **a, node **b) {
  node *temp = *a;
  *a = *b;
  *b = temp;
}

void findCulprits(node *r, node **pre, node **a, node **b) {
  if (r == NULL) {
    return;
  }
  findCulprits(r->left, pre, a, b);

  if (*pre) {
    if ((*pre)->data > r->data) {
      if (!*a) {
        *a = *pre;
      }
      *b = r;
    }
  }
  printf("%d:%d ", (*pre ? (*pre)->data : -1), r->data);
  *pre = r;
  findCulprits(r->right, pre, a, b);
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

node *findParent(node *r, node *n) {
  if (n == NULL || r == NULL || r == n) {
    return NULL;
  }
  if (r->left == n || r->right == n) {
    return r;
  }
  node *pleft = findParent(r->left, n);
  node *pright = findParent(r->right, n);
  return (pleft ? pleft : pright);
}

struct node *createTree() {
  struct node *root = newNode(5);
  root->left = newNode(2);
  root->left->left = newNode(1);
  root->left->right = newNode(6);
  root->left->right->right = newNode(4);
  root->right = newNode(8);
  root->right->left = newNode(3);
  root->right->left->right = newNode(7);
  root->right->right = newNode(9);
  root->right->right->right = newNode(10);
  return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  // finding the culprits
  node *pre = NULL, *a = NULL, *b = NULL;
  findCulprits(root, &pre, &a, &b); printf("\n");

  printf("Culprits: a=%d, b=%d\n", (a ? a->data : -1), (b ? b->data : -1));

  // find the parents of the culprits
  node *parent_a = findParent(root, a);
  node *parent_b = findParent(root, b);
  printf("Parents: a=%d, b=%d\n", (parent_a ? parent_a->data : -1), (parent_b ? parent_b->data : -1));

  // fixing the pointers
  if (parent_a && parent_b) {
    // swapping the child pointers of culprits
    swap(&a->left, &b->left);
    swap(&a->right, &b->right);

    if (parent_a->left == a) {
      if (parent_b->left == b)
        swap(&parent_a->left, &parent_b->left);
      else
        swap(&parent_a->left, &parent_b->right);
    }
    else {
      if (parent_b->left == b)
        swap(&parent_a->right, &parent_b->left);
      else
        swap(&parent_a->right, &parent_b->right);
    }
  }

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");
  return 0;
}
