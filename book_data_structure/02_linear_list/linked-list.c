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
  Node * head = NULL;
  int length;
};

Status ListInit(struct LinkedList * L)
{
  L->head = (struct Node * )malloc(sizeof(struct Node *));
  L->head->next = NULL;

  return OK;
}

Status ListInsert(struct LinkedList * L, int index, ElemType e)
{
  struct Node * p = L->head;

  int i = 0;
  while (p != NULL && i <= index)
  {
    p = p->next;
    i++;
  }
  
  if (p != NULL)
  {
    struct Node * q = (struct Node * )malloc(sizeof(struct Node *));
    q->data = e;
    q->next = p->next;
    
  }
  

  return OK;
}




int main(int argc, char const *argv[])
{
  struct LinkedList L;
  ListInit(&L);
  
  return 0;
}
