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

void insertSorted(struct Node * p, int x)
{
  struct Node *t, *q;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  q = NULL;
  if (first == NULL)
  {
    first = t;
  }
  else
  {
    while (x > p->data && p)
    { 
      q = p;
      p = p->next;
    }

    if (first == p)
    {
      t->next = first;
      first = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
    
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
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);

  printList(first);
  insertSorted(first, 1);
  printList(first);

  return 0;
}
