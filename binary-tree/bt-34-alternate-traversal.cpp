#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<queue>
#include<algorithm>

using namespace std;

/*
   For perfect binary trees only:

             15
            /  \
          13    14
        /  \    /  \
       9   10  11   12
      / \  / \ / \  / \
     1  2  3 4 5 6  7 8

     Traversal1: 1 8 2 7 3 6 4 5 9 12 10 11 13 14 15
     Traversal2: 15 13 14 9 12 10 11 1 8 2 7 3 6 4 5

 */

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

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
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

int reverse (int n, int bits) {
  int res = 0;
  for (int i = 0; i < bits; i++) {
    if (n & (1 << i)) {
      res |= (1 << (bits - i - 1));
    }
  }
  return res;
}

node *getNode (node *r, int num, int bits) {
  num = reverse(num, bits);
  for (int i = 0; i < bits; num >>= 1, i++) {
    r = (num & 1 ? r->right : r->left);
  }
  return r;
}

void traversal1 (node *r) {
  int height = 0;
  for (node *n = r; n; n = n->left, height++);

  if (height == 0)
    return;

  for (int bits = height - 1; bits > 0; bits--) {
    int last = pow(2, bits);

    for (int i = 0, j = last-1; i < j; i++, j--) {
      cout << getNode(r, i, bits)->data << " ";
      cout << getNode(r, j, bits)->data << " ";
    }
  }
  cout << r->data << endl;
}

/* Modified level order:
 * O(n) space
 * O(n) time
 */
void traversal2 (node *r) {
  if (r == NULL)
    return;

  printf("%d ", r->data);

  if (r->left == NULL) {
    printf("\n");
    return;
  }

  node *first, *second;

  queue<node*> q;
  q.push(r->left);
  q.push(r->right);

  // there are always even or zero number of nodes in the queue
  while (!q.empty()) {
    first = q.front();  q.pop();
    second = q.front(); q.pop();

    printf("%d %d ", first->data, second->data);

    if (first->left) {
      q.push(first->left);
      q.push(second->right);
      q.push(first->right);
      q.push(second->left);
    }
  }
  printf("\n");
}

struct node *createTree() {
  struct node *r = newNode(15);
  r->right = newNode(14);
  r->left = newNode(13);
  r->right->right = newNode(12);
  r->right->left = newNode(11);
  r->left->right = newNode(10);
  r->left->left = newNode(9);
  r->right->right->right = newNode(8);
  r->right->right->left = newNode(7);
  r->right->left->right = newNode(6);
  r->right->left->left = newNode(5);
  r->left->right->right = newNode(4);
  r->left->right->left = newNode(3);
  r->left->left->right = newNode(2);
  r->left->left->left = newNode(1);
  return r;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  traversal1(root);
  traversal2(root);

  return 0;
}
