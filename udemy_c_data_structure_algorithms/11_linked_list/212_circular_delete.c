#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *Head = NULL;

void create(int *arr, int n)
{
  struct Node *t, *last;
  Head = (struct Node *)malloc(sizeof(struct Node));
  Head->data = arr[0];
  Head->next = Head;
  last = Head;

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

  last->next = Head;
}

void printCircularList(struct Node *h)
{
  do
  {
    printf("%d ", h->data);
    h = h->next;
  } while (h != Head);

  printf("\n");
}

void delCricularList(struct Node *h, int index)
{
  struct Node *p, *q;
  p = h;
  if (index == 1)
  {
    while (p->next != Head)
    {
      p = p->next;
    }

    if (Head == p)
    {
      free(Head);
      Head = NULL;
    }
    else
    {
      q = Head;
      Head = Head->next;
      p->next = Head;
      free(q);
    }
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      q = p;
      p = p->next;
    }
    q->next = p->next;
    free(p);
  }
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  printCircularList(Head);
  delCricularList(Head, 1);
  delCricularList(Head, 3);
  printCircularList(Head);
  return 0;
}
