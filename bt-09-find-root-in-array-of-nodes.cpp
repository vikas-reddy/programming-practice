#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<map>
#include<iterator>

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

// populates the array of "random" nodes
void populateArray(struct node *r, struct node *arr[], int *idx) {
  if (r == NULL) {
    return;
  }
  populateArray(r->left, arr, idx);
  arr[(*idx)++] = r;
  populateArray(r->right, arr, idx);
}

void preOrder(struct node *n, map<struct node*,bool> *m) {
  if (n == NULL) {
    return;
  }
  if (!(*m)[n]) {
    (*m)[n] = true;
    preOrder(n->left, m);
    preOrder(n->right, m);
  }
}

int getSize(struct node *r) {
  if (r == NULL) {
    return 0;
  }
  return (1 + getSize(r->left) + getSize(r->right));
}

int findRootIdx1(struct node *arr[], int n) {
  map<struct node*, bool> m;
  for (int i = 0; i < n; i++) {
    preOrder(arr[i], &m);
    /* printf("arr[%d]:%d m.size():%d\n", i, arr[i]->data, m.size()); */
    if (m.size() == n) {
      return i;
    }
  }
}

int findRootIdx2(struct node *arr[], int n) {
  for (int i = 0; i < n; i++) {
    if (getSize(arr[i]) == 10) {
      return i;
    }
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

void printArray(struct node *arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]->data);
  }
  printf("\n");
}

void printMap(map<struct node*, bool> *m) {
  for (map<struct node*,bool>::iterator i = (*m).begin(); i != (*m).end(); ++i) {
    printf("%d:%d ", i->first ? i->first->data : -1, i->second);
  }
  printf("\n");
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  // 10 nodes as of now
  struct node *arr[10] = {};

  int idx = 0;

  populateArray(root, arr, &idx);

  printArray(arr, 10);

  printf("root is at %d\n", findRootIdx1(arr, 10));
  printf("root is at %d\n", findRootIdx2(arr, 10));

  return 0;
}
