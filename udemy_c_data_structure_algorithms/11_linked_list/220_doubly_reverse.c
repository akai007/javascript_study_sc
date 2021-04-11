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

void reverse(struct Node * p)
{
  struct Node *t;

  while (p != NULL)
  {
    t = (struct Node *)malloc(sizeof(struct Node));
    t = p->next;
    p->next = p->prev;
    p->prev = t;
    p = p->prev;

    if (p != NULL && p->next == NULL)
    {
      first = p;
    }
    
  }
  
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  printList(first);
  reverse(first);
  printList(first);

  return 0;
}
