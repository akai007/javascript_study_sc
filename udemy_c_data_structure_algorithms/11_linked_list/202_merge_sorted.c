#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
} *first = NULL, *second = NULL;

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

void printList(struct Node *p)
{
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

struct Node * sortedMerge(struct Node * p1, struct Node * p2)
{

  struct Node * p3 = NULL;
  struct Node * last;

  if (p1->data < p2->data)
  {
    p3 = p1;
    last = p1;
    p1 = p1->next;
    last->next = NULL;
  } else {
    p3 = p2;
    last = p2;
    p2 = p2->next;
    last->next = NULL;
  }
  

  while (p1 != NULL && p2 != NULL)
  {
    if (p1->data < p2->data)
    {
      last->next = p1;
      last = p1;
      p1 = p1->next;
      last->next = NULL;
    }
    else
    {
      last->next = p2;
      last = p2;
      p2 = p2->next;
      last->next = NULL;
    }
  }

  while (p1 != NULL)
  {
    last->next = p1;
    last = p1;
    p1 = p1->next;
    last->next = NULL;
  }
  while (p2 != NULL)
  {
    last->next = p2;
    last = p2;
    p2 = p2->next;
    last->next = NULL;
  }
  
  return p3;
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  second = first;
  first = NULL;
  int B[] = {2, 4, 6, 8, 10};
  create(B, 3);

  printList(first);
  printList(second);
  printList(sortedMerge(first, second));

  return 0;
}
