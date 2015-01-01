#include<iostream>
#include<stdlib.h>
#include<cmath>
#include<queue>
#include<list>
#include<iterator>
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
     Traversal3: 15 13 14 9 12 10 11 1 8 2 7 3 6 4 5 (same as 2)

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

void printLevel (list<node*> *l) {
  list<node*>::const_iterator i = (*l).begin();
  list<node*>::reverse_iterator j = (*l).rbegin();

  for (int ct = 0; ct < l->size()/2; ct++, ++i, ++j)
    printf("%d %d ", (*i)->data, (*j)->data);
}

void traversal3 (node *r) {
  if (r == NULL)
    return;

  node *n;
  list<node*> l;
  l.push_back(r);
  l.push_back(NULL); // level marker

  printf("%d ", r->data);

  while (!l.empty()) {
    n = l.front();
    l.pop_front();

    // End of level
    if (n == NULL) {
      if (l.empty())
        break;

      // We have the entire level with us now, in a doubly linked list.
      printLevel(&l);

      l.push_back(NULL);
      continue;
    }

    if (n->left) {
      l.push_back(n->left);
      l.push_back(n->right);
    }
  }
  printf("\n");
}

struct node *createTree() {
  /* struct node *r = newNode(15); */
  /* r->right = newNode(14); */
  /* r->left = newNode(13); */
  /* r->right->right = newNode(12); */
  /* r->right->left = newNode(11); */
  /* r->left->right = newNode(10); */
  /* r->left->left = newNode(9); */
  /* r->right->right->right = newNode(8); */
  /* r->right->right->left = newNode(7); */
  /* r->right->left->right = newNode(6); */
  /* r->right->left->left = newNode(5); */
  /* r->left->right->right = newNode(4); */
  /* r->left->right->left = newNode(3); */
  /* r->left->left->right = newNode(2); */
  /* r->left->left->left = newNode(1); */
  /* return r; */
  //Perfect Binary Tree of Height 4
    node *root = newNode(1);
 
    root->left        = newNode(2);
    root->right       = newNode(3);
 
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left  = newNode(6);
    root->right->right = newNode(7);
 
    root->left->left->left  = newNode(8);
    root->left->left->right  = newNode(9);
    root->left->right->left  = newNode(10);
    root->left->right->right  = newNode(11);
    root->right->left->left  = newNode(12);
    root->right->left->right  = newNode(13);
    root->right->right->left  = newNode(14);
    root->right->right->right  = newNode(15);
 
    root->left->left->left->left  = newNode(16);
    root->left->left->left->right  = newNode(17);
    root->left->left->right->left  = newNode(18);
    root->left->left->right->right  = newNode(19);
    root->left->right->left->left  = newNode(20);
    root->left->right->left->right  = newNode(21);
    root->left->right->right->left  = newNode(22);
    root->left->right->right->right  = newNode(23);
    root->right->left->left->left  = newNode(24);
    root->right->left->left->right  = newNode(25);
    root->right->left->right->left  = newNode(26);
    root->right->left->right->right  = newNode(27);
    root->right->right->left->left  = newNode(28);
    root->right->right->left->right  = newNode(29);
    root->right->right->right->left  = newNode(30);
    root->right->right->right->right  = newNode(31);

    return root;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* traversal1(root); */
  traversal2(root);
  traversal3(root);

  return 0;
}
