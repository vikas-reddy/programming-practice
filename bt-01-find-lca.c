#include<stdio.h>
#include<stdlib.h>

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

int isPresent(struct node *n, int d) {
  if (n == NULL) {
    return 0;
  }
  if (n->data == d) {
    return 1;
  }
  return isPresent(n->left, d) || isPresent(n->right, d);
}

struct node *getLca(struct node *n, int a, int b) {
  if (n == NULL) {
    return NULL;
  }
  if (n->data == a || n->data == b) {
    return n;
  }
  int la_p = isPresent(n->left, a),
      lb_p = isPresent(n->left, b);
  if (la_p ^ lb_p) {
    return n;
  }
  if (la_p && lb_p) {
    return getLca(n->left, a, b);
  }
  else if (!la_p && !lb_p) {
    return getLca(n->right, a, b);
  }
  return NULL;
}

struct node *getLca2(struct node *n, int a, int b) {
  if (n == NULL) {
    return NULL;
  }
  if (n->data == a || n->data == b) {
    return n;
  }
  struct node *left_lca = getLca2(n->left, a, b);
  struct node *right_lca = getLca2(n->right, a, b);

  if (left_lca && right_lca) {
    return n;
  }

  return (left_lca ? left_lca : right_lca);
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root);
  printf("\n");

  /* printf("isPresent: %d\n", isPresent(root, 14)); */
  printf("lca: %d\n", getLca2(root, 4, 10)->data);
  printf("lca: %d\n", getLca2(root, 6, 7)->data);
  printf("lca: %d\n", getLca2(root, 9, 10)->data);
  printf("lca: %d\n", getLca2(root, 10, 3)->data);
  return 0;
}
