#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct LLNode {
  LLNode *next;
  int data;
};

struct TNode {
  int data;
  TNode *left;
  TNode *right;
};

void insertLL (LLNode **head, LLNode **tail, int elem) {
  LLNode *n = (LLNode *)malloc(sizeof(LLNode));
  n->data = elem;
  n->next = NULL;
  if (*head == NULL) {
    *head = *tail = n;
  }
  else {
    (*tail)->next = n;
    *tail = n;
  }
}

int sizeLL(LLNode *head) {
  int size = 0;
  LLNode *n = head;
  for (size = 0; n; n = n->next, size++);
  return size;
}

void printLL(LLNode *head) {
  if (head) {
    LLNode *n = head;
    for (n = head; n; n = n->next) {
      printf("%d ", n->data);
    }
    printf("\n");
  }
}

TNode *newNode(int data) {
  TNode *n = (TNode*)malloc(sizeof(TNode));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void swap (int *a, int *b) {
  int t = *a; *a = *b; *b = t;
}

void inOrder(TNode *n) {
  if (n == NULL) {
    return;
  }
  inOrder(n->left);
  printf("%d ", n->data);
  inOrder(n->right);
}

void preOrder(TNode *n) {
  if (n == NULL) {
    return;
  }
  printf("%d ", n->data);
  preOrder(n->left);
  preOrder(n->right);
}

TNode* convertToBST (LLNode **head, int len) {
  if (len <= 0)
    return NULL;

  TNode *leftTree = convertToBST (head, len/2);

  TNode *r = newNode((*head)->data);
  *head = (*head)->next;

  r->right = convertToBST (head, len - len/2 - 1);

  r->left = leftTree;
  return r;
}

int main(int argc, const char *argv[])
{
  LLNode *head = NULL, *tail = NULL;

  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int len = sizeof(arr)/sizeof(arr[0]);

  for (int i = 0; i < len; i++) {
    insertLL (&head, &tail, arr[i]);
  }

  TNode *root = NULL;

  root = convertToBST(&head, len);

  inOrder(root); printf("\n");
  preOrder(root); printf("\n");

  return 0;
}
