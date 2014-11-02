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

int isPresent(struct node *list[], struct node *n, int f, int l) {
  if (f > l) {
    return 0;
  }
  int i;
  for (i = f; i <= l; i++) {
    if (list[i]->data == n->data) {
      return 1;
    }
  }
  return 0;
}

int findIdx(struct node *list[], struct node *n) {
  int i = 0;
  for (i = 0; i < 10; i++) {
    if (list[i]->data == n->data) {
      return i;
    }
  }
  return -1;
}

struct node *buildTree(struct node *inOrder[], struct node *preOrder[], int f, int l) {
  if (f < 0 || l >= 10 || f > l) {
    return NULL;
  }
  /* printf("[%d, %d] - %d\n", f, l, preOrder[f]->data); */
  if (f == l) {
    return preOrder[f];
  }
  struct node *r = preOrder[f];
  int inOrderIdx = findIdx(inOrder, r);
  int i;
  for (i = f + 1; i < l; i++) {
    if (!isPresent(inOrder, preOrder[i], 0, inOrderIdx - 1))
      break;
  }
  /* printf("i: %d\n", i); */
  r->left = buildTree(inOrder, preOrder, f + 1, i - 1);
  r->right = buildTree(inOrder, preOrder, i, l);
  return r;
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

  // creating inOrder and preOrder arrays
  int inOrderElements[10] = {15, 28, 32, 56, 60, 70, 75, 81, 83, 94};
  int preOrderElements[10] = {60, 32, 15, 28, 56, 70, 83, 75, 81, 94};
  struct node *inOrder[10];
  struct node *preOrder[10];
  int i = 0;
  for (i = 0; i < 10; i++) {
    inOrder[i] = newNode(inOrderElements[i]);
  }
  for (i = 0; i < 10; i++) {
    preOrder[i] = newNode(preOrderElements[i]);
  }

  struct node *root2 = buildTree(inOrder, preOrder, 0, 10 - 1);
  inOrderT(root2); printf("\n");
  preOrderT(root2); printf("\n");
  return 0;
}
