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
  struct Node * head;
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

  // if (!p && i >= index) return ERROR;
  // TODO fix error

  struct Node * q = (struct Node * )malloc(sizeof(struct Node *));
  q->data = e;
  q->next = p->next;
  p->next = q;

  return OK;
}

enum Status ListSortedInsert(struct LinkedList * L, ElemType e)
{

}

void ListSortedConcat(struct LinkedList * La, struct LinkedList * Lb)
{
  struct Node * pa = La->head->next;
  struct Node * pb = Lb->head->next;
  struct Node * t = NULL;

  while (pa && pb)
  {
    
    if (pa->data <= pb->data)
    {
      pa = pa->next;
    } else {
      t = pb;
      pb = pb->next;
      t->next = pa->next;
      pa->next = t;
    }
  }

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
  ListInsert(&L, 1, 3);
  ListInsert(&L, 2, 5);
  ListInsert(&L, 3, 7);
  ListDisplay(&L);
<<<<<<< Updated upstream
=======

  struct LinkedList Lb;
  ListInsert(&Lb, 0, 4);
  ListSortedConcat(&L, &Lb);
  ListDisplay(&L);

  
  
  return 0;
>>>>>>> Stashed changes
}

// int main(int argc, char const *argv[])
// {
//   test();
//   return 0;
// }
