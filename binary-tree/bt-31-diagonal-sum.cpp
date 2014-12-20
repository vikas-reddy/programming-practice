#include<iostream>
#include<stdlib.h>
#include<queue>
#include<map>
#include<iterator>
#include<algorithm>
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

void printDiagonalSums1 (node *r) {
  if (r == NULL)
    return;

  queue<node*> q;
  int sum = 0, ct1 = 0, ct2 = 0;

  // First insert into the queue
  node *n = r;
  while (n) {
    q.push(n);
    sum += n->data;
    ct1++;
    n = n->right;
  }

  do {
    printf("%d \n", sum);
    ct2 = 0;
    sum = 0;
    for (int i = 0; i < ct1; i++) {
      n = q.front();
      q.pop();
      if (n->left) {
        for (node *temp = n->left; temp; temp = temp->right) {
          q.push(temp);
          sum += temp->data;
          ct2++;
        }
      }
      n = n->right;
    }
    ct1 = ct2;
  } while (ct1); // ct1 becomes zero when the queue is empty
}

void printDiagonalSums2Util (node *r, int vd, int hd, map<unsigned,int> *m) {
  if (r == NULL)
    return;
  (*m)[(vd - hd)/2] += r->data;
  printDiagonalSums2Util(r->left, vd + 1, hd - 1, m);
  printDiagonalSums2Util(r->right, vd + 1, hd + 1, m);
}

void printDiagonalSums2 (node *r) {
  map<unsigned,int> m;
  printDiagonalSums2Util(r, 0, 0, &m);
  for (map<unsigned,int>::const_iterator i = m.begin(); i != m.end(); ++i) {
    printf("%d\n", i->second);
  }
}

struct node *createTree() {
  /* struct node *root = newNode(1); */
  /* root->left = newNode(2); */
  /* root->left->left = newNode(4); */
  /* root->left->right = newNode(5); */
  /* root->left->right->left = newNode(8); */
  /* root->left->right->right = newNode(9); */
  /* root->right = newNode(3); */
  /* root->right->left = newNode(6); */
  /* root->right->right = newNode(7); */
  /* root->right->right->right = newNode(10); */
  /* return root; */

  node *r = newNode(1);
  r->right = newNode(3);
  r->right->right = newNode(5);
  r->right->left = newNode(4);
  r->right->left->left = newNode(12);
  r->right->left->right = newNode(7);
  r->left = newNode(2);
  r->left->left = newNode(9);
  r->left->left->right = newNode(10);
  r->left->right = newNode(6);
  r->left->right->left = newNode(11);
  return r;
}

int main(int argc, const char *argv[])
{
  struct node *root = createTree();

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  /* printDiagonalSums1(root); */
  printDiagonalSums2(root);

  return 0;
}
