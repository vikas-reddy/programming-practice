#include<iostream>
#include<queue>
#include<stack>

using namespace std;

struct node {
  int data;
  node *left, *right;
};

node *newNode (int data) {
  node *n = new node;
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

node *createTree () {
  node *r = newNode(1);
  r->left = newNode(2);
  r->left->left = newNode(7);
  r->left->right = newNode(6);
  r->right = newNode(3);
  r->right->left = newNode(5);
  r->right->right = newNode(4);
  return r;
}

void inOrder (node *r) {
  if (r == NULL)
    return;
  inOrder(r->left);
  cout << r->data << " ";
  inOrder(r->right);
}

void preOrder (node *r) {
  if (r == NULL)
    return;
  cout << r->data << " ";
  preOrder(r->left);
  preOrder(r->right);
}

void spiralOrder (node *r) {
  if (r == NULL)
    return;

  node *n = NULL;

  stack<node*> s1, s2;
  s1.push(r);

  while (!s1.empty() || !s2.empty()) {
    while (!s1.empty()) {
      n = s1.top();
      s1.pop();
      cout << n->data << " ";

      if (n->left)
        s2.push(n->left);
      if (n->right)
        s2.push(n->right);
    }

    while (!s2.empty()) {
      n = s2.top();
      s2.pop();
      cout << n->data << " ";

      if (n->right)
        s1.push(n->right);
      if (n->left)
        s1.push(n->left);
    }
  }
}

int main(int argc, const char *argv[])
{
  node *r = createTree();
  spiralOrder(r);
  return 0;
}
