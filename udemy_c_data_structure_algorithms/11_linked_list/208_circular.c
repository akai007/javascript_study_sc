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
void printCircularListRecurse(struct Node *h)
{
  static int flag = 0;
  if (h!= Head || flag == 0)
  {
    flag = 1;
    printf("%d ", h->data);
    printCircularListRecurse(h->next);
  }
  flag = 0;
}

int main(int argc, char const *argv[])
{
  int A[] = {2, 3, 5, 7, 11, 13, 17};
  create(A, 7);

  printCircularList(Head);
  printCircularListRecurse(Head);
  return 0;
}
