#include <stdio.h>
#include <stdlib.h>

enum Status {ERROR = 0, OK = 1};

typedef int ElemType;

struct Node
{
  ElemType data;
  struct Node * next;
};

struct LinkedList
{
  int length;
  struct Node * head = NULL;
};

enum Status ListInit(struct LinkedList * L)
{
  L->head = (struct Node * )malloc(sizeof(struct Node *));
  L->head->next = NULL;

  return OK;
}

enum Status ListInsert(struct LinkedList * L, int index, ElemType e)
{
  struct Node * p = L->head;

  int i = 0;
  while (p != NULL && i < index)
  {
    p = p->next;
    i++;
  }

  if (!p || i >= index) return ERROR;

  struct Node * q = (struct Node * )malloc(sizeof(struct Node *));
  q->data = e;
  q->next = p->next;
  p->next = q;

  return OK;
}

void ListDisplay(struct LinkedList * L)
{
  struct Node * p = L->head->next;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  printf("\n");
}

void test()
{
  struct LinkedList L;
  ListInit(&L);
  ListInsert(&L, 0, 2);
  ListInsert(&L, 0, 3);
  ListInsert(&L, 0, 5);
  ListInsert(&L, 4, 7);
  ListDisplay(&L);
}

// int main(int argc, char const *argv[])
// {
//   test();
//   return 0;
// }
