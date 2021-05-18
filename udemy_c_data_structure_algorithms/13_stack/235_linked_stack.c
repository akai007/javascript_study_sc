#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *next;
} *top = NULL;

void push(int x)
{
  struct Node *t;
  t = (struct Node *)malloc(sizeof(struct Node));

  if (t == NULL)
    printf("stack is full \n");
  
  t->data = x;
  t->next = top;
  top = t;

}

int pop()
{
  struct Node *t;
  int x = -1;

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
  struct Node *p;
  p = top;
  while (p != NULL)
  {
    printf("%d ", p->data);
    p = p->next;
  }
  
  printf("\n");
  
}

int main(int argc, char const *argv[])
{
  push(2);
  push(3);
  push(5);
  push(7);
  push(11);
  push(13);
  
  printStack();
  pop();
  printStack();
  
  return 0;
}
