#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
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

void insertCricularList(struct Node *h, int index, int x)
{
  struct Node *t, *p;
  p = h;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;

  if (index == 0)
  {
    if (Head == NULL)
    {
      Head = t;
      Head->next = Head;
    } else {
      t->next = h;
      while (p->next != h)
      {
        p = p->next;
      }
      p->next = t;
      Head = t;
    }
  }
  else
  {
    for (int i = 0; i < index - 1; i++)
    {
      p = p->next;
    }
    t->next = p->next;
    p->next = t;
  }
  
}


int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);
  insertCricularList(Head, 0, 2);
  insertCricularList(Head, 2, 4);
  insertCricularList(Head, 4, 6);
  insertCricularList(Head, 6, 8);

  printCircularList(Head);
  return 0;
}
