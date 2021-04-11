#include <stdio.h>
#include <stdlib.h>

struct Node
{
  struct Node *prev;
  struct Node *next;
  int data;
} *first = NULL;

void create(int * arr, int size)
{
  int i = 1;
  struct Node *last, *p;
  first = (struct Node *)malloc(sizeof(struct Node));
  first->data = arr[0];
  first->next = NULL;
  first->prev = NULL;
  last = first;
  
  while (i < size)
  {
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = arr[i];
    p->next = NULL;
    p->prev = last;
    last->next = p;
    last = p;

    i++;
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

int length(struct Node *p)
{
  int count = 0;

  while (p != NULL)
  {
    count++;
    p = p->next;
  }
  
  return count;
  
}

void insert(struct Node * p, int index, int x)
{
  if (index < 0 || index > length(p))
    return;

  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->next = NULL;
  t->prev = NULL;
  t->data = x;

  if (index == 0)
  {
    t->next = p;
    first->prev = t;
    first = t;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
      p = p->next;

    t->next = p->next;
    t->prev = p;
    if (p->next)
      p->next->prev = t;
    p->next = t;
  }
  
}


int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  printList(first);
  insert(first, 5, 1);
  insert(first, 8, 1);
  printList(first);

  return 0;
}
