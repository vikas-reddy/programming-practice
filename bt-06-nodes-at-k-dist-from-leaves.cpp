#include<iostream>
#include<stdlib.h>
#include<list>
#include<set>
#include<iterator>

using namespace std;

struct node {
  int data;
  struct node *left;
  struct node *right;
};

void printStack(list<node*> l) {
  list<node*>::iterator i;
  for (i = l.begin(); i != l.end(); ++i) {
    printf("%d ", (*i)->data);
  }
  printf("\n");
}

void printSet(set<node*> s) {
  for (set<node*>::const_iterator i = s.begin(); i != s.end(); ++i) {
    printf("%d ", (*i)->data);
  }
  printf("\n");
}

void getKthAncestor(list<node*> l, int k, set<node*> *result) {
  if (k >= l.size()) {
    return;
  }
  list<node*>::iterator i;
  int dist = 0;
  for (i = l.begin(); i != l.end() && dist < k; ++i, dist++);
  (*result).insert(*i);
  /* printf("%dth=%d\n", k, (*i)->data); */
}

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

int depth(struct node *root) {
  if (root == NULL) {
    return 0;
  }
  int dleft = depth(root->left);
  int dright = depth(root->right);
  return (dleft > dright ? dleft : dright) + 1;
}

void printNodesAtKDistFromLeaves(struct node *r, int k, list<node*> *ancestors, set<node*> *result) {
  if (r == NULL || k < 0) {
    return;
  }
  (*ancestors).push_front(r);
  if (!r->left && !r->right) {
    /* printf("leaf(%d) ", r->data); */
    /* printStack(*ancestors); */
    getKthAncestor(*ancestors, k, result);
    (*ancestors).pop_front();
    return;
  }
  printNodesAtKDistFromLeaves(r->left, k, ancestors, result);
  printNodesAtKDistFromLeaves(r->right, k, ancestors, result);
  (*ancestors).pop_front();
  return;
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

  list<node*> ancestors;
  set<node*> result;
  int k = 3;
  printNodesAtKDistFromLeaves(root, k, &ancestors, &result);
  printSet(result);
  return 0;
}
