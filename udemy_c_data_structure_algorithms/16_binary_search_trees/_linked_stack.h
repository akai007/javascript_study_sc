#include <stdio.h>
#include <stdlib.h>
#include "./_tree_node.h"

struct StackNode
{
  struct TreeNode *data;
  struct StackNode *next;
} *top = NULL;

void push(struct TreeNode *x)
{
  struct StackNode *t;
  t = (struct StackNode *)malloc(sizeof(struct StackNode));

  if (t == NULL)
    printf("stack is full \n");
  
  t->data = x;
  t->next = top;
  top = t;

}

struct TreeNode * pop()
{
  struct StackNode *t;
  struct TreeNode *x = NULL;

  if (top == NULL)
    printf("stack is empty \n");
  else
  {
    t = top;
    top = top->next;
    x = t->data;
    free(t);
  }
  
  return x;
}

void printStack()
{
  struct StackNode *p;
  p = top;
  while (p != NULL)
  {
    printf("%d ", p->data->data);
    p = p->next;
  }
  
  printf("\n");
  
}
