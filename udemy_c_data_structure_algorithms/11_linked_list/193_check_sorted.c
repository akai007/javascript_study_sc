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

int del(struct Node * p, int index)
{
  struct Node *t, *q;
  int x = -1;

  if ( index < 1 ) return -1;

  if (index == 1)
  {
    q = first;
    first = first->next;
    x = q->data;
    free(q);
    return x;
  }
  else 
  {
    q = NULL;
    for (int i = 0; i < index-1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    x = p->data;
    free(p);
    return x;
  }

}

int checkSorted(struct Node * p)
{
  int x = INT32_MIN;
  while (p != NULL)
  {
    if ( x > p->data)
      return 0;
    x = p->data;
    p = p->next;
  }

  return 1;
  
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
  printf("%d \n", checkSorted(first));

  int B[] = {2, 3, 5, 7, 11, 13, 11};
  create(B, 7);
  printf("%d \n", checkSorted(first));

  return 0;
}
