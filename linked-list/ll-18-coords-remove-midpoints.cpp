#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<algorithm>

using namespace std;

/*
 * Given a linked list of co-ordinates where adjacent points either form a
 * vertical line or a horizontal line. Delete points from the linked list which
 * are in the middle of a horizontal or vertical line.
 */

struct node {
  int x, y;
  struct node *next;
};

void push_back (struct node **head, struct node **tail, int x, int y) {
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->x = x;
  n->y = y;
  n->next = NULL;

  if (*head == NULL) {
    *head = *tail = n;
  }
  else {
    (*tail)->next = n;
    *tail = n;
  }
}

int sizeLL(struct node *head) {
  int size = 0;
  struct node *n = head;
  for (size = 0; n; n = n->next, size++);
  return size;
}

void printLL(struct node *head) {
  if (head) {
    struct node *n = head;
    for (n = head; n; n = n->next) {
      printf("(%d,%d) ", n->x, n->y);
    }
    printf("\n");
  }
}

void removeMidpoints (node *head) {
  node *start = head;
  int ct_x = 1, ct_y = 1, ct;
  node *x_ptr, *y_ptr, *ptr;

  // start from the head
  while (start) {
    x_ptr = start;
    y_ptr = start;
    ct_x = 1;
    ct_y = 1;

    // Number of points starting from `start` which are on same vertical line
    while (x_ptr->next && x_ptr->next->x == start->x) {
      x_ptr = x_ptr->next;
      ct_x++;
    }

    // Number of points starting from `start` which are on same horizontal line
    while (y_ptr->next && y_ptr->next->y == start->y) {
      y_ptr = y_ptr->next;
      ct_y++;
    }

    /* printf("ct_x: %d, ct_y: %d\n", ct_x, ct_y); */
    // Maximum of both
    ct = max(ct_x, ct_y);

    // Delete nodes only if there are "middle" nodes
    if (ct >= 3) {
      /* printf("x_ptr: (%d,%d), y_ptr: (%d,%d)\n", x_ptr->x, x_ptr->y, y_ptr->x, y_ptr->y); */
      // The end pointer
      ptr = (ct == ct_x) ? x_ptr : y_ptr;

      // Now delete (free) the middle nodes
      for (node *t = start->next; t != ptr; ) {
        node *temp = t;
        t = t->next;
        free(temp);
      }
      start->next = ptr;
    }
    else {
      // Increment by just one
      start = start->next;
    }
  }
}


int main() {
  // initializing an empty LL
  struct node *head = NULL, *tail = NULL;

  // (0,10)->(1,10)->(5,10)->(7,10)->(7,5)->(20,5)->(40,5)
  /* push_back (&head, &tail, 0, 10); */
  /* push_back (&head, &tail, 1, 10); */
  /* push_back (&head, &tail, 5, 10); */
  /* push_back (&head, &tail, 7, 10); */
  /* push_back (&head, &tail, 7, 5); */
  /* push_back (&head, &tail, 20, 5); */
  /* push_back (&head, &tail, 40, 5); */

  // (2,3)->(4,3)->(6,3)->(10,3)->(12,3)
  push_back (&head, &tail, 2, 3);
  push_back (&head, &tail, 4, 3);
  push_back (&head, &tail, 6, 3);
  push_back (&head, &tail, 10, 3);
  push_back (&head, &tail, 12, 3);

  printLL(head);

  removeMidpoints (head);

  printLL(head);
}
