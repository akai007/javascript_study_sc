#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
} *first = NULL;

void create(int *arr, int n)
{
  struct Node *t, *last;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  last = first;

  int i = 1;
  while (i < n)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = arr[i];
    t->next = NULL;
    last->next = t;
    last = t;
    i++;
  }
}

int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}

void reverse(struct Node * p)
{
  int * A;
  int i = 0;
  struct Node *q = p;

  A = (int *)malloc(sizeof(int)*count(p));

  while (p != NULL)
  {
    A[i] = q->data;
    q = q->next;
    i++;
  }
  q = p;
  i--;
  while (q!=NULL)
  {
    q->data = A[i];
    q = q->next;
    i--;
  }
}

void printList(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 7, 11, 13, 17, 17};
  create(A, 7);

  printList(first);
  reverse(first);
  printList(first);

  return 0;
}
