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

int del(struct Node * p, int index)
{
  if (index < 1 || index > length(p))
    return -1;
  
  int x = -1;
  
  if (index == 1)
  {
    p = p->next;
    p->prev = NULL;
    x = first->data;
    free(first);
    first = p;
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
      p = p->next;

    p->prev->next = p->next;
    if (p->next)
      p->next->prev = p->prev;
    
    x = p->data;
    free(p);
  }

  return x;
}


int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  printList(first);
  del(first, 1);
  del(first, 3);
  del(first, 5);
  printList(first);

  return 0;
}
