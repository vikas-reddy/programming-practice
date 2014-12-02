#include<iostream>
#include<stdlib.h>

#define MARKER -1

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

void serialize(node *n, FILE *fp) {
  if (n == NULL) {
    fprintf(fp, "%d ", MARKER);
    return;
  }
  fprintf(fp, "%d ", n->data);
  serialize(n->left, fp);
  serialize(n->right, fp);
}

node *deserialize(FILE *fp) {
  int val;
  if (!fscanf(fp, "%d", &val) || val == MARKER)
    return NULL;

  node *r = newNode(val);
  r->left = deserialize(fp);
  r->right = deserialize(fp);
  return r;
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

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  FILE *fp = fopen("tree.txt", "w");
  serialize(root, fp);
  fclose(fp);

  fp = fopen("tree.txt", "r");
  node *r = deserialize(fp);
  fclose(fp);
  preOrder(r); printf("\n");

  return 0;
}
