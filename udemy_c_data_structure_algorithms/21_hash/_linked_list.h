#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node * next;
};

void linkedList_sortedInsert(struct Node **H, int x)
{
   struct Node *t,*q=NULL,*p=*H;
  t = (struct Node *)malloc(sizeof(struct Node));
  t->data = x;
  t->next = NULL;

  q = NULL;
  if (*H == NULL)
  {
    *H = t;
  }
  else
  {
    while (p && x > p->data)
    { 
      q = p;
      p = p->next;
    }

    if (*H == p)
    {
      t->next = *H;
      *H = t;
    }
    else
    {
      t->next = q->next;
      q->next = t;
    }
    
  }
  
}

struct Node * linkedList_serch(struct Node * p, int key)
{
  while (p != NULL)
  {
    if (p->data == key)
        return p;
    p = p->next;
  }
  return NULL;
}
