#include<iostream>
#include<stdlib.h>
#include<queue>
using namespace std;

int max(int a, int b) {
  return (a > b) ? a : b;
}

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

int findDepth(node *r) {
  if (r == NULL)
    return 0;
  return 1 + max(findDepth(r->left), findDepth(r->right));
}

void levelOrderIterative(node *r) {
  if (r == NULL)
    return;

  node *n;
  int level = 1;

  queue<node*> q;
  q.push(r);
  q.push(NULL); // NULL as level marker

  while (!q.empty()) {
    n = q.front();
    q.pop();

    // when we find a level marker, we insert one for the next level
    if (n == NULL) {
      printf(" -- %d\n", level++);

      // end of tree
      if (q.empty())
        break;

      q.push(NULL);
      continue;
    }

    printf("%d ", n->data);

    if (n->left)  q.push(n->left);
    if (n->right) q.push(n->right);
  }
}

void levelOrderRecursiveUtil(node *r, int level) {
  if (r == NULL) return;

  if (level == 1) {
    printf("%d ", r->data);
  }
  else {
    levelOrderRecursiveUtil(r->left, level - 1);
    levelOrderRecursiveUtil(r->right, level - 1);
  }
}

void levelOrderRecursive(node *r) {
  int depth = findDepth(r);
  for (int d = 1; d <= depth; d++) {
    levelOrderRecursiveUtil(r, d);
    printf("\n");
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

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* levelOrderIterative(root); */
  levelOrderRecursive(root);

  return 0;
}
