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

struct Node * searchImprove(struct Node *p, int key)
{
  struct Node *q;
  while (p != NULL)
  {
    q = p;
    if (p->data == key)
    {
      q->next = p->next;
      p->next = first;
      first = p;
      return p;
    }
    p = p->next;
  }
  return NULL;
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
  // printf("max: %d \n", max(first));
  printf("search: %d \n", searchImprove(first, 5)->data);
  printf("search: %d \n", searchImprove(first, 17)->data);
  printList(first);

  return 0;
}
